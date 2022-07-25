/* Within this file i am exploring the different types of preprocessing stuff in cpp
    
    It should be noted that typically, defined Macros are usually written using Uppercase Lettered words/phases. This allows for easier seperation of pre-processor Macros and realtime defines variables.
*/

#include <iostream>

#define COUNTRY "USA" 
// this here is a preprocessing macro. It will be compiled/saved in memory when we compile the code, and not on execution. It will replace all references to COUNTRY with the string "USA"


//here i am using the \ character to show that you can define WELCOME on multiple lines
#define WELCOME "Hello World,\
Welcome."


#define MULTIPLY(f1, f2) f1 * f2





int main(){

    //std::cout << "I am living within the country " << COUNTRY;
    std::cout << WELCOME << std::endl;
    std::cout << "2 * 6 = " << MULTIPLY(2, 6) << std::endl;
    
    
    
    return 0;
}





