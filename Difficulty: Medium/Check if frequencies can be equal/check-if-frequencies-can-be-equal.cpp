//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    map<char,int>mp;
	   
	   for(auto it:s)
	   {
	       mp[it]++;
	   }
	   vector<int>frq;
	   set<int>st;
	   for(auto it:mp)
	   {
	      frq.push_back(it.second);
	      st.insert(it.second);
	   }
	   if(st.size()==1)return true;
	   
	   if(st.size()>2)return false;
	   
	   sort(frq.begin(),frq.end());
	   int ans=0;
	   int jam=frq[0];
	   set<int>k;
	   for(int i=1;i<frq.size();i++)
	   {
	       ans+=(frq[i]-jam);
	       k.insert(frq[i]);
	   }
	   if(ans>1)
	   {
	       if(k.size()==1 && jam==1)
	       {
	           return true;
	       }
	       return false;
	   }
	   
	   return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends