#include<cstdio>
#include<cmath>
using namespace std;

#define ll long long
#define CIPHER_CNT 18

static const ll CIPHER = pow(10, CIPHER_CNT);

typedef struct _tagBigInteger {
    ll high;
    ll low;
} BI;

BI ll_to_bi(ll li) {
    return {0, li};
}

BI bi_add_bi(BI a, BI b) {
    ll tLow = (a.low + b.low)%CIPHER;
    ll carry = (a.low + b.low)/CIPHER;
    ll tHigh = carry;
    tHigh += (a.high + b.high);

    return {tHigh, tLow};
}

int main()
{
    return 0;
}