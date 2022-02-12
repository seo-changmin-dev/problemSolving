package Lv1.SortMyWay;

import java.util.ArrayList;

public class SortMyWay {
    class Solution {
        public String[] solution(String[] strings, int n) {

            // ArrayList<String>[] arr = new ArrayList<String>[26];
            // for(String str : strings) {
            //     arr[str.charAt(n) - 'a'].add(str);
            // }

            String[] answer = {};
            return answer;
        }
    }

    public static void main(String[] args) {
        SortMyWay cl = new SortMyWay();
        Solution sol = cl.new Solution();

        String[] strings = {"sun", "bed", "car"};
        final int n = 1;
        System.out.println(sol.solution(strings, n));
    }
}
