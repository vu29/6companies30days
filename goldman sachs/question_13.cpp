#include <bits/stdc++.h>
using namespace std;

string repeat(string str, int n){
    string ans = "";
    for (int i = 0; i < n; i++){
        ans += str;
    }
    return ans;
}

string decodedString(string s){
    string ans = "";
    stack<int> int_s;
    stack<char> char_s;

    for (int i = 0; i < s.size(); i++){
        char ch = s[i];
        if (ch == ']'){
            int mul = int_s.top();
            int_s.pop();

            string curr = "";

            while (char_s.top() != '['){
                curr = char_s.top() + curr;
                char_s.pop();
            }
            char_s.pop();
            curr = repeat(curr, mul);

            for (char c : curr){
                char_s.push(c);
            }
        }
        else if (isdigit(ch)){
            if (i > 0 && isdigit(s[i - 1])){
                int val = int_s.top();
                int_s.pop();
                val = 10 * val + (ch - '0');
                int_s.push(val);
            }
            else
                int_s.push((int)ch - '0');
        }
        else{
            char_s.push(ch);
        }
    }

    while (!char_s.empty()){
        ans = char_s.top() + ans;
        char_s.pop();
    }

    return ans;
}