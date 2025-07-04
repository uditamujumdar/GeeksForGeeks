class Solution {

  public:
    int f(int ind, int sum, vector<int>& arr, vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }    
        if(sum<0 || ind>=arr.size()){
            return false;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int pick=f(ind+1, sum-arr[ind], arr, dp);
        int notpick=f(ind+1, sum, arr, dp);
        
        return dp[ind][sum]=pick | notpick;
    }
    
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        int total=accumulate(arr.begin(), arr.end(), 0);
        
        int ans=INT_MAX;
        vector<vector<int>>dp(n, vector<int>(total+1, -1));
        
        for(int sum=0;sum<=total;sum++){
            if(f(0, sum, arr, dp)){
                ans=min(ans, abs(sum-(total-sum)));
            }
        }
        
        return ans;
    }
};
