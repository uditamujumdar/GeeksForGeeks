//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int setbits(int n){
        int cnt=0;
        while(n>0){
            cnt+=(n&1);
            n>>=1;
        }
        return cnt;
    }
    string f(int n){
        string s="";
        while(n>0){
            int dig=n&1;
            s.push_back(dig+'0');
            n>>=1;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    int func(string s){
        int ans=0;
        for(auto it: s){
            ans=ans*2+(it-'0');
        }
        return ans;
    }
    
    int minVal(int a, int b) {
        int n=setbits(b);
        int m=setbits(a);
        
        string s=f(a);
        string x=s;
        
        if(n==m){
            return func(x);
        }
        
        if(m>n){
            int diff=m-n;
            for(int i=x.size()-1;i>=0;i--){
                if(diff==0)break;
                if(x[i]=='1'){
                    x[i]='0';
                    diff--;
                }
            }
        }
        
        if(m<n){
            int diff=n-m;
            for(int i=x.size()-1;i>=0;i--){
                if(diff==0)break;
                if(x[i]=='0'){
                    x[i]='1';
                    diff--;
                }
            }
        }
        
        return func(x);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends