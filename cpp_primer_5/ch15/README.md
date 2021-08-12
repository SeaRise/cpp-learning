- 静态类型和动态类型
    - `type a = obj`, type是a的静态类型，编译时可知，obj的实际类型是a的静态类型.除了指针(智能指针),引用外，静态类型和动态类型一致.
    - c++的多态即是，指针,引用在运行时才得知动态类型.
    - 只有virtual函数，才会在运行时调用动态类型，否则按照静态类型来.所以析构函数也得搞成virtual，这样delete才不会delete错.
- 基类，派生类
```
class base {
public:
    base(type v);
    // 只有virtual函数才能被继承类覆盖，也只有virtual函数才会在运行时绑定实现，其他的都是编译时知道.
    // virtual函数的默认实参由引用/指针的类型决定...
    virtual type func1(args);
    virtual type func2(args);
    virtual ~base() = default; // 通常有个虚析构函数.
// 派生类可见.
protected:
    type var;
}

class impl : public base {
public:
    impl(type v) : base(v) {}; // 调用base的构造函数.
    type func(args) override; // 覆盖func1函数
    type func(args) override final; // 覆盖func2函数, 且禁止被children覆盖
}
```
- final class, 不可继承; final func, 不可覆盖.
```
class c final
type func() final
```
- 抽象基类，包含纯虚函数的类就是抽象基类，不可实例化
```
class obj {
public:
    // = 0 定义纯虚函数
    virtual type func(args) = 0;
}
```
- 实践： 如果有需求，那就在基类把 三/五 都定义出来，=default; 然后继承类就会自动合成. 当然最好还是显式定义出来.