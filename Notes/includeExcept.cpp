#include <iostream>
#include <stdexcept> //needed lib for any of the keywords to work

int main(){

    return 0
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
    }