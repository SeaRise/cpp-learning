- io库
    - iostream, 基类和标准输出输入
    - fstream, 文件读写
    - sstream， string读写
- io对象不可拷贝、赋值.也不能是底层const.
- io缓存刷新
```
// 刷新且回车/空格/无
cout << "test" << endl;
cout << "test" << ends;
cout << "test" << flush;

// 总是刷新
cout << unitbuf;
// 恢复
cout << nounitbuf;
```
- 关联istream和ostream
  - `is.tie(&os);`
  - `ostream *oldTie = is.tie(nullptr);`
- 文件读写
  - `fstream`构造自动`open()`, 销毁自动`close()`.
  - `ifstream input(fileName)`
  - `ofstream out(fileName, ofstream::status)`, status有out,ate等等.
- string读写
  - `istringstream`只读，`ostringstream`只写，`stringstream`可读写.
  - `strm.str()`返回拷贝, `strm.str(s)`把s拷贝到strm里.