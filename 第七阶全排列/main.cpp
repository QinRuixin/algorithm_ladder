#include <iostream>

using namespace std;

int nums[10001];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i + 1];
    }
    int a = N;
    int b = N;
    while (M--) {
        for (int j = N - 1; j >= 1; --j) {
            if (nums[j] < nums[j + 1]) {
                a = j;
                break;
            }
        }
        for (int k = N; k >= 1; --k) {
            if (nums[k] > nums[a]) {
                b = k;
                break;
            }
        }
        swap(nums[a], nums[b]);
        b = N;
        while (a + 1 < b) {
            swap(nums[a + 1], nums[b]);
            ++a;
            --b;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << nums[i + 1];
        if (i != N) {
            cout << " ";
        }
    }

    return 0;
}