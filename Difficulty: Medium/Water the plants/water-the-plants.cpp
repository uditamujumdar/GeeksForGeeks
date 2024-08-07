//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gal[], int n)
    {
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            if(gal[i]==-1)continue;
            else{
                vp.push_back({i-gal[i], i+gal[i]});
            }
        }
        sort(vp.begin(), vp.end());
        
        int maxi=0;
        int ans=0;
        int i=0;
        
        while(maxi<n){
            if(vp[i].first>maxi || i==vp.size()){
                return -1;
            }
            int currmax=vp[i].second;
            
            while(i<vp.size()-1 && vp[i+1].first<=maxi){
                currmax=max(currmax, vp[i+1].second);
                i++;
            }
            
            if(currmax<maxi){
                return -1;
            }
            ans++;
            maxi=currmax+1;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends