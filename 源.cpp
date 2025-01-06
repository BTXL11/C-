#include<iostream>
#include<string>
#include"solution.h"
#include<cmath>
#include<vector>
#include<string.h>
#include"Person.h"
#include"student.h"
int main()
{   
	int a=10;
	student s1("Tom",18,"male",100,"1001");
	Person p1("John",20,"male",a);
	Person p2(p1);
	p2.setMoney(1000);
	p1.print();
	p2.print();
	s1.print();
	return 0;
}



















