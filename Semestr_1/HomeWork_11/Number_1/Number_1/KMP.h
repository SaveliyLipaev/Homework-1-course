#pragma once
#include <string>
#include <fstream>

//takes a pointer to the file and the substring to be found,
//returns the place in the file where the given string is first encountered
int find(std::ifstream &file, const std::string &prototype);