//timeTrip
#include<iostream>
#include<vector>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
    {
        int V,W;
        cin >> V >> W;

        vector<pair<int,int> > adj[MAX_V];
        for(int i = 0; i < W; i++)
        {
            int u,v,c;
            cin >> u >> v >> c;

            adj[u].push_back(make_pair(v,c));
        }

        //bellmanFord - shortest path
        vector<int> dist1(V, INF);
        dist1[0] = 0;

        bool isUpdated = false;
        for(int iter = 0; iter <= V; iter++)
        {
            isUpdated = false;

            for(int here = 0; here < V; here++)
                for(int i = 0; i < adj[here].size(); i++)
                {
                    if(dist1[here] == INF) continue;

                    int there = adj[here][i].first;
                    int nextDist = dist1[here] + adj[here][i].second;

                    if(dist1[there] > nextDist)
                    {
                        isUpdated = true;
                        dist1[there] = nextDist;
                    }
                }

            if(!isUpdated) break;
            if(iter == V && isUpdated) dist1.clear();
        }

        //bellmanFord - longest path
        vector<int> dist2(V, -INF);
        dist2[0] = 0;

        isUpdated = false;
        for(int iter = 0; iter <= V; iter++)
        {
            isUpdated = false;
            for(int here = 0; here < V; here++)
                for(int i = 0; i < adj[here].size(); i++)
                {
                    if(dist2[here] == -INF) continue;

                    int there = adj[here][i].first;
                    int nextDist = dist2[here] + adj[here][i].second;

                    if(dist2[there] < nextDist)
                    {
                        isUpdated = true;
                        dist2[there] = nextDist;
                    }
                }

            if(!isUpdated) break;
            if(iter == V && isUpdated) dist2.clear();
        }


        if(dist1[1] == INF || dist2[1] == -INF)
            cout << "UNREACHABLE\n";
        else
        {
            if(dist1.empty()) cout << "INFINITY";
            else cout << dist1[1];

            cout << ' ';

            if(dist2.empty()) cout << "INFINITY";
            else cout << dist2[1];

            cout << '\n';
        }
    }

    return 0;
}