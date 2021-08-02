- 参数
    - 实参, 就是方法调用是传进去的变量
    - 形参，func的局部变量，用实参来初始化，类似`type 形参 = 实参;`
- 变量
    - 局部变量
        - 超过作用域后, 分配的对象自动销毁
    - 局部静态变量
        - 超过作用域，依然存在，直到程序结束, `static size_t = 0;`
- 分离式编译?待看.
- 参数传递
    - 有`type 形参 = 实参;`， 所以也有`type &形参 = 实参;`, `type *形参 = &实参;`, 分别是赋值传递，引用传递，指针传递.
        - 推荐用引用传递.同时也可以用引用传递搞多返回值.尽量用常量引用,`const int & c`.
    - 数组传参
        - 传指针begin，end
        - 传首指针 + 数组长度
        - 传数组引用, `int (&arr)[10]`, 但限定了数组大小.
        - 多维数组传参，待看..
    - 可变数量形参, initializer_list, 前提：类型一致.
    ```
    #include <initializer_list>
    using std::initializer_list;
    void error_msg(initializer_list<string> il) {
        for (auto beg = il.begin(); beg != il.end(); ++beg) { 
            // do something.
        }
    }
  
    error_msg({"1", "2", "3", "fd"});
    ```
- 返回值
    - 不要返回局部变量的指针/引用
    ```
    const string &manip() {
        return "return";
    }
    ```
    - 列表初始化返回值, `return {'a', 'b', 'c'}`, 和`type tmp = {'a', 'b', 'c'}`没区别.
    - 如果返回的是引用，那就是左值，否则就是右值，返回左值有`func() = value;`
    - 返回数组参数，好麻烦...先跳过.
- 函数重载
    - 参数不区分顶层const，但是区分底层const
    - 不区分返回类型
- 内联: 加关键字`inline`, `inline const string & shorterString(const string &, const string &);`
    - 通常声明且定义在头文件, 最好只在定义的地方说明inline
    - 如果声明和定义都在class/struct内部，那就是隐式内联.
- constexpr函数: `constexpr int new_size() {return 42; }`, 返回值，形参是字面值类型,函数体有且只有一个return.
    - 只有当形参都是常量表达式，constexpr函数返回值才会是常量表达式.
    - constexpr函数
    - 通常声明且定义在头文件
- 调试帮助
    - `#include "cassert"`, 如果`#define NDEUG`, `assert(condition)`会生效.
    ```
    __(FILE/LINE/TIME/DATE)__
    ```
    - 用预处理的if，endif来控制debug的执行内容
    ```
    // NDEBUG定义要在include cassert之前.
    #define NDEBUG
    #include <cassert>
  
    #ifndef NDEBUG
        // debug时才执行的内容
    #endif
    ```
- 函数指针
```
// 函数声明
boolean lengthCompare(const string &, const string &);
// 函数指针
boolean (*pf) (const string &, const string &);
// 赋值
pf = nullptr;
pf = lengthCompare;
pf = &lengthCompare;
// 调用
pf("a", "b");
(*pf)("a", "b");
lengthCompare("a", "b");
// 函数指针形参
void useBigger(const string &s1, const string &s2, boolean pf(const string &, const string &));
void useBigger(const string &s1, const string &s2, boolean (*pf)(const string &, const string &));
// 别名简化
// Func和Func2是等价的函数类型
typedef bool Func(const string &, const string &);
typedef decltype(lengthCompare) Func2;
// FuncP和FuncP2是等价的函数指针类型
typedef bool (*FuncP)(const string &, const string &);
typedef decltype(lengthCompare) *FuncP2;

void useBigger(const string &s1, const string &s2, Func); // 函数类型被自动转成指针
void useBigger(const string &s1, const string &s2, FuncP2);

// 函数指针返回值
using F = int(int *, int);
using PF = int(*) (int *, int);
PF f2(int);
F *f2(int);
decltyoe(func) *f2(int); // func是想要返回的类型的某个函数
auto f1(int) -> int (*)(int *, int); // 尾置返回类型
```
- 尾置返回类型
```
auto func(int i) -> int(*)[10]; // 返回一个指针，指针指向一个10大小的数组，数组元素为int.
auto f1(int) -> int (*)(int *, int); // 返回int(int *, int)的函数指针
```