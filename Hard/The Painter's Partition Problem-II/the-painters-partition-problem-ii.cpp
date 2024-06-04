//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
#define ll long long
class Solution
{
  public:
    ll f(vector<ll>& nums, ll maxsum){
        ll sum=0,x=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=maxsum){
                sum+=nums[i];
            }
            else{
                x++;
                sum=nums[i];
            }
        }
        return x;
    }
    
    long long minTime(int a[], int n, int k){
        vector<ll>arr;
        for(int i=0;i<n;i++){
            arr.push_back(a[i]);
        }
        ll i=*max_element(arr.begin(), arr.end());
        ll j=accumulate(arr.begin(), arr.end(),0ll);

        while(i<=j){
            ll mid=i+(j-i)/2;
            ll flag=f(arr, mid);

            if(flag>k){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return i;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends