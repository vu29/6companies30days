#include <bits/stdc++.h>
using namespace std;

int number_of_sq_in_nxn(int n){
    if(n < 0)
        return 0;
    
    return n*(n+1)*(2*n+1)/6;
}
