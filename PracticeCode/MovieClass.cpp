#include <iostream>
using namespace std;

class Movie{
    private:
        string title;
        string director;
        int year;

    public:
        Movie();
        Movie(string title, string director, int year);
        void isClassic();

};

int main(){
    Movie m1;
    Movie m2("The End", "John Pork", 1999);
    m1.isClassic();
    m2.isClassic();
    return 0;
}

Movie::Movie(){}

Movie::Movie(string title, string director, int year){
    this->title = title;
    this->director = director;
    this->year = year;
}

void Movie::isClassic(){
    if(year < 2000){
        cout <<"This movie is a classic"<< endl;
    }
    else{
        cout << "This movie isnt a classic" << endl;
    }
}
