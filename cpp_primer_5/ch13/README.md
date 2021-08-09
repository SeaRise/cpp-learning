- 三/五法则 // 建议：5个函数，要么都有，要么都没有.
    - 三：拷贝构造函数，拷贝赋值函数，析构函数
    - 五：移动构造函数，移动赋值函数
```
class object {
    // 拷贝构造
    object(const object &) { // xxx };
    object(const object &) = default; // 使用编译器合成的, ps:或者不写
    object(const object &) = delete; // 禁用拷贝构造函数
    // 拷贝赋值
    object& operator=(const object &) { // xxx }; // 返回左值引用.
    // 析构函数
    ~object() { //先执行函数体，然后才会调用每个成员的析构函数. };
    // 移动构造, 因为输入是右值引用，所以可以不用拷贝，直接把右值引用的成员拿过来用， 
    // 拿过来后最好保证被移动的对象状态正常，可以正常使用，正常析构.
    object(object &&s) noexcept { // xxx }; // noexcept用于承诺函数不会抛错.
    // 移动赋值, 同上
    object& operator=(object &&) { // xxx }; // 返回左值引用.
}
```
- 拷贝操作的写法
    - 考虑自值拷贝，先复制右值，再删除自己的内存，再从右值拷贝过来.
    - 考虑异常安全，抛错时，状态是否正常.
    - 行为： 类值(参考string) / 类指针(参考shared_ptr).
- swap
    - std::swap
    ```
    type tmp = v1;
    v1 = v2;
    v2 = tmp;
    ```
    - 自定义swap
    ```
    class object {
        friend void swap(object &, object &);
    }
    
    void swap(object &v1, object &v2) { 
        using std::swap;
        // 这里如果fn有定义自己的swap函数，就会用自己的，否则std::swap
        swap(v1.f1, v2.f1);
        swap(v1.f2, v2.f2);
    };
    ```
- std::move();
    - 左右值： 右值临时， 左值长久.
    - 右值引用，右值是常量或临时对象，本身没有引用，但是用右值引用可以例外 `int &&r = 42;`
    - 左值转成右值引用： int &&r = std::move(var);
- 移动迭代器： 解引用获得右值引用.
```
make_move_iterator(iter);
```
- 因为右值引用本身也是变量，所以可能会出现向右值引用赋值的情况，这时可以在函数里加限定符&,只能左值使用 // 实际是限定*this的类型
```
object &operator=(const object &) &;
"a" + "b" = "c"; // 报错.

// 限定右值可以用的赋值函数
object &operator=(const object &) &&;
"a" + "b" = "c"; // 不报错.
```