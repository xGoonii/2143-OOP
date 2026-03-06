#include <iostream>
using namespace std;

class dPoint{
    private:
        int x;
        int y;
        int z;
        string color;

    public:
        dPoint();
        dPoint(int x, int y, int z, string color);
        dPoint(int x, int y, int z);

        int getX();
        int getY();
        int getZ();
        string getColor();

        void setX(int);
        void setY(int);
        void setZ(int);
        void setColor(string);

        void move2D(int x, int y);
        void moveUp(int y);

        dPoint operator+ (dPoint &rhs);
    };
    dPoint operator+ (dPoint rhs){
            dPoint temp;
            temp.x = x + rhs.x;
            temp.y = y + rhs.y;
            temp.z = z + rhs.z;
            return temp;
    }


int main(){
    dPoint one();
    dPoint two(3,3,3);
    one + two = dPoint three
    return 0;
}

dPoint::dPoint(){
    x = 0;
    y = 0;
    z = 0;
}
dPoint::dPoint(int xrhs, int yrhs, int zrhs, string colorrhs){
    x = xrhs;
    y = yrhs;
    z = zrhs;
    color = colorrhs;
}

dPoint::dPoint(int x, int y, int z)

