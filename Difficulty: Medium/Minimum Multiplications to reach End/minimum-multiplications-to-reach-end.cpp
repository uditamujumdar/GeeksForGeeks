// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>>q;
        q.push({0, start});
        vector<int>dist(100000, 1e9);
        dist[start]=0;
        int mod=100000;
        
        while(!q.empty()){
            int node=q.front().second;
            int steps=q.front().first;
            q.pop();
            
            for(auto it: arr){
                int num=(it*node)%mod;
                
                if(steps+1<dist[num]){
                    dist[num]=steps+1;
                    q.push({steps+1, num});
                    if(num==end){
                        return steps+1;
                    }
                }
            }
        }
        if(start==end){
            return 0;
        }
        return -1;
    }
};