#include <bits/stdc++.h>
using namespace std;

bool canPair(vector<int> arr, int k){
    if (arr.size() & 1)
        return false;

    unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] % k == 0){
            if (m[0])
                m[0]--;
            else
                m[0]++;
        }
        else{
            int val = arr[i] % k;
            if (m[k - val])
                m[k - val]--;
            else
                m[val]++;
        }
    }

    for (auto i = m.begin(); i != m.end(); i++){
        if (i->second > 0){
            return false;
        }
    }
    return true;
}