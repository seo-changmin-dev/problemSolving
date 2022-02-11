package Programmers.CaesarCipher;

public class CaesarCipher {
    class Solution {
        public String solution(String s, int n) {
            char[] cArr = s.toCharArray();

            for(int i = 0; i < cArr.length; i++) {
                if(cArr[i] == ' ') continue;
                
                if('a' <= cArr[i] && cArr[i] <= 'z') {
                    cArr[i] = (char) ((cArr[i] - 'a' +  n) % 26 + 'a');
                } else { // A to Z
                    cArr[i] = (char) ((cArr[i] - 'A' +  n) % 26 + 'A');
                }
            }

            return new String(cArr);
        }
    }

    public static void main(String[] args) {
        CaesarCipher cl = new CaesarCipher();
        Solution sol = cl.new Solution();

        String s = "a B z";
        int n = 26;
        System.out.println(sol.solution(s, n));
    }
}
