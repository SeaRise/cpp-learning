- 模板不要分离编译...
- 实例化模板定义, 这样就不会每次使用相同模板都实例化一次.
```
// 在文件1， 对模板class和func进行实例化
template class TempObj<String>;
template String TempFunc();

// 在文件2， 3， 4， 5， 。。。使用该实例化.
extern template class TempObj<String>;
extern template String TempFunc();
```
- 将实参传递给带模板类型的函数形参时，能够自动应用的类型转换只有:
    - const转换
        - 忽略顶层const
        - 底层非const转成底层const
    - 数组或函数到指针的转换。
- 模板函数，尾置返回值
```
template<typename It>
auto func(It begin, It end) -> decltype(*beg);

// 返回值为*beg的值类型，而不是引用.
template<typename It>
auto func(It begin, It end) -> typename std::remove_reference<decltype(*beg)>::type;
```
- 16.2.5, 引用折叠
    - 对于template<typename T> void f(T &&), 可以绑定左值
        - 右值引用参数推断: 当`int i = 1; f(i);`时, 推断T的类型为int&, 所以T &&为int& &&
            - T可以推断为引用，可能会导致`T t = var`意思不明确， 不过可以用`remove_reference`获取值类型，不管T是不是引用.
        - 引用折叠: 所以右值引用参数可以接受左值/右值, 同时T&&也可能是左值/右值.
            - X& &, X& &&, X&& &都折叠成X&
            - X&& &&折叠成X&&
        - template<typename T> void f(T &&), 可以保证T &&一定是引用，而且和传入参数的左右值一致.
    - move, forward: https://www.jianshu.com/p/b90d1091a4ff
        - std::move, 将左值转为右值
        - std::forward, 转发值，左值还是左值，右值引用还会是右值, ps: 右值引用本身是左值，所以需要用这个函数.
- 可变参数模板
    - 和initializer的区别是，类型可以不一致.
```
// 单纯打印
template <typename T, typename... Args>
void func(const T &t, const Args& ... args) {
    cout << sizeof...(Args) << endl; // 类型参数的数目.
    cout << sizeof...(args) << endl; // 函数参数的数目.
}

// 递归
// 递归终止函数
template<typename T>
ostream &print(ostream &os, const T &t) {
    return os << t;
}
// 递归中间函数
template<typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args& ... args) {
    os << t << ", ";
    print(os, args...);
}
// 参数包扩展
template<typename T, typename... Args>
ostream &print(const T &t, const Args& ... args) {
    os << t << ", ";
    print(os, convert(args)...); // 相当于foreach args调用convert.
}
```
- 模板特例化， 直接看16.5吧..