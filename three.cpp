#include <iostream>
#include <string>

int main(){
    int a;
    int b;
    int c;
    std::cin>>a>>b>>c;
    int result;
    if(a>b && a>c){
        result=a;
    }if(b>a && b>c){
        result=b;
    }if(c>a && c>b){
        result=c;
    }
    std::cout<<result;
}