- using
    - 头文件不要用using，容易引发混乱.
```
using std::string;
using std::cout;
using std::endl;

string s("test");
cout << s << endl;
```
- string
    - std::string
    - 字面值可以转为string, `string("a") + "ss";`
    - 常用库， `#include "cctype"` / `#include "ctype.h"`
    - 和java string的区别，java的是不可变的，但是c++的是变的，所以=实际是修改原对象.
    - for
        - 遍历
        ```
        string s("test");
        for (auto c : s) {
            cout << c << endl;
        }
        ```
        - 修改
        ```
        string s("test");
        for (auto &c : s) {
            c = toupper(c);
        }
        ```
        - 下标访问
        ```
        string s("test");
        for (decltype(s.size()) i = 0; i < s.size(); ++i) {
            cout << s[i] << endl;
        }
        ```
- vector
    - 基本和java的list差不多吧.
    - push_back应该是copy元素的.因为vector是紧密排列元素，而不是引用的数组？暂时猜一下.