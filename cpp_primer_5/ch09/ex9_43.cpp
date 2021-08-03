#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;

// 9.43
string &replaceWith1(string &s, const string& oldVal, const string &newVal) {
    for (auto iter = s.begin(); iter != s.end() - oldVal.size() - 1;) {
        auto end = iter + oldVal.size();
        if (oldVal == string{iter, end}) {
            iter = s.erase(iter, end);
            iter = s.insert(iter, newVal.cbegin(), newVal.cend());
            iter += newVal.size();
        } else {
            ++iter;
        }
    }
    return s;
}

// 9.44
string &replaceWith2(string &s, const string& oldVal, const string &newVal) {
    for (decltype(s.size()) pos = 0; pos <= (s.size() - oldVal.size());) {
        if (s[pos] == oldVal[0] && s.substr(pos, oldVal.size()) == oldVal) {
            s.replace(pos, oldVal.size(), newVal);
            pos += newVal.size();
        } else {
            ++pos;
        }
    }
    return s;
}

// 9.45
string &combine1(string &s, const string &prefix, const string &suffix) {
    s.insert(s.cbegin(), prefix.cbegin(), prefix.cend());
    return s.append(suffix);
}

// 9.46
string &combine2(string &s, const string &prefix, const string &suffix) {
    s.insert(0, prefix);
    return s.insert(s.size(), suffix);
}

int main() {
    // 9.43
    string s1{ "To drive straight thru is a foolish, tho courageous act." };
    cout << replaceWith1(replaceWith1(s1, "tho", "though"), "thru", "through") << endl;

    // 9.44
    string s2{ "To drive straight thru is a foolish, tho courageous act." };
    cout << replaceWith2(replaceWith2(s2, "tho", "though"), "thru", "through") << endl;

    string s3("Wang");
    cout << combine1(s3, "Mr.", ", Jr.") << endl;

    string s4("Wang");
    cout << combine2(s4, "Mr.", ", Jr.") << endl;
    return 0;
}