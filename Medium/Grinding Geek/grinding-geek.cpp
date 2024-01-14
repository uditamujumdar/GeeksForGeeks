//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<vector<int>> dp;
    
    int helper(int i, vector<int>& cost, int total) {
        if(i == cost.size())
            return 0;
        if(dp[i][total] != -1)
            return dp[i][total];

        int curr = cost[i];
        int pick = 0, notPick = 0;
        if(curr <= total)
            pick = 1 + helper(i+1, cost, total - curr + (curr * 9) / 10);
        notPick = helper(i+1, cost, total);
        return dp[i][total] = max(pick, notPick);
    }
    
    int max_courses(int n, int total, vector<int> &cost) {
        dp = vector<vector<int>>(n, vector<int>(total + 1, -1));
        return helper(0, cost, total);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends