#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

int main() {
    std::ifstream file("nume.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open file";
        return 1;
    }
    std::string contents((std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());

    //split
    std::vector<std::string> words;
    std::string::size_type start = 0;
    while (start != std::string::npos) {
        std::string::size_type end = contents.find_first_of(" ,.!?;:\n", start);
        if (end != std::string::npos) {
            if (end != start) {
                words.push_back(contents.substr(start, end - start));
            }
            start = contents.find_first_not_of(" ,.!?;:\n", end);
        }
        else {
            if (contents.length() - start > 0) {
                words.push_back(contents.substr(start));
            }
            start = end;
        }
    }


    std::map<std::string, int> nrword;
    for (const auto& word : words) {
        std::string data(word);
        std::transform(data.begin(), data.end(), data.begin(), ::tolower);
        nrword[data]++;
    }

    auto compare = [](const std::pair<std::string, int>& left, const std::pair<std::string, int>& right) {
        return left.second < right.second || (left.second == right.second && left.first > right.first);
        };
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(compare)> sortedWords(compare);
    for (const auto& pair : nrword) {
        sortedWords.push(pair);
    }

    
    while (!sortedWords.empty()) {
        auto pair = sortedWords.top();
        std::cout << pair.first << " => " << pair.second << std::endl;
        sortedWords.pop();
    }

    return 0;
}