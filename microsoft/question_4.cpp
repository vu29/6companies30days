#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> arr, int r, int c)
{
    vector<int> ans;
    int tne = r * c, count = 0;

    int min_r = 0, min_c = 0, max_r = r - 1, max_c = c - 1;

    while (count < tne)
    {

        // top
        for (int i = min_c; i <= max_c && count < tne; i++)
        {
            ans.push_back(arr[min_r][i]);
            count++;
        }

        // right
        for (int i = min_r + 1; i <= max_r && count < tne; i++)
        {
            ans.push_back(arr[i][max_c]);
            count++;
        }

        // bottom
        for (int i = max_c - 1; i >= min_c && count < tne; i--)
        {
            ans.push_back(arr[max_r][i]);
            count++;
        }

        // left
        for (int i = max_r - 1; i >= min_r + 1 && count < tne; i--)
        {
            ans.push_back(arr[i][min_c]);
            count++;
        }
        min_r++;
        min_c++;
        max_r--;
        max_c--;
    }

    return ans;
}