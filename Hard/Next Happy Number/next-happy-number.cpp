//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool check(int n){
        if(n==1||n==7){
            return 1;
        }
        int sum=n, curr=n;
        
        while(sum>9){
            sum=0;
            while(curr>0){
                int d=curr%10;
                sum+=d*d;
                curr/=10;
            }
            if(sum==1){
                return 1;
            }
            curr=sum;
        }
        if(sum==7){
            return 1;
        }
        return 0;
    }
    
    int nextHappy(int N){
        int num=N+1;
        
        while(true){
            if(check(num)){
                return num;
            }
            num++;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends