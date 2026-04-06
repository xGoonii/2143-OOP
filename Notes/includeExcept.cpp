#include <iostream>
#include <stdexcept> //needed lib for any of the keywords to work

using namespace std;

/* Think of the code like this TRY (your code) 
IF error happens Throw an error message. 
when an error message is throw something has to catch it(the end)
The catch is what is displayed along with the error.

The "e.what()" is the message that is thrown*/


int main(){
    try{
        int age;

        cout << "enter your age ";
        cin >> age;

        if(age<0){
            throw runtime_error("Age cannot be negative!!");
        }

        if(age>122){
            throw runtime_error("Nice try, you are not the oldest person to ever live");
        }
        cout << "Your age is : " << age << endl;
    }
    catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }
return 0;
}

/*The reason for this is telling your compiler to do something else INSTEAD of crashing when an error occurs 
you can tell it to do something else like send an error message. syntax looks like -->

try{
        insert code first 

        then enter something like,

        if(!file){
        throw runtime_error("failed to open message")
        } 
        okay, file opened. Now what? We use the file 
    }
catch(exception& e) {  
        cout << "Error: " << e.what() << endl;
    }*/ 


