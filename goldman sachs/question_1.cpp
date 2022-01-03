#include <bits/stdc++.h>
using namespace std;

vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<map<char,int>,vector<string>> big_map;
        
        
        for(string str : string_list){
            map<char,int> freq_map;
            
            for(char ch : str){
                freq_map[ch]++;
            }
            big_map[freq_map].push_back(str);
        }
        
        vector<vector<string>> ans;
        
        for(auto itr = big_map.begin();itr!=big_map.end();itr++){
            if(!itr->second.empty()){
                ans.push_back(itr->second);
            }
        }
        
        return ans;
}