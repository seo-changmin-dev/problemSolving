// 17144
#include<iostream>
#include<vector>
using namespace std;

const int MAX_N = 50;

void diffusion();
void circulate();
int dustLeft();
void printBoard();

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

vector<int> botPos;
int board[MAX_N][MAX_N];

int R,C,T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> R >> C >> T;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == -1) botPos.push_back(i);
		}

	while(T--)
	{
		diffusion();
		circulate();
	}
	cout << dustLeft() << endl;
	return 0;
}

void diffusion()
{
	vector<vector<int> > tempBoard(MAX_N, vector<int>(MAX_N, 0));
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			if(board[i][j] == -1) continue;
			else
			{
				for(int k = 0; k < 4; k++)
				{
					int nextY = i + dy[k];
					int nextX = j + dx[k];
					
					if(nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue;
					if(board[nextY][nextX] == -1) continue;
					
					tempBoard[i][j] -= board[i][j]/5;
					tempBoard[nextY][nextX] += board[i][j]/5;
				}
			}
	
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			board[i][j] += tempBoard[i][j];
	
	return;
}

void circulate()
{
	//topPart
	
	for(int i = botPos[0]; i > 0; i--)
		swap(board[i][0], board[i-1][0]);

	for(int j = 0; j < C-1; j++)
		swap(board[0][j], board[0][j+1]);
	
	for(int i = 0; i < botPos[0]; i++)
		swap(board[i][C-1], board[i+1][C-1]);

	for(int j = C-1; j > 0; j--)
		swap(board[botPos[0]][j], board[botPos[0]][j-1]);
	
	board[botPos[0]][0] = -1;
	board[botPos[0]][1] = 0;
	
	//bottomPart
	
	for(int i = botPos[1]; i < R-1; i++)
		swap(board[i][0], board[i+1][0]);
	
	for(int j = 0; j < C-1; j++)
		swap(board[R-1][j], board[R-1][j+1]);
	
	for(int i = R-1; i > botPos[1]; i--)
		swap(board[i][C-1], board[i-1][C-1]);
	
	for(int j = C-1; j > 0; j--)
		swap(board[botPos[1]][j], board[botPos[1]][j-1]);
	
	board[botPos[1]][0] = -1;
	board[botPos[1]][1] = 0;
}

int dustLeft()
{
	int ret = 0;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			if(board[i][j] != -1) ret += board[i][j];
	
	return ret;
}

void printBoard()
{
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}