/*
��1,2,...,9��9�����ֳ�����,�ֱ����������λ��,
��ʹ��������λ������1:2:3�ı��������磺������λ��192��384��576��
*/
#include <iostream>

using namespace std;
/*
����set�ṹ
    for (int i = 123; i < 345; ++i) {
        set<int> st;
        for (int j = 1; j <= 3; ++j) {
            int k = i*j;
            while(k){
                st.insert(k%10);
                k /= 10;
            }
        }
        if(st.size()==9&&st.find(0)==st.end()){
            cout<<i<<" "<<i*2<<" "<<i*3<<endl;
        } else{
            continue;
        }

    }
*/
int main() {
    bool used[10]= {false};
    for (int i = 1; i < 4; ++i) {
        used[0] = true;
        used[i] = true;
        for (int j = 1; j < 10; ++j) {
            if (j == i) {
                continue;
            }
            used[j] = true;
            for (int k = 1; k < 10; ++k) {
                if (k == i || k == j) {
                    continue;
                }
                used[k] = true;
//                check dif
                int first = 100 * i + 10 * j + k;
                int second = 2 * first;
                int third = 3 * first;
                if (third < 1000) {
                    used[second / 100] = !used[second / 100];
                    used[(second % 100) / 10] = !used[(second % 100) / 10];
                    used[second % 100 % 10] = !used[second % 100 % 10];
                    used[third / 100] = !used[third / 100];
                    used[(third % 100) / 10] = !used[(third % 100) / 10];
                    used[third % 100 % 10] = !used[third % 100 % 10];
                    bool condition = true;
                    for (int m = 1; m <= 9; ++m) {
                        if (!used[m]) {
                            condition = false;
                            break;
                        }
                    }
                    if (condition) {
                        cout << first << " " << second << " " << third << endl;
                    }
                    used[second / 100] = !used[second / 100];
                    used[(second % 100) / 10] = !used[(second % 100) / 10];
                    used[second % 100 % 10] = !used[second % 100 % 10];
                    used[third / 100] = !used[third / 100];
                    used[(third % 100) / 10] = !used[(third % 100) / 10];
                    used[third % 100 % 10] = !used[third % 100 % 10];
                }
                used[k] = false;
            }
            used[j] = false;
        }
        used[i] = false;
    }
}