//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram

    long long getMaxArea(long long arr[], int n){
    stack<long long> s; 
    
    s.push(-1); 
    long long area = arr[0]; 
    int i = 0; 
    
    vector<long long> left_smaller(n, -1), right_smaller(n, n); 
    while (i < n) { 
        while (!s.empty() && s.top() != -1 
               && arr[s.top()] > arr[i]) { 
            
            right_smaller[s.top()] = i; 
            s.pop(); 
        } 
        if (i > 0 && arr[i] == arr[i - 1]) { 
            
            left_smaller[i] = left_smaller[i - 1]; 
        } 
        else { 
            
            left_smaller[i] = s.top(); 
        } 
        s.push(i); 
        i++; 
    } 
    for (int j = 0; j < n; j++) { 
        
        area = max(area, arr[j] * (right_smaller[j] - left_smaller[j] - 1)); 
    } 
    return area; 
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends