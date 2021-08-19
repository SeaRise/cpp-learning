#ifndef CPP_LEARNING_MY_PTR_H
#define CPP_LEARNING_MY_PTR_H

#include <functional>

template<typename T> class Deleter;
template<typename T> class my_shared_ptr;
template<typename T, typename... Args> my_shared_ptr<T> make_my_shared_ptr(Args&&... args);
template<typename T, typename D> class my_unique_ptr;

template<typename T>
struct Deleter {
    void operator()(T *p) { delete p; }
};

template<typename T>
class my_shared_ptr {
public:
    my_shared_ptr(): ptr(nullptr), counter(nullptr), deleter(Deleter<T>()) {};
    explicit my_shared_ptr(T *p): ptr(p), counter(new std::size_t(1)), deleter(Deleter<T>()) {};
    my_shared_ptr(T *p, std::function<void(T *)> func): ptr(p), counter(new std::size_t(1)), deleter(func) {};
    my_shared_ptr(const my_shared_ptr &);
    ~my_shared_ptr() { free(); };
    my_shared_ptr &operator=(const my_shared_ptr &);
    T &operator*() const { return *ptr; };
    T *operator->() const { return &(this->operator*()); }
    T *get() const { return ptr; }
private:
    T *ptr;
    std::size_t *counter;
    std::function<void(T *)> deleter;
    void free();
};

template<typename T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr &other)
    : ptr(other.ptr), counter(other.counter), deleter(other.deleter) {
    if (counter) {
        ++*counter;
    }
}

template<typename T>
my_shared_ptr<T> &my_shared_ptr<T>::operator=(const my_shared_ptr &other) {
    if (other.counter) {
        ++*other.counter;
    }
    free();
    ptr = other.ptr;
    counter = other.counter;
    deleter = other.deleter;
}

template<typename T>
inline void my_shared_ptr<T>::free() {
    if (counter && !(--*counter)) {
        deleter(ptr);
        delete counter;
    }
}

template<typename T, typename... Args>
my_shared_ptr<T> make_my_shared_ptr(Args&&... args) {
    return my_shared_ptr<T>(new T(std::forward<Args>(args)...));
}

template<typename T, typename D = Deleter<T>>
class my_unique_ptr {
public:
    my_unique_ptr(): ptr(nullptr), deleter(D()) {};
    my_unique_ptr(const my_unique_ptr<T, D> &) = delete;
    explicit my_unique_ptr(T *p): ptr(p), deleter(D()) {};
    my_unique_ptr(T *p, D d): ptr(p), deleter(d) {};
    ~my_unique_ptr() { free(); };
    my_unique_ptr &operator=(const my_unique_ptr<T, D> &) = delete;
    void release();
    void reset(T *new_p);
    T &operator*() { return *ptr; }
    T *operator->() { return &(this->operator*()); }
private:
    void free();
    T *ptr;
    D deleter;
};

template<typename T, typename D>
void my_unique_ptr<T, D>::release() {
    free();
    ptr = nullptr;
}

template<typename T, typename D>
void my_unique_ptr<T, D>::free() {
    if (ptr) {
        deleter(ptr);
    }
}

template<typename T, typename D>
void my_unique_ptr<T, D>::reset(T *new_p) {
    free();
    ptr = new_p;
}

#endif //CPP_LEARNING_MY_PTR_H
