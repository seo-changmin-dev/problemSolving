// 2981
#include<iostream>
#include<set>
using namespace std;

const int MAX_N = 100;

int gcd(int a, int b);

int main()
{
    int arr[MAX_N];
    
    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int gcdVal = -1;
    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
        {
            int comp = arr[i] > arr[j] ? arr[i] - arr[j] : arr[j] - arr[i];
            if(gcdVal == -1) gcdVal = comp;
            else gcdVal = gcd(gcdVal, comp);
        }

    set<int> ans;
    for(int i = 1; i*i <= gcdVal; i++)
        if(gcdVal%i == 0)
        {
            ans.insert(i);
            ans.insert(gcdVal/i);
        }

    for(int i:ans)
        if(i == 1) continue;
        else cout << i << ' ';

    return 0;
}

int gcd(int a, int b)
{
    if(b > a) return gcd(b, a);
    if(b == 0) return a;

    return gcd(a%b, b);
}