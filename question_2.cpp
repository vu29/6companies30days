#include <bits/stdc++.h>
using namespace std;

int doOverlap(int l1[], int r1[], int l2[], int r2[]){
    int xa1 = l1[0], xa2 = r1[0];
    int ya1 = r1[1], ya2 = l1[1];

    int xb1 = l2[0], xb2 = r2[0];
    int yb1 = r2[1], yb2 = l2[1];

    // x-axis check
    if (xa2 < xb1 || xb2 < xa1){
        return 0;
    }

    // y-axis check
    if (ya1 > yb2 || yb1 > ya2){
        return 0;
    }

    return 1;
}