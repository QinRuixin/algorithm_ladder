#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool chose[51];
vector<int> res;
vector<int> ans;
int endPvt;


bool isAns(){
    int sz = res.size();

    for (int i = 1; i <= sz; ++i) {
        if(!chose[i]){
            return false;
        }
    }
    return true;

}

//左开右闭区间, 第几个数字
void dfs(const string &str, int begin) {
    if (begin == endPvt) {
        if(isAns()){
            ans = res;
        }
        return;
    }
    for (int i = 1; i <= 2; ++i) {
        if (begin + i > endPvt) {
            break;
        }
        string temp = str.substr(begin, i);
        int candidate = stoi(temp);
        if (candidate <= 50 && !chose[candidate]) {
            res.push_back(candidate);
            chose[candidate] = true;
            dfs(str, begin + i);
            res.pop_back();
            chose[candidate] = false;
        }

    }

}

int main() {
    string str;
    cin >> str;
    endPvt = str.size();
    dfs(str, 0);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}
