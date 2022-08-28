// Within this scrap file here i use the main function to call other functions that will perform taskes of interest.
//This is designed to be used for solving leetcode problems, practice other constructs such as maps, classes, structs, ect. 


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;





struct Student{
    string name;
    int age;
    Student *next;
};

void pointTopointer(){
    //within this file here we are going to look at the concept of having a pointer pointing to a pointer that points to a value

    int a = 5;
    int *p1 = &a;
    cout << "Pointer P1's value: " << *p1 << ", and the addres of P1: " << &p1 << ", and the address of a is: " << &a << endl;

    //now we are going to create another pointer to point to p1
    int **p2 = &p1;
    cout << "Pointer P2's value: " << *p2 << ", and the address of P2: " << &p2 << ", and the address of a is still: " << &a << endl;
    cout << "This is expected because the value of p2 is the value stored in p1. But p1 is a pointer, so it must store an address. Thus the value of p2 is the address that p1 points too." << endl;

    cout << "Here is the value of a from P2: " << **p2 << endl;
    cout << "Here is the address of P1 from P2: " << p2 << endl;

}

void StudentLinkedLists(){
    //Within this method we are going to be looking at the idea of linked lists, pointers and such

    //first we are going to create a student object
    Student s1;
    // we can now set values for the different attributes of the struct
    s1.age = 15;
    s1.name = "John Matthews";
    s1.next = NULL;
    cout << s1.age << endl;
    cout << s1.name << endl;

    //now we are going to create a pointer that points to the struct s1
    Student *p1 = &s1;
    cout << "------------" << endl;
    cout << "Address of s1: " << p1 << endl;
    cout << "Address of p1: " << &p1 << endl;
    cout << "Values that p1 are pointing too:"<<endl;
    cout << "   Name: " << p1->name << endl;
    cout << "   Age: " << p1->age << endl; 

    //Now if we were to create a list of students, we could have each student (node) point to the next one withint the list. And if we wanted to traverse through the list, we would use a pointer to point to the pointers pointing to each of the nodes.
    Student s2;
    s2.age = 22;
    s2.name = "Peter Parker";
    s2.next = NULL;

    Student s3;
    s3.age = 11;
    s3.name = "Clark Kent";
    s3.next = NULL;

    //here we are having each node point to the next one;
    s1.next = &s2; // again since we are "pointing", we need to set the addresses
    s2.next = &s3;

    //Now say we wanted to traverse through the list and print out the information. We create a pointer to point to each of the nodes
    Student *printPt = &s1; //we have it point to the address of the head node of the lsit

    while (printPt != NULL){
        cout << "Name: " << printPt->name << ", Age: " << printPt->age << endl;
        printPt = printPt->next;
    }

    delete printPt;
    //now say we wanted to change the age of the last node, we first have to traverse through the list and the change the last node's age
    Student *changeAge = &s1;

    while (changeAge->next != NULL){
        changeAge = changeAge->next;
    }
    cout << "-----------------------------" << endl;
    delete changeAge;


    Student *printPt2 = &s1; //we have it point to the address of the head node of the lsit

    while (printPt2 != NULL){
        cout << "Name: " << printPt2->name << ", Age: " << printPt2->age << endl;
        printPt2 = printPt2->next;
    }

    delete printPt2;


}


void PointersOfLists(){

    int list[5] = {1, 2, 4, 8, 16};

    int *ptr = list;

    int length = sizeof(list)/sizeof(int);
    int n = 0;
    while (n <length){
        cout << *(ptr + n) << endl;
        n++;
    }

    //here we are going to use the pointer to change the value within the list
    n=0;
    while (n < length){
        int tmp = *(ptr + n);
        if (tmp == 8){
            *(ptr+n) = 32;
        }
        
        n++;
    }
    cout << "-------------" << endl;
    n=0;
    while (n <length){
        cout << *(ptr + n) << endl;
        n++;
    }




}


