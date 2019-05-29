import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.util.Pair; 
import java.util.ArrayList; 

public class Solution {
    static long arrayManipulation(int n, int[][] queries, int m) {
      long[] arr = new long[10000002];


      for(int i = 0; i < n; i++){
        arr[i] = 0;
      }
      
      int l, r, val;
      for(int i = 0; i < m; i++){
        l = queries[i][0];
        r = queries[i][1];
        val = queries[i][2];
        arr[l] += val;
        arr[r+1] -= val;
      }
      
      long ans = 0;
      for(int i = 1; i <= n; i++){
        arr[i] += arr[i-1];
        ans = Math.max(ans, arr[i]);
      }
      
      return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        int[][] queries = new int[m][3];

        for (int i = 0; i < m; i++) {
            String[] queriesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 3; j++) {
                int queriesItem = Integer.parseInt(queriesRowItems[j]);
                queries[i][j] = queriesItem;
            }
        }

        long result = arrayManipulation(n, queries, m);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
