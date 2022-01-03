#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int k, vector<int> &arr){
    int left = 0, right = 0, min_len = INT_MAX;

    int sum = 0;
    while (right < arr.size()){
        sum += arr[right++];

        while (left <= right && sum >= k){
            int len = right - left;
            min_len = min(min_len, len);
            sum -= arr[left++];
        }
    }

    return min_len == INT_MAX ? 0 : min_len;
}