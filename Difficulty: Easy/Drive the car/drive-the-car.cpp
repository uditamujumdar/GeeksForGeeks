//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
        long long required(long long arr[], long long n, long long k) {
            long long ans=0;
            sort(arr,arr+n);
            if(k>=arr[n-1]){
                return -1;
            }
            for(int i=0;i<n;i++){
                if(arr[i]>k){
                    ans+=(arr[i]-k);
                    k+=(arr[i]-k);
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long arr[n];
        for (long long i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        cout << ob.required(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends