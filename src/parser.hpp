#pragma once

#include <string>
#include <vector>
#include <filesystem>

using namespace std;

struct Function {
    std::string name;
    std::vector<std::string> tokens;
};

std::vector<Function> parseFunctions(const std::vector<std::string>& tokens) {
    std::vector<Function> functions;

    Function current;
    bool inFunction = false;
    int braceCount = 0;

    for (int i = 0; i < tokens.size(); i++) {
        const std::string& t = tokens[i];

        if(!inFunction) {
            if (t.find("(") < t.size() && i > 0) {
                current = Function{};
                current.name = tokens[i - 1];
                current.tokens.clear();

                inFunction = true;
            }
        }

        if (inFunction) {
            current.tokens.push_back(t);

            if(t == "{") {
                braceCount++;
            } else if(t == "}") {
                braceCount--;
            }

            if(inFunction && braceCount == 0 && !current.tokens.empty()) {
                functions.push_back(current);
                inFunction = false;
            }
        }

    }

    return functions;

}