package Programmers.GcdLcm;

import java.util.Arrays;
import java.util.Scanner;

public class GcdLcm {
  public int[] solution(int n, int m) {

    // Get Gcd using uclidean method
    final int GCD = getGcd(n, m);

    // Get Lcm divide n * m / gcd
    final int LCM = (int) (((long) n) * ((long) m) / GCD);

    int[] answer = {GCD, LCM};
    return answer;
  }

  public int getGcd(int n, int m) {
    if(n < m) return getGcd(m, n);
    if(m == 0) return n;

    return getGcd(n%m, m);
  }

  public static void main(String[] args) {
    
    Scanner scan = new Scanner(System.in);
    final int n = scan.nextInt();
    final int m = scan.nextInt();

    GcdLcm sol = new GcdLcm();
    System.out.println(Arrays.toString(sol.solution(n, m)));
  }
}
