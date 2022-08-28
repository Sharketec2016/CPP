
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