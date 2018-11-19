#pragma once
#include <string>

struct HashTable;

//determines the size of the hash table
void constructor(HashTable &set);

//hash function
unsigned long long hashFunction(const std::string &str);

//function to add a value to a hash table
void add(HashTable &set, const std::string str);

//returns the address of the selected memory cell of the HashTable structure
HashTable* createHashTable();

//Prints a hash table
void printTable(HashTable &set);

//returns the fill factor of the hash table
float loadFactor(HashTable &set);

//deletes the hash table
void deleteHashTable(HashTable &table);

//returns maximum list length
int maxLength(HashTable &table);

//returns average list length
float averageLength(HashTable &table);