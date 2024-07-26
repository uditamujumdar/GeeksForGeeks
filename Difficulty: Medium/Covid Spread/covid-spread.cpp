//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hos)
    {
        int n=hos.size();
        int m=hos[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        queue<pair<int,pair<int,int>>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(hos[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        int ans=0;
        
        while(!q.empty()){
            int t=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            ans=t;
            
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && hos[nr][nc]==1){
                    vis[nr][nc]=1;
                    hos[nr][nc]=2;
                    q.push({t+1,{nr,nc}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(hos[i][j]==1){
                    ans=-1;
                    break;
                }
            }
            if(ans==-1){
                break;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends