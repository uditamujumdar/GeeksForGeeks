//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool f(vector<int>&nums, int mid, int k){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]/mid);
            if(nums[i]%mid){
                sum++;
            }
        }
        return sum<=k;
    }
    
    int smallestDivisor(vector<int>& nums, int K) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int i=1, j=nums[n-1];
        
        while(i<=j){
            int mid=i+(j-i)/2;
            bool flag=f(nums,mid,K);
            
            if(flag){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return i;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends