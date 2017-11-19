#include <iostream>
#include <stdlib.h>
const int TABLE_SIZE = 128;

class LinkedHashEntry {
private:

      std::string key_s;
      int key;
      int value;
      LinkedHashEntry *next;
public:
      LinkedHashEntry(int key, int value) {
            this->key = key;
            this->value = value;
            this->next = NULL;
      }

      LinkedHashEntry(std::string key, int value) {
            this->key_s = key;
            this->value = value;
            this->next = NULL;
      }
 
      std::string getKey_s() {
            return key_s;
      }

      int getKey() {
            return key;
      }


 
      int getValue() {
            return value;
      }
   
 
      void setValue(int value) {
            this->value = value;
      }
 
      LinkedHashEntry *getNext() {
            return next;
      }
 
      void setNext(LinkedHashEntry *next) {
            this->next = next;
      }
};
 
class HashMap {
private:
      LinkedHashEntry **table;
public:
    int hash_val ;
    HashMap() {
            table = new LinkedHashEntry*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL; //içerisi NULL olan bir dizi yaratıyoruz aslında ilk başta.
    }
 
    int get(int key) {
        hash_val = (key % TABLE_SIZE);

        if ( table[hash_val]  == NULL ) {
            return -1;
        }
        else{
            LinkedHashEntry *entry = table[hash_val]; //iterator tarzı bir yapı yaratıyoruz.
            while(entry != NULL &&  entry->getKey() !=key){
                entry = entry->getNext(); //bir sonraki hash objesini point ettiriyoruz.
            }
            if (entry == NULL){
                return -1;
            }
            else{
                return entry->getValue();
            }
        }


    }
 
    void put(int key, int value) {


        hash_val = (key % TABLE_SIZE);
        if (table[hash_val] == NULL){

            table[hash_val] = new LinkedHashEntry(key, value); //NULL ise direkt olarak o yapıyı yaratıyoruz.
        }
        else{
                //yeni bir entry  (kod içerisinde genel olarak entry adının verdiğimiz) instance'ı yaratıyoruz.
                LinkedHashEntry *entry = table[hash_val];
                while( entry->getNext() != NULL){
                    entry = entry->getNext();
                }
                if (entry->getKey() == key){
                    entry->setValue(value);
                }
                else{
                    entry->setNext(new LinkedHashEntry(key, value));
                }

        }

    }

    int hash_for_string (std::string key) {
        int hash_val = 0, len = key.length();
        for(int i=0; i<len; i++) {
            hash_val += key[i];	}
        return hash_val  % TABLE_SIZE;
    }



    void put(std::string key, int value) {
        hash_val = (this->hash_for_string(key));

        if (table[hash_val] == NULL){

            table[hash_val] = new LinkedHashEntry(key, value); //NULL ise direkt olarak o yapıyı yaratıyoruz.
        }
        else{
                //yeni bir entry  (kod içerisinde genel olarak entry adının verdiğimiz) instance'ı yaratıyoruz.
                LinkedHashEntry *entry = table[hash_val];
                while( entry->getNext() != NULL){
                    entry = entry->getNext();
                }
                if (entry->getKey_s() == key){
                    entry->setValue(value);
                }
                else{
                    entry->setNext(new LinkedHashEntry(key, value));
                }

        }
            
        

    }

    int get(std::string key) {
        hash_val = (this->hash_for_string(key));

        if ( table[hash_val]  == NULL ) {
            return -1;
        }
        else{
            LinkedHashEntry *entry = table[hash_val]; //iterator tarzı bir yapı yaratıyoruz.
            while(entry != NULL &&  entry->getKey_s() !=key){
                entry = entry->getNext(); //bir sonraki hash objesini point ettiriyoruz.
            }
            if (entry == NULL){
                return -1;
            }
            else{
                return entry->getValue();
            }
        }


    }
 
  
};





int main(){
    HashMap h1;
    h1.put(1,123);
    h1.put("2",14141);


    std::cout<<h1.get("2");
}