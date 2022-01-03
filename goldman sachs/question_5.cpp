#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull getNthUglyNo(int n) {
	    vector<ull> dp;
	    dp.push_back(1);
	    n--;
	    int i2 = 0, i3 = 0, i5 = 0;
	    ull mul2 = 2, mul3 = 3, mul5 = 5;
	    
	    while(n--){
	        ull current_val = min(min(mul2,mul3),mul5);
	        dp.push_back(current_val);
	        
	        if(current_val == mul2){
	            mul2 = 2*dp[++i2];
	        }
	        if(current_val == mul3){
	            mul3 = 3*dp[++i3];
	        }
	        if(current_val == mul5){
	            mul5 = 5*dp[++i5];
	        }
	    }
	    return *(dp.end()-1);
	    
	}