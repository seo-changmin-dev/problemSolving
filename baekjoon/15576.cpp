// 15576
#include<iostream>
#include<algorithm>
using namespace std;

string SUM(string str1, string str2);
string MUX(string str1, string str2);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    cout << MUX(s1,s2) << '\n';
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

string MUX(string str1, string str2)
{
    if(str1.length() < str2.length())
        return MUX(str2, str1);

    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());

    str2 += string(str1.length() - str2.length(), '0');

    string ret;
    for(int i = 0; i < str2.length(); i++)
    {
        int carry = 0;
        string tmp = string(i,'0');

        if(str2[i] == '0') continue;

        for(int j = 0; j < str1.length(); j++)
        {
            int mux = (str1[j]-'0') * (str2[i]-'0') + carry;
            int digit = mux % 10;
            carry = mux / 10;

            tmp.push_back(digit + '0');
        }

        if(carry) tmp.push_back(carry + '0');

        reverse(tmp.begin(), tmp.end());
        
        if(ret.empty()) ret = tmp;
        else ret = SUM(ret, tmp);
    }

    return ret;
}