#include "Person.h"
Person::Person() :age(0), name("someone"), gender("male"), money(nullptr)
{
    std::cout << "Person: " << name << " is created" << std::endl;
    count++;
};
Person::Person(std::string name, int age, std::string gender) : age(age), name(name), gender(gender) { count++; }
Person::Person(std::string name, int age, std::string gender, int money)
{
    this->age = age;
    this->name = name;
    this->gender = gender;
    if (money != 0)
    {
        this->money = new int(money);
    }
    else
    {
        this->money = nullptr;
    }
    count++;
}
;
Person::~Person() 
{
    std::cout << "Person: " << name << " is destroyed" << std::endl;
    if (money != nullptr)
    {
        delete money;
    }
    count--;
}
void Person::print() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "money:" << *money << std::endl;
    std::cout << "==========================================" << std::endl;
}
int Person::getAge() const { return age; };
std::string Person::getName() const { return name; };
std::string Person::getGender() const { return gender; };
int Person::getCount() const { return count; };
void Person::setAge(int age) { this->age = age; };
void Person::setName(std::string name) { this->name = name; };
void Person::setGender(std::string gender) { this->gender = gender; };
int Person::count = 0;
//Person::Person(const Person& Person):age(Person.age),name(Person.name),gender(Person.gender),money(Person.money){count++;}//undeep copy
Person::Person(const Person& Person):age(Person.age),name(Person.name),gender(Person.gender)//deep copy
{
    count++;
    if (Person.money != nullptr)
    {
        money = new int(*Person.money);
    }
}
Person::Person(Person&& Person) :age(std::move(Person.age)), name(std::move(Person.name)), gender(std::move(Person.gender)) 
{
    count++;
    if (Person.money != nullptr)
    {
        money = Person.money;
        delete Person.money;
    }
};
Person& Person::operator=(const Person& Person)
{
    if (this == &Person)
        return *this;
    age = Person.age;
    name = Person.name;
    gender = Person.gender;
    if (Person.money != nullptr)
    {
        if (money != nullptr)
        {
            delete money;
        }
        money = new int(*Person.money);
    }
    count++;
    return *this;
}
void Person::setMoney(int money)
{
    if (this->money == nullptr)
    {
        this->money = new int(money);
    }
    else
    {
        *(this->money) = money;
    }

}
int Person::getMoney() const
{
    if (money == nullptr)
    {
        return 0;
    }
    return *(this->money);
}
std::ostream& operator<<(std::ostream& os, const Person& Person)
{
    os << "Name: " << Person.name << std::endl
        << "Age: " << Person.age << std::endl
        << "Gender: " << Person.gender << std::endl;
    if (Person.money != nullptr)
    {
        os << "Money: " << *Person.money << std::endl;
    }
    else
    {
        os << "Money: " << "null" << std::endl;
    }
    os << "=========================" << std::endl;
    return os;
}
