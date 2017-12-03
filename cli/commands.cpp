#include<iostream>
#include<stdlib.h>

template <class T>
T set(T key,T val){


    T result ;
    result = key + val;
    return result;

}

int main(){

    std::string test="ali";
    std::string test_2 = "veli";
    std::string result ;
    int result2;
    result = set <std::string>(test,test_2);   
    result2 = set <int>(1,2);   

    std::cout<<result2;

}