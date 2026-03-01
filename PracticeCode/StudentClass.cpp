#include <iostream>
using namespace std;

// practing on class construction, commenting, and code structure

//class will get and store a string and double and let oyu know if the student is on the deans list.

//Student class
class Student{
    private:
        string name;
        double gpa;
    public:
        Student();
        Student(string n, double g);
        bool isDeanList();
};

//main 
int main(){
    Student s1("Julio", 3.4);
    s1.isDeanList();
}
//student default constructor 
Student::Student(){};

//student default constructor 
Student::Student(string n, double g){
    this->name = n;
    this->gpa = g;
};
//is deans list funtion to check if student is on the deans list or not 
bool Student::isDeanList(){
    if(gpa>=3.5){
        cout << "Dean's List!" << endl;
        return true;
    }
    else{
        cout << "Not on Dean's List!" << endl;
        return false;
    }
};