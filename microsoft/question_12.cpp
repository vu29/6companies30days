#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    int n = arr.size();

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int st = j + 1, end = n - 1;
            while (st < end)
            {
                int sum = arr[i] + arr[j] + arr[st] + arr[end];
                if (sum > k)
                {
                    end--;
                }
                else if (sum < k)
                {
                    st++;
                }
                else
                {
                    vector<int> curr = {arr[i], arr[j], arr[st], arr[end]};
                    ans.push_back(curr);

                    while (st < end && arr[st] == curr[2])
                        st++;

                    while (st < end && arr[end] == curr[3])
                        end--;
                }
            }

            // if arr[j+1] == arr[j] dont concider arr[j+1]
            while (j + 1 < n && arr[j + 1] == arr[j])
                j++;
        }
        // if arr[i+1] == arr[i] dont concider arr[i+1]
        while (i + 1 < n && arr[i + 1] == arr[i])
            i++;
    }

    return ans;
}