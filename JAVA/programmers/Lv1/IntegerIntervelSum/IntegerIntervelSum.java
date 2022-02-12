package Lv1.IntegerIntervelSum;

import java.util.Random;

public class IntegerIntervelSum {
    class Solution {
        public long solution(int a, int b) {
            if(a > b) return solution(b, a);
            else return (a+b)*(b-a+1L)/2L;
        }
    }

    public static void main(String[] args) {
        IntegerIntervelSum cl = new IntegerIntervelSum();
        Solution sol = cl.new Solution();

        int a = 9524779;
        int b = 6796277;
        System.out.println(sol.solution(a, b));

        // Fuzzing Test
        // while(true) {
        //     Random random = new Random();
        //     int a = random.nextInt(10000000);
        //     int b = random.nextInt(10000000);

        //     long sum = 0;
        //     for(int i = Math.min(a,b); i <= Math.max(a,b); i++)
        //         sum += i;

        //     System.out.println(sum);
        //     System.out.println(sol.solution(a, b));

        //     if(sum != sol.solution(a, b)){
        //         System.out.println(a);
        //         System.out.println(b);
        //         System.out.println(sum);
        //         System.out.println(sol.solution(a, b));
        //         break;
        //     }
        // }
    }
}
