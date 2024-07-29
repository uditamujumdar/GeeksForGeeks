//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    int f(vector<int>& temp, int num){
        int ind=-1;
        int i=0, j=temp.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(temp[mid]==num){
                ind=mid;
                j=mid-1;
            }
            else if(temp[mid]<num){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ind;
    }
    
    vector<int> constructLowerArray(vector<int> &arr) {
        int n=arr.size();
        vector<int>ans, temp;
        for(auto it: arr){
            temp.push_back(it);
        }
        sort(temp.begin(), temp.end());
        for(int i=0;i<n;i++){
            int ind=f(temp, arr[i]);
            ans.push_back(ind);
            temp.erase(temp.begin()+ind);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends