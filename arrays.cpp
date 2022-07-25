#include <iostream>
using namespace std;



double cube(int num){
    double result = num * num * num;
    return result;
}

int main(){

    int list[] = {1, 2, 65, 3, 2, 1,6, 3, 45, 22, 33, 23};
    int size = sizeof(list)/sizeof(int);
    for (int i = 0; i < size; i++){
        cout << list[i] << " ";
    }
    cout << "\nLength of the list: " << size << "\n\n";
    

    //now we are going to be creating a list that contains the numbers 0-9 and then printing out the cube of that number
    int list2[10] = {};

    int size2 = sizeof(list2)/sizeof(int);
    for (int i = 0; i < size2; i++)
    {
        list2[i] = i;

    }

    for (int i = 0; i < size2; i++)
    {
        cout << list2[i] << " " << cube(list2[i]) << "\n";
    }

    
    
    
    


}