#include "Class.h"
#include<string.h>

products p;
admin a;
user u;
order o;
fstream fp , fptemp ;
person *pr;

void coo(products n, order &oor )
{
	oor.ID = n.getid();
	strcpy_s(oor.name, n.getName());
	oor.price = n.price;
	oor.discount = n.discount;
	oor.total = n.total;
}

void admin::Add()
{
	p.setid();
	p.setname();
	cout << endl << "Please Enter The Price of The Product: ";
	cin >> p.price;
	cout << "Please Enter The Discount (%): ";
	cin >> p.discount;
	cout << "Please Enter The product quantity : ";
	cin >> p.quantity;
	p.total = p.price - ((p.discount / 100) * p.price);
	fp.open("Products.dat", ios::app );
	fp.write((char*)&p, sizeof(products));
	fp.close();
	cout << endl << endl << "The Product Has Been Sucessfully ADDED...";
}

void admin::delet()
{
	p.showAllProducts();
	cout << "\n=====================================================\n";
	int id ;
	cout << "Enter id = ";
	cin >> id;
	fp.open("Products.dat", ios::in);
	fptemp.open("temp.dat", ios::app);
	while (fp.read((char*)&p , sizeof(products)))
	{
		if (id != p.getid())
		{
			fptemp.write((char*)&p, sizeof(products));
		}
	}
	fp.close();
	fptemp.close();
	remove("Products.dat");
	rename("temp.dat", "Products.dat");
}

void admin::edit()
{
	system("cls");
	int id , i =0 , c = 0;
	p.showAllProducts();
	cout << "\n=====================================================\n";
	cout << "Enter id = ";
	cin >> id;
	fp.open("Products.dat", ios::in);
	fptemp.open("temp.dat", ios::app);
	while (fp.read((char*)&p, sizeof(products)))
	{
		if (id == p.getid())
		{
			system("cls");
			p.show(c);
			cout << "\n\n\t\t\t\t\t Enter New info \n\n";
			p.setid();
			p.setname();
			cout << endl << "Please Enter The Price of The Product: ";
			cin >> p.price;
			cout << "Please Enter The Discount (%): ";
			cin >> p.discount;
			cout << "Please Enter The product quantity : ";
			cin >> p.quantity;
			p.total = p.price - ((p.discount / 100) * p.price);
			i = 1;
		}
		fptemp.write((char*)&p, sizeof(products));
	}
	if (i == 0)
		cout << "\n\n\t\t\t\t\tNot found" << endl;
	else
	{
		cout <<"\n\n\t\t\t\t\t Successfully Updated...";
	}
	fp.close();
	fptemp.close();
	remove("Products.dat");
	rename("temp.dat", "Products.dat");
}

bool admin::login()
{
	cout << "Enter user name = ";
	cin >> this->user;
	cout << "Enter user password = ";
	cin >> this->pass;
	if (this->user == "admin" && this->pass == "admin")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void user::Buy()
{
	int idd;
	p.showAllProducts();
	cout << "\n\n========================================================================\n\n";
	cout << "Enter product id = ";
	cin >> idd;
	cout << "Enter quantity = "; 
	cin >> o.quantity;
	u.filldata();
	fptemp.open("orders.dat", ios::app);
	fp.open("Products.dat", ios::in);
	while (fp.read((char*)&p, sizeof(products)))
	{
		if (idd == p.getid())
		{
			coo(p, o);
			strcpy_s(o.email, u.email);
			fptemp.write((char*)&o, sizeof(order));
		}
	}
	fp.close();
	fptemp.close();
		
}

void user::delet()
{
	int z = 0;
	char emai[20];
	int k;
	showAllOrders(o , emai);
	cout << "\n\n=========================================================================\n\n";
	cout << "Enter id : ";
	cin >> k;
	fp.open("orders.dat", ios::in);
	fptemp.open("temp.dat", ios::app);
	while (fp.read((char*)&o , sizeof(order)))
	{
		if( (strcmp(o.email ,emai)==0))
		{
			if (k == o.ID)
			{
				continue;
			}
		}
		fptemp.write((char*)&o, sizeof(order));
	}
	fp.close();
	fptemp.close();
	remove("orders.dat");
	rename("temp.dat", "orders.dat");
}

void user::filldata()
{
	cout << "Enter first Name : ";
	cin.ignore(); cin.getline(fname, 20);
	cout << "Enter Last Name : ";
	cin.getline(lname, 20);
	cout << "Enter city  : ";
	cin.getline(city, 20);
	cout << "Enter Email : ";
	cin.getline(email, 20);
	cout << "Enter phone = ";
	cin >> phone;
	cout << "Enter Streat No = ";
	cin >> streatNo;
	cout << "Enter current day = ";
	cin >> day;
	cout << "Enter current month = ";
	cin >> month;
	cout << "Enter current year = ";
	cin >> year;
	cout << "Enter balance = ";
	cin >> balance;
	fp.open("user.dat",ios::app);
	fp.write((char*)this, sizeof(user));
	fp.close();
}

void user::showAllOrders(order pode , char k[20])
{
	double tot = 0;
	int x = 0;
	cout << "Enter your email : ";
	cin.ignore();		cin.getline(k,20);
	fp.open("orders.dat", ios::in);
	while (fp.read((char*)&pode,sizeof(order)))
	{
		if (strcmp(pode.email,k) == 0)
		{
			tot += pode.quantity * pode.total;
			pode.showOrder(x);
		}
	}
	fp.close();
	cout << "\n\n\t\t\t\t" << "Total Money you will pay =  " << tot << "\n\n" << endl;
}

void products::showAllProducts()
{
	int i = 0;
	fp.open("Products.dat", ios::in);
	while (fp.read((char*)&p, sizeof(products)))
	{
		p.show(i);
	}
	fp.close();
}

void products::show(int& i)
{
	if (i == 0)
	{
		cout << "Pro id\t" << setw(12) << "Product Name" << "\t" << setw(5) << "Price" << "\t" << setw(7) << "Discount" << "\t" << setw(10) << "Net Price" << "\t" << setw(9) << "Quantity" << endl;
		i++;
	}
	cout << id<<"\t" << setw(12) << product_name<< "\t" << setw(5) << price << "\t" << setw(7) << discount << "\t" << setw(10) << total <<"\t" << setw(9)<< quantity << endl;

}

void order::showOrder(int &i)
{
	if (i == 0)
	{
		cout << "Pro id\t" << setw(12) << "Product Name" << "\t" << setw(5) << "Price" << "\t" << setw(7) << "Discount" << "\t" << setw(10) << "Net Price" << "\t" << setw(9) << "Quantity" << "\t" << endl;
		i++;
	}
	cout << ID << "\t" << setw(12) << name << "\t" << setw(5) << price << "\t" << setw(7) << discount << "\t" << setw(10) << total << "\t" << setw(9) << quantity << endl;

}
