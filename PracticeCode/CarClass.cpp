#include <iostream>
using namespace std;
/* more practice code working on using terminal to run and push code to repo
through codespace*/
class Car{
    private:
        string make;
        string model;
        int year;
        
    public:
    Car();
    Car(string make, string model, int year);
    void getAge();

};

int main(){
    Car c1("Audi", "A4", 2014);
    c1.getAge();
    return 0;
}

Car::Car(){}

Car::Car(string make, string model, int year){
    this->make = make;
    this->model = model;
    this->year = year;
}

void Car::getAge(){
    int currentYear = 2026;
    cout << "The make of your car is " << make << endl;
    cout << "The model of your car is " << model << endl;
    cout << "The year of your car is " << year << endl;
    cout << "Your car is " << currentYear - year << " years old!" << endl;
}