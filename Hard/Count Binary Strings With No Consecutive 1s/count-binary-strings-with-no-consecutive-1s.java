//{ Driver Code Starts
// Initial Template for Java
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while (t-- > 0) {

            long N = Long.parseLong(br.readLine().trim());

            Solution ob = new Solution();
            System.out.println(ob.countStrings(N));
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int countStrings(long N) {
        // Code here
        int Mod = 1000000007;
        return power(new int[][]{{1, 1}, {1, 0}}, N+1, Mod)[0][0];
    }
    public int[][] multiply(int[][] A, int[][] B, int Mod) {
        int[][] arr = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    arr[i][j] = (arr[i][j] + (int)((long)A[i][k] * B[k][j] % Mod)) % Mod;
                }
            }
        }
        return arr;
    }
    public int[][] power(int[][] A, long n, int Mod) {
        if (n == 1)  return A;
        int[][] ans = power(A, n/2, Mod);
        int[][] res = multiply(ans, ans, Mod);
        if (n%2 == 1) {
            res = multiply(res, A, Mod);
        }
        return res;
    }
    
}