// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

queue<char> words;
stack<char> word_stack;
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int len = S.length();
        for(int i=len-1;i>=0;i--)
        {
            if(S[i]=='.')
            {
                while(!words.empty())
                {
                    char letter=words.front();
                    words.pop();
                    word_stack.push(letter);
                }
                word_stack.push('.');
            }
            else
            {
                words.push(S[i]);
            }
        }
        string reversed_string="";
        char first_letter=words.front();
        words.pop();
        reversed_string+=first_letter;
        while(!word_stack.empty())
        {
            char letter=word_stack.top(); 
            word_stack.pop();
            reversed_string+=letter;
        }
        reverse(reversed_string.begin(),reversed_string.end());
        return reversed_string;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends