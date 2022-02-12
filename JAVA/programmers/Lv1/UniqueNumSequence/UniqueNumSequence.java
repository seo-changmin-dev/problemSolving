package Lv1.UniqueNumSequence;

import java.util.ArrayList;
import java.util.Arrays;

public class UniqueNumSequence {
    public class Solution {
        public int[] solution(int []arr) {

            ArrayList<Integer> iArr = new ArrayList<>();

            int prev = -1;
            for(int e : arr) {
                if(e != prev) iArr.add(e);
                prev = e;
            }
            
            int[] answer = new int[iArr.size()];
            for(int i = 0; i < answer.length; i++)
                answer[i] = iArr.get(i);
            
            return answer;
        }
    }

    public static void main(String[] args) {
        UniqueNumSequence cl = new UniqueNumSequence();
        Solution sol = cl.new Solution();

        int[] arr = {1,1,3,3,0,1,1};
        System.out.println(Arrays.toString(sol.solution(arr)));
    }
}
