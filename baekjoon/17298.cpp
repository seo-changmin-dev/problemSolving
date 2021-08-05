// 17298
#include<iostream>
#include<stack>
using namespace std;

const int MAX_N = 1000000;
int ans[MAX_N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    stack<pair<int,int> > stk;
    for(int i = 0; i < N; i++)
    {
        int x; cin >> x;
        pair<int,int> next = make_pair(x, i);

        while(!stk.empty())
        {
            pair<int,int> now = stk.top();
            if(now.first >= next.first) break;
            else
            {
                stk.pop();
                ans[now.second] = next.first;
            }
        }
        stk.push(next);
    }

    while(!stk.empty())
    {
        pair<int,int> now = stk.top();
        ans[now.second] = -1;
        stk.pop();
    }

    for(int i = 0; i < N; i++)
        cout << ans[i] << ' ';

    return 0;
}