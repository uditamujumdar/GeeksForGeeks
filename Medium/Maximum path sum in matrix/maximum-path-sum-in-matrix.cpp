//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(j<0||j>=mat.size()){
            return -1e9;
        }
        if(i==0){
            return mat[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=mat[i][j]+f(i-1,j,mat,dp);
        int left=mat[i][j]+f(i-1,j-1,mat,dp);
        int rt=mat[i][j]+f(i-1,j+1,mat,dp);
        
        return dp[i][j]=max(up, max(left, rt));
    }
    
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int maxi=INT_MIN;
        vector<vector<int>>dp(N, vector<int>(N, -1));
        for(int i=0;i<N;i++){
            maxi=max(maxi, f(N-1, i, Matrix, dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends