// Defn.

class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) { cout << "Animal ctor\n"; }
    ~Animal() { cout << "Animal dtor\n"; } // Destructor runs 
    void eat() { cout << name << " eats.\n"; }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) { cout << "Dog ctor\n"; }
    ~Dog() { cout << "Dog dtor\n"; } // Destructor runs
    void bark() { cout << name << " barks!\n"; }  // name is protected, so OK
};

int main() {
    Dog d("Rex");
    d.eat();   // inherited from Animal
    d.bark();  // defined in Dog
}