- namespace查找规则：　`对func(arg1, args2, ...);` (没有指定func的namespace)
    - 先ADL查找
        - 查找查找arg1, arg2, ...类型所在的namespace.
    - 再order查找
        - 先查找当前namespace, 包括当前namespace using的.
        - 再查找上层namespace, 包括上层namespace using的. 递归.
    ```
    void swap(T v1, T v2) {
        using std::swap;
        // 先查找当前namespace, 上层namespace， 再是v1.field1类型所在作用域, 再是std.
        swap(v1.field1, v2.field1);
    }
    ```
- 默认namespace内部的相当于static, c++11推荐.
```
namespace {
    xxx;
}
```
- 多重继承，虚集成.