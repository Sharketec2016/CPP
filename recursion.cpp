#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void BackWardsTriangle(int n, int space, int limit){
    if(n == limit){
        return;
    }
    else{
        cout << string(n, '*');
        cout << string(2*space, ' ');
        cout << string(n, '*') << endl;
        BackWardsTriangle(n+1, space-1, limit);
    } 
}


void RightTriangle(int n, int space){
    if(n==0){
        return;
    }
    else{
        cout << string(n, '*') << string(2*space, ' ') << string(n, '*') << endl;
        RightTriangle(n-1, space+1);
    }
}

// void ProperTriangle(int n, int limit){
//     if(n == limit){
//         return;
//     }
//     else{
//         cout << string(n, '*') << endl;
//         ProperTriangle(n+1, limit);
//     }
// }


int main(){

    int n=0;
    int limit = 9;
    int space = limit-n;
    RightTriangle(limit, n);
    cout << string(space/2, ' ') << " Matthew";
    BackWardsTriangle(0, space, limit+1);
    std::cin.get(); //this is to pause the drawing of the design

    return 0;
}