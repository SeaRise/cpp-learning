#include "StrBlob.h"
#include "memory"
#include "vector"
#include "string"
#include "stdexcept"

using namespace std;

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

inline void StrBlob::check(StrBlob::size_type i, const string &msg) const {
    if (i >= data->size()) throw out_of_range(msg);
}

inline void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

ConstStrBlobPtr StrBlob::cbegin() {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() {
    auto ret = ConstStrBlobPtr(*this, data->size());
    return ret;
}

inline shared_ptr<vector<string>> StrBlobPtr::check(StrBlob::size_type sz, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (sz >= ret->size()) {
        throw out_of_range(msg);
    }
    return ret;
}

string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "dereference past end");
    ++curr;
    return *this;
}

bool StrBlobPtr::equalsTo(const StrBlobPtr &other) const {
    if (curr != other.curr) {
        return false;
    }
    auto ptr = wptr.lock();
    auto otherPtr = other.wptr.lock();
    if (ptr && otherPtr) {
        return ptr.get() == otherPtr.get();
    } else if (!ptr && !otherPtr) {
        return true;
    } else {
        return false;
    }
}

inline shared_ptr<vector<string>> ConstStrBlobPtr::check(StrBlob::size_type sz, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (sz >= ret->size()) {
        throw out_of_range(msg);
    }
    return ret;
}

const std::string &ConstStrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr() {
    check(curr, "dereference past end");
    ++curr;
    return *this;
}

bool ConstStrBlobPtr::equalsTo(const ConstStrBlobPtr &other) const {
    if (curr != other.curr) {
        return false;
    }
    auto ptr = wptr.lock();
    auto otherPtr = other.wptr.lock();
    if (ptr && otherPtr) {
        return ptr.get() == otherPtr.get();
    } else if (!ptr && !otherPtr) {
        return true;
    } else {
        return false;
    }
}

