#include <bits/stdc++.h>
using namespace std;

string encode(string src){
    string ans = "";
    char prev_ch = src[0];
    int count = 1;

    for (int i = 1; i < src.size(); i++){
        if (src[i] == prev_ch){
            count++;
        }
        else{
            ans += prev_ch + to_string(count);
            prev_ch = src[i];
            count = 1;
        }
    }

    ans += prev_ch + to_string(count);

    return ans;
}