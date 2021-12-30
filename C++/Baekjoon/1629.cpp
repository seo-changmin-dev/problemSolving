// 1629
#include<iostream>
using namespace std;

typedef long long ll;

ll power(ll A, ll B, ll C)
{
    if(B == 1) return A%C;

    if(B%2 == 0)
    {
        ll temp = power(A, B/2, C);
        return (temp*temp)%C;
    }
    else return (A*power(A, B-1, C))%C;

}

int A, B, C;
int main()
{
    cin >> A >> B >> C;
    cout << power(A,B,C) << endl;
    return 0;
}