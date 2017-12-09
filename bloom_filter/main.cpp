#include "hashing.h"
#include <iostream>
#define N 10000000000
#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */
#define FIRSTH 37 /* also prime */       
    
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

unsigned hash_func_2(const char* s)
{
   unsigned h = FIRSTH;
   while (*s) {
     h = (h * A) ^ (s[0] * B);
     s++;
   }
   return h;
}



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