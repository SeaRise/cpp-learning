#ifndef CPP_LEARNING_BLOB_H
#define CPP_LEARNING_BLOB_H

#include <vector>
#include <memory>
#include <stdexcept>

template<typename T> class Blob;

template<typename T> class BlobPtr;

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template<typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template<typename T>
class Blob {
    friend class BlobPtr<T>;
public:
    typedef typename std::vector<T>::size_type size_type;
    Blob(): data(std::make_shared<std::vector<T>>()) {}
    Blob(std::initializer_list<T> il) : data(il) {}
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    BlobPtr<T> begin() { return BlobPtr<T>(*this); }
    BlobPtr<T> end() {
        auto ret = BlobPtr<T>(*this, data->size());
        return ret;
    }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(const T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T& back();
    const T& back() const;
    T& operator[](size_type i);
    const T& operator[](size_type i) const;
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const {
        if (i >= data->size()) {
            throw std::out_of_range(msg);
        }
    }
};

template<typename T>
class BlobPtr {
    friend bool operator==<T> (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator!=<T> (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
public:
    typedef typename Blob<T>::size_type size_type;
    BlobPtr(): curr(0) {}
    BlobPtr(Blob<T> &a, size_type sz = 0): wptr(a.data), curr(sz) {}
    T &operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr<T> &operator++();
    BlobPtr<T> &operator--();
    BlobPtr<T> operator++(int);
    BlobPtr<T> operator--(int);
private:
    std::shared_ptr<std::vector<T>>
    check(size_type, const std::string &) const;

    std::weak_ptr<std::vector<T>> wptr;
    size_type curr;
};

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    if (lhs.curr != rhs.curr) {
        return false;
    }
    auto ptr = lhs.wptr.lock();
    auto otherPtr = rhs.wptr.lock();
    if (ptr && otherPtr) {
        return ptr.get() == otherPtr.get();
    } else if (!ptr && !otherPtr) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs);
}

template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(BlobPtr::size_type sz, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (sz >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
    check(curr, "increment past end of StrBlob");
    ++curr;
    return *this;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator--() {
    -- curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template<typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template<typename T>
T &Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
const T &Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
T &Blob<T>::operator[](Blob::size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
const T &Blob<T>::operator[](Blob::size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

#endif //CPP_LEARNING_BLOB_H
