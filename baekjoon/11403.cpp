// 11403
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX_N = 100;
vector<int> adj[MAX_N];

int N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
		{
			int x; cin >> x;
			if(x == 1) adj[i].push_back(j);
		}
	
	
	for(int i = 0; i < N; i++)
	{
		vector<int> visited(N, 0);
		
		queue<int> q;
		for(int e : adj[i]) q.push(e);
		
		while(!q.empty())
		{
			int curr = q.front();
			q.pop();
			
			if(visited[curr]) continue;
			else
			{
				visited[curr] = 1;
				for(int e : adj[curr]) q.push(e);
			}
		}
		
		for(int e : visited)
			cout << e << ' ';
		cout << '\n';
	}
}
