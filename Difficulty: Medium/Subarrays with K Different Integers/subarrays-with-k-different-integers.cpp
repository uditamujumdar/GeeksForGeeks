//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(vector<int>& arr, int k){
        int i=0, j=0;
        int N=arr.size();
        unordered_map<int,int>mp;
        int ans=0;
        
        while(j<N){
            mp[arr[j]]++;
            
            while(i<=j && mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    
    int subarrayCount(vector<int> &arr, int N, int k) {
        return f(arr,k)-f(arr,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends