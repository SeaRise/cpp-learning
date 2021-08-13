#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::cin;
using std::cout;
using std::endl;

namespace ch16_2 {
    template<typename T>
    inline int compare(const T &v1, const T &v2) {
        auto lessOp = std::less<T>();
        return lessOp(v1, v2) ? -1 : lessOp(v2, v1) ? 1 : 0;
    }
}

namespace ch16_4 {
    template<typename Iter, typename Value>
    inline Iter find(Iter iter, const Iter end, const Value &v) {
        for (; iter != end && *iter != v; ++iter);
        return iter;
    }
}

namespace ch16_5_6 {
    template<std::size_t N, typename Value>
    inline Value *begin(Value (&array)[N]) {
        return array;
    }

    template<std::size_t N, typename Value>
    inline Value *end(Value (&array)[N]) {
        return array + N;
    }

    template<std::size_t N, typename Value>
    inline void print(Value (&array)[N]) {
        for (auto iter = begin<N, Value>(array); iter != end<N, Value>(array); ++iter) {
            std::cout << *iter << " ";
        }
        cout << endl;
    }
}

namespace ch16_7 {
    template<std::size_t N, typename Value>
    inline std::size_t size(Value (&array)[N]) { return N; }
}

int main() {
    // 16.2
    cout << ch16_2::compare(1, 0) << endl;
    std::vector<int> vec1{ 1, 2, 3 }, vec2{ 4, 5, 6 };
    cout << ch16_2::compare(vec1, vec2) << endl;
    cout << endl;

    // 16.4
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto is_in_vector = vec.cend() != ch16_4::find(vec.cbegin(), vec.cend(), 5);
    std::cout << (is_in_vector ? "found\n" : "not found\n");

    std::list<string> list{"a", "b", "c", "d", "e"};
    auto is_in_list = list.cend() != ch16_4::find(list.cbegin(), list.cend(), "a");
    std::cout << (is_in_list ? "found\n" : "not found\n");
    cout << endl;

    // 16.5, 16.6
    std::string s[] = { "ssss", "aaa", "ssssss" };
    char c[] = { 'a', 'b', 'c', 'd' };
    int  i[] = { 1 };
    ch16_5_6::print(s);
    ch16_5_6::print(c);
    ch16_5_6::print(i);
    cout << endl;

    // 16.7
    cout << ch16_7::size(s) << endl;
    cout << ch16_7::size(c) << endl;
    cout << ch16_7::size(i) << endl;

    return 0;
}