#include <iostream>
#include <string>

int pow(int a, int b){
    int pow=1;
    int i=1;
    while(i<=b){
        pow *=a;
        ++i;
    }
    return pow;

}

int main(){
    int a;
    int b;
    std::cin>>a>>b;
    int result=pow(a,b);
    std::cout<<result;
}