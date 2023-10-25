//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int shaurya(int index,int target,int *val,int *wt, vector<vector<int>> &dp)
{
    if(target<=0)
    {
        return 0;
    }
    if(index==0)
    {
        if(wt[index]<=target)
        {
            return (int)(target/wt[0])*val[0];
        }
        else
        {
            return -1e9;
        }
    }
    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }
    
    int notpick=shaurya(index-1,target,val,wt,dp);
    
    int pick=0;
    
    if(target>=wt[index])
    {
        pick=val[index]+shaurya(index,target-wt[index],val,wt,dp);
    }
    return dp[index][target]=max(pick,notpick);
}

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
       
     int ans=shaurya(N-1,W,val,wt,dp);
      if(ans==-1e9)
      {
          return 0;
      }
      else
      {
          return ans;
      }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends