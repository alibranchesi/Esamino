#include <iostream>
#include <string>

int main(){
    int a;
    std::cin>>a;
    int sum=0;
    int i=1;
    while(i<=a){
        sum +=i;
        ++i;
    }
    std::cout<<sum;
}