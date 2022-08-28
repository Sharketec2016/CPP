#include <iostream>
#include <vector>


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
