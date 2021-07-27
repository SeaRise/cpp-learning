#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int isPrefix(vector<int> *vec1, vector<int> *vec2) {
    for (auto iter1 = vec1->begin(), iter2 = vec2->begin(); iter1 != vec1->end() && iter2 != vec2->end(); ++iter1, ++iter2) {
        if (*iter1 != *iter2) {
            return -1;
        }
    }
    return 0;
}

int main() {
    vector<int> vec1{0, 1, 1, 2};
    vector<int> vec2{0, 1, 1, 2, 3, 5, 8};

    return vec1.size() <= vec2.size() ? isPrefix(&vec1, &vec2) : isPrefix(&vec2, &vec1);
}