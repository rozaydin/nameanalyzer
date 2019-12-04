#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

class NameAnalyzer
{

    std::vector<std::string> adjectives;

public:
    bool loadLibrary(std::string path)
    {
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
        return true;
    }

    std::vector<std::string> analyzeName(std::string name)
    {

        std::vector<std::string> result;
        for (char ch : name)
        {
            result.push_back(findAdjective(ch));
        }
        //
        return result;
    }

    std::string findAdjective(char ch)
    {
        //
        for (std::string adj : this->adjectives)
        {
            if (adj.starts_with(ch))
            {
                return adj;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    std::cout << "Input your name for analyzing!" << std::endl;
    NameAnalyzer na;
    na.loadLibrary("./data/adjectives.txt");
    std::vector<std::string> result = na.analyzeName("ridvan");
    for ( std::string letter : result ) {
        std::cout << letter << std::endl;
    }
}