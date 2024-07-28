//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
    int sumSubarrayMins(int n, vector<int> &arr) {
        int left[n], right[n];
 
        stack<pair<int, int> > s1, s2;
 
        for (int i = 0; i < n; ++i){
            int cnt = 1;
 
            while (!s1.empty() && (s1.top().first) > arr[i]) {
                cnt += s1.top().second;
                s1.pop();
            }
 
            s1.push({ arr[i], cnt });
            left[i] = cnt;
        }

        for (int i = n - 1; i >= 0; --i) {
            int cnt = 1;
        
            while (!s2.empty() && (s2.top().first) >= arr[i]) {
                cnt += s2.top().second;
                s2.pop();
            }
 
            s2.push({ arr[i], cnt });
            right[i] = cnt;
        }
 
        int result = 0;
 
   
        for (int i = 0; i < n; ++i)
            result = (result%mod + (arr[i] * left[i] * right[i])%mod);
 
        return result%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends