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
- 数组
    - 定义
        - 从数组的名字开始，从内往外看.
    ```
    // 字符串数组
    char a1[] = "c++";
    char a2[] = {'c', '+', '+', '\0'};
  
    // 其他
    int a[] = {0, 1, 2};
    int *ptrs[10]; // 数组，含有10个指针，指针指向int
    int &refs[10] = /* ? */; // 数组，含有10引用，引用int，但是这个非法，数组的元素不能是引用.
    int (*Parray) [10] = &arr; // 指针，指向数组，数组含有10个int.
    int (*arrRef) [10] = arr; // 引用，引用数组，数组含有10个int.
    ```
    - 初始化
        - 数组初始化，元素的值是未知的，不一定是0.
    - 指针 / 迭代器
        - 数组名字等价数组首元素地址, `arr`等价`&arr[0]`
        - 指针可以+/-, 因为指针的类型是知道的，所以每次+1/-1的单位实际是类型的大小.和迭代器的使用方法一样
        ```
        #include <iterator>;
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (auto iter = begin(ia); iter < end(ia); ++iter) {
            cout << *iter << endl;
        }
        ```
        - 指针和下标使用
        ```
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        * (ia + 4) 等价 ia[4] 
        ```
- cstring
    - 操作库, `#include "cstring"`
    - 内部格式: `{'a', 'b', 'c', 'd', '\0'}`, 末尾的`'\0'`是结束符.
- 旧借口兼容
    - string转cstring.
    ```
    string s("test");
    const char *str = s.c_str();
    ```
    - 数组转vector
    ```
    int arr[10] = {};
    vector<int> vec(begin(arr), end(arr));
    ```
- 多维数组