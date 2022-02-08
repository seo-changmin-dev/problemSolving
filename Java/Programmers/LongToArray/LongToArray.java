package Programmers.LongToArray;

import java.util.Arrays;
import java.util.Scanner;

public class LongToArray {
  class Solution {
    public int[] solution(long n) {
      char[] arr = Long.toString(n).toCharArray();
      
      int[] answer = new int[arr.length];
      for(int i = 0; i < arr.length; i++) {
        answer[i] = arr[arr.length - 1 - i] - '0';
      }

      return answer;
    }
  }

  public static void main(String[] args) {
    LongToArray cl = new LongToArray();
    Solution sol = cl.new Solution();

    Scanner scan = new Scanner(System.in);
    while(true) {
      long n = scan.nextInt();
      System.out.println(Arrays.toString(sol.solution(n)));
    }
  }
}
