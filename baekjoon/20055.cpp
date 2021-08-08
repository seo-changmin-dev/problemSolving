// 20055
#include<iostream>
#include<queue>
using namespace std;

const int MAX_N = 100;
const int MAX_HP = 1000;

bool onRobot[2*MAX_N];
int hp[2*MAX_N];

int totalBroken = 0;
int loadPos, dropPos;
int N,K;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;
	loadPos = 0; dropPos = N-1;
	for(int i = 0; i < 2*N; i++)
		cin >> hp[i];
	
	int trial = 0;
	queue<int> robotPos;
	while(totalBroken < K)
	{
		trial++;
		
		// 1. 벨트 회전
		loadPos = (loadPos+2*N-1)%(2*N);
		dropPos = (dropPos+2*N-1)%(2*N);
		
		// 내리는 로봇 체크
		onRobot[dropPos] = false;
			
		// 2.
		int qSize = robotPos.size();
		for(int i = 0; i < qSize; i++)
		{
			int here = robotPos.front();
			int there = (here+1)%(2*N);
			robotPos.pop();
			
			if(here == dropPos) continue;
			
			//b. check wheater robot can move or not
			if(!onRobot[there] && hp[there] > 0)
			{
				onRobot[here] = false; onRobot[there] = true;

				hp[there]--;
				if(hp[there] <= 0) totalBroken++;
				
				if(there == dropPos) onRobot[dropPos] = false;
				else robotPos.push(there);
			}
			else robotPos.push(here);
		}
		
		// 3. 로봇 싣기
		if(!onRobot[loadPos] && hp[loadPos] > 0)
		{
			onRobot[loadPos] = true;
			hp[loadPos]--;
			if(hp[loadPos] <= 0) totalBroken++;
			
			robotPos.push(loadPos);
		}
	}
	
	cout << trial << endl;
	return 0;
}
