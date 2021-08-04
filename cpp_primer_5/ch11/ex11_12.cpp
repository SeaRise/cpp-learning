#include <iostream>
#include <map>
#include <vector>#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using std::string;
using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    // 11.12, 11.13
    vector<std::pair<string, int>> vec;
    string s;
    int i;
    while (cin >> s >> i) {
        vec.emplace_back(s, i);
//        vec.push_back(std::make_pair(s, i));
//        vec.push_back(std::pair<std::string, int>(s, i));
//        vec.push_back({s, i});
    }
    for (const auto &item : vec) {
        cout << item.first << " : " << item.second << endl;
    }
    return 0;
}