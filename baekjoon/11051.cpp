// 11051
#include<iostream>
using namespace std;

const int N_MAX = 1000;
const int MOD = 10007;

int dp[N_MAX+1][N_MAX+1];
int N, K;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    //init dp
    for(int i = 0; i <= N; i++)
        dp[i][0] = dp[i][i] = 1;
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j < i; j++)
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%MOD;

    cout << dp[N][K] << endl;
    return 0;
}