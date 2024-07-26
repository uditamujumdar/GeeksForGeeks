//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool check(string& sub){
        int m=sub.size();
        if(m==1) return true;
        int s=0,e=m-1;
        while(s<e){
            if(sub[s]!=sub[e]) return false;
            s++;
            e--;
        }
        return true;
    }
    void read(int i,int& n,const string& s,vector<string>& vp,vector<vector<string>>& ans){
        if(i==n){
            ans.push_back(vp);
        }
        else{
            for(int j=i;j<n;j++){
                string sub=s.substr(i,j-i+1);
                if(check(sub)){
                    vp.push_back(sub);
                    read(j+1,n,s,vp,ans);
                    vp.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> ans;
        vector<string> vp;
        int i=0,n=S.size();
        read(i,n,S,vp,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends