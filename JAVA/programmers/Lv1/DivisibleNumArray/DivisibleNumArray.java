package Lv1.DivisibleNumArray;

import java.util.ArrayList;
import java.util.Arrays;

public class DivisibleNumArray {
    class Solution {
        public int[] solution(int[] arr, int divisor) {
            ArrayList<Integer> iArr = new ArrayList<>();
            for(int e : arr) if(e%divisor == 0) iArr.add(e);

            int[] answer = new int[iArr.size()];
            for(int i = 0; i < answer.length; i++)
                answer[i] = iArr.get(i);
            
            Arrays.sort(answer);
            return iArr.isEmpty() ? new int[]{-1} : answer;
        }
    }

    public static void main(String[] args) {
        DivisibleNumArray cl = new DivisibleNumArray();
        Solution sol = cl.new Solution();

        int[] arr = {5, 9, 7, 10};
        int divisor = 8;
        System.out.println(Arrays.toString(sol.solution(arr, divisor)));
    }
}
