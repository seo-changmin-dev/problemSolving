// NTHLON
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc; cin >> tc;
	while(tc--)
	{
		int m; cin >> m;
		vector<pair<int,int> > record(m);
		for(int i = 0; i < m; i++)
			cin >> record[i].first >> record[i].second;
		
		vector<int> dist(400, INF);
		priority_queue<pair<int,int> > pq;
		
		for(int i = 0; i < m; i++)
		{
			int u = record[i].first;
			int v = record[i].second;
			
			pq.push(make_pair(-u, 200+(v-u)));
		}
		
		while(!pq.empty())
		{
			int cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			
			if(dist[here] < cost) continue;
			
			for(int i = 0; i < m; i++)
			{
				int u = record[i].first;
				int v = record[i].second;
				
				int there = here + (v-u);
				int nextDist = cost + u;
				
				if(there < 0 || there >= 400) continue;
				
				if(dist[there] > nextDist)
				{
					dist[there] = nextDist;
					pq.push(make_pair(-nextDist, there));
				}
			}
		}
		
		if(dist[200] == INF) cout << "IMPOSSIBLE\n";
		else cout << dist[200] << '\n';
	}
	
	return 0;
}
