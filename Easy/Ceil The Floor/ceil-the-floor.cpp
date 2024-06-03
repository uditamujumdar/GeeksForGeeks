//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int a[], int n, int x) {
    vector<int>arr;
    for(int i=0;i<n;i++){
        arr.push_back(a[i]);
    }
    sort(arr.begin(),arr.end());
    
    int i=0, j=n-1;
    int ans1=-1,ans2=-1;
    
    while(i<=j){
        int mid=i+(j-i)/2;
       if(arr[mid]<=x){
           ans1=arr[mid];
           i=mid+1;
       }
       else{
           j=mid-1;
       }
    }
    
    i=0,j=n-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid]>=x){
            ans2=arr[mid];
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    
    return {ans1,ans2};
    
}