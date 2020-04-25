#include <iostream>
#include <stack>

using namespace std;

int serious[100005];
int preSum[100005];

int main() {
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp > 8) {
            serious[i] = 1;
        }else{
            serious[i] = -1;
        }
    }
    preSum[0] = 0;
    stack<int> increIdx;
    increIdx.push(0);
    for (int j = 1; j <= n; ++j) {
        preSum[j] = preSum[j - 1] + serious[j - 1];
        if (preSum[j] < preSum[increIdx.top()]) {
            increIdx.push(j);
        }
    }
    //preSum[0]= 0  依照idx
    int max = 0;
    for (int k = n; k >= 0; --k) {
        int low=0;
        while (!increIdx.empty() && preSum[k] > preSum[increIdx.top()]) {
            low = increIdx.top();
            increIdx.pop();
        }
        if (k - low > max && preSum[k] > preSum[low]) {
            max = k - low;
        }
    }
    cout << max;
    return 0;
}
