#ifndef CPP_LEARNING_MY_PTR_H
#define CPP_LEARNING_MY_PTR_H

template<typename T> class my_shared_ptr;
template<typename T, typename... Args> my_shared_ptr<T> make_my_shared_ptr(Args&&... args);
template<typename T> class my_unique_ptr;

template<typename T>
class my_shared_ptr {
public:
    my_shared_ptr(): ptr(nullptr), counter(nullptr) {};
    explicit my_shared_ptr(T *p): ptr(p), counter(new std::size_t(1)) {};
    my_shared_ptr(const my_shared_ptr &);
    ~my_shared_ptr() { free(); };
    my_shared_ptr &operator=(const my_shared_ptr &);
    T &operator*() const { return *ptr; };
    T *operator->() const { return &(this->operator*()); }
    T *get() const { return ptr; }
private:
    T *ptr;
    std::size_t *counter;
    void free();
};

template<typename T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr &other)
    : ptr(other.ptr), counter(other.counter) {
    if (counter) {
        ++*counter;
    }
}

template<typename T>
my_shared_ptr<T> &my_shared_ptr<T>::operator=(const my_shared_ptr &other) {
    free();
    ptr = other.ptr;
    counter = other.counter;
    if (counter) {
        ++*counter;
    }
}

template<typename T>
inline void my_shared_ptr<T>::free() {
    if (counter && !(--*counter)) {
        delete ptr;
        delete counter;
    }
}

template<typename T, typename... Args>
my_shared_ptr<T> make_my_shared_ptr(Args&&... args) {
    return my_shared_ptr<T>(new T(std::forward<Args>(args)...));
}

template<typename T>
class my_unique_ptr {
public:
    my_unique_ptr(): ptr(nullptr) {};
    my_unique_ptr(const my_unique_ptr<T> &) = delete;
    explicit my_unique_ptr(T *p): ptr(p) {};
    ~my_unique_ptr() { free(); };
    my_unique_ptr &operator=(const my_unique_ptr<T> &) = delete;
    void release();
    void reset(T *new_p);
    T &operator*() { return *ptr; }
    T *operator->() { return &(this->operator*()); }
private:
    void free();
    T *ptr;
};

template<typename T>
void my_unique_ptr<T>::release() {
    free();
}

template<typename T>
void my_unique_ptr<T>::free() {
    if (ptr) {
        delete ptr;
    }
}

template<typename T>
void my_unique_ptr<T>::reset(T *new_p) {
    free();
    ptr = new_p;
}

#endif //CPP_LEARNING_MY_PTR_H
