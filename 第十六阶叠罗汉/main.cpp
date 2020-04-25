#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool shorter(vector<int> &v1, vector<int> &v2) {
    return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] > v2[1]);
}

int longestSub(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    vector<int> res;
    int sz = nums.size();
    int max = -1;
    res.push_back(1);
//        res[0] = 1;
    for (int i = 1; i < sz; ++i) {
        res.push_back(1);
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && res[j] + 1 > res[i]) {
                res[i] = res[j] + 1;
            }
        }
    }
    for (int k = 0; k < sz; ++k) {
        if (res[k] > max) {
            max = res[k];
        }
    }
    return max;
}

int maxHeight(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(), shorter);
    vector<int> nums;
    for (auto envelope:envelopes) {
        nums.push_back(envelope[1]);
    }
    return longestSub(nums);
}

int main() {
    vector<vector<int>> luoHans;
    int N;
    cin >> N;
    vector<int> temp = {0, 0};
    for (int i = 0; i < N; ++i) {
        cin >> temp[0] >> temp[1];
        luoHans.push_back(temp);
    }
    int a = maxHeight(luoHans);
    cout << a;
}
