#pragma once
#include <string>
#include <iostream>
#include <vector>

class Person
{
public:
	Person();
	Person(std::string name, int age, std::string gender);
	Person(std::string name, int age, std::string gender, int money);
	~Person();
	void virtual setAge(int age);
	void virtual setName(std::string name);
	void virtual setGender(std::string gender);
    void setMoney(int money);
    int getMoney() const;
	int virtual getAge() const;
	std::string virtual getName() const;
	std::string virtual getGender() const;
	int virtual getCount() const;
	void virtual print() const;
    Person(const Person& Person);
	Person(Person&& Person);
	Person& operator=(const Person& Person);
	friend std::ostream& operator<<(std::ostream& os, const Person& Person);
	
	

private:
	int age;
	std::string name;
	std::string gender;
	static int count;
	int* money;
};

