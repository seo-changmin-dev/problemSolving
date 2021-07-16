// 11657
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 500;

int N,M;
vector<pair<int,int>> adj[MAX_N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int A,B,C;
        cin >> A >> B >> C;

        adj[A-1].push_back(make_pair(B-1, C));
    }

    vector<ll> upper(N, INF);
    upper[0] = 0;
    bool updated = false;
    for(int iter = 0; iter < N; iter++)
    {
        updated = false;
        for(int here = 0; here < N; here++)
            for(int i = 0; i < adj[here].size(); i++)
            {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                if(upper[here] != INF && upper[there] > upper[here] + cost)
                {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }

            }
    }

    if(updated) upper.clear();

    if(upper.empty()) puts("-1");
    else
    {
        for(int i = 1; i < N; i++)
        {
            if(upper[i] == INF) cout << -1 << '\n';
            else cout << upper[i] << '\n';
        }
    }
}