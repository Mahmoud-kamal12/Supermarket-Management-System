#pragma once
#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
using namespace std;
class products
{
private:
	int id;
	char product_name[12];

public:
	float price, quantity,  discount , total;

	void setname()
	{
		cout << endl << "Please Enter The Name of The Product: ";
		cin.ignore();		cin.getline(this->product_name, 12);
	}
	void setid()
	{
		cout << endl << "Please Enter The ID of The Product: ";
		cin >> this->id;
	}

	char* getName()
	{
		return product_name;
	}
	int getid()
	{
		return id;
	}

	void showAllProducts();
	void show(int &i);
};
class order : public products
{
public:
	int ID;
	char name[12];
	char email[20];
	void showOrder(int& i);
};

class person
{
public:
	virtual void delet() = 0;
};

class user : public person
{
public:
	char fname[20];
	char lname[20];
	char email[20];
	char city[10];
	int  phone , streatNo, day, month, year;
	float balance;

	void Buy();
	void delet();
	void filldata();
	void showAllOrders(order pode, char k[20]);
};

class admin : public person
{
public:
	string user;
	string pass;

	void Add();
	void delet();
	void edit();
	bool login();

};


