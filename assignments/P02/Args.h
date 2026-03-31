#include <iostream>
using namespace std;

struct Args {
    string  input;
    string  output;

    bool grayscale = false;
    bool blur = false;
    bool flipH = false;
    bool flipV = false;

    bool use_brighten = false;
    int brighten = 0;

    bool use_rotate = false;
    int rotate = 0;

    static Args parse(int argc, char** argv[]);
};