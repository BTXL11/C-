#include "student.h"
student::student(std::string name, int age, std::string gender,int money, std::string id)
{
    setName(name);
    setAge(age);
    setGender(gender);
    setMoney(money);
    this->id = id;
    std::cout<<"student:"<<getName()<<" is created"<<std::endl;
}

student::~student()
{
    std::cout<<"student:"<<getName()<<" is destroyed"<<std::endl;
}

student::student(const student& s)
{
    setName(s.getName());
    setAge(s.getAge());
    setGender(s.getGender());
    setMoney(s.getMoney());
    this->id = s.id;
}
student::student(student&& s)
{
    setName(std::move(s.getName()));
    setAge(std::move(s.getAge()));
    setGender(std::move(s.getGender()));
    setMoney(std::move(s.getMoney()));
    this->id = std::move(s.id);
}
student& student::operator=(const student& s)
{
    if (this == &s)
        return *this;
    else
        setName(s.getName());
        setAge(s.getAge());
        setGender(s.getGender());
        setMoney(s.getMoney());
        this->id = s.id;
    return *this;
}


student& student::operator=(student&& s)
{
    if (this == &s)
        return *this;
    else
        setName(std::move(s.getName()));
        setAge(std::move(s.getAge()));
        setGender(std::move(s.getGender()));
        setMoney(std::move(s.getMoney()));
        this->id = std::move(s.id);
    return *this;
}

std::string student::get_id()
{
    return std::string(this->id);
}

void student::set_id(std::string id)
{
    this->id = id;
}

void student::print()
{
    std::cout << "Name:" << getName() << std::endl;
    std::cout << "Age:" << getAge() << std::endl;
    std::cout << "Gender:" << getGender() << std::endl;
    std::cout << "ID:" << this->id << std::endl;
    if (getMoney() > 0)
        std::cout << "Money:" << getMoney() << std::endl;
    else
        std::cout << "Money:None" << std::endl;
    std::cout << "==============================================" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const student& s)
{
    os << "Name:"<< s.getName() << std::endl;
    os << "Age:" << s.getAge() << std::endl;
    os << "Gender:" << s.getGender() << std::endl;
    os << "ID:" << s.id << std::endl;
    os << "money:" << s.getMoney() << std::endl;

    os << "=================================" << std::endl;
    return os;
}


