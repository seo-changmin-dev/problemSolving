// 2206
#include<iostream>
#include<queue>
using namespace std;

const int INF = 987654321;
const int MAX_N = 1000;
const int MAX_M = 1000;

int dy[] = {1,-1,0,0};
int dx[] = {0,0,-1,1};

string board[MAX_N];
int visited[MAX_N][MAX_M][2];

int N,M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // init
    for(int i = 0; i < MAX_N; i++)
        for(int j = 0; j < MAX_M; j++)
            visited[i][j][0] = visited[i][j][1] = INF;
    
    visited[0][0][0] = 1;

    // input
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> board[i];
    
    queue<pair<pair<int,int>, int> > Q;
    Q.push({{0,0},0});
    
    while(!Q.empty())
    {
        pair<pair<int,int>, int> now = Q.front();
        int &nowY = now.first.first;
        int &nowX = now.first.second;
        Q.pop();

        for(int k = 0; k < 4; k++)
        {
            pair<pair<int,int>, int> next = now;
            int &nextY = next.first.first;
            int &nextX = next.first.second;
            nextY += dy[k]; nextX += dx[k];

            // outOfBound
            if(nextY < 0 || N <= nextY || nextX < 0 || M <= nextX) continue;
            
            // no Wall
            if(board[nextY][nextX] == '0')
            {
                if(visited[nextY][nextX][next.second] <= visited[nowY][nowX][now.second] + 1) continue;
                else
                {
                    visited[nextY][nextX][next.second] = visited[nowY][nowX][now.second] + 1;
                    Q.push({{nextY,nextX},next.second});
                }
            }
            else // wall
            {
                if(now.second == 1) continue;
                if(visited[nextY][nextX][1] <= visited[nowY][nowX][now.second] + 1) continue;
                else
                {
                    visited[nextY][nextX][1] = visited[nowY][nowX][now.second] + 1;
                    Q.push({{nextY,nextX},1});
                }

            }
        }
    }

    int ans = min(visited[N-1][M-1][0], visited[N-1][M-1][1]);
    if(ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}