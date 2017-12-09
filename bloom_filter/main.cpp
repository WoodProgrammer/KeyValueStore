#include "hashing.h"
#include <iostream>
#define N 10000000000
          
    
bool *sieve = new bool[N];
int hash_func_1(char *key)
{
    int hash, i;
    for(hash = i = 0; i < strlen(key); ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash%(6753);
}

bool get_from_bloom ( char *instance) {
    unsigned index = hash_func_1(instance);
    return sieve[index];

}
void set_to_bloom ( char *instance) {
    unsigned index = hash_func_1(instance);
    sieve[index] = true   ;
}

int main(){
    set_to_bloom("asdc");
    std::cout<<get_from_bloom("asdc");
}