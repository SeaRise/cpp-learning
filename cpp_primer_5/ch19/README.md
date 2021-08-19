- 重载new, delete, 必须在全局作用域或者类作用域里.
- RTTI, 运行时判断类型
    - dynamic_cast, cat指针/引用, `https://www.cnblogs.com/lomper/p/4108540.html`
    ```
    type *newE = dynamic_cast<type*>(e); // 失败return nullptr
    type &newE = dynamic_cast<type&>(e); // 失败throw bad_cast
    type &&newE = dynamic_cast<type&&>(e); // 失败throw bad_cast
    ```
    - typeid, 返回type_info
    ```
    obj *p = new impl();
    typeid(*p); // 返回impl对应的type_info， 获取动态类型.
    ```
- enum
    - 不限定作用域(或者说作用域就是enum定义所在的作用域), 可以隐式转成整型
    ```
    enum color {red = 0, yellow, green};
    or
    enum {red, yellow, green};
    ```
    - 限定作用域， 不可以隐式转成整型
    ```
    enum class color {red = 0, yellow, green};
    ```
    - 默认enum潜在类型是int， 可以指定
    ```
    enum intValues ： unsigened long long;
    ```