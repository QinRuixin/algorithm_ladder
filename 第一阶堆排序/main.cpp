#include <iostream>
 
void creHeap(int *nums, int n);
 
void goDown(int *nums, int n, int i);
 
using namespace std;
 
int main() {
    int n = 0;
    cin >> n;
//  1到n是数据
    int nums[100001]{};
    for (int i = 0; i < n; i++) {
        cin >> nums[i + 1];
    }
    creHeap(nums, n);
    int temp;
    for (int i = n; i > 1; --i) {
        temp = nums[i];
        nums[i] = nums[1];
        nums[1] = temp;
        goDown(nums, i - 1, 1);
    }
    for (int i = 1; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << nums[n] << endl;
}
 
//1到n是数据
void creHeap(int num[], int n) {
    for (int i = n / 2; i > 0; --i) {
        goDown(num, n, i);
    }
}
 
void goDown(int nums[], int n, int i) {
//    cout << "before:" << nums[1] << nums[2] << nums[3] << nums[4] << nums[5] << endl;
    if (n <= 1) {
        return;
    }
    int ls = 2 * i;
    int rs = 2*i+1;
    int idx;
    int hole = i;
    int cur = *(nums + hole);
    while (ls <= n) {
 
        if (rs > n || *(nums + ls) > *(nums + rs)) {
            idx = ls;
        } else {
            idx = rs;
        }
        if (*(nums + idx) > cur) {
            *(nums + hole) = *(nums + idx);
            hole = idx;
        } else {
            break;
        }
        ls = 2 * hole;
        rs = 2 * hole + 1;
    }
    *(nums + hole) = cur;
//    cout << "after:" << nums[1] << nums[2] << nums[3] << nums[4] << nums[5] << endl;
}