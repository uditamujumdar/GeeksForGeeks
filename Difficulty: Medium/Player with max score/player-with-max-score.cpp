//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution{   
public:
    ll f(int i, int j, int arr[], vector<vector<ll>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        ll a=arr[i]+ min( f(i+2,j,arr,dp), f(i+1,j-1,arr,dp));
        ll b=arr[j]+ min( f(i+1,j-1,arr,dp), f(i,j-2,arr,dp));
        
        return dp[i][j]=max(a,b);
    }
    
    bool is1winner(int N,int arr[]) {
        ll sum=accumulate(arr, arr+N, 0ll);
        
        vector<vector<ll>>dp(N, vector<ll>(N, -1));
        
        ll p=f(0,N-1,arr,dp);
        
        return p>=(sum-p);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends