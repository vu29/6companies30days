#include <bits/stdc++.h>
using namespace std;

vector<string> generate(int n)
{
    vector<string> ans = {"1"};
    n--;

    vector<string> v = {"0", "1"};
    queue<string> q;
    q.push("1");

    while (n)
    {
        string front = q.front();
        q.pop();
        for (auto str : v)
        {
            string curr = front + str;
            ans.push_back(curr);
            q.push(curr);
            n--;
            if (n <= 0)
                break;
        }
    }

    return ans;
}