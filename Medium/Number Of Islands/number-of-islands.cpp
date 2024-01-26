//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisJoint{
  public:
  vector<int>rank,parent,size;
  DisJoint(int n){
      rank.resize(n+1,0);
      parent.resize(n+1);
      size.resize(n+1);
      for(int i=0;i<=n;i++){
          parent[i]=i;
      }
      for(int i=0;i<=n;i++){
          size[i]=1;
      }
  }

  int findUPar(int node){
      if(parent[node]==node)
      return node;
      
      return parent[node]=findUPar(parent[node]);
  }

  void unionbyRank(int u,int v){
      int ulp_u=findUPar(u);
      int ulp_v=findUPar(v);
      
      if(ulp_u==ulp_v)return;
      
      if(rank[ulp_u]<rank[ulp_v]){
          parent[ulp_u]=ulp_v;
      }
      else if(rank[ulp_v]<rank[ulp_u]){
          parent[ulp_v]=ulp_u;
      }
      else{
           parent[ulp_v]=ulp_u;
           rank[ulp_u]++;
      }
  }

  void unionbySize(int u,int v){
      int ulp_u=findUPar(u);
      int ulp_v=findUPar(v);
      
      if(ulp_u==ulp_v)return;
      
      if(size[ulp_u]<size[ulp_v])
      {
          parent[ulp_u]=ulp_v;
          size[ulp_u]+=size[ulp_v];
      }
      else
      {
        parent[ulp_v]=ulp_u;
        size[ulp_v]+=size[ulp_u];  
      }
  }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisJoint ds(n*m);
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int cnt=0;
        vector<int>ans;
        
        for(auto it: operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                
                if(nrow>=0 && nrow<n && ncol<m && ncol>=0){
                    if(vis[nrow][ncol]){
                        int nodeNo=row*m+col;
                        int adjnode=nrow*m+ncol;
                        
                        if(ds.findUPar(nodeNo)!=ds.findUPar(adjnode)){
                            cnt--;
                            ds.unionbySize(nodeNo, adjnode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends