#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<string> strStack;

void unfold() {
    string cur;
    string temp = strStack.top();
    while (temp != "[") {
        cur = temp + cur;
        strStack.pop();
        temp = strStack.top();
    }
    strStack.pop();
    int cnt = 1;

    if (!strStack.empty() && strStack.top().at(0) >= '0' && strStack.top().at(0) <= '9'){
        cnt = stoi(strStack.top());
        strStack.pop();
    }

    string tempRes;
    while (cnt != 0) {
        tempRes += cur;
        --cnt;
    }
    strStack.push(tempRes);
}

int main() {
    string src;
    cin >> src;
    int sz = src.size();
    int i = 0;
    string space;
    for (int i = 0; i < sz; ++i) {
        char c = src[i];
        if (c == ']') {
            unfold();
        } else if (c >= '0' && c <= '9') {
            int temp = c - '0';
            ++i;
            c = src[i];
            while (c >= '0' && c <= '9') {
                temp = temp * 10 + (c - '0');
                ++i;
                c = src[i];
            }
            --i;
            strStack.push(to_string(temp));
        } else {
            strStack.push(space + c);
        }
    }
    string ans;
    while (!strStack.empty()) {
        ans = strStack.top() + ans;
        strStack.pop();
    }
    cout << ans << endl;

}