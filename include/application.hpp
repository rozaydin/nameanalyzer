#pragma once
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory>

void sayHello();

extern "C" __attribute__((visibility("default"))) __attribute__((used))
int HelloWorld();

namespace app
{

class NameAnalyzer
{

public:
std::unique_ptr<std::unordered_map<std::string, std::vector<std::string>>>
    orderAdjectives(std::vector<std::string> &adjectives);

std::vector<std::string> loadLibrary(std::string path);

std::vector<std::string> analyzeName(std::string name, std::unique_ptr<std::unordered_map<std::string, std::vector<std::string>>> &orderedAdjectives);

std::string findAdjective(char ch, std::unique_ptr<std::unordered_map<std::string, std::vector<std::string>>> &orderedAdjectives);

};


} // namespace app