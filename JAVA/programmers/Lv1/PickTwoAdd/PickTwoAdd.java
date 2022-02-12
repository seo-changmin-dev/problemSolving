package Lv1.PickTwoAdd;

import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;

public class PickTwoAdd {
    class Solution {
        public int[] solution(int[] numbers) {
            HashSet<Integer> hs = new HashSet<>();

            for(int i = 0; i < numbers.length; i++)
                for(int j = i+1; j < numbers.length; j++)
                    hs.add(numbers[i] + numbers[j]);
            
            int[] answer = new int[hs.size()];
            
            int i = 0;
            Iterator it = hs.iterator();
            while(it.hasNext()) {
                answer[i] = (int)it.next();
                i++;
            }

            Arrays.sort(answer);
            return answer;
        }
    }

    public static void main(String[] args) {
        PickTwoAdd cl = new PickTwoAdd();
        Solution sol = cl.new Solution();

        int[] numbers = {2, 1, 3, 4, 1};
        System.out.println(Arrays.toString(sol.solution(numbers)));
    }
}