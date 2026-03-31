#include "Args.h"
#include <stdexepct>
#include <iostream>
#include <string>


using namespace std; 

Args args::parse(int argc, char** argv[]){
    Args args;

    if (argc < 3){
        throw runtime_error("missing required arguements");
    }

    args.input = argv[1];
    args.output = argv[2];

    for (int i = 3; i < argc; i++){
        string flag = argv[i];

        if(flag == "--grayscale" || flag == "-g"){
            args.grayscale = true;
        }

        else if (flag == "--blur" || flag == "-l"){
            args.blur = true;
        }
        else if (flag == "--flipH" || flag == "-h"){
            args.flipH = true;
        }
        else if (flag == "--flipV" || flag == "-v"){
            args.flipV = true;
        }
        else if (flag == "--brightness" || flag == "-b"){
            // checks if following value is there. i+1 > argc (cap) means out of bounds
            if (i + 1 >= argc) {
                throw runtime_error("--brighten requires a value");
            }
            string value = argv[++i]; //moves to following value 
            if (value[0]== '-'){
                throw runtime_error ("--brighten expected a value got option " + value);
            }
            int n; 
            try { 
                n = stoi(value);
            } 
            catch (...){
                throw runtime_error("invalid integer for --brightness: " + value):
            }
            if(n < -225 || n > 255) {
                throw runtime_error("brighten must be in [-255, 255]");
            }

            args.use_brighten = true;
            args.brighten = n; 
        }
    
    }

    return args;
}