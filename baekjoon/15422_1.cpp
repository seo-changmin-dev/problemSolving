// 15422
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;

const ll INF = 1e10;
const int MAX_N = 50000;
const int MAX_M = 150000;
const int MAX_F = 1000;

vector<pair<int,int> > adj[MAX_N];
vector<int> flights[MAX_F];
vector<vector<ll> > dist(MAX_N, vector<ll>(2, INF));

int n,m,f,s,t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> f >> s >> t;
    for(int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    for(int i = 0; i < f; i++)
    {
        int u, v;
        cin >> u >> v;
        flights[u].push_back(v);
    }

    priority_queue<pair<ll,pair<int,int> > > pq;
    dist[s][0] = 0;
    dist[s][1] = 0;
    pq.push({0, {s, 0}});

    while(!pq.empty())
    {
        ll cost = -pq.top().first;
        int curr = pq.top().second.first;
        int useFly = pq.top().second.second;
        pq.pop();

        if(dist[curr][useFly] < cost) continue;

        //도로
        for(int i = 0; i < adj[curr].size(); i++)
        {
            int next = adj[curr][i].first;
            ll nextDist = cost + adj[curr][i].second;

            if(dist[next][useFly] > nextDist)
            {
                dist[next][useFly] = nextDist;
                dist[next][1] = min(dist[next][1], nextDist);
                pq.push({-nextDist, {next, useFly}});
            }
        }

        //비행기
        if(useFly == 0)
        {
            for(int i = 0; i < flights[curr].size(); i++)
            {
                int next = flights[curr][i];
                if(dist[next][1] > cost)
                {
                    dist[next][1] = cost;
                    pq.push({-cost, {next, 1}});
                }
            }
        }
    }

    cout << min(dist[t][0], dist[t][1]) << '\n';
    return 0;
}