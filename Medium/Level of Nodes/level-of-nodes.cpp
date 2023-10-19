//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    vector<bool> visited(V, false);
    int level = 0;

    // Create a queue for BFS.
    queue<int> q;

    // Start from the source node (node 0).
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int size = q.size();

        // Process all nodes at the current level.
        for (int i = 0; i < size; i++) {
            int current = q.front();
            q.pop();

            // If the current node is X, return the current level.
            if (current == X) {
                return level;
            }

            // Enqueue unvisited neighbors.
            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        // Increment the level after processing all nodes at the current level.
        level++;
    }

    // If X is not found, return -1.
    return -1;

	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends