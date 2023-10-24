//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   
    int palindromicPartition(string str)
    {
        // code here
        
        
    // Get the length of the string
    int n = str.length();

    int C[n][n];
 
    // P[i][j] = true if substring str[i..j] is palindrome,
    // else false
    bool P[n][n];
 
    // Note that C[i][j] is 0 if P[i][j] is true
 
    // Every substring of length 1 is a palindrome
    for (int i = 0; i < n; i++) {
        P[i][i] = true;
        C[i][i] = 0;
    }

    for (int L = 2; L <= n; L++) {
 
        // For substring of length L, set
        // different possible starting indexes
        for (int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1; // Set ending index
 
            // If L is 2, then we just need to
            // compare two characters. Else
            // need to check two corner characters
            // and value of P[i+1][j-1]
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j]
                    = (str[i] == str[j]) && P[i + 1][j - 1];
 
            // IF str[i..j] is palindrome, then C[i][j] is 0
            if (P[i][j] == true)
                C[i][j] = 0;
            else {
 
                // Make a cut at every possible
                // location starting from i to j,
                // and get the minimum cost cut.
                C[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                    C[i][j] = min(
                        C[i][j], C[i][k] + C[k + 1][j] + 1);
            }
        }
    }
 
    // Return the min cut value for
    // complete string. i.e., str[0..n-1]
    return C[0][n - 1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends