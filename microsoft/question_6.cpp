#include <bits/stdc++.h>
using namespace std;

void util(int *arr, int N, vector<vector<char>> &alpha, vector<string> &ans, string str, int i)
{
    if (i == N)
    {
        ans.push_back(str);
        return;
    }

    for (char ch : alpha[arr[i]])
    {
        util(arr, N, alpha, ans, str + ch, i + 1);
    }
}

vector<string> possibleWords(int a[], int N)
{

    // BETTER OPTION  : should have used switch case in the util function

    vector<vector<char>> alpha(10);
    alpha[2] = {'a', 'b', 'c'};
    alpha[3] = {'d', 'e', 'f'};
    alpha[4] = {'g', 'h', 'i'};
    alpha[5] = {'j', 'k', 'l'};
    alpha[6] = {'m', 'n', 'o'};
    alpha[7] = {'p', 'q', 'r', 's'};
    alpha[8] = {'t', 'u', 'v'};
    alpha[9] = {'w', 'x', 'y', 'z'};

    vector<string> ans;

    util(a, N, alpha, ans, "", 0);

    return ans;
}