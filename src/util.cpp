#include "util.hpp"

namespace util
{
std::random_device rDev;
auto seed = rDev();
std::mt19937 generator(seed);
} // namespace util

int util::generateRandomNumber(int start, int end)
{
    std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
    return dist(generator);
}
