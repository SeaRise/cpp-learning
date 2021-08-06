- 动态分配内存：堆内存.
- 手动管理关键字： new， delete.
- 智能指针, `#include <memory>`
    - shared_ptr: 共享指针
    - unique_ptr: 独占指针
    - weak_ptr: 弱引用，指向shared_ptr管理的对象.
- 操作
    - 共有
    ```
    if (p), 如果有指向的对象，为true.
    *ptr, 获取对象
    ptr->xxx 等价 (*ptr).xxx
    p.get(), 获取p保存的裸指针
    swap(p, q), p.swap(q), 交换指针.
    ```
    - shared_ptr独享
    ```
    shared_ptr<type> p = make_shared<type>(args);
    shared_ptr<type> p(q); // 递增q指向对象的计数器.
    p = q; // 递增p指向对象的计数器, 递减p指向对象的计数器
    p.unique(); // p.use_count() == 1
    p.use_count(); // 返回所有指针数量，慢，debug用
    ``` 

- 猜测：shared_ptr是怎么实现的？
    - 内部结构: 计数器本身是new的，然后shared_ptr持有计数器的指针和type的指针.
    ```
    shared_ptr {
        int *count = new int(0);
        type ptr = nullptr;
    }
    ```
    - 当p = q时， 重写了=操作符
    ```
    --(*(p.count));
    ++(*(q.count));
    p.count = q.count;
    p.ptr = q.ptr;
    ```
    - shared_ptr<type> p(q);
    ```
    ++(*(q.count));
    p.count = q.count;
    p.ptr = q.ptr;
    ```

- shared_ptr
    - 析构函数对内存指针调用delete， 或者传入的销毁函数.
    - 构造
        - make_shared, 推荐
        - shared_ptr<T> p(q, function), 传入q的销毁函数.
    - reset(x), 调用原对象delete或销毁函数，设置新对象q.
    - 可以用shared_ptr来做try {} finally {释放资源}, 因为传入销毁函数后，shared_ptr会自动调用，不会担心throw exception后没有调用销毁函数.
    - 使用规范:
    ```
    不要shared_ptr<T> p(指针) / p.reset(指针)
    不要delete p.get()
    非new分配的对象，记得传个deleteFunction给shared_ptr.
    ```
    - 如果传入的是数组，那么要传销毁函数，用来delete[]。

- unique_ptr
    - 只有unique_ptr<type> p(new type(xxx)) / unique_ptr<type, deleteFunc> p(new type(xxx), deleteFunc)，传指针构造.
    - 不支持拷贝和赋值[p1(p2), p1 = p2]，但是下面的情况可以
    ```
    unique_ptr<type> func() { return unique_ptr<type>(new type(xxx)); }
    unique_ptr<type> func() { 
        unique_ptr<type> p(new type(xxx));
        // ...
        return p;
    }
    ```
    - 操作
    ```
    u = nullptr, 释放对象，且置空u.
    u.release(), 不释放对象，置空u且返回指针.
    u.reset(x), 释放原对象，换新对象.
    ```
    - 转让所有权
    ```
    p2(p1.release());
    p3.reset(p2.release());
    ```
    - 支持管理动态数组，所以会自动delete[], 也可以p[i]

- weak_ptr: 弱引用, shared_ptr的伴随类，不增加计数.
    - 这里有个地方讲一下，如果w内部持有一个shared_ptr,那就相当于会增加计数，所以weak_ptr内部应该是没有shared_ptr的， lock()估计是new shared_ptr.
```
weak_ptr<T> w(sp); // 参数：shared_ptr<T>
w = p; // p可shared_ptr / weak_ptr
w.reset() //置空
w.use_count() // shared_ptr.use_count()
w.expired() // w.use_count() == 0
w.lock() // 返回shared_ptr.
```

- 手动管理内存
    - 分配： new
        - 返回指针
        ```
        int *p1 = new int / new int() / new int(42);
        const int *p1 = new const int(42); // 底层const.
        int *p1 = new (nothrow) int; // 失败返回nullptr.
        int *p1 = new int[5]; // 分配数组，返回首元素指针.
        ```
    - 销毁： delete / delete[]
        - 后面接指针. 后者专门用于delete数组.
        ```
        delete p;
        delete[] p;
        p = nullptr; // delete后重置指针是个好习惯.
        ```
      
- allocator: new在分配内存时会初始化，用allocator可以只分配内存，不初始化，后面再调方法初始化.
```
allocator<type> alloc;
const auto p = alloc.allocate(n); // 分配n个type对象的内存， 但未初始化.
alloc.deallocate(p, n); // 回收allocate分配的内存，不涉及析构函数.
alloc.construct(p + 1, args); // 在分配的内存上面创建对象.
alloc.destory(p + 1); // 对p指向的对象执行析构函数.
uninitialized_copy // 可以用拷贝来构造对象，而不是construct.
```