//This file will check every number up too the limit specified and see if it is a prime number or not. The program only checks odd numbers past 2 since all even 
//numbers are factors of 2. This speeds the program up substantially. chrono time pointers are used to find the time of this programs excecution.


#include <chrono>
#include "Log.h"
#include "Log.cpp"

using namespace std;




int main(){
    chrono::time_point<chrono::system_clock> start, end;

    start =chrono::system_clock::now();

    vector<unsigned int> primes = {2, 3};
    int limit = 10000000;
    for(int i=5; i<limit; i+=2){
        if(IsPrime(i, primes)){
            cout << i << " | " << i << endl;
            primes.push_back(i);
        }
        else{
            cout << i << " | " << endl;
        }
    }

    end = chrono::system_clock::now();

    chrono::duration<double> seconds = end - start;
    cout << seconds.count() << " seconds." << endl;


    return 0;
    
    
    
}       
    

//without even numbers: 25.49 seconds
//with even numbers: 31.065 seconds
