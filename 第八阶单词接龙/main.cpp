#include <iostream>
#include <string>

using namespace std;

string str[20];
int count[20];
int ans;
int n;

inline int isMatch(const string &a,const string &b){
    int len1= a.size();
    int len2 = b.size();
    int minLen = min(len1,len2);
    int res=minLen;
    for (int i=0; i < minLen; ++i) {
//        cout << a.substr(len1-i-1) << endl;
//        cout << b.substr(0,i+1) << endl;
        if((a.substr(len1-i-1)==b.substr(0,i+1)) && (i+1<res)){
            res = i+1;
        }
    }
    if(res==minLen){
        res = 0;
    }
    return res;
}

void dfs(int strIdx,int sum){
    if(sum>ans)
        ans=sum;
    string curStr = str[strIdx];

    for (int i = 0; i < n; ++i) {
        if(count[i]>=2){
            continue;
        }
        int len = isMatch(curStr,str[i]);
        if(len){
            ++count[i];
            dfs(i,sum+static_cast<int>(str[i].size())-len);
            --count[i];
        }
    }

}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    char c;
    cin >> c;
    for (int i = 0; i < n; ++i) {
        if(str[i][0]==c){
            ++count[i];
            dfs(i, static_cast<int>(str[i].size()));
            --count[i];
        }
    }
    cout << ans;
}