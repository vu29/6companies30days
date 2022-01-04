#include <bits/stdc++.h>
using namespace std;

int child_get_defected_toy(int n,int m,int k){
    if(k-1+m > n){
        return (k-1+m) % n;
    }
    return k-1+m;
}
