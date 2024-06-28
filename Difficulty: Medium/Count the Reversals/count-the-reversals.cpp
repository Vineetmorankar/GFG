//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    stack<char> st;
    if(s.size()==0) return 0;
    // your code here
    st.push(s[0]);
    for(int i=1;i<s.size();i++)
    {
        char ch = s[i];
        
        if(!st.empty() && st.top()=='{' && ch=='}')
        {
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }
    
    if(st.size()%2!=0) return -1;
    int count = 0;
    while(!st.empty())
    {
        char ch1 = st.top();
        st.pop();
        char ch2 = st.top();
        st.pop();
        
        if((ch1=='{' && ch2=='{') || (ch1=='}' && ch2=='}'))
        {
            count+=1;
        }
        else if((ch1=='}' && ch2=='{') || (ch1=='{' && ch2=='}'))
        {
            count+=2;
        }
    }
    return count;
}