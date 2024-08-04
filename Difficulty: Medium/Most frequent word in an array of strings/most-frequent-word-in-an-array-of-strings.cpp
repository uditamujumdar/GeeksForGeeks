//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        map<string,int>mp2;
        for(int i=0;i<n;i++){
            if(mp2.find(arr[i])==mp2.end()){
                mp2[arr[i]]=i;
            }
        }
        
        int maxi=-1;
        string s="";
        for(auto it: mp){
            if(it.second>maxi){
                maxi=it.second;
                s=it.first;
            }
            if(it.second==maxi){
                if(mp2[it.first]>mp2[s]){
                    s=it.first;
                }
            }
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends