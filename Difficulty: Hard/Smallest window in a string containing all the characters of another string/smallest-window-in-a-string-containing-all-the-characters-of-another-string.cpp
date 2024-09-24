//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int> mp(256,0);
        for(int i=0;i<p.size();i++)
        {
          mp[p[i]]++;   
        }
        
        int st=-1;
        int cnt=0;
        int mini = INT_MAX;
        int r=0, l=0;

        while(r<s.size())
        {
            if(mp[s[r]]>0)
            {
                cnt++;
            }
            mp[s[r]]--;
            
            while(cnt==p.size())
            {
                if(r-l+1<mini)
                {
                    mini=r-l+1;
                    st=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0)
                {
                    cnt--;
                    
                }
                l++;
            }
            r++;
        }
        
        return st==-1 ? "-1" : s.substr(st,mini);
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
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends