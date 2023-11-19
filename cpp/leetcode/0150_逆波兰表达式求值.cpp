//
// Created by 鲁红呈 on 2023/11/15.
//
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int size = tokens.size();
        for(int i=0;i<size;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                if(tokens[i]=="+") st.push(num1+num2);
                if(tokens[i]=="-") st.push(num1-num2);
                if(tokens[i]=="*") st.push(num1*num2);
                if(tokens[i]=="/") st.push(num1/num2);
            }else{
                st.push(stoll(tokens[i]));
            }
        }
        return st.top();
    }
};