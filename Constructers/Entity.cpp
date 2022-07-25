// Within this file we are going to be looking at constructers. A constructer is a method, within a class entity, that will run automatically when you compile the program. Within this file we are also going to be looking at destructors, which are exactly as constructors in that they run on creation of entity. A destructor runs when you destroy a entity.

// Now the reason that this is of importance is because when you compile a program, parts of your program will actually get executed. An example is if i have a class called Entity, and then within the main method i then create an entity, matthew. The creation of this entity within memory, or later use, will be done for us. If this entity have attributes, say a name and age, these variables will be created within memory, and assigned a random value at compilation. The thing is we might want to specify what that value is when we create a new entity, and that is done with a constructer.

#include <stdio.h>
#include <iostream>

using namespace std;

class Entity
{
    // this entity class will have two attributes. A name and an age.
public:
    float age;
    string name;

    // similar to python where we have a init() method that will initalize that attributes of the class, in cpp we do something similar to that by creating a constructer. A constructer for a class has to have the same name as the class
    Entity()
    {
        age = 0;
        name = "";
    }
};

class Student
{
private:
    /* data */
public:
    Student(string name, int age);
    ~Student(); // this is the syntax for a destructor.
    string Name;
    int Age;
};

Student::Student(string name, int age)
{
    cout << "Student was created" << endl;
    Name = name;
    Age = age;
}

Student::~Student()
{
    cout << "Student has been destroyed" << endl;
}

int main()
{

    // Entity matthew;

    // //here we are showing that we have
    // cout << matthew.age << ", " << matthew.name << endl;
    // matthew.age = 22;
    // matthew.name = "Matthew";
    // cout << matthew.age << ", " << matthew.name << endl;

    Student matthew = Student("Matthew", 22);
    cout << matthew.Name << ", " << matthew.Age << endl;

    

    delete &matthew; // this line is called to destroy the Student obj. In reality any obj created will be destroyed at the end of the current method. In this case we are within the main method, and at the end it will also call the destroy destructor.
    cin.get();
    return 0;
}
