#include <iostream>
using namespace std;

//ÓÐÓÃÀý´íÎó
int main() {
    int N, T;
    cin >> N >> T;
    int times[N];
    int max = -1;
    for (int i = 0; i < N; ++i) {
        cin >> times[i];
        if(times[i]>max){
            max = times[i];
        }
    }
    if (N == T) {
        return max;
    }

    int start = 0;
    int end = max;
    int res = max;
    int curNum;
    while (start <= end) {
        curNum = (start + end) / 2;
        int sum = 0;
        //check if right
        for (int i = 0; i < N; ++i) {
            sum += times[i] / curNum;
            if (times[i] % curNum) {
                ++sum;
            }
        }
        if (sum <= T) {
            //right
            if(curNum < res){
                res = curNum;
            }
            end = curNum - 1;
        } else {
            start = curNum + 1;
        }
    }
    cout << res;
    return 0;
}
/*
4 5
7
13
4
5

4 6
1 2 3 9

 3

4 5
1 2 3 8

 4
 */