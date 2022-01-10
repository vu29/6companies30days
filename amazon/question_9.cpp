#include <bits/stdc++.h>
using namespace std;

int isValid(vector<vector<int>> mat){
        
    int n = 9;
    int row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            int val = mat[i][j];
            
            if(val != 0){
                val--; // map 1->0 & so on 
                
                row[i][val]++;
                
                col[j][val]++;
                
                box[3*(i/3)+j/3][val]++;
                
                if(row[i][val] > 1 || col[j][val] > 1 || box[3*(i/3)+j/3][val] > 1)
                    return false;
            }
        }
    }
    
    return true;
    
    }