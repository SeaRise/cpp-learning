- 重载运算符, 可成员/非成员函数.
    - 语法
    ```
    type operator<运算符>(args);
    ```
    - 如何判断是成员/非成员.
        - 二元运算符一般都是非成员
        - 有赋值的，一般都是成员.
        - 一元运算符，一般都是成员.
        - (), [], -> 必须是成员.
        - >>, << 必须是非成员.
    - 重载例子
    ```
    ostream &operator<<(ostream &, const type &);
    istream &operator>>(istream &, type &);

    // 这里要返回临时量，然后由上层调用的函数copy到栈里，不能修改输入.
    type operator+(const type &, const type &);
    type operator-(const type &, const type &);
    type operator*(const type &, const type &);
    type operator/(const type &, const type &);
  
    // 这里直接修改*this, 然后返回*this的引用.少了两次copy.
    type &operator+=(const type &);
    type &operator-=(const type &);
    type &operator*=(const type &);
    type &operator/=(const type &);
  
    // 需要满足类似java equals的规范.
    bool operator==(const type &, const type &);
    bool operator!=(const type &, const type &);
  
    // 定义顺序, 如果定义了<, 那语意要有a!=b, 有a<b或a>b, 即是说要在关系运算上统一.
    bool operator<(const type &, const type &);
  
    // 赋值
    type &operator=(std::initializer_list<type2>); // type v = {a, b, c, d};
    type &operator=(const type3 &); // type v = type3;
  
    // 下标
    type& operator[](size_t n);
    const type& operator[](size_t n) const;
  
    // 前置++, --； ++i
    type &operator++();
    type &operator--();
    // 后置++， --; i++
    type &operator++(int);
    type &operator--(int);
  
    type& operator*() const;
    // ->必须返回指针，或者重载了->
    //     (*point).xxx
    //     point.operator->()->xxx
    type* operator->() const { return &(this->operator*()); };
  
    // 重载函数调用，可以有var(args).重载了()的对象称作函数对象.
    type operator()(args);
    ```
- 函数对象
    - lambda本身是函数对象.见ch10
    - 标准库定义的函数对象.`#include functional`, 见510页.
- function, 可以指向 lambda, 函数指针，函数对象.
    - 见ex14_44.cpp
- 重载类型转换
    - 通常只会重载bool().
```
operator type() const; // 讲*this转为type类型
explicit operator type() const; // 禁用隐式转换, 不过在if, while, for, ?:, ||, !, &&这里地方，还是会隐式转换，也就是bool的使用场景.
```