## Problem 2 solution

```cpp
class Player {
    private: 
        string name; // priv date members
        int score;
        int level;
    public: 
        Player(); // default constructor 
        Player(string n); // extra constructors 
        Player(int lvl); // extra constructors 
        Player(string n, int lvl);
        void setScore (int s);
        void levelUp();
        int getScore();
};

int main(){

}

Player::Player(){
    name = "";
    level = 1;
    score = 0;
}

Player::Player(string n){
    name = n;
    level = 1;
    score = 0;
}
Player::Player(int lvl){
    name = "";
    level = lvl;
    score = 0;
}
Player::Player(string n, int lvl){
    name = n;
    level = lvl;
    score = 0;
}
// setters and getters 
void Player::setScore (int s){
    score = s;
}
void Player::levelUp(){
    level ++;
}
int Player::getScore(){
    return score;
}
```