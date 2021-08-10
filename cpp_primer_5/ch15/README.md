- 静态类型和动态类型
    - `type a = obj`, type是a的静态类型，编译时可知，obj的实际类型是a的静态类型.除了指针(智能指针),引用外，静态类型和动态类型一致.
    - c++的多态即是，指针,引用在运行时才得知动态类型.
- 基类，派生类
```
class base {
public:
    base(type v);
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