#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int N, K, M;
    cin >> N >> K >> M;
    int gap1 = K - 1;
    int gap2 = M - 1;
    bool candidates[100];
    fill(candidates,candidates+N, true);
    int i1 = 0, i2 = N - 1;
    int g1, g2, temp1, temp2;
    int cnt = N;
    while (true) {
        g1 = 0;
        g2 = 0;
        while (g1 != gap1) {
            if (candidates[i1]) {
                ++g1;
            }
            i1 = (i1 + 1) % N;
        }
        while (!candidates[i1]) {
            i1 = (i1 + 1) % N;
        }
        temp1 = i1;
        while (g2 != gap2) {
            if (candidates[i2]) {
                ++g2;
            }
            i2 = (i2 - 1 + N) % N;
        }
        while (!candidates[i2]) {
            i2 = (i2 - 1 + N) % N;
        }
        temp2 = i2;
        candidates[temp1] = false;
        candidates[temp2] = false;
        if (temp1 == temp2) {
            cout << temp1 + 1;
            break;
        } else {
            cnt -= 2;
            if (cnt > 0) {
                cout << temp1 + 1 << " " << temp2 + 1 << " ";
            } else {
                cout << temp1 + 1 << " " << temp2 + 1;
                break;
            }
        }
    }
}