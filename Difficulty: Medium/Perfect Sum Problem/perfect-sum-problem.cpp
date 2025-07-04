class Solution {
  public:
    int f(int ind, int sum, vector<int>& arr, vector<vector<int>>& dp){
        if(ind==arr.size()){
            return sum==0;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int pick=0;
        if(arr[ind]<=sum){
            pick=f(ind+1, sum-arr[ind], arr, dp);
        }
        int notpick=f(ind+1, sum, arr, dp);
        
        return dp[ind][sum]=(pick+notpick);
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        
        return f(0, target, arr, dp);
    }
};