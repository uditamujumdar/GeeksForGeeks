//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int start, int V, vector<int>adj[], int col[]){
        queue<int>q;
        q.push(start);
        col[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it: adj[node]){
                //if adj node is not colored, give it opposite color
                if(col[it]==-1){
                    col[it]=!col[node];
                    q.push(it);
                }
                //if curr node has color same as that of its adjacent node, graph is not bipartite
                else if(col[it]==col[node]){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0;i<V;i++){
	        color[i]=-1;
	    }
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(!check(i,V,adj,color)){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends