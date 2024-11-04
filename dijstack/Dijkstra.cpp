/*
 * @Author: 1454164915@qq.com 1454164915@qq.com
 * @Date: 2024-11-04 15:51:12
 * @LastEditors: 1454164915@qq.com 1454164915@qq.com
 * @LastEditTime: 2024-11-04 18:09:03
 * @FilePath: /learn/C++/dijstack/Dijkstra.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <queue>

using namespace std;


int n, m ,s ; //点数,边数,起点
namespace dij{//O(n2)
    const int maxn = 1001;
    int vis[maxn], d[maxn], w[maxn][maxn];
    void dij(){
        memset(vis, 0, sizeof(vis));
        memset(d, 0x3f, sizeof(d));
        d[s] = 0;
        for(int i = 1; i <= n; ++i){
            int x = -1;
            for(int y =-1; y <= n; ++y){
                if(!vis[y])if(x==-1||d[y] < d[x]) x=y;
            }
            vis[x] = true;
            for(int y =1; y <= n; ++y){
                d[y] = min(d[y], d[x]+ w[x][y]);
            }

        }
    }
}

namespace fast_dij{
    const int maxn = 2100;
    vector<pair<int, int>> G[maxn];

    int d[maxn];
    void fast_dij(){
        using node  = pair<int, int>;
        priority_queue<node, vector<node>, greater<node>> Q;
        memset(d, 0x3f, sizeof(d));


        d[s] = 0;//s start point node
        Q.emplace(0,s);
        while(!Q.empty()){
            auto [dist, x] = Q.top();Q.pop();
            if(dist!= d[x])continue;
            for(auto[y,w] : G[x]){

                if(d[y] > d[x] + w){
                    d[y] = d[x] + w;
                    Q.emplace(d[y], y);
                }
            }

        }

    }

    void solve() {
        scanf("%d %d %d", &n, &m, &s);
        for (int i = 0; i < m; ++i) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            G[x].emplace_back(y, z);
        }
        fast_dij();
        for (int i = 1; i <= n; ++i)
        printf("%d ", d[i] == 0x3f3f3f3f ? INT_MAX : d[i]);
        printf("\n");
    }
}



int main() {
    //freopen("in.txt", "r", stdin);
    fast_dij::solve();
    return 0;
}




// int main(){
//     return 0;
// }