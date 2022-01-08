#include <bits/stdc++.h>
using namespace std;

int rot_neighbours(vector<vector<int>>& grid, queue<pair<int,int>>& rotten_q ,pair<int,int> org_crd){
        vector<int> dir = {0,1,0,-1,0};
        int r,c, new_rotten = 0;
        
        for(int i=1;i<dir.size();i++){
            r = org_crd.first + dir[i];
            c = org_crd.second + dir[i-1];
            
            if(r < grid.size() && c < grid[0].size() && grid[r][c] == 1){
                grid[r][c] = 2;
                rotten_q.push({r,c});
                new_rotten++;
            }
        }
        
        return new_rotten;
    }


int orangesRotting(vector<vector<int>>& grid) {
        
        int row_size = grid.size(), col_size = grid[0].size();
        queue<pair<int,int>> rotten_q;
        
        int fresh_orange_count = 0;
        
        // find initial rotten and fresh count
        for(int r=0;r<row_size;r++){
            for(int c=0;c<col_size;c++){
                if(grid[r][c] == 2){
                    rotten_q.push({r,c});
                }
                else if(grid[r][c] == 1){
                    fresh_orange_count++;
                }
            }
        }
        
        int mins = 0;
        
        while(!rotten_q.empty()){
            int sz = rotten_q.size();
            while(sz--){
                pair<int,int> orange_crd = rotten_q.front();
                rotten_q.pop();
                
                int x = rot_neighbours(grid,rotten_q,orange_crd);
                fresh_orange_count -= x;
            }
            mins++;
        }
        
        
        if(fresh_orange_count > 0)
            return -1;
        
        return max(0,mins-1);