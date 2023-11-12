//
// Created by 鲁红呈 on 2023/10/18.
//

#include <iostream>
#include <string>
#include <regex>
using namespace std;

#if 0
void process(string& str) {
    for (int i = 2; i < str.length(); i++) {
        if (str[i] == str[i - 1] && str[i - 1] == str[i - 2]) {
            str.erase(i, 1);
            i--;
            continue;
        }
        if (i >= 3 && str[i] == str[i - 1] && str[i - 2] == str[i - 3]) {
            str.erase(i, 1);
            i--;
            continue;
        }
    }
}


int main() {
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        process(s);
        cout << s << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
#endif

string replace(string input, string regStr, string rep){
    regex reg(regStr);
    return regex_replace(input, reg, rep);
}
int main(){
    int n;
    cin>>n;
    while(n--){
        string input;
        cin >> input;
        cout << replace(replace(input, "(.)\\1+", "$1$1"), "(.)\\1(.)\\2", "$1$1$2") << endl;
    }
    return 0;
}
