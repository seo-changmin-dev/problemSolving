package Programmers.SortDigitDesc;

import java.util.Arrays;

public class SortDigitDesc {
  class Solution {
    public long solution(long n) {
        String str = Long.toString(n);
        char[] arr = str.toCharArray();

        Arrays.sort(arr);
        for(int i = 0; i < arr.length / 2; i++) {
          char temp = arr[i];
          arr[i] = arr[(arr.length - 1) - i];
          arr[(arr.length - 1) - i] = temp;
        }

        str = new String(arr);
        return Long.parseLong(str);
    }
  }

  public static void main(String[] args) {
    SortDigitDesc cl = new SortDigitDesc();
    Solution sol = cl.new Solution();

    System.out.println(sol.solution(314159265));
  }
}
