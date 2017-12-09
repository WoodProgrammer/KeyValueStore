#include "hashing.h"
#include <iostream>
#define N 10000000000
    

bool *sieve = new bool[N];


bool get_from_bloom ( char *str_instance) {
    unsigned index = hash_func_1(str_instance);
    unsigned index2 = hash_func_2(str_instance);

    if (sieve[index] == true && sieve[index2] == true){
        return true;
    }else{
        return false;
    }

}
void set_to_bloom ( char *str_instance) {
    unsigned index = hash_func_1(str_instance);
    unsigned index2 = hash_func_2(str_instance);

    sieve[index] = true   ;
    sieve[index2] = true   ;
}




int main(){
    set_to_bloom("asdasdasdd");
    std::cout<<get_from_bloom("asdasdadd");
}