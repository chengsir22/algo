#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int len = s.size();
        if (len % 2 == 1)
            return false;

        stack<char> st;

        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '(')
                st.push(')');
            else if (s[i] == '{')
                st.push('}');
            else if (s[i] == '[')
                st.push(']');
            else if (!st.empty() && st.top() == s[i])
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};

int main(int, char **)
{
    string str = "({})[]";
    Solution s;
    cout << s.isValid(str) << endl;
}
