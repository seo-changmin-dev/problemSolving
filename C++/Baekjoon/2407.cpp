// 2407
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

string SUM(string str1, string str2);
string MUX(string str1, string str2);

string combi[MAX_N+1][MAX_M+1];

int n,m;
int main()
{  
    cin >> n >> m;

    for(int i = 1; i <= MAX_N; i++)
    {
        combi[i][0] = "1";
        combi[i][i] = "1";
    }

    for(int i = 2; i <= MAX_N; i++)
        for(int j = 1; j < i; j++)
            combi[i][j] = SUM(combi[i-1][j], combi[i-1][j-1]);
    
    cout << combi[n][m] << '\n';
    return 0;
}

string SUM(string str1, string str2)
{
    if(str1.length() < str2.length())
        return SUM(str2, str1);
    
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());

    str2 += string(str1.length() - str2.length(), '0');
    string ret;

    int carry = 0;
    for(int i = 0; i < str2.length(); i++)
    {
        int sum = (str1[i] - '0') + (str2[i] - '0') + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ret.push_back(digit + '0');
    }
    if(carry) ret.push_back(carry + '0');

    reverse(ret.begin(),ret.end());
    return ret;
}