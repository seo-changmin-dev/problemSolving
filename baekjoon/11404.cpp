// 11404
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;

int n,m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int adj[MAX_V][MAX_V];
    for(int i = 0; i < MAX_V; i++)
        for(int j = 0; j < MAX_V; j++)
            adj[i][j] = INF;
    
    for(int i = 0; i < MAX_V; i++)
        adj[i][i] = 0;

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u,v,c;
        cin >> u >> v >> c;

        adj[u-1][v-1] = min(adj[u-1][v-1], c);
    }
    
    //floyd
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << (adj[i][j] == INF ? 0 : adj[i][j]) << ' ';
        cout << '\n';
    }
}