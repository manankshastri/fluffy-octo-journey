#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name{};
    int age{};
    virtual void getData() = 0;
    virtual void putData() = 0;

};

class Professor : public Person {
private:
    int publications{};
    static int id;

public:

    void getData() override {
        cin>>name>>age>>publications;
    }

    void putData() override {
        cout<<name<<" "<<age<<" "<<publications<<" "<<id++<<endl;
    }
};

class Student : public Person {
private:
    int marks[6]{};
    static int id;

public:
    int sum = 0;

    void getData() override {
        cin>>name>>age;
        for (int & mark : marks) {
            cin >> mark;
        }
    }

    void putData() override {

        for (int &mark : marks) {
            sum += mark;
        }

        cout<<name<<" "<<age<<" "<<sum<<" "<<id++<<endl;
    }
};

int Student :: id = 1;
int Professor :: id = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
	
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getData(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putData(); // Print the required output for each object.

    return 0;

}


/*
 i/p :
    4
    1
    Walter 56 99
    2
    Jesse 18 50 48 97 76 34 98
    2
    Pinkman 22 10 12 0 18 45 50
    1
    White 58 87

 o/p:
    Walter 56 99 1
    Jesse 18 403 1
    Pinkman 22 135 2
    White 58 87 2
 */