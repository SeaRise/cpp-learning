- this, 和java差不多的意思
    - this是指向非常量的常量指针.对obj的成员函数func()
    ```
    obj.func();
    等价
    func(Object *const this);
    func(&obj);
    ```
  - 如果obj本身是常量对象, 因为初始化的原则是，底层const必须一致. this本身不是底层const， &obj是底层const，所以this无法被初始化, 所以对常量obj只能使用常量成员函数.
      - 常量对象以及它的指针/引用只能用常量成员函数.
  ```
  string isbn() const { return bookNo; }
  ```
- 构造函数
  - 默认初始化，编译器自动生成，或`Obj() = default;`, ps: 对于内置/复合类型,初始值是未知的,string不是内置类型，默认值是空字符串.
  ```
  Obj(const type f1, const type s2) : f1(f1), f2(f2) { // 进入到这里的话，*this已经初始化完成了. }
  // explicit 指定不用于隐式转换和复制初始化.
  // explicit能加就加吧
  // https://zhuanlan.zhihu.com/p/52152355
  explicit Obj::Obj(const type f1, const type s2) { 
      // 进入到这里的话，*this已经初始化完成了.
      //do something 
      (*this).f1 = f1;
      (*this).f2 = f2;
  }
  ```
- 右值引用
  - `std::move`: 只是所有权变更而已，把一个普通的变量，cast成一个右值引用.
  - 右值引用的目的是为了性能，用右值引用作为参数，就是为了直接把右值引用对象的内存地址拿来构建新对象，不需要copy.前提是右值引用对象之后就会废弃掉。不用了.
  - 很多STL的类都提供了 右值引用 的构造函数， 即 移动构造函数. 
  - https://zhuanlan.zhihu.com/p/335994370
```
std::string str = "test";
string && r = std::move(str);
string newStr(std::move(str)); 
```
- 拷贝，赋值，析构: 如果没有主动定义，那就是编译器生成默认的，和构造函数一样.
- 访问控制
  - struct和class的区别， 前者默认public，后者默认private.
  - 友元函数，和成员函数一样有内部访问权，但是不是成员函数.
  ```
  class object {
  // 友元函数
  // 这里只是声明这是个友元函数，这个类外面还得再声明一次.
  friend type func(params...);
  
  public: 
      // something
  private:
      // something
  };
  
  type func(params...);
  ```
- inline，内联，在成员函数定义处加inline.
- mutable, 可变数据成员，即使对象本身是const，也可以修改值.const成员函数里可以修改.
```
mutable type var;
void func() const {
    var = xxxx;
}
```
- 友元， 可以访问私有
```
class object {
// 这里只是友元声明， 这个类外面还得再声明一次.
// 友元函数
friend type func(params...);
// 友元类
friend class FriendClass;
// 友元成员函数
friend type FriendClass::func(params...);

public: 
    // something
private:
    // something
};
```
- 委托构造函数， 类似java里, this(xx, yy, zz);
```
Obj(string a, string b) : oa(a), ob(b) {};
Obj() : Obj('a', 'b') {};
```
- 隐式转换
  - 如果一个构造函数只有一个形参如Obj(type a)， 那么可以认为同时定义了一种隐式转换, `Obj obj = a;`, 除非加了`explicit`.
- 静态成员
```
class Obj {
public:
    static type getField();
private:
    static type field;
}

Obj::getField() {
    return field;
}
```