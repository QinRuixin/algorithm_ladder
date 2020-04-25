#include <iostream>

using namespace std;

struct node {
    int lhs;
    int rhs;
};

node nodes[100001];

int dis = 0;

int getLongest(const node &n) {

    int lLen = 0;
    int rLen = 0;
    if (n.lhs != -1)
        lLen = getLongest(nodes[n.lhs]) + 1;
    if (n.rhs != -1)
        rLen = getLongest(nodes[n.rhs]) + 1;
    dis = max(dis, lLen + rLen);
    return max(lLen, rLen);

}

int main() {
    int n;
    cin >> n;
    int l, r;
    // 0 号是根节点
    cin >> l >> r;
    nodes[0].lhs = l;
    nodes[0].rhs = r;
    for (int i = 1; i < n; ++i) {
        cin >> l >> r;
        nodes[i].lhs = l;
        nodes[i].rhs = r;
    }
    getLongest(nodes[0]);
    cout << dis + 2 * (n - 1 - dis);
    return 0;
}
