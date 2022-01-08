#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        if(k == 1)
            return arr;
            
        vector<int> ans;
        vector<int> nge(n);
        stack<int> s;
        
        nge[n-1] = n;
        s.push(n-1);
        
        // find nge
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && arr[i] >= arr[s.top()]){
                s.pop();
            }    
            nge[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        int j = 0;
        //find max of k-sized window starting from 1
        for(int i=0;i<n-k+1;i++){
            if(j < i){
                j = i;
            }
            
            while(nge[j] < i + k){
                j = nge[j];
            }
            ans.push_back(arr[j]);
        }
        
        return ans;
    }