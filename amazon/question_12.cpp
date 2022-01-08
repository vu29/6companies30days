#include <bits/stdc++.h>
using namespace std;

string colName (long long int n){
        
    string str = "";
    
    while(n>0){
        int rem = n%26;
        if(rem == 0){
            str ='Z' + str;
            n = (n/26)-1;
        }
        else{
            str = (char)('A' + (rem-1)) + str;
            n = n/26;
        }
    }
    return str;
}