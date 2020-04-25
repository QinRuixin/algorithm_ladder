#include <iostream>
#include <queue>

using namespace std;

queue<int> station;
int leave[1001];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> leave[i];
    }
    int n = 0;//station中现存的
    int cur = 0;//等待进站的车
    int idx = 0;
    while (idx < N) {
        if (leave[idx] >= cur) {
            while (leave[idx] != cur) {
                //
//                cout << cur << " in" << endl;
                station.push(cur++);
                ++n;
            }
            if (n > M) {
                cout << "NO" << endl;
                return 0;
            }
            //
//            cout << cur << " pass" << endl;
            ++cur;
            ++idx;
        } else if ((!station.empty()) && (leave[idx] == station.front())) {
            station.pop();
            //
//            cout << leave[idx] << " out" << endl;
            --n;
            ++idx;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

}
