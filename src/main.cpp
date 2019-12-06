#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory>

class NameAnalyzer {

    // std::unique_ptr<std::unordered_map<std::string, std::vector<std::string>>> orderedAdjectives;

public:
    //
    std::unique_ptr<std::unordered_map<std::string, std::vector<std::string>>>
    orderAdjectives(std::vector<std::string> &adjectives) {

        using itemMap = std::unordered_map<std::string, std::vector<std::string>>;
        std::unique_ptr<itemMap> orderedAdjectives = std::make_unique<itemMap>();
        //
        for (auto &adjective : adjectives) {
            if (adjective.length() > 0) {
                char startChar = adjective[0];
                const std::string key{startChar};
                //
                if (orderedAdjectives->find(key) == orderedAdjectives->end()) {
                    // key not present insert
                    std::pair<std::string, std::vector<std::string>> pair = std::make_pair(key,
                                                                                           std::vector<std::string>{});
                    orderedAdjectives->insert(pair);
                }
                //
                std::vector<std::string> &contents = orderedAdjectives->at(key);
                contents.push_back(adjective);
            }
        }
        //
        return orderedAdjectives;
    };

    std::vector<std::string> loadLibrary(std::string path) {

        std::vector<std::string> adjectives;
        std::ifstream file(path);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                if (!(std::all_of(line.begin(), line.end(), isspace))) {
                    adjectives.push_back(line);
                }
            }
        }
        //
        return adjectives;
    }

    std::vector<std::string> analyzeName(std::string name,  std::unique_ptr<std::unordered_map<std::string, std::vector<std::string>>>& orderedAdjectives) {

        std::vector<std::string> result;
        for (char ch : name) {
            result.push_back(findAdjective(ch, orderedAdjectives));
        }
        //
        return result;
    }

    std::string findAdjective(char ch,
                              std::unique_ptr<std::unordered_map<std::string, std::vector<std::string>>>& orderedAdjectives) {
        std::vector<std::string> &adjectives = orderedAdjectives->at(std::string{ch});
        const int adjectivesSize = adjectives.size();
        int randomIndex = (std::rand() % adjectivesSize);
        std::cout << " randomIndex: " << randomIndex << std::endl;
        return adjectives[randomIndex];
    }

};

int main(int argc, char *argv[]) {

    std::cout << "Input your name for analyzing!" << std::endl;

    NameAnalyzer na;
    auto adjectives = na.loadLibrary("/home/rozaydin/data/adjectives.txt");
    auto orderedAdjectives = na.orderAdjectives(adjectives);

    std::cout << " I am working " << orderedAdjectives->at(std::string{'b'})[0] << std::endl;

    std::vector<std::string> result = na.analyzeName("ugur", orderedAdjectives);
    for (const std::string& letter : result) {
        std::cout << letter << std::endl;
    }
}
