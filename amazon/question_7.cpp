#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A){
		    
		    vector<int> freq(26,0);
		    vector<char> ch_vec;
		    
		    string ans = "";
		    
		    for(int i=0;i<A.size();i++){
		        // char from incoming stream
		        char ch = A[i];
		        
		        if(freq[ch-'a'] == 0){
		            ch_vec.push_back(ch);
		        }
		        
		        freq[ch-'a']++;
		        
		        int pt = 0;
		        
		        while(pt < ch_vec.size() && freq[ch_vec[pt]-'a'] > 1){
		            pt++;
		        }
		        
		        
		        if(pt == ch_vec.size()){
		            ans += '#';
		        }
		        else{
		            ans += ch_vec[pt];
		        }
		    }
		  
		  
		    return ans;
		}