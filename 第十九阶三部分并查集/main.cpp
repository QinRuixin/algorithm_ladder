#include <iostream>
#include <cstring>

using namespace std;

int ufSet[150005];

int find(int i) {
    int tempI = i;
    while (ufSet[tempI] != -1) {
        tempI = ufSet[tempI];
    }
    //tempI为根节点；
    while (i != tempI) {
        int tmp = ufSet[i];
        ufSet[i] = tempI;
        i = tmp;
    }
    return tempI;
}

bool check(int i1, int i2) {
    int p1 = find(i1);
    int p2 = find(i2);
    return p1 == p2;
}

void unionTwo(int i1, int i2) {
    int p1 = find(i1);
    int p2 = find(i2);
    if (p1 != p2)
        ufSet[p2] = p1;
}

int main() {
    memset(ufSet, 0xff, sizeof(int) * 150004);
    int N, M;
    cin >> N >> M;
    int res = 0;
    int kind, n1, n2;
    for (int i = 0; i < M; ++i) {
        cin >> kind >> n1 >> n2; // n1 和 n2 应该为1到N的值
        if (n1 > N || n2 > N) {
            ++res;
            continue;
        }
        // 表示方式： x为x+N的克星，x+N为x+2*N的克星，x+2*N为x的克星
        // 设 2 x y 则x 为y的克星，又x 为x+N的克星，则 y与x+N为同类；
        // 又y为y+N的克星，x+N为x+2*N的克星，则y+N与x+2*N为同类；
        // 又y+N为y+2*N的克星，x+2*N为x的克星，则y+2*N与x为同类；

        switch (kind) {
            case 1:
                if (check(n1 + N, n2) || check(n1 + 2 * N, n2)) {
                    ++res;
                } else {
                    unionTwo(n1, n2);
                    unionTwo(n1 + N, n2 + N);
                    unionTwo(n1 + 2 * N, n2 + 2 * N);
                }
                break;
            case 2:
                if (check(n1, n2) || check(n1 + 2 * N, n2)) {
                    ++res;
                } else {
                    unionTwo(n2, n1 + N);
                    unionTwo(n2 + N, n1 + 2 * N);
                    unionTwo(n2 + 2 * N, n1);
                }
                break;
            default:
                break;
        }

    }
    cout << res;

    return 0;

}
