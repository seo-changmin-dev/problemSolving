package Lv1.LottoMinMaxRank;

import java.util.Arrays;

public class LottoMinMaxRank {
    class Solution {
        public int[] solution(int[] lottos, int[] win_nums) {

            int minCnt = 0;
            for(int i = 0; i < lottos.length; i++)
                for(int j = 0; j < win_nums.length; j++)
                    if(lottos[i] == win_nums[j]) minCnt++;

            int maxCnt = minCnt;
            for(int i = 0; i < lottos.length; i++)
                if(lottos[i] == 0) maxCnt++;

            int[] answer = {getRank(maxCnt), getRank(minCnt)};
            return answer;
        }

        private int getRank(int cnt) {
            if (cnt <= 1) return 6;
            else return 7 - cnt;
        }
    }

    public static void main(String[] args) {
        LottoMinMaxRank cl = new LottoMinMaxRank();
        Solution sol = cl.new Solution();

        int[] lottos = {41, 1, 0, 0, 31, 25};
        int[] win_nums = {31, 10, 45, 1, 6, 19};
        System.out.println(Arrays.toString(sol.solution(lottos, win_nums)));
    }
}
