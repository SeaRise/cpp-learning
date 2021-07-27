#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    // 5.9, 5.10, 5.11, 5.12
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0,
             uCnt = 0, spaceCnt = 0, tabCnt = 0, newlineCnt = 0,
             ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch;
    char pre = '*';
    while (cin >> ch) {
        if (ch == '*') {
            break;
        }

        switch (ch) {
            case 'A': case 'a':
                ++aCnt;
                break;
            case 'E': case 'e':
                ++eCnt;
                break;
            case 'I': case 'i':
                ++iCnt;
                break;
            case 'O': case 'o':
                ++oCnt;
                break;
            case 'U': case 'u':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
            default:
                break;
        }
        if (pre == 'f') {
            switch (ch) {
                case 'f':
                    ++ffCnt;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
                default:
                    break;
            }
        }
        pre = ch;
    }

    return 0;
}