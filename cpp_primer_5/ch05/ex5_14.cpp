#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    int cnt = 0;
    int maxCnt = 0;
    string maxStr;
    for (string pre, cur; cin >> cur && cur != "exit"; pre = cur) {
        if (pre == cur) {
            ++cnt;
        } else {
            if (cnt > maxCnt) {
                maxCnt = cnt;
                maxStr = pre;
            }
            cnt = 0;
        }
    }

    if (maxStr.empty()) {
        cout << "There's no duplicated string." << endl;
    } else {
        cout << "the word " << maxStr << " occurred " << maxCnt + 1 << " times. " << endl;
    }

    return 0;
}