// 17298
// with struct

#include<iostream>
#include<stack>
using namespace std;

typedef struct {
    int val, idx;
} datta;

const int N_MAX = 1000000;
int ans[N_MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    
    stack<datta> stk;
    for(int i = 0; i < N; i++)
    {
        datta next;
        cin >> next.val;
        next.idx = i;

        while(!stk.empty())
        {
            datta now = stk.top();
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
        datta now = stk.top();
        stk.pop();
        ans[now.idx] = -1;
    }

    for(int i = 0; i < N; i++)
        cout << ans[i] << ' ';

    return 0;
}