- 左右值
    - 左值：占用了一定内存，且拥有可辨认的地址的对象
    - 右值：左值以外的所有对象
```
int i = 1;   // i是左值,  1是右值.
int *p = &i; // i是左值, p也是左值
i = i + 2; // i是左值, (i+2)是右值
```
- cast
  - `cast-name<type>(expression)`
  - 不包含底层const, static_const
  ```
  int j = 10;
  double slope = static_const<double>(j);
  ```
  - 要修改底层const, const_const
  ```
  const char *pc;
  char *p = const_cast<char*>(pc);
  ```
  - 无视所有限制，直接cast, reinterpret_cast
  ```
  int *ip;
  char *pc = reinterpret_cast<char*>(ip);
  ```