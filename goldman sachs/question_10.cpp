#include <bits/stdc++.h>
using namespace std;

// int n -> input size (10M)
vector<int> max10(int n){
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> q;

    int inp;

    for (int i = 1; i <= n; i++){

        // uncomment for user input
        // cin >> inp;
        inp = i;

        if (i < 10){
            q.push(inp);
        }
        else if (!q.empty() && inp > q.top()){
            q.pop();
            q.push(inp);
        }
    }

    while (!q.empty()){
        ans.push_back(q.top());
        q.pop();
    }

    return ans;
}
