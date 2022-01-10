#include <bits/stdc++.h>
using namespace std;

int minTime(Node* root, int target){
        
        // => storing parents 
        
        // <node,parent>
        unordered_map<Node*,Node*> parent_map;
        queue<Node*> q;
        
        q.push(root);
        parent_map[root] = NULL;
        
        Node* target_node;
        
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
            
            if(n->data == target)
                target_node = n;
            
            if(n->left){
                parent_map[n->left] = n;
                q.push(n->left);
            }
            
            if(n->right){
                parent_map[n->right] = n;
                q.push(n->right);
            }
        }
        
        // => burning the tree
        unordered_set<Node*> visited;
        
        int minute = 0;
        
        q.push(target_node);
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
            
                Node* current = q.front();
                
                q.pop();
                
                Node *left = current->left, *right = current->right, *parent = parent_map[current];
                
                if(left && visited.count(left) == 0){
                    visited.insert(left);
                    q.push(left);
                }
                
                if(right && visited.count(right) == 0){
                    visited.insert(right);
                    q.push(right);
                }
                
                if(parent && visited.count(parent) == 0){
                    visited.insert(parent);
                    q.push(parent);
                }
                
            }
            
            minute++;
        }
        
        return minute-1;
    }