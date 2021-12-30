// 17298
// with struct

#include<iostream>
#include<stack>
using namespace std;

typedef struct _Data{
    int val, idx;
} Data;

const int N_MAX = 1000000;
int ans[N_MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    
    stack<Data> stk;
    for(int i = 0; i < N; i++)
    {
        Data next;
        cin >> next.val;
        next.idx = i;

        while(!stk.empty())
        {
            Data now = stk.top();
            if(now.val >= next.val) break;
            else
            {
                ans[now.idx] = next.val;
                stk.pop();
            }
        }
        stk.push(next);
    }

    while(!stk.empty())
    {
        Data now = stk.top();
        stk.pop();
        ans[now.idx] = -1;
    }

    for(int i = 0; i < N; i++)
        cout << ans[i] << ' ';

    return 0;
}