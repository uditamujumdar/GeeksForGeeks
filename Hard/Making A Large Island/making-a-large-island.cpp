//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    void dfs(int i,int j,vector<vector<int>>&grid,int k,unordered_map<int,int>&mp)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||i>=n||j<0||j>=m)return ;
          if(grid[i][j]!=1)return ;
            grid[i][j]=k;
            mp[k]++;
           dfs(i+1,j,grid,k,mp);
           dfs(i-1,j,grid,k,mp);
           dfs(i,j+1,grid,k,mp);
           dfs(i,j-1,grid,k,mp);
    }   
    
    
    int largestIsland(vector<vector<int>>& grid) 
    {
        int k=2;
          unordered_map<int,int>mp;
         for(int i=0;i<grid.size();i++)
         {
             for(int j=0;j<grid[0].size();j++)
             {
                if(grid[i][j]==1)
                {
                   dfs(i,j,grid,k,mp);
                   k++;
                }
             }
         }
         vector<pair<int,int>>v={{0,-1},{0,1},{1,0},{-1,0}};
         int n=grid.size();
         int m=grid[0].size();
         int z=0;
         int f=0;
         for(int i=0;i<grid.size();i++)
         {
            for(int j=0;j<grid[0].size();j++)
            {
                  if(grid[i][j]==0)
                  {
                      int sum=0;
                      f++;
                      unordered_map<int,bool>mp1;
                      for(auto it:v)
                      {
                          int x1=it.first+i;
                          int y1=it.second+j;
                            if(x1>=0&&x1<n&&y1>=0&&y1<m)
                            {
                              if(mp1[grid[x1][y1]]==false){
                              sum+=mp[grid[x1][y1]];
                              mp1[grid[x1][y1]]=true;
                              }
                            }
                      }
                    z=max(sum+1,z);
                     
                  }
            }
         }
           if(f==0)return (n*m);
         return z;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends