#include<bits/stdc++.h>

int partion(char* nuts, char* bolts, int low, int high){
    
    int nut_pivot = bolts[high];
    int index = low;
    
    for(int i=low;i<=high;i++){
        if(nuts[i] < nut_pivot){
            swap(nuts[i],nuts[index++]);
        }
    }
    
    for(int i=low;i<=high;i++){
        if(nut_pivot == nuts[i]){
            swap(nuts[i],nuts[index]);
        }
    }
    
    int bolt_pivot = nuts[index];
    
    index = low;
    for(int i=low;i<high;i++){
        if(bolts[i] < bolt_pivot){
            swap(bolts[i],bolts[index++]);
        }
    }
    
    for(int i=low;i<=high;i++){
        if(bolt_pivot == bolts[i]){
            swap(bolts[i],bolts[index]);
        }
    }
    
    return index;
    
}

void quicksort(char* nuts, char* bolts, int low, int high){
    if(low < high){
        
        int pi = partion(nuts, bolts, low, high);
        
        quicksort(nuts,bolts,low,pi-1);
        quicksort(nuts,bolts,pi+1,high);
        
    }
}