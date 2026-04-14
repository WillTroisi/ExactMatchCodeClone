#include <iostream>
#include <string>
#include <fstream>

std::vector<std::string> normalize(std::istream& in)
{
    std::vector<std::string> words;
    std::istream_iterator<std::string> it(in), end;

    while (it != end) {
        words.push_back(*it);
        ++it;
    }

    return words;
}
