- 顺序容器本身只有少量的成员函数，大部分用的是泛型的公共方法，主要在`algorithm`和`numeric`
- 算法本身不会修改迭代器的大小.
- 插入迭代器：赋值=插入值， 用在算法时，无需考虑容量够不够，如`fill_n`, `copy`.
```
#include <iterator>
vector<int> vec;
auto it = back_inserter(vec);
*it=42;
```
- lambda
    - 格式: `[capture list] (parameter list) -> return type { function body }`
        - 解释： `[要使用(捕获)的外部局部非static变量] (形参列表) -> 返回类型 { 方法体 }`
        - 例子
        ```
        // 值捕获
        [sz] (const string &a) -> bool { return a.size() >= sz; }
      
        // 引用捕获
        [&sz] (const string &a) { return a.size() >= sz; }
      
        // 隐式捕获引用
        [&] (const string &a) { return a.size() >= sz; }
      
        // 隐式捕获值
        [=] (const string &a) { return a.size() >= sz; }
      
        // 混合: 隐式引用，显式值
        [&, c]
      
        // 混合: 隐式值，显式引用
        [=, &c]
        ```
- 参数绑定
```
对func(a1, a2, a3, a4, a5)
using namespace std::placeholders;
值绑定
auto g = bind(f, a, b, std::placeholders::_1, c, _2)
引用绑定
#include <functional>
auto g = bind(f, std::ref(a), std::ref(b), _1, std::cref(c), _2)
```
- 判读奇数: `i & 0x1`
- 插入迭代器
```
back_inserter
front_inserter
inserter
```
- 流迭代器
```
istream_iterator<string> it(in), eof; // 空迭代器相当于cend()
ostream_iterator<string> out1(os), out2(os, '\n'); // 第二个参数是每次输出后追加字符.
```
- 反向迭代器
    - reverse_iterator和iterator的转换：　`reverse_iterator.base();`
    - `rbegin, rend, crbegin, crend`
    - ++相当于正向的--.
- `std::prev(vec.cend())`, 获取尾指针的前一位.