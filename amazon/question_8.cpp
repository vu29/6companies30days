#include <bits/stdc++.h>
using namespace std;

long long countWays(int m){
    long long res[m + 1];
    res[0] = 1;
    res[1] = 1;
    
    for(int i = 2; i <= m; i++){
        res[i] = (res[i-2] + 1);
    }
    
    return res[m];
}