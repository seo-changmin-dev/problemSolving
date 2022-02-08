package Programmers.AddDigits;

import java.util.Scanner;

public class AddDigits {
  public class Solution {
    public int solution(int n) {
        int answer = digitSum(n, 0);        
        return answer;
    }

    // For Tail-Recursion, add ret parameter
    public int digitSum(int n, int ret) {
      if(n == 0) return ret;
      else return digitSum(n / 10, ret + n % 10);
    }
  }

  public static void main(String[] args) {
    AddDigits cl = new AddDigits();
    Solution sol = cl.new Solution();

    while(true) {
      Scanner scan = new Scanner(System.in);
      int n = scan.nextInt();

      System.out.println(sol.solution(n));
    }
  }
}
