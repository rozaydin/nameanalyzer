#include <iostream>
#include <string>
#include <vector>
#include "application.hpp"


int main(int argc, char *argv[]) {

    app::NameAnalyzer na;
    auto adjectives = na.loadLibrary("./data/adjectives.txt");
    auto orderedAdjectives = na.orderAdjectives(adjectives);

    const std::string name {"ugur"};
    std::cout << "Analyzng name: " << name << std::endl;
    std::vector<std::string> result = na.analyzeName(name, orderedAdjectives);
    for (const std::string& letter : result) {
        std::cout << letter << std::endl;
    }
}
