//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        if(s[0]!='-' && !(s[0]>='0'&&s[0]<='9')){
            return -1;
        }
        for(int i=1;i<s.length();i++){
            if(!(s[i]>='0'&&s[i]<='9')){
                return -1;
            }
        }
        
        return stoi(s);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends