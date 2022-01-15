#include <bits/stdc++.h>
using namespace std;

int util(Node* root, int X, int& count){
    if(!root)
        return 0;
        
    int lSum = util(root->left,X,count);
    int rSum = util(root->right,X,count);
    int currSum = root->data + lSum + rSum;
    
    if(currSum == X){
        count++;
    }
    
    return currSum;
    
}


int countSubtreesWithSumX(Node* root, int X){
    int count = 0;
    util(root,X,count);
    return count;
}