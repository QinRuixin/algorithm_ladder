#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int *> nums;
int N;

int getTwoMatch(int target) {
    int *C = nums[2];
    int *D = nums[3];
    int ic = 0;
    int id = N - 1;
    int sum = C[ic] + D[id];
    int res =0 ;
    while ( ic <= N - 1 && id >= 0){
        sum = C[ic] + D[id];
        if(sum==target){
            ++res;
            ++ic;
            --id;
        }else if (sum<target)
            ++ic;
        else
            --id;
    }
    return res;
}

int DFS(int startList, int target) {
    if (startList == 2) {
        return getTwoMatch(target);
    }
    if (startList == 4) {
        if (target == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    int *curList = nums[startList];
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (target - curList[i] < 0) {
            break;
        }
        res += DFS(startList + 1, target - curList[i]);
    }
    return res;
}


int main() {
    cin >> N;
    //A B C D 10000
    for (int j = 0; j < 4; ++j) {
        int *temp = new int[N];
        for (int i = 0; i < N; ++i) {
            cin >> temp[i];
        }
        sort(temp, temp + N);
        nums.push_back(temp);
    }

    cout << DFS(0, 10000);
    return 0;
}