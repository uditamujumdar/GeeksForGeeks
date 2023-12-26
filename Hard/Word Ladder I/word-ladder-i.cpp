//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>>q;
        q.push({startWord, 1});
        set<string>st(wordList.begin(), wordList.end());
        st.erase(startWord);
        
        while(!q.empty()){
            string w=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(w==targetWord){
                return steps;
            }
            
            for(int i=0;i<w.size();i++){
                char org=w[i];
                for(char ch='a';ch<='z';ch++){
                    w[i]=ch;
                    if(st.find(w)!=st.end()){
                        st.erase(w);
                        q.push({w,steps+1});
                    }
                }
                w[i]=org;
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends