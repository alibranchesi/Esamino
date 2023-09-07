#include <iostream>

class Player
{
    int x, y;
    int speed_;

    public:
    Player (int posx, int posy, int speed): x{posx}, y{posy}, speed_{speed} {}
    double posx(){return x;}
    double posy(){return y;}
    double speed(){return speed_;}

    void Move(int xa, int ya){
        x+=xa*speed_;
        y+=ya*speed_;

    }
};

int main(){
    Player player(5,4,3);
}