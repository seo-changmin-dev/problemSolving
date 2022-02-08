package Programmers.WeirdString;

public class WeirdString {
  class Solution {
    public String solution(String s) {
        String[] strArr = s.split(" ");
        
        String answer = "";
        for(String str : strArr) {
          if(str == "" || str == " ") continue;

          char[] cArr = str.toCharArray();

          for(int i = 0; i < cArr.length; i++) {
            if(i%2 == 0 && 'a' <= cArr[i] && cArr[i] <= 'z')
              cArr[i] = Character.toUpperCase(cArr[i]);
              
              if(i%2 == 1 && 'A' <= cArr[i] && cArr[i] <= 'Z')
              cArr[i] = Character.toLowerCase(cArr[i]);
          }

          answer += ' ' + new String(cArr);
        }

        return answer.substring(1);
    }
  }

  public static void main(String[] args) {
    WeirdString cl = new WeirdString();
    Solution sol = cl.new Solution();

    String str = "aaaa    aaaaaaa";
    System.out.println(sol.solution(str));

  }
}