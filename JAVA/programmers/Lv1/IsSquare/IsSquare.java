package Lv1.IsSquare;

public class IsSquare {
  class Solution {
    public long solution(long n) {
      long sqrtCand1 = (long) Math.ceil(Math.sqrt(n));
      long sqrtCand2 = (long) Math.floor(Math.sqrt(n));

      long ans = -1;
      if(sqrtCand1 * sqrtCand1 == n) ans = (sqrtCand1 + 1) * (sqrtCand1 + 1);
      else if(sqrtCand2 * sqrtCand2 == n) ans = (sqrtCand2 + 1) * (sqrtCand2 + 1);

      return ans;
    }
  }

  public static void main(String[] args) {
    IsSquare Cl = new IsSquare();
    Solution sol = Cl.new Solution();

    System.out.println(sol.solution(3));
  }
}
