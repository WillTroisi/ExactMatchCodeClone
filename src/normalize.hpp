#include <iostream>
#include <string>
#include <fstream>

std::string removeComments(std::string& line) {
    std::string result;
    int i = 0;

    while (i < line.size()) {
        //For single-line comments
        if(i + 1 < line.size() && line[i] == '/' && line[i+1] == '/')
            break;
        
        result += line[i];
        i++;
        
    }
}

std::vector<std::string> normalize(std::istream& in)
{
    std::vector<std::string> words;
    std::string line;
    std::istream_iterator<std::string> it(in), end;
    bool blockComment = false;

    while(std::getline(in, line)) {
        std::string cleaned;
        int i = 0;

        while(i < line.size()) {
            //Checks if the current line starts with /* or ends with */
            if (blockComment == false && i + 1 < line.size() && line[i] == '/' && line[i+1] == '*') {
                blockComment = true;
                i += 2; // + 2 to skip past the '/' and '*'
            } else if (blockComment && i + 1 < line.size() && line[i] == '*' && line[i+1] == '/') {
                blockComment = false;
                i += 2;
            } else {
                i++; //In this case, you would be inside of the block so just keep iterating.
            }
        }


        cleaned = removeComments(cleaned); //Remove the single line comments


        //Returns a vector with removed whitespace
        while (it != end) {
            words.push_back(*it);
            ++it;
        }

        return words;
    }
}
