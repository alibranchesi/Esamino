#include <iostream>
#include <string>
#include <cmath>

int main() {
    int a;
    std::cout<<"Enter a number to check if it is even: \n";
    std::cin>>a;
    int b = a%2;

    bool result;

    if(b==0){
        result=true;
    }else{
        result = false;
    }
    std::cout<<std::boolalpha<<result<<'\n';
}