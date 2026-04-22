// Defn. for Inheritance Hierarchies 
#include <iostream>
using namespace std;

class Animal {
protected:
    string name; //This is protected to it is accesible to child class
public:
    Animal(string n) : name(n) { cout << "Animal ctor\n"; } // constuctor 
    ~Animal() { cout << "Animal dtor\n"; } // Destructor runs 
    void eat() { cout << name << " eats.\n"; } // eat method using the protected member "name"  for it to be used 
};

//line below is allowing child class Dog access members in class Animal
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) { cout << "Dog ctor\n"; }  // constuctor
    ~Dog() { cout << "Dog dtor\n"; } // Destructor runs
    void bark() { cout << name << " barks!\n"; }  // name is protected, so OK
};

/*in order for it to work and cout the name it had to used in the child class
it would shoot an error if you tried to 

cout << d.name ---> ERROR 

*/

int main() {
    Dog d("Rex");
    d.eat();   // inherited from Animal
    d.bark();  // defined in Dog
}

/*
Create a Vehicle base class with data brand and method honk(). 
Derive a Car class that adds int doors and method drive(). 
Show the constructor for Car calling the Vehicle constructor.
*/

#include <iostream> 

using namespace std;

class Vehicle {
protected : 
    string brand;
public : 
    Vehicle(string b) : brand(b) {cout << "Vehicle ctor \n";}
    ~Vehicle() {cout << "Vehicle dtor \n";}
    void honk(){ cout << brand << " Honks.\n";}
};

class Car : public Vehicle{
protected:
    int doors;
public :
    Car(string b, int d) : Vehicle(b), doors(d) {cout << "Car ctor\n"; }  
    ~Car() {cout << "Car dtor\n"; }
    void drive() {cout << brand << " with "<< doors << " is driving\n"; }
};

int main(){
    Car one("tesla", 4);
    one.honk();
    one.drive();
    return 0;
}

//---------------------------------------------------------------------------
//ABSTRACT Classes and Pure Virtual Functions 


