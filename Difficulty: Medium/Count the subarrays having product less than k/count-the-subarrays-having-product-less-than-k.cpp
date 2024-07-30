//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i=0, j=0;
        long long prod=1, cnt=0;
        if(k==0 || k==1){
            return 0;
        }
        
        while(j<n){
            prod*=a[j];
            while(prod>=k && i<n){
                prod/=a[i];
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends