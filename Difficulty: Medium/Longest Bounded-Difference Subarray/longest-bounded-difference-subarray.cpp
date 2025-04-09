//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n=arr.size();
        int i=0, j=0;
        int len=0, start=0;
        multiset<int>st;
        
        while(j<n){
            st.insert(arr[j]);
            
            while(*st.rbegin()-*st.begin()>x){
                st.erase(st.find(arr[i]));
                i++;
            }
            
            int curr=j-i+1;
            if(curr>len){
                len=curr;
                start=i;
            }
            
            j++;
        }
        
        vector<int>ans;
        for(int i=start;i<start+len;i++){
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends