- 引用，并非对象，只是变量的别名
```
int &a = b;
```
- 指针，是一个对象，值的是对象的地址.
```
int *a = &b;
```
- `*`
    - 用在声明，是声明指针.
    - 用在表达式，是解引用符.
- `&`
    - 用在声明，是声明引用.
    - 用在表达式，是取地址符.
- 判断类型
    - 从右往左看
    ```
    int *p
    int *&r = p; // 一个引用，引用的指针, 指针指向int类型.
  
    int n = 0;
    const int *const pip = &n; // 一个常量指针，指向常量int.
    const int &rir = n; // 一个引用，引用常量int.
    ```
- const
  - 顶层const：指针本身是常量,或者变量本身是常量，引用本身可以说就是顶层const.
    - copy不影响
  - 底层const：指针指向的是常量,或者引用指向的常量.
    - copy要求两边都是/不是底层const
- constexpr, 常量表达式标识符
  - `constexpr int mf = 20;`
  - `constexpr int *q = nullptr`, q是指向整数的常量指针，和上面的不同，是constexpr的特殊导致的, 只用于顶层const.
  - 只用于字面值，string，自定义class这些都不行.
- 类型
  - 别名
    - `typedef double *wages;`, wages是double*的别名.
      - `const wages p = nullptr`, p是指向double的常量指针
      - `const wages *p`, p本身是一个指针，指针指向常量指针，常量指针指向double
      - 判断类型的时候，把别名本身看做一个整体，不是单纯的把别名替换过来，再判断类型.
        - 是`const (double*) p = nullptr`, 而不是`const double* p = nullptr`, 前者是常量指针，后者是指针指向常量.
    - `using wages double;`
  - `auto`
    - 自动判断类型，类似scala的val吧.
    - 忽略顶层const，保留底层const.
    - 引用+auto，避免copy.
    ```
    int a = 0;
    auto &h = a;
    ```
  - decltype, 推断类型.
    - `decltype(f()) a = x;`, `f()`没有被实际调用.
    - `decltype(z) a = x;`, 如果z是引用，那a也是引用，auto则不是.
    - `decltype((z)) a = x;`, 得到z的引用类型.
    - `decltype(z = 1) a = x;`, 赋值的结果是引用.
    - decltype会保留顶层const，如果是引用，还会保留引用类型.
- struct
```
struct Sales_data {
  std::string bookNo;
  unsigned int units_sold = 0;
  double revenue = 0.0;
};

Sales_data accum, *salesptr;
```