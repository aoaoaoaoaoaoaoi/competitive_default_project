#include <bits/stdc++.h>
#define INF 1000000007 //1000000000000000003
#define MOD 1000000007
#define MAX 2000005
#define PI 3.141592653589793
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int, int>;

const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,-1,0,1 };

int main()
{
    int H, W; cin >> H >> W;
    int CH, CW; cin >> CH >> CW; --CH; --CW;
    int DH, DW; cin >> DH >> DW; --DH; --DW;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    deque<P> que;
    que.emplace_back(make_pair(CH, CW));//スタート
    vector<vector<int>> cost(H, vector<int>(W, INF));
    cost[CH][CW] = 0;

    while(!que.empty()){
        P target = que.front(); que.pop_front();
        int targetCost = cost[target.first][target.second];
        
        //徒歩
        rep(i, 4){
            int nextY = target.first + dy[i];
            int nextX = target.second + dx[i];
            if(nextY < 0 || H <= nextY || nextX < 0 || W <= nextX) continue; //表示内か
            if(S[nextY][nextX] == '#') continue; //道か
            if(cost[nextY][nextX] <= targetCost) continue; //他のルートの方が少ないコストか
            cost[nextY][nextX] = targetCost;
            que.emplace_front(make_pair(nextY, nextX));
        }

        //魔法
        for(int i = -2; i <= 2; ++i){
            for(int j = -2; j <= 2; ++j){
                int nextY = target.first + i;
                int nextX = target.second + j;
                if(nextY < 0 || H <= nextY || nextX < 0 || W <= nextX) continue; //表示内か
                if(S[nextY][nextX] == '#') continue; //道か
                if(cost[nextY][nextX] <= targetCost + 1) continue; //他のルートの方が少ないコストか
                cost[nextY][nextX] = targetCost + 1;
                que.emplace_back(make_pair(nextY, nextX));
            }
        }
    }

    int ans = cost[DH][DW] == INF ? -1 : cost[DH][DW];
    cout << ans << endl;
    return 0;
}