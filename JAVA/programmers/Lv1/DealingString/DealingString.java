package Lv1.DealingString;

import java.util.*;
public class DealingString {
    class Solution {
        public boolean solution(String s) {
            if(s.length() != 4 && s.length() != 6) return false;

            try {
                Integer.parseInt(s);
                return true;
            } catch(Exception e) {
                return false;
            }
        }
    }

    public static void main(String[] args) {
        DealingString cl = new DealingString();
        Solution sol = cl.new Solution();

        String s = "12345";
        System.out.println(sol.solution(s));        
    }
}
