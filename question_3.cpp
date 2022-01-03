#include <bits/stdc++.h>
using namespace std;

int countSubArrayProductLessThanK(const vector<int> &arr, int n, long long k){

    int count = 0, start = 0, end = 0;
    long long prod = 1;

    while (end < n){
        prod *= arr[end++];

        while (start < end && prod >= k){
            prod /= arr[start++];
        }

        if (prod < k){
            count += end - start;
        }
    }

    return count;
}