package Lv1.KakaoReportResult;

import java.util.Arrays;
import java.util.HashMap;

public class KakaoReportResult {
    class Solution {
        public int[] solution(String[] id_list, String[] reports, int k) {
            int[][] g = new int[id_list.length][id_list.length];
                    
            HashMap<String, Integer> hm = new HashMap<>();
            for(int i = 0; i < id_list.length; i++)
                hm.put(id_list[i], i);

            for(String report : reports){
                String a = report.split(" ")[0];
                String b = report.split(" ")[1];

                // Consider Locality
                g[hm.get(b)][hm.get(a)]++;
            }

            int[] answer = new int[id_list.length];
            for(int i = 0; i < id_list.length; i++){
                boolean isReported = false;

                int reportCnt = 0;
                for(int j = 0; j < id_list.length; j++) {
                    if(g[i][j] > 0) reportCnt++;
                    if(reportCnt >= k) {
                        isReported = true;
                        break;
                    }
                }

                if(isReported) {
                    for(int j = 0; j < id_list.length; j++) {
                        if(g[i][j] > 0) answer[j]++;
                    }
                }
            }

            return answer;
        }
    }
    public static void main(String[] args) {
        KakaoReportResult cl = new KakaoReportResult();
        Solution sol = cl.new Solution();
        
        String[] id_list = {"muzi", "frodo", "apeach", "neo"};
        String[] report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
        int k = 2;

        System.out.println(Arrays.toString(sol.solution(id_list, report, k)));
    }
}
