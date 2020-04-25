#include <iostream>
#include <string>

using namespace std;

int val[401];
int idx = 1;
int totalNode;
int i1;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int i) : val(i), left(NULL), right(NULL) {};
};

class Tree {
    Node *root;

    void create(Node *&subTree);

    void print(Node *&subTree);

    bool isSym(Node *&lhs, Node *&rhs);

public:
    Tree() : root(NULL) {};

//    Tree(int v) : root(&Node(v)){};
    void create() { create(root); };

    void print() { print(root); };

    bool isSym(Tree &rhs) { return isSym(root, rhs.root); };
};


void Tree::create(Node *&subTree) {
    int cur = val[i1++];
    if (cur != -1) {
        subTree = new Node(cur);
        create(subTree->left);
        create(subTree->right);
    } else {
        subTree = NULL;
    }
}

//前序遍历
void Tree::print(Node *&root) {
    cout << root->val << " ";
    if (root->left != NULL) {
        print(root->left);
    }
    if (root->right != NULL) {
        print(root->right);
    }
}

bool Tree::isSym(Node *&lhs, Node *&rhs) {
    if (lhs == NULL && rhs == NULL) {
        return true;
    }
    return (lhs != NULL && rhs != NULL)
           && (lhs->val == rhs->val)
           && (isSym(lhs->left, rhs->right))
           && (isSym(lhs->right, rhs->left));

};

int main() {
    int temp;
    while (cin >> temp) {
        val[idx++] = temp;
    }
    totalNode = idx - 1;
    //建树
    i1 = 1;
    Tree tree1 = Tree();
    tree1.create();
//    tree1.print();
    if (2 * (i1-1) != totalNode) {
        cout << "NO" << endl;
        return 0;
    }
    Tree tree2 = Tree();
    tree2.create();
//    tree2.print();

    bool isSym = tree1.isSym(tree2);

    if (isSym) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}