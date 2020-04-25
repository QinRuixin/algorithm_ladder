//ac´úÂë

#include <iostream>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    int times[N];
    int max = -1;
    int timeSum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> times[i];
        timeSum += times[i];
        if (times[i] > max) {
            max = times[i];
        }
    }
    if (N == T) {
        cout << max;
        return 0;
    }
    int start = timeSum / T + 1;
    int end = max;
    int res = max;
    int curNum;
    while (start <= end) {
        curNum = (start + end) / 2;
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += (times[i]+curNum-1) / curNum;
        }
        if (sum <= T) {
            res = curNum;
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

7


4 6
1
2
3
9

3


4 5
1
2
3
8

4


3 3
1
2
3

3


3 100
1
2
3

1
 */