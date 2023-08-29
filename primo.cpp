#include<iostream>
#include<cmath>

int main(){
int myAge;
int votingAge = 18;
std::cout<<"Enter your age: "; 
std::cin>>myAge;
if (myAge >= votingAge) {
  std::cout << "Old enough to vote! \n";
} else {
  std::cout << "Not old enough to vote.\n";
}

}