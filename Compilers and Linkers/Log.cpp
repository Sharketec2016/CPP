#include <iostream>
#include <vector>


void Log(auto* message){
    std::cout << message << std::endl;
}

int Multiply(int a, int b){

    int result = a*b;
    return result;
}




int IsPrime(int x, auto primes){
    int cond = 1;
    for(int i=0; i<primes.size(); i++){
        if(x%primes[i] == 0){
            cond = 0;
            break;
        }
    }
    return cond;
}
