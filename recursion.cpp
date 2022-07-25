#include <iostream>

using namespace std;


double func(double num, int count){

    if (count == 0){
        return num;
    }
    else{
        count--;
        return num * func(num, count);

    }
}


int main(){

    double val = 2.2;
    int count = 5;
    cout << "first we started with " << val << "\nNow we have ended up with: " << func(val, count);



}