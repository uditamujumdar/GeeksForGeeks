//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dict, string Pat) {
        vector<string>ans;
        int m=Pat.size();
        
        for(auto it: Dict){
            string s=it;
            int i=0, j=0;
            while(i<s.size() && j<Pat.size()){
                if(s[i]==Pat[j]){
                    i++;
                    j++;
                }
                else{
                    if(s[i]>='A' && s[i]<='Z'){
                        break;
                    }
                    else{
                        i++;
                    }
                }
            }
            if(j==m){
                ans.push_back(s);
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size()==0){
            ans.push_back("-1");
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends