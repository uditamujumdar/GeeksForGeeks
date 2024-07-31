//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&kni, vector<int>&tar, int n){
	    vector<vector<int>>vis(n, vector<int>(n, 0));
	    int x=kni[0]-1;
	    int y=kni[1]-1;
	   
        vis[x][y]=1;
        int ans=0;
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0, {x,y}});
        int dr[]={2, 2, -2, -2, 1, 1, -1, -1};
        int dc[]={1, -1, 1, -1, 2, -2, 2, -2};
        
        while(!q.empty()){
            int t=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            ans=t;
            
            if(r==tar[0]-1 && c==tar[1]-1){
                return ans;
            }
            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]){
                    q.push({t+1,{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }
        
        return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends