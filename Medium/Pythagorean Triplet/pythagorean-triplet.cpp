//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    int maxi = 0;
 
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
        }

        int hash[maxi + 1] = { 0 };

        for (int i = 0; i < n; i++)
            hash[arr[i]]++;
 
        for (int i = 1; i < maxi + 1; i++) {
        
            if (hash[i] == 0)
                continue;
 
        for (int j = 1; j < maxi + 1; j++) {

            if ((i == j && hash[i] == 1) || hash[j] == 0)
                continue;
 
            int val = sqrt(i * i + j * j);
 
            if ((val * val) != (i * i + j * j))
                continue;
 
            if (val > maxi)
                continue;

            if (hash[val]) {
                return true;
            }
        }
    }
    return false;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends