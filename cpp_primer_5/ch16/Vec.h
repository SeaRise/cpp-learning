#ifndef CPP_LEARNING_VEC_H
#define CPP_LEARNING_VEC_H

#include <memory>

template<typename T>
class Vec {
public:
    Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(const Vec &);
    Vec &operator=(const Vec &);
    ~Vec();
    void push_back(const T &);
    void push_back(const T &&);
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }
private:
    std::allocator<T> alloc;
    void chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }
    std::pair<T *, T *> alloc_n_copy(const T *, const T *);
    void free();
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;
};

template<typename T>
Vec<T>::Vec(const Vec &vec) {
    auto new_data = alloc_n_copy(vec.begin(), vec.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

template<typename T>
Vec<T>::~Vec() {
    free();
}

template<typename T>
Vec<T> &Vec<T>::operator=(const Vec &vec) {
    auto new_data = alloc_n_copy(vec.begin(), vec.end());
    free();
    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

template<typename T>
void Vec<T>::push_back(const T &t) {
    chk_n_alloc();
    alloc.construct(first_free++, t);
}

template<typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *t1, const T *t2) {
    T* data = alloc.allocate(t2 - t1);
    return std::pair<T *, T *>(data, std::uninitialized_copy(t1, t2, data));
}

template<typename T>
void Vec<T>::free() {
    if (elements) {
        for (auto p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

template<typename T>
void Vec<T>::reallocate() {
    auto new_capacity = size() ? 2 * size() : 1;
    auto new_data = alloc.allocate(new_capacity);
    auto dest = new_data;
    auto elem = elements;
    for (int i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

template<typename T>
void Vec<T>::push_back(const T &&t) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(t));
}

#endif //CPP_LEARNING_VEC_H
