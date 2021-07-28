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