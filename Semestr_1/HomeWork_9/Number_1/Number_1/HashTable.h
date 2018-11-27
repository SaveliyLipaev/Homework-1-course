#pragma once
#include <string>

struct HashTable;

//function to add a value to a hash table
void add(HashTable *table, const std::string &str);

//returns the address of the selected memory cell of the HashTable structure
HashTable* createHashTable();

//Prints a hash table
void printTable(HashTable *table);

//returns the fill factor of the hash table
float loadFactor(HashTable *table);

//deletes the hash table
void deleteHashTable(HashTable *table);

//returns maximum list length
int maxLength(HashTable *table);

//returns average list length
float averageLength(HashTable *table);

//returns how many times this character set entered the table
int findStr(HashTable *table, std::string &str);