#include <iostream>
#include <string>

int main(){
    int a;
    int b;
    std::cout<<"Enter a pair of numbers: \n";
    std::cin>>a>>b;
    if(a>b){
        std::cout<<a<<" is greater than "<<b<<'\n';
    }else{
        std::cout<<b<<" is greater than "<<a<<'\n';
    }
}