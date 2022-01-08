#include <bits/stdc++.h>
using namespace std;

void linkdelete(struct Node  *head, int M, int N){
        Node* temp = head;
        while(temp){
            for(int i=0;i<M-1 && temp;i++){
                temp = temp->next;
            }
            
            if(!temp)
                return;
    
            Node* link = temp;
            
            for(int i=0;i<=N && temp;i++){
                temp = temp->next;
            }
            
            
            link->next = temp;
        }
    }