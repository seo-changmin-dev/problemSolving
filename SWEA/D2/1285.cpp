#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int arr[1000];
int main()
{
    freopen("./datas/input.txt", "r", stdin);
	
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++)
    {
        int N; cin >> N;
        for(int i = 0; i < N; i++)
        {
            cin >> arr[i];
        	arr[i] = abs(arr[i]);
        }
        
        int min_val = *min_element(arr, arr+N);
        int cnt = count(arr, arr+N, min_val);
        
        cout << "#" << tc << ' ' << min_val << ' ' << cnt << '\n';
    }
    return 0;
}