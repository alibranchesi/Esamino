#include <iostream>
#include <string>
#include <cmath>

void solutions(int a, int b, int c){
    int delta = ((b * b) - (4 * a * c));
    if(delta<0){
        std::cout<<"Impossible\n";
    }else{
    std::cout<<"1st solution: "<<(-b+sqrt(delta))/(2*a)<<'\n';
    std::cout<<"2nd solution: "<<(-b-sqrt(delta))/(2*a)<<'\n';
   }
    }

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    solutions(a,b,c);
}
