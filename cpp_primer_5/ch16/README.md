- 模板不要分离编译...
- 实例化模板定义, 这样就不会每次使用相同模板都实例化一次.
```
// 在文件1， 对模板class和func进行实例化
template class TempObj<String>;
template String TempFunc();

// 在文件2， 3， 4， 5， 。。。使用该实例化.
extern template class TempObj<String>;
extern template String TempFunc();
```