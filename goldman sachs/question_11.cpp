#include <bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n){
    int *ans = new int[2];

    for (int i = 0; i < n; i++){
        if (arr[abs(arr[i]) - 1] < 0){
            ans[0] = abs(arr[i]);
        }
        else{
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
    }

    for (int i = 0; i < n; i++){
        if (arr[i] > 0)
            ans[1] = i + 1;
    }

    return ans;
}