#include <iostream>
#include <string>
#include <vector>
#include "application.hpp"


int main(int argc, char *argv[]) {

    std::cout << "Input your name for analyzing!" << std::endl;

    app::NameAnalyzer na;
    auto adjectives = na.loadLibrary("./data/adjectives.txt");
    auto orderedAdjectives = na.orderAdjectives(adjectives);

    std::cout << " I am working " << orderedAdjectives->at(std::string{'b'})[0] << std::endl;

    std::vector<std::string> result = na.analyzeName("ugur", orderedAdjectives);
    for (const std::string& letter : result) {
        std::cout << letter << std::endl;
    }
}
