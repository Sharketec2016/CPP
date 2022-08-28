/*
    Within this file i decide to write a high school student database. 

*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;
struct Student{

    int age; //age of the student
    string firstname; //name of the student
    string lastname; 
    string classes[5]; //list of classes that a student can take
    int id;
    Student *next;
    
};

char PrintMenu(){
    char opt;
    cout << "#-------Welcome-------#" << endl;
    cout << "Please enter in the option you wish to proceed with." << endl;
    cout << "Display Student Database (a)\nAdd Student to the Database (b)\nCheck if Student is Within the Database (c)\nRemove a Student from the Database (d)\nQuit (q): ";
    cin >> opt;
    cout << "\n\n";
    return opt;
}

void PrintDatabase(Student **head){ //this method is to serve the purpose of printing out the student databse. Since it is a linked list we first need a double pointer and then iterate through the list with this pointer
    Student *step = *head;

    cout << "$$ Student Database $$\n" << endl; 


    while (step){
        cout << "Name: " << step->firstname << " " << step->lastname << endl;
        cout << "Age: " << step->age << endl;
        cout << "Id: " << step->id << endl;
        cout << "Classes: " << step->classes[0];

        int size = sizeof(step->classes) / sizeof(string);
        
        for(int i=1; i<size; i++){
            if(step->classes[i] != ""){
            cout <<  ", " << step->classes[i];
            }
            else{
                break;
            }
        }
        cout << "\n\n";
        step = step->next;
    }
    cout << "$$------------------$$";
    cout << "\n\n\n";

}


bool AddStudent(Student **head, int beginner){
    bool add_cond = true;
    
    string temp_firstname;
    string temp_lastname;
    int new_age;
    string curr_class;
    int new_id;
    int num_of_class;
    Student *new_student = new Student();

    
    
    
    if (beginner) {
        cout << "Please enter the first name of the new student: ";
        cin >> temp_firstname;
        cout << "Please enter the last name of the student: ";
        cin >> temp_lastname;
        cout << "Please enter the age of the new student: ";
        cin >> new_age;
        cout << "Please enter the new students id: ";
        cin >> new_id;
        cout << "Please enter the number of classes the new student is taking: ";
        cin >> num_of_class;
        for(int i=0; i<num_of_class; i++){
            cout << "Please enter the name of class: ";
            cin >> curr_class;
            new_student->classes[i] = curr_class;
        }
        new_student->firstname = temp_firstname;
        new_student->lastname = temp_lastname;
        new_student->id = new_id;
        new_student->next = NULL;
        *head = new_student;

    } else{

    
        Student *step = *head;
    
        while(step->next != NULL){
            step = step->next;
        }

        cout << "Please enter the first name of the new student: ";
        cin >> temp_firstname;
        cout << "Please enter the last name of the new student: ";
        cin >> temp_lastname;
        cout << "Please enter the age of the new student: ";
        cin >> new_age;
        cout << "Please enter the new students id: ";
        cin >> new_id;
        cout << "Please enter the number of classes the new student is taking: ";
        cin >> num_of_class;
        for(int i=0; i<num_of_class; i++){
            cout << "Please enter the name of class: ";
            cin >> curr_class;
            new_student->classes[i] = curr_class;
        }
        new_student->firstname = temp_firstname;
        new_student->lastname = temp_lastname;
        new_student->age = new_age;
        new_student->id = new_id;
        new_student->next = NULL;

        step->next = new_student;


        
    }

    
   

    return add_cond;


}

bool CheckForStudent(Student **head, int check_id, Student &temp_student){

    bool cond = false;

    Student *step = *head;
    while (step) {
        if(step->id == check_id){
            temp_student.age = step->age;
            temp_student.firstname = step->firstname;
            temp_student.lastname = step->lastname;
            int size = sizeof(step->classes) / sizeof(string);
            for(int i=0; i<size; i++){
                if(step->classes[i] != ""){
                    temp_student.classes[i] = step->classes[i];
                }
                else{
                    break;
                }
            }
            cond = true;
            break;
        } else {
            step = step->next;
        }

    }

    return cond;


}


bool RemoveStudent(Student **head, int remove_id){

    bool cond = false;

    Student *step = *head;
    Student *temp = *head;
   


    if(step == NULL){
        return cond;
    } else if (step->next == NULL){
        if(step->id == remove_id){
                *head = NULL;
                cond = true;
        }
    } else {
        if(step->id == remove_id){
            *head = step->next;
            cond = true;
        } else{
            step = step->next;
            while(step){
                if(step->id == remove_id){
                    temp->next = step->next;
                    cond = true;
                    break;
                }
                step = step->next;
                temp = temp->next;
            }
        }

    }



    return cond;
}





int main(){

    bool cond = true;
    char opt;
    Student *head = NULL;

    


    while (cond){
        opt = PrintMenu();
        switch (opt)
        {

        case '\0':
            break;

        case 'q':
            cond = false;
            break;
        
        case 'Q':
            cond = false;
            break;

        case 'a':
            if (head == NULL){ //this here means that our Student Database has not yet been created and thus we need to add a student first.
                cout << "Sorry, but it appears that there are no students within the databse currently. Please try and enter a student into the database.\n\n" << endl;  
                break;              
            }
            else{
                Student **Head = &head;
                PrintDatabase(Head);
                delete(Head);
                break;
            }

        case 'b':
            char second_opt;
            cout << "Do you still wish to enter a new student into the database?\nYes (y) or No (n): ";
            cin >> second_opt;

            switch (second_opt)
            {
            case 'y':
                {
                    
                    if (head == NULL){
                        Student **Head = &head;
                        bool add_cond = AddStudent(Head, 1);
                       
                    }

                    else{
                        Student **Head = &head;
                        bool add_cond = AddStudent(Head, 0);
                        delete(Head);
                        if (add_cond){
                            cout << "Addition of new student was successful" << endl;

                        }
                        else{
                            cout << "**Failure to add the new student. Please try again**" << endl;
                        }
                    }
                }
                
                break;
            
            case 'Y':
                {
                    
                    if (head == NULL){
                        Student **Head = &head;
                        bool add_cond = AddStudent(Head, 1);
                        delete(Head);
                    }

                    else{
                        Student **Head = &head;
                        bool add_cond = AddStudent(Head, 0);
                        delete(Head);
                        if (add_cond){
                            cout << "Addition of new student was successful" << endl;

                        }
                        else{
                            cout << "**Failure to add the new student. Please try again**" << endl;
                        }
                    }
                }
                
                break;


            default:
                break;
            }
            break;

        case 'c':
            if(head == NULL){
                cout << "There are no students currently within this database." << endl;
                break;
            } else {
                Student **Head = &head;
                int check_id;
                cout << "Please enter the id of the student you wish to search for: ";
                cin >> check_id;

                Student temp_student;

                bool doesExist = CheckForStudent(Head, check_id, temp_student);
                
                if (doesExist){

                    cout << "Name: " << temp_student.firstname << " " << temp_student.lastname << endl;
                    cout << "Age: " << temp_student.age << endl;
                    cout << "Id: " << check_id << endl;
                    cout << "Classes: " << temp_student.classes[0];
                    for(int i=1; i<sizeof(temp_student.classes)/sizeof(temp_student.classes[0]); i++){
                        if(temp_student.classes[i] != ""){
                        cout <<  ", " << temp_student.classes[i];
                        }
                        else{
                            break;
                        }
                    }
                    cout << "\n\n";
                } else {
                    cout << "Sorry, but it doesnt appear that the student exists. Please try again with the correct information, or try adding the student into the database." << endl;
                }
            }
            break;

        case 'C':
            if(head == NULL){
                cout << "There are no students currently within this database." << endl;
                break;
            } else {
                Student **Head = &head;
                int check_id;
                cout << "Please enter the id of the student you wish to search for: ";
                cin >> check_id;

                Student temp_student;

                bool doesExist = CheckForStudent(Head, check_id, temp_student);
                
                if (doesExist){

                    cout << "Name: " << temp_student.firstname << " " << temp_student.lastname << endl;
                    cout << "Age: " << temp_student.age << endl;
                    cout << "Id: " << check_id << endl;
                    cout << "Classes: " << temp_student.classes[0];
                    for(int i=1; i<sizeof(temp_student.classes)/sizeof(temp_student.classes[0]); i++){
                        if(temp_student.classes[i] != ""){
                        cout <<  ", " << temp_student.classes[i];
                        }
                        else{
                            break;
                        }
                    }
                    cout << "\n\n";
                } else {
                    cout << "Sorry, but it doesnt appear that the student exists. Please try again with the correct information, or try adding the student into the database." << endl;
                }
            }
            break;


        case 'd':
            if(head == NULL){
                cout << "Sorry, but there are not students within the database to remove." << endl;
                break;
            } 
            else {
                Student **Head = &head;
                int remove_id;
                cout << "Please enter the id of the student you wish to remove: ";
                cin >> remove_id;
                bool cond = RemoveStudent(Head, remove_id);
                delete(Head);

                if(cond){
                    cout << "**Success, Student was removed from Database**" <<endl;
                } else {
                    cout << "**Failure to remove student. Please try again**" << endl;

                }

            }
            break;





        default:
            cout << "Sorry, but it appears that you have entered a incorrect option. Please try again. \n\n" << endl;
            break;
        }
    }



    return 0;
}