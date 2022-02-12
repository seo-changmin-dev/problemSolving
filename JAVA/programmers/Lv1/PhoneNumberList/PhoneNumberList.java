package Lv1.PhoneNumberList;

import java.util.Arrays;

public class PhoneNumberList {
  class Solution {
    public boolean solution(String[] phone_book) {
      Arrays.sort(phone_book); // nlogn

      for(int i = 1; i < phone_book.length; i++) { // n
        String lhs = phone_book[i];
        String rhs = phone_book[i+1];

        if(lhs.length() < rhs.length() && lhs.equals(rhs.substring(0, lhs.length())))
          return false;
      }
      
      return true;
    }
  }

  public static void main(String[] args) {
    PhoneNumberList cl = new PhoneNumberList();
    Solution sol = cl.new Solution();

    String[] phone_book = {"12","123", "1234","1235","567","88"};
    System.out.println(sol.solution(phone_book));
  }
}
