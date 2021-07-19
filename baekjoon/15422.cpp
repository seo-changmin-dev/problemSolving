// 15422
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;

const ll INF = 1e10;
const ll MAX_V = 50000;
vector<pair<ll,ll> > adj[MAX_V];

ll dijkstra(int V, int src, int dest);

int n,m,f,s,t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> f >> s >> t;
    for(int i = 0; i < m; i++)
    {
        int u,v,c;
        cin >> u >> v >> c;

        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    vector<int> flight[MAX_V];
    for(int i = 0; i < f; i++)
    {
        int u,v;
        cin >> u >> v;
        flight[u].push_back(v);
    }

    ll ret = INF;
    for(int here = 0; here < n; here++)
        for(int i = 0; i < flight[here].size(); i++)
        {
            int there = flight[here][i];
            adj[here].push_back({there, 0});
            ret = min(ret, dijkstra(n,s,t));
            adj[here].pop_back();
        }

    ret = min(ret, dijkstra(n,s,t));
    cout << ret << '\n';
    return 0;
}

ll dijkstra(int V, int src, int dest)
{
    vector<ll> dist(V, INF);
    dist[src] = 0;

    priority_queue<pair<ll,int> > pq;
    pq.push({0, src});

    while(!pq.empty())
    {
        ll cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].first;
            ll nextDist = cost + adj[here][i].second;

            if(dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }

    return dist[dest];
}