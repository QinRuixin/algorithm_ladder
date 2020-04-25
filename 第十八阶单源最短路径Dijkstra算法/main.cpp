#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool visited[2][1001];
//int adj[2][101][101];
int n, m;

int main() {
    cin >> n >> m;

    vector<vector<int>> adj0(n + 1,  vector<int>(n + 1,INT_MAX)  );
    vector<vector<int>> adj1(n + 1,  vector<int>(n + 1,INT_MAX)  );
    vector<vector<vector<int>>> adj;
    adj.push_back(adj0);
    adj.push_back(adj1);

    vector<vector<int>> dis(2, vector<int>(n + 1, INT_MAX));

    int s, e, l, c;
    for (int i = 0; i < m; ++i) {
        cin >> s >> e >> l >> c;
        adj[c-1][s][e] = l;
        if (s == 0) {
            dis[c-1][e] = l;
        }
    }

    visited[0][0] = true;
    visited[1][0] = true;
    dis[0][0] = 0;
    dis[1][0] = 0;
    for (int oriC = 0; oriC < 2; ++oriC) {
        int c = oriC;
        for (int i = 1; i < n; ++i) {
            int minLen = INT_MAX;
            int minIdx = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[c][j] && dis[c][j] < minLen) {
                    minLen = dis[c][j];
                    minIdx = j;
                }
            }
            if (minIdx == -1) {
                break;
            }
            visited[c][minIdx] = true;
            c = 1 - c;// 换司机
            //更新邻接顶点最小距离
            for (int j = 0; j < n; ++j) {
                if (!visited[c][j] && adj[c][minIdx][j] != INT_MAX
                    && dis[1-c][minIdx] + adj[c][minIdx][j] < dis[c][j]) {
                    dis[c][j] = dis[1-c][minIdx] + adj[c][minIdx][j];
                }
            }
        }
    }

    int minDis[1001];

    for (int i = 0; i < n; ++i) {
        int tempMin = min(dis[0][i], dis[1][i]);
        minDis[i] = ((tempMin == INT_MAX) ? -1 : tempMin);
    }

    for (int i = 0; i < n; ++i) {
        cout << minDis[i] << " ";
    }
}


/*
6 6
0 1 1 1
0 3 2 2
1 2 2 2
3 2 1 1
2 4 3 1
4 5 1 2
 */