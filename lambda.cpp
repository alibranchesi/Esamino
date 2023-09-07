#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func){
    for(int value:values)
    func(value);
}

int main(){
    std::vector<int> values={1,5,4,2,3};
    int a=5;
    auto lambda=[&a](int value){std::cout<<"Value: "<<value<<std::endl;};
    ForEach(values, lambda);

}