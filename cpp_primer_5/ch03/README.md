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
- 迭代器
    - non-const
        - `vec.begin()`
        - `vec.end()`
    - const
        - `vec.cbegin()`
        - `vec.cend()`
    - 获取元素: `*iter`, 解引用符，不过应该不是指针，只是重载了操作符感觉.
    - 访问函数
        - `(*iter).func()`
        - `iter->func()`
    - 遍历
        - 这里的`++`, `=`, `*`估计都是重载的操作符.
        - 遍历不要增删元素.
    ```
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
      *iter = toupper(*iter);
    }
    ```
    - 重载了`it1 - it2`, `it + n`, `>,>=,<,<=,=`，意思能猜得出来.
    