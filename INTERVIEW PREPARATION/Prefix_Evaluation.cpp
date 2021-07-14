#include<bits/stdc++.h>
#include<stack>
#include<math.h>
using namespace std;

int prefixEvaluation(string s)            //function to evaluate the prefix expression
{
    stack<int> st;                        //initializing stack
    for(int i=s.length()-1;i>=0;i--)      //As it is prefix operation , evaluation will start from end of string
    {
        if(s[i]>='0' && s[i]<='9')        //if the value is an integer then push it into stack
        {
            st.push(s[i]-'0');            //s[i]-'0' will convert string to corresponding integer ascii
        }
        else
        {
            int op1 = st.top();           //retreiving the first operand from stack
            st.pop();                     //popping it out to get the next operand
            int op2 = st.top();           //retreiving the second operand from stack
            st.pop();                     //popping it out

            switch (s[i])                 //checking which operarton needs to be performed
            {
            case '+':                     //if it is '+' then do addition
                st.push(op1+op2);
                break;

            case '-':                     //if it is '-' then do subtraction
                st.push(op1-op2);
                break;

            case '*':                     //if it is '*' then do multiplication
                st.push(op1*op2);
                break;

            case '/':                     //if it is '/' then do division
                st.push(op1/op2);
                break;

            case '^':                     //if it is '^' then do exponent
                st.push(pow(op1,op2));
                break;
            
            default:
                break;
            }
        }
    }
    return st.top();          //returning the top because at the end there will be only one value which will be the output
}
int main()
{
    cout<<prefixEvaluation("-+7*45+20")<<endl;
    return 0;
}