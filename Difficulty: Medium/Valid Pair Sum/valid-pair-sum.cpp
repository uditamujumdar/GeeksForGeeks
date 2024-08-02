//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++


class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
    	 long long ans=0;
    	 sort(a,a+n);
    	 for(int i=0;i<n;i++){
    	     if(a[i]<=0)continue;
    	     
    	     int ind=lower_bound(a,a+n,-a[i]+1)-a;
    	     ans+=(i-ind);
    	 }
    	 return ans;
    }   
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	}
	return 0; 
} 


// } Driver Code Ends