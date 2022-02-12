package Lv1.WeirdString;

import java.util.Arrays;

public class WeirdString {
  class Solution {
    public String solution(String s) {
      char[] cArr = s.toCharArray();

      int offset = 0;
      for(int i = 0; i < cArr.length; i++) {
        if(cArr[i] == ' ') offset = -1;
        else if(offset % 2 == 0) { // Even
          cArr[i] = Character.toUpperCase(cArr[i]);
        } else { // Odd
          cArr[i] = Character.toLowerCase(cArr[i]);
        }

        offset++;
      }

      return new String(cArr);
    }
  }

  public static void main(String[] args) {
    WeirdString cl = new WeirdString();
    Solution sol = cl.new Solution();

    String str = "aaaa    aaaaaaa";
    System.out.println(sol.solution(str));

  }
}