void MergeSortedLists(){
    int nums1[] = {-1, 0, 0, 2, 3, 6, 0, 0, 0};
    int m = 6;
    int nums2[] = {1, 2, 7};
    int n = 3;

    //the idea here is that we are going to be combinine the two lists into nums1, and then performing a sorthing algorithm on nums1.
    if (n==0){

    }
    else if (m == 0){
        nums1[0] = nums2[0];
    }
    else{
        for(int i=n; i>=0; i--){
            nums1[m+i] = nums2[i];
        }

        //from here nums1 has all of the numbers within it. Now we perform a sort on it.
        int tmp = 0;
        for(int i=0; i<m+n; i++){
            for(int j=1; j<m+n; j++){
                if(nums1[j] < nums1[j-1]){
                    tmp = nums1[j];
                    nums1[j] = nums1[j-1];
                    nums1[j-1] = tmp;
                }
            }
        }
    }
    for(int i=0; i<m+n; i++){
        cout << nums1[i] << endl;
    }

}

void WorkingWithMaps(){
    //here i am working with the C++ equivalent of a dictionary, called Maps
    map<string, int>data = {
        {"Matthew",22},
        {"Clara",23},
        {"Andrew",18}
    };

    //cout << data["Matthew"];

    

}


void Palindrome(){
    //within C++ it is possible to strip a pointer of its data type, and then assign it a new data type.
    int x = 121;
    string X = to_string(x);
    bool cond = true;
    int backend = X.length() - 1;
    for(int i=0; i<X.length()/2; i++){
        if(X[i] != X[backend]){
            cond = false;
        }
        backend--;
    }




}


void Vectors(){

    
    vector<int> nums;
    for(int i=0; i<10; i++){
        nums.push_back(i);
    }

    // for(int i=0; i<10; i++){
    //     std::cout << nums[i] << " ";
    // }


    /* Here i am iterating through the vector using the pointer methods */
    auto beginning = nums.begin();
    for(int i=0; i<10; i++){
        std::cout << *(beginning + i) << ' ';
    }


    
    


}


bool comparator(string a, string b){
    return a<b;
}

void Comparing_Strings(){



    string a = "Buchkowski";
    string b = "Miller";
    string c = "Smith";

    // bool cond = a>b;
    // cout << cond;
    // int n=2;
    // string list[n] = {b, a};
    // for(int i=0; i<2; i++){
    //     cout << list[i] << ", ";
    // }
    // cout << "\n";
    // sort(list, list+n, comparator);
    // for(int i=0; i<n; i++){
    //     cout << list[i] << ", ";
    // }

    cout << (a>b) << endl;
    cout << (b>c) << endl;
    cout << (c>a) << endl;


}


void FindMaxNum(){ //Within this method i am going to write some code that will attempt to find the maximum value within an array/vector

    //first lets create our vector
    vector<int> x = {1, 12, 55, 13, 34, -25, 676, 20, 3};

    int max = 0;
    int n = x.size();
    cout << n << endl;
    for(int i=0; i < n; i++){
        if(x[i] > max){
            max = x[i];
        }
    }
    cout << "This is the max value: " << max << endl;




}

void SumOfDigitsOfNum(){
    int x = 123; // we know that the sum of the digits of 404 is 8
    int sum=0;
    while(x != 0){
        int digit = x%10;
        x = x/10;
        sum += digit;
    }
    cout << sum;
}





int IsPrime(int x, int *ptr, int pos){
    int val = 1;
    int step=0;
    while (pos > 0){
        if(x%ptr[step] == 0){
            val = 0;
            break;
        }
        step++;
        pos--;
    }
    return val;
}


void CheckIfPrime(){

    int n=10000, m=2;
    int *arr = new int(m);
    arr[0] = 2;
    arr[1] = 3;
    int pos = 2;
    for(int i=4; i<n; i++){
        if(IsPrime(i, arr, pos)){
            cout<< i << " | " << i << endl;
            arr[pos] = i;
            pos++;
        }
        else{
            cout << i << " | " << endl;
        }
    }
}

int main(){
    //pointTopointer();
    //StudentLinkedLists();
    //PointersOfLists();
    //MergeSortedLists();
    //WorkingWithMaps();
    //Palindrome();
    //Vectors();
    //Comparing_Strings();
    //FindMaxNum();
    //SumOfDigitsOfNum();
    CheckIfPrime();
}