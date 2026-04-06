#include "Args.h"
#include "Args.cpp"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv []){
    try{
        Args args = Args::parse(argc, argv);

        //input / output 
        cout << "INPUT : " << args.input << endl;
        cout << "OUTPUT : " << args.output << endl;

        bool hasFlag = false;
        // flags active 
        cout << "FLAGS : "
        if (args.greyscale){
            cout << "greyscale ";
        }

        if (args.blur){
            cout << "blur ";
        }

        if(args.flipH){
            cout "flip horizontally ";
        }

        if(args.flipV){
            cout << "flip vertically ";
        }

        if(use_brighten){
            cout << "brighten "
        }
        cout  << endl;
        bool hasParms = false;
        cout << "PARAMS : " << endl;

        if(args.brighten != 0){
            cout << "brighten=" << args.brighten << " ";
            hasParms = true;
        }

        if(args.rotate != 0){
            cout << "rotate=" << args.rotate << " ";
            hasParms = true;
        }
        if(!hasParms){
            cout << "none";
        }
        cout << endl;
    }
    catch (exception& e){
        cout << "Error: " << e.what() << endl;
        cout << "Usage: ./imgtool <input_image> <output_image> [options" << endl;
        return 1;
    }
    