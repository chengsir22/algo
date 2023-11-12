#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int glen = g.size(), slen = s.size();
        int ret = 0;
        for (int i = 0, j = 0; i < glen && j < slen; i++, j++)
        {
            while (j < slen && g[i] > s[j])
                j++;
            if (j < slen)
            {
                ret++;
            }
        }
        return ret;
    }
};

int main(int, char **)
{
    std::vector<int> a, b;
    a = {1, 2, 3};
    b = {1, 2};
    Solution s;
    cout << s.findContentChildren(a, b) << endl;
}