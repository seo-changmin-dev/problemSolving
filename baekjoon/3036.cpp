// 3036
#include<iostream>
using namespace std;

int gcd(int a, int b);

int main()
{
    int N; cin >> N;

    int ring1; cin >> ring1;
    for(int i = 1; i < N; i++)
    {
        int ringRadi; cin >> ringRadi;
        int gcdVal = gcd(ring1, ringRadi);
        cout << ring1/gcdVal << '/' << ringRadi/gcdVal << '\n';
    }

    return 0;
}

// a >= b
int gcd(int a, int b)
{
    if(b > a) return gcd(b, a);
    if(b == 0) return a;

    return gcd(a%b, b);
}