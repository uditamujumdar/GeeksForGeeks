//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(int i, int target, int k, int n, vector<vector<long long>>&dp) {
        if(i == n){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[i][target] != -1) {
            return dp[i][target];
        }
        
        long long count = 0;
        
        for(int j = 1; j<=k; j++) {
            if(target >= j) {
                count += solve(i+1, target-j, k, n, dp);
            }
        }
        return dp[i][target] = count;
    }
    
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>>dp(N, vector<long long>(X+1, -1));
        return solve(0, X, M, N, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends