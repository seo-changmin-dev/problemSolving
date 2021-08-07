// 14503
#include<iostream>
using namespace std;

const int MAX_N = 50;
const int MAX_M = 50;

int board[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int N,M;
int r,c,dir;
int cnt = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	cin >> r >> c >> dir;
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> board[i][j];
	
	while(true)
	{
		if(!visited[r][c])
		{
			visited[r][c] = true;
			cnt++;
		}
		
		bool move = false;
		for(int i = 0; i < 4; i++)
		{
			dir = (dir+3)%4;
			if(board[r+dy[dir]][c+dx[dir]] == 1) continue;
			if(visited[r+dy[dir]][c+dx[dir]]) continue;

			r += dy[dir];
			c += dx[dir];
			move = true;
			break;
		}
		
		if(!move)
		{
			int candDir = (dir+2)%4;
			if(board[r+dy[candDir]][c+dx[candDir]] == 1)
			{
				cout << cnt << endl;
				return 0;
			}
			else
			{
				r += dy[candDir];
				c += dx[candDir];
			}
		}
	}
}
