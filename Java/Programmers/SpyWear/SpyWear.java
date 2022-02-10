package Programmers.SpyWear;

import java.util.HashMap;

public class SpyWear {
  class Solution {
    public int solution(String[][] clothes) {
      HashMap<String, Integer> hm = new HashMap<>();
      for(String[] set : clothes) {
        hm.put(set[1], hm.getOrDefault(set[1], 0) + 1);
      }

      int answer = 1;
      for(int value : hm.values()) {
        answer *= value + 1;
      }

      return answer-1;
    }
  }
  
  public static void main(String[] args) {
    SpyWear cl = new SpyWear();
    Solution sol = cl.new Solution();

    String[][] clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    System.out.println(sol.solution(clothes));

  }


}
