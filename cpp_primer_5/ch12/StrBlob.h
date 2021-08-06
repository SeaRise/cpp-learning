#ifndef CPP_LEARNING_STRBLOB_H
#define CPP_LEARNING_STRBLOB_H


#include <vector>
#include <string>
#include <memory>

class StrBlobPtr;

class ConstStrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    bool empty() const { return data->empty(); }
    size_type size() const { return data->size(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

    ConstStrBlobPtr cbegin();
    ConstStrBlobPtr cend();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) {}
    explicit StrBlobPtr(StrBlob &a): wptr(a.data), curr(0) {}
    StrBlobPtr(StrBlob &a, StrBlob::size_type st): wptr(a.data), curr(st) {}
    std::string &deref() const;
    StrBlobPtr &incr();
    bool equalsTo(const StrBlobPtr &) const;

private:
    const std::weak_ptr<std::vector<std::string>> wptr;
    StrBlob::size_type curr;
    std::shared_ptr<std::vector<std::string>> check(StrBlob::size_type, const std::string &) const;
};

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr(): curr(0) {}
    explicit ConstStrBlobPtr(const StrBlob &a): wptr(a.data), curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, StrBlob::size_type st): wptr(a.data), curr(st) {}
    const std::string &deref() const;
    ConstStrBlobPtr &incr();
    bool equalsTo(const ConstStrBlobPtr &) const;

private:
    const std::weak_ptr<std::vector<std::string>> wptr;
    StrBlob::size_type curr;
    std::shared_ptr<std::vector<std::string>> check(StrBlob::size_type, const std::string &) const;
};

#endif //CPP_LEARNING_STRBLOB_H
