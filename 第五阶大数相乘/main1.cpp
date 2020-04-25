#include <iostream>
#include <string>

using namespace std;

int revRes[11][110 + 2];
int carry[110 + 2];

int main() {
    int N;
    cin >> N;
    string ss[N + 1];
    char *cs[N + 1];
    int lens[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> ss[i];
        auto len = ss[i].size();
        lens[i] = len;
        cs[i] = new char[len + 1];
        for (decltype(len) j = 1; j <= len; ++j) {
            cs[i][j] = ss[i].at(len - j);
        }
    }
    
    for (int i = 1; i <= lens[1]; ++i) {
        revRes[1][i] = cs[1][i] - '0';
    }
    int tempResLen[N];
    tempResLen[1] = lens[1];

    for (int i = 1; i < N; ++i) {
        int j;
        int k = 1;

        for (j = 1; j <= tempResLen[i]; ++j) {
            for (k = 1; k <= lens[i + 1]; ++k) {
                revRes[i+1][j + k - 1] += (revRes[i][j]) * (cs[i + 1][k] - '0') + carry[j + k - 2];
                carry[j + k - 2] = 0;
                carry[j + k - 1] = revRes[i+1][j + k - 1] / 10;
                revRes[i+1][j + k - 1] = revRes[i+1][j + k - 1] % 10;
            }
            revRes[i+1][j + k - 1] += carry[j + k - 2];
            carry[j + k - 2] = 0;
            revRes[i+1][j + k] += revRes[i+1][j + k - 1] / 10;
            revRes[i+1][j + k - 1] = revRes[i+1][j + k - 1] % 10;
            if(revRes[i+1][j + k - 1]!=0){
                tempResLen[i + 1] = j + k - 1;
            } else{
                tempResLen[i + 1] = j + k - 2;
            }
        }
        revRes[i+1][j + k - 1] += carry[j + k - 2];
        carry[j + k - 2] = 0;
        revRes[i+1][j + k] += revRes[i+1][j + k - 1] / 10;
        revRes[i+1][j + k - 1] = revRes[i+1][j + k - 1] % 10;
    }

    for (int i = tempResLen[N]; i >= 1; --i) {
        cout << revRes[N][i];
    }
}