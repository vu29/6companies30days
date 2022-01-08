#include <bits/stdc++.h>
using namespace std;

int longestMountain(vector<int>& arr) {
        if(arr.size()<3)
            return 0;
        
        int ans = 0;
        int n = arr.size();
        for(int i=1;i<n-1;){
            
            // check if it's a peak
            if(arr[i-1] < arr[i] && arr[i+1] < arr[i]){
                int size = 1;
                int j = i;
                // check left
                while(j > 0 && arr[j] > arr[j-1]){
                    size++;
                    j--;
                }
                // right
                while(i < n-1 && arr[i] > arr[i+1]){
                    size++;
                    i++;
                }
                // select max len;
                ans = max(ans,size);
            }
            // if not a peak
            else{
                i++;
            }
        }
        
        return ans;
    }