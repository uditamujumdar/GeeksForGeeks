//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    int ans=0;
	    for(int i=0;i<s.length();i++){
	        if(s[i]=='1'){
	            if(i&1){
	                ans+=2;
	            }
	            else{
	                ans+=1;
	            }
	        }
	    }
	    return ans%3==0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends