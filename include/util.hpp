#pragma once
//
#include <string>
#include <random>



namespace util
{
    std::random_device rDev;
    auto seed = rDev();
    std::mt19937 generator(seed);
    

    static int generateRandomNumber(int start, int end) 
    {    
        std::uniform_int_distribution<std::mt19937::result_type> dist(start,end);
        return dist(generator);
    }


}; // namespace na