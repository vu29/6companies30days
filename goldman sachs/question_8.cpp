#include <bits/stdc++.h>
using namespace std;

int CountWays(string str){
    int mod = 1000000007;

    vector<int> dp(str.size() + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    if (str[0] == '0'){
        return 0;
    }

    for (int i = 1; i < str.size(); i++){
        // dp[len] = no_of_strings
        int len = i + 1;

        // taking single digit
        if (str[i] > '0')
            dp[len] += dp[len - 1] % mod;

        // if 2 dig possible
        if (str[i - 1] == '1' || (str[i - 1] == '2' && str[i] < '7')){
            dp[len] += dp[len - 2] % mod;
        }
    }
    return dp[str.size()] % mod;
}