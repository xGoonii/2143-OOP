#include <iostream>

using namespace std;

class Book{
    private:
        string title;
        string author;
        string IBM;
        int numOfPages;
        int year;  
        double price;

    public:
    Book(); //default constructor
    Book(string title, string author, int numOfPages, int year); // constructor w parameteres
    Book(string title, string author, int year); // constructor w parameteres

    //getters DO return something so they have 
    //a return typebut not parameters
    double getPrice();
    string getTitle();
    string getAuthor();
    string getIBM();
    int getPages();
    int getYear();

    //setters dint return nada but take in a parameter
    void setPrice(double);
    void setTitle(string);
    void setAuthor(string);
    void setIBM(string);
    void setPages(int);
    void setYear(int);


};

int main(){

    return 0;
}