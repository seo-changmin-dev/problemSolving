#include <iostream>
#include <vector>
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
        int V, W;
        cin >> V >> W;

        vector<pair<int,int> > adj[MAX_V];
        for(int i = 0; i < W; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;

            adj[u].push_back(make_pair(v,c));
        }

        // shortest BellmanFord
        vector<int> upper(V, INF);
        upper[0] = 0;

        bool updated = false;
        for(int iter = 0; iter < V-1; iter++)
        {
            updated = false;
            for(int here = 0; here < V; here++)
                for(int i = 0; i < adj[here].size(); i++)
                {
                    int there = adj[here][i].first;
                    int cost = adj[here][i].second;

                    if(upper[there] > upper[here] + cost)
                    {
                        upper[there] = upper[here] + cost;
                        updated = true;
                    }
                }
            
            if(!updated) break;
        }

        int temp = upper[1];
        for(int here = 0; here < V; here++)
            for(int i = 0; i < adj[here].size(); i++)
            {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                if(upper[there] > upper[here] + cost)
                {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }

        if(upper[1] != temp) upper.clear();

        // longest BellmanFord
        vector<int> lower(V, -INF);
        lower[0] = 0;

        updated = false;
        for(int iter = 0; iter < V-1; iter++)
        {
            updated = false;
            for(int here = 0; here < V; here++)
                for(int i = 0; i < adj[here].size(); i++)
                {
                    int there = adj[here][i].first;
                    int cost = adj[here][i].second;

                    if(lower[there] < lower[here] + cost)
                    {
                        lower[there] = lower[here] + cost;
                        updated = true;
                    }
                }
            
            if(!updated) break;
        }

        temp = lower[1];
        for(int here = 0; here < V; here++)
            for(int i = 0; i < adj[here].size(); i++)
            {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                if(lower[there] < lower[here] + cost)
                {
                    lower[there] = lower[here] + cost;
                    updated = true;
                }
            }
        if(lower[1] != temp) lower.clear();

        bool isUnreachable = false;
        const int M = V * 1000; // # of node * maxCost 
        if(upper.empty()) cout << "INFINITY ";
        else if(upper[1] >= INF - M) isUnreachable = true;
        else cout << upper[1] << ' ';

        if(lower.empty()) cout << "INFINITY\n";
        else if(isUnreachable) cout << "UNREACHABLE\n";
        else cout << lower[1] << "\n"; 
    }

    return 0;
}