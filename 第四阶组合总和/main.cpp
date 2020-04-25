#include <iostream>

using namespace std;

int N;
int nums1[10001];

int main() {
    cin >> N;
    int A[N];
    int B[N];
    int C[N];
    int D[N];

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }

    int temp;
    for(int i=0;i<N;i++){
        for (int j = 0; j < N; ++j) {
            temp = A[i]+B[j];
            if(temp<=10000){
                ++nums1[temp];
            }
        }
    }
    int res=0;
    for(int i=0;i<N;i++){
        for (int j = 0; j < N; ++j) {
            temp = C[i]+D[j];
            if(temp<=10000){
                res += nums1[10000-temp];
            }
        }
    }
    cout << res;
    return 0;
}
