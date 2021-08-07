// 1753
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int INF = 987654321;
const int MAX_V = 20000;
const int MAX_E = 300000;

int V,E;
int src;
vector<pair<int,int> > adj[MAX_V];

vector<int> dijkstra(int s);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;
    cin >> src;

    for(int i = 0; i < E; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;

        adj[u-1].push_back({v-1,w});
    }

    vector<int> ans = dijkstra(src-1);
    for(int i : ans)
        if(i != INF) cout << i << '\n';
        else cout << "INF" << '\n';
    
    return 0;
}

vector<int> dijkstra(int s)
{
    vector<int> dist(V, INF);
    dist[s] = 0;

    priority_queue<pair<int,int> > pq;
    pq.push({-0, s});

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if(dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }

    return dist;
}