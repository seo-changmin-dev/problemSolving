package Lv1.SumOfDivider;

public class SumOfDivider {
  class Solution {
    public int solution(int n) {
      int answer = 0;

      for (int i = 1; i <= Math.sqrt(n); i++) {
        if (n % i != 0)
          continue;

        int a = i;
        int b = n / i;
        if (a == b)
          answer += a;
        else
          answer = answer + a + b;
      }
      return answer;
    }
  }

  public static void main(String[] args) {
    SumOfDivider cl = new SumOfDivider();
    Solution sol = cl.new Solution();

    System.out.println(sol.solution(3000));
  }
}
