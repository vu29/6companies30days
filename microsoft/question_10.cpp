#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(int arr[], int n){
    int ex = 0, inc = arr[0];

    int ex_prev = ex, inc_prev = inc;

    for (int i = 1; i < n; i++)
    {

        ex = max(ex_prev, inc_prev);
        inc = ex_prev + arr[i];

        ex_prev = ex;
        inc_prev = inc;
    }

    return max(inc, ex);
}