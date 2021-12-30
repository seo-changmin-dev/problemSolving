// // 1219
// #include<iostream>
// #include<vector>
// using namespace std;

// const int INF = 987654321;
// const int MAX_N = 100;
// int N,s,e,M;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> N >> s >> e >> M;

//     vector<pair<int,int> > adj[MAX_N];
//     for(int i = 0; i < M; i++)
//     {
//         int u,v,c;
//         cin >> u >> v >> c;

//         adj[u].push_back(make_pair(v,c));
//     }

//     vector<int> earning(N,0);
//     for(int i = 0; i < N; i++)
//         cin >> earning[i];

//     vector<int> upper(N, -INF);
//     upper[s] = 0;

//     bool updated = false;
//     for(int iter = 0; iter < N; iter++)
//     {
//         updated = false;
//         for(int here = 0; here < N; here++)
//             for(int i = 0; i < adj[here].size(); i++)
//             {
//                 int there = adj[here][i].first;
//                 int cost = adj[here][i].second;

//                 if(upper[here] != -INF && upper[there] > upper[here] + earning[there] - cost)
//                 {
//                     upper[there] = upper[here] + earning[there] - cost;
//                     updated = true;
//                 }
//             }

//         if(!updated) break;
//     }

//     if(updated)
// }