#include <bits/stdc++.h>
using namespace std;

string printMinNumberForPattern(string str)
{
    int dig = 1;
    stack<string> s;
    string ans = "";

    for (char ch : str){
        if (ch == 'I'){
            // push -> dig++ -> pop out all

            s.push(to_string(dig));
            dig++;
            while (!s.empty()){
                ans += s.top();
                s.pop();
            }
        }
        else if (ch == 'D'){
            // push -> dig++

            s.push(to_string(dig));
            dig++;
        }
    }

    // end of string
    s.push(to_string(dig));
    while (!s.empty()){
        ans += s.top();
        s.pop();
    }

    return ans;
}