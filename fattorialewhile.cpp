#include <iostream>

int main(){
    int a;
    std::cin>>a;
    int i=1;
    int fact=1;
    while(i<=a){
        fact *=i;
        i++;
    }
    std::cout<<fact;
}