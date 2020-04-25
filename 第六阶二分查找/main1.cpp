#include <iostream>
#include <algorithm>

using namespace std;
//³¬Ê±
int main() {
    int N, T;
    cin >> N >> T;
    int times[N];
    for (int i = 0; i < N; ++i) {
        cin >> times[i];
    }
    sort(times, times + N);
    if (N == T) {
        return times[N - 1];
    }
    int start = 0;
    int end = N - 1;
    int curIdx = 0;
    int tempRes;
    int total = T + 1;
    int res = times[N - 1];
    while (start <= end) {
        curIdx = (start + end) / 2;
        while (curIdx != N - 1 && times[curIdx + 1] == times[curIdx])
            ++curIdx;
        int before = curIdx + 1;
        int after = N - curIdx - 1;
        if (before + 2 * after > T) {
            start = curIdx + 1;
            continue;
        } else {
            int sum = before;
            //check if right
            tempRes = times[curIdx];
            for (int i = curIdx + 1; i < N; ++i) {
                sum += times[i] / tempRes;
                if (times[i] % tempRes) {
                    ++sum;
                }
            }
            if (sum <= T) {
                //find min
                if (sum < total) {
                    res = tempRes;
                    total = sum;
                }
                end = curIdx - 1;
            } else {
                start = curIdx + 1;
            }
        }
    }

    if (curIdx == 0) {
        start = 1;
    } else {
        start = times[curIdx - 1] + 1;
    }
    end = res;
    tempRes = res;
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
            if(curNum < tempRes){
                tempRes = curNum;
            }
            end = curNum - 1;
        } else {
            start = curNum + 1;
        }
    }
//    cout << res;
    cout << tempRes;
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