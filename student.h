#pragma once
#include "Person.h"
#include<iostream>
class student: public Person
{
	public:
		student(std::string name, int age,std::string gender,int money, std::string id);
		~student();
		student(const student& s);
		student(student&& s);
		student& operator=(const student& s);
		student& operator=(student&& s);
		std::string get_id();
		void set_id(std::string id);
		void print();
		friend std::ostream& operator<<(std::ostream& os, const student& s);
	private:
		std::string id;
		static int count;

};

