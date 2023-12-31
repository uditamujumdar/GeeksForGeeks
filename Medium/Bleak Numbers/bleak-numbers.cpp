//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int f(int x){
        int count = 0;
        x--;
        while (x > 0) {
            x = x >> 1;
            count++;
        }
        return count;
    }
    
    int countSetBits(int x){
        unsigned int count = 0;
        while (x) {
            x &= (x - 1);
            count++;
        }
        return count;
    }
 

    int is_bleak(int n){

       for (int x = n - f(n); x < n; x++)
        if (x + countSetBits(x) == n)
            return 0;
 
        return 1;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends