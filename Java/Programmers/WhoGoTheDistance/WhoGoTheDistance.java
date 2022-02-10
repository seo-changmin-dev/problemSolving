package Programmers.WhoGoTheDistance;

import java.util.HashMap;

public class WhoGoTheDistance {
  class Solution {
    public String solution(String[] participant, String[] completion) {
      HashMap<String, Integer> hm = new HashMap<>();
      for(String single : participant) {
        hm.put(single, hm.getOrDefault(single, 0) + 1);
      }

      for(String single : completion) {
        hm.put(single, hm.get(single) - 1);
      }

      String answer = "";
      for(String single : hm.keySet()) {
        if(hm.get(single) != 0) {
          answer = single;
        }
      }

      return answer;
    }
  }

  public static void main(String[] args) {
    WhoGoTheDistance cl = new WhoGoTheDistance();
    Solution sol = cl.new Solution();

    final String[] participant = {"marina", "josipa", "nikola", "vinko", "filipa"};
    final String[] completion = {"josipa", "filipa", "marina", "nikola"};

    System.out.println(sol.solution(participant, completion));

    // HashMap<String, Integer> m = new HashMap<>();
    // System.out.println(m.get("apple"));
  }
}
