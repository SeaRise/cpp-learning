#ifndef CPP_LEARNING_PERSION_H
#define CPP_LEARNING_PERSION_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <utility>

class Person {
    friend std::istream &read(std::istream &is, Person &person);

public:
    Person() = default;
    Person(std::string paramName, std::string paramAddress)
            : name(std::move(paramName)), address(std::move(paramAddress)) {
    };
    explicit Person(std::string paramName)
        : name(std::move(paramName)) {
    };
    explicit Person(std::istream &is);

    std::string getName() const { return name; };
    std::string getAddress() const { return address; };

private:
    std::string name{};
    std::string address{};
};

std::istream &read(std::istream &is, Person &person) {
    return is >> person.name >> person.address;
}

Person::Person(std::istream &is) {
    if (!read(is, *this)) {
        throw std::runtime_error("No data?!");
    }
}

#endif //CPP_LEARNING_PERSION_H
