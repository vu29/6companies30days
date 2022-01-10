#include <bits/stdc++.h>
using namespace std;

//Function to serialize a tree and return a list containing nodes of tree.
vector<int> serialize(Node *root){
    vector<int> ans;
    queue<Node*> q;
    
    q.push(root);
    
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        
        if(current == NULL)
            ans.push_back(-1);
        else{
            ans.push_back(current->data);
            
            q.push(current->left);
            q.push(current->right);
        }
    }
    
    return ans;
    
}

//Function to deserialize a list and construct the tree.
Node * deSerialize(vector<int> &arr)
{
    
    if(arr.size() == 0)
        return NULL;
    
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    
    //pushing root
    q.push(root);
    
    int i = 0;
    while(!q.empty()){
        Node* n = q.front();
        q.pop();
        int lc_data = arr[++i];
        
        if(lc_data != -1){
            n->left = new Node(lc_data);
            q.push(n->left);
        }
        
        int rc_data = arr[++i];
        
        if(rc_data != -1){
            n->right = new Node(rc_data);
            q.push(n->right);
        }
    }
    return root;   
}