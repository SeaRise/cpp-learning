- 重载new, delete, 必须在全局作用域或者类作用域里.
- 定位new， 只调用构造函数，不分配内存
```
new (address) 构造函数
如：
new(p) string("abc");
```
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
- 类成员指针, 不知道有啥用...先记着有这玩意.
- 嵌套类
- union
    - 包含类时, 且类有自定义的默认构造函数/拷贝控制成员时， union会合成对应的成员为delete.
        - 当union非匿名单独使用的时候，就要定义对应的成员(构造/拷贝)
        - 当union匿名在类成员时，就构建类成员的，参考Token.