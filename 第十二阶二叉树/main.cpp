#include <iostream>
#include <queue>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int val;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

Node *nodes[31];
bool edge[31];
queue<int> cur;
queue<int> nex;

void dealQue(Node *root, queue<int> &q) {
    if (root->left) {
        int v = root->left->val;
        if (q.empty()) {
            edge[v] = true;
        }
        q.push(v);
    }
    if (root->right) {
        int v = root->right->val;
        if (q.empty()) {
            edge[v] = true;
        }
        q.push(v);
    }
}

void bfs(Node *root) {

    dealQue(root, cur);
    while (!cur.empty() || !nex.empty()) {
        int last = 0;
        while (!cur.empty()) {
            Node *temp = nodes[cur.front()];
            dealQue(temp, nex);
            last = cur.front();
            cur.pop();
        }
        edge[last] = true;
        while (!nex.empty()) {
            Node *temp = nodes[nex.front()];
            dealQue(temp, cur);
            last = nex.front();
            nex.pop();
        }
        edge[last] = true;
    }


}

int main() {
    int n;
    cin >> n;
    Node root(1);
    Node *temp;
    int l;
    int r;
    nodes[1] = &root;
    edge[1] = true;
    int idx = 2;
    //i= 1; left = 2*i; right = 2*i+1;
    for (int i = 1; i <= n; ++i) {
        cin >> l;
        if (l != -1) {
            temp = new Node(l);
            nodes[i]->left = temp;
            if (l == idx) {
                nodes[idx] = temp;
                ++idx;
            }
        }
        cin >> r;
        if (r != -1) {
            temp = new Node(r);
            nodes[i]->right = temp;
            if (r == idx) {
                nodes[idx] = temp;
                ++idx;
            }
        }

    }
    bfs(&root);
    cout << "1";
    for (int j = 2; j <= n; ++j) {
        if (edge[j]) {
            cout << " " << j;
        }
    }
//    cout << " ";
}
