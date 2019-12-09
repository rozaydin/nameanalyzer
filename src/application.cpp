#include "application.hpp"
#include "util.hpp"


void sayHello()
{
    std::cout << "Hello Wordl!";
}

// extern "C" __attribute__((visibility("default"))) __attribute__((used))
int HelloWorld() {
    std::cout<<"Hello World with something!"<< std::endl;
    return 0;
}

// std::unique_ptr<std::unordered_map<std::string, std::vector<std::string>>> orderedAdjectives;

//
std::unique_ptr<std::unordered_map<std::string, std::vector<std::string>>>
app::NameAnalyzer::orderAdjectives(std::vector<std::string> &adjectives)
{

    using itemMap = std::unordered_map<std::string, std::vector<std::string>>;
    std::unique_ptr<itemMap> orderedAdjectives = std::make_unique<itemMap>();
    //
    for (auto &adjective : adjectives)
    {
        if (adjective.length() > 0)
        {
            char startChar = adjective[0];
            const std::string key{startChar};
            //
            if (orderedAdjectives->find(key) == orderedAdjectives->end())
            {
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

std::vector<std::string> app::NameAnalyzer::loadLibrary(std::string path)
{

    std::vector<std::string> adjectives;
    std::ifstream file(path);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            if (!(std::all_of(line.begin(), line.end(), isspace)))
            {
                adjectives.push_back(line);
            }
        }
    }
    //
    return adjectives;
}

std::vector<std::string> app::NameAnalyzer::analyzeName(std::string name, std::unique_ptr<std::unordered_map<std::string, std::vector<std::string>>> &orderedAdjectives)
{

    std::vector<std::string> result;
    for (char ch : name)
    {
        result.push_back(findAdjective(ch, orderedAdjectives));
    }
    //
    return result;
}

std::string app::NameAnalyzer::findAdjective(char ch,
                                             std::unique_ptr<std::unordered_map<std::string, std::vector<std::string>>> &orderedAdjectives)
{
    std::vector<std::string> &adjectives = orderedAdjectives->at(std::string{ch});
    const int adjectivesSize = adjectives.size();
    int randomIndex = util::generateRandomNumber(0, (adjectivesSize - 1));
    return adjectives[randomIndex];
}
