package Lv1.PopSmallestOne;

import java.util.Arrays;

public class PopSmallestOne {

  class Solution {
    public int[] solution(int[] arr) {
      int minVal = Integer.MAX_VALUE;
      for(int elem : arr) minVal = Math.min(minVal, elem);

      int arrLen = arr.length;
      for(int elem : arr) {
        if(elem == minVal) arrLen--;
      }

      int[] answer = new int[arrLen];
      for(int i = 0, j = 0; i < arr.length; i++) {
        if(arr[i] != minVal) {
          answer[j] = arr[i];
          j++;
        }
      }

      if(arrLen < 1) return new int[]{-1};
      else return answer;
    }
  }

  public static void main(String[] args) {
    PopSmallestOne Cl = new PopSmallestOne();
    PopSmallestOne.Solution sol = Cl.new Solution();

    int[] arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9};
    System.out.println(Arrays.toString(sol.solution(arr)));
  }
}
