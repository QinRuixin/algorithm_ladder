#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct pr {
    int x;
    int y;
    int power;
};
pr p[100001];
int ufSet[20001];
int other[20001];

int find(int i){
    int tempI = i;
    while (ufSet[tempI]!=-1){
        tempI = ufSet[tempI];
    }
    //tempI 为根节点
    while (i!=tempI){
        int nextI = ufSet[i];
        ufSet[i] = tempI;
        i = nextI;
    }
    return tempI;
}

bool check(int x,int y){
    int a = find(x);
    int b = find(y);
    return a==b;

}

void unionTwo(int x,int y){
    int a = find(x);
    int b = find(y);
    ufSet[b] = a;
}

int main() {
    int N, M;//人数 和对数
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].power;
    }
    sort(p,p+M,
            [](pr p1,pr p2){
        return p1.power > p2.power;
    });
    //初始化并查集为-1
    memset(ufSet,-1, sizeof(int)*20001);
    for (int i = 0; i < M; ++i) {
        if(find(p[i].x)==find(p[i].y)){
            cout << p[i].power ;
            return 0;
        } else{
            if(!other[p[i].x]){
                other[p[i].x] = p[i].y;
            } else if(!check(p[i].y,other[p[i].x])){
                unionTwo(p[i].y,other[p[i].x]);
            }
            if(!other[p[i].y]){
                other[p[i].y] = p[i].x;
            } else if(!check(p[i].x,other[p[i].y])){
                unionTwo(p[i].x,other[p[i].y]);
            }
        }
    }

    cout << 0 ;
    return 0;
}
/*
5 8
4 5 8730
2 4 5777
2 5 6235
2 3 6164
1 2 4462
1 3 1292
3 5 4380
3 4 7220


4 4
1 2 700
3 4 600
1 3 500
1 4 400
 */