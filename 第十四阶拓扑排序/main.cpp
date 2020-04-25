#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int inDegree[600001];
int res[600001];

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int N, M;
    cin >> N >> M;
    //N个人 从0到N-1
    vector<int> aj[N];
    int idx=0;
    int start;
    int end;
    for (int i = 0; i < M; ++i) {
        cin >> start >> end;
        aj[start].push_back(end);
        ++inDegree[end];
    }
    priority_queue<int,vector<int>,greater<int> > pq;
    for (int i = 0; i < N; ++i) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();
//        cout << temp << " ";
        res[idx++] = temp;

        while (!aj[temp].empty()) {
            int tempEnd = aj[temp].back();
            --inDegree[tempEnd];
            if (inDegree[tempEnd] == 0) {
                pq.push(tempEnd);
            }
            aj[temp].pop_back();
//            cout << tempEnd << " out ";
        }
    }

    for (int j = 0; j < N; ++j) {
        cout << res[j];
        if(j!=N-1){
            cout << " ";
        }
    }

    return 0;

}
