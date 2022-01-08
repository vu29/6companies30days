#include <bits/stdc++.h>
using namespace std;
// Function to find maximum of each subarray of size k.
vector<int> max_of_subarrays(int *arr, int n, int k){

    if (k == 1)
        return vector<int>(arr, arr + n);

    vector<int> nge(n);
    stack<int> s;
    vector<int> ans;

    // find nge
    for (int i = n - 1; i >= 0; i--){

        while (!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }

        nge[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // find max elemnet in window of size k
    int j = 0;
    for (int i = 0; i < n - k + 1; i++){
        if (j < i)
            j = i;

        while (nge[j] < i + k){
            j = nge[j];
        }

        ans.push_back(arr[j]);
    }

    return ans;
}