//典型 双向环形链表 约瑟夫问题
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int element;
    ListNode *before;
    ListNode *next;

    ListNode() {}

    ListNode(int ele, ListNode *b = nullptr, ListNode *n = nullptr) : element(ele), before(b), next(n) {}

    ListNode *insertAsBef(int const &e);

    ListNode *removeThis();
};

ListNode *ListNode::insertAsBef(const int &e) {
    ListNode *b = new ListNode(e, this->before, this);
    b->next->before = b;
    b->before->next = b;
    return this;
}

ListNode *ListNode::removeThis() {
    ListNode *n = this->next;
    n->before = this->before;
    this->before->next = n;
    return n;
}

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    int gap1 = K - 1;
    int gap2 = M - 1;
    ListNode l = ListNode(1);
    l.next = &l;
    l.before = &l;
    ListNode *cur = &l;
    for (int i = 2; i <= N; ++i) {
        l.insertAsBef(i);
    }
    int g1 = 0;
    int g2 = 0;
    ListNode *p1 = cur;
    ListNode *p2 = cur->before;
    int remain = N;
    while (true) {
        while (g1 != gap1) {
            p1 = p1->next;
            ++g1;
        }
        while (g2 != gap2) {
            p2 = p2->before;
            ++g2;
        }
        if (p1->element == p2->element) {
            cout << p1->element << endl;
            break;
        }
        remain -=2;
        if(remain>0){
            cout << p1->element << ' ' << p2->element << ' ';
        } else{
            cout << p1->element << ' ' << p2->element << endl;
            break;
        }
        p1 = p1->removeThis();
        if(p1->element==p2->element){
            p1 = p1->next;
        }
        p2 = p2->removeThis()->before;
        g1 = 0;
        g2 = 0;
    }

}
