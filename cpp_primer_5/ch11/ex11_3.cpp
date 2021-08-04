#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;

bool read(string &buffer, string &word, std::istream &is) {
    if ((is >> buffer).good() && buffer != "exit") {
        word.clear();
        std::for_each(buffer.cbegin(), buffer.cend(), [&word](const char c) {
            if (!ispunct(c)) {
                word.push_back(std::tolower(c));
            }
        });
        return true;
    } else {
        return false;
    }
}

// 11.3, 11.4
int main() {
    map<string, size_t> word_count;
    string buffer;
    string word;
    while (read(buffer, word, cin)) {
        ++word_count[word];
    }
    for (const auto &item : word_count) {
        cout << item.first << " occurs " << item.second
             << ((item.second > 1) ? " times" : " time") << endl;
    }
    return 0;
}