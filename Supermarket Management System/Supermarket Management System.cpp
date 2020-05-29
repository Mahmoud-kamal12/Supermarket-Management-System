#include"Class.h"


int main(int argc, char* argv[])
{
    int op = 0, d, f = 0;
    char kk[20];
    admin a;
    user u;
    products p;
    order oo;
    person *pr;
    oo.ID = 0;
    while (op != 3)
    {
        cout << "\t\t\t\t 1- Admin" << endl;
        cout << "\t\t\t\t 2- Customer" << endl;
        cout << "\t\t\t\t 3- to Exit" << endl;
        cout << "Enter Option (1-3) : ";
        cin >> op;

        if (op == 1)
        {
            do
            {
                system("cls");
                if (f == 0) { cout << "\t\t\t\t\tUser Name = admin \n\t\t\t\t\tPasswor = admin\n\n" << endl; }
                if (f == 1 || a.login())
                {
                    f = 1;
                    pr = &a;
                    cout << "\t\t\t\t 1- to Add PRODECTS " << endl;
                    cout << "\t\t\t\t 2- to DISPLAY ALL PRODECTS " << endl;
                    cout << "\t\t\t\t 3- to UPDATE PRODUCT" << endl;
                    cout << "\t\t\t\t 4- to DELETE PRODUCT" << endl;
                    cout << "\t\t\t\t 5- to Exit" << endl;
                    cout << "Enter Option (1-5) : ";
                    cin >> op;
                    switch (op)
                    {
                    case 1:
                        system("cls");
                        a.Add();
                        cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                        cin >> d;
                        break;
                    case 2:
                        system("cls");
                        p.showAllProducts();
                        cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                        cin >> d;
                        break;
                    case 3:
                        system("cls");
                        a.edit();
                        cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                        cin >> d;
                        break;
                    case 4:
                        system("cls");
                        pr->delet();
                        cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                        cin >> d;
                        break;
                    case 5:
                        exit(0);
                    default:
                        cout << "Enter correct num ";
                        d = 0;
                        exit(0);
                        cout << "\a";
                        break;
                    }
                }
                else
                {
                    cout << "Enter correct user or pass ";
                    d = 1;
                    exit(0);
                }
            } while (d == 1);
        }
        else if (op == 2)
        {
            pr = &u;
            do
            {
                system("cls");
                p.showAllProducts();
                
                cout << "\n\n\t\t\t\t 1- to BUY" << endl;
                cout << "\t\t\t\t 2- to SHOW ALL ORDERS" << endl;
                cout << "\t\t\t\t 3- to DELET ORDER" << endl;
                cout << "\t\t\t\t 4- to Exit" << endl;
                cout << "Enter Option (1-4) : ";
                cin >> op;
                switch (op)
                {
                case 1:
                    system("cls");
                    u.Buy();
                    cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                    cin >> d;
                    break;
                case 2:
                    system("cls");
                    u.showAllOrders(oo ,kk );
                    cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                    cin >> d;
                    break;
                case 3:
                    system("cls");
                    pr->delet();
                    cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                    cin >> d;
                    break;
                case 4:
                    d = 0;
                    exit(0);
                    break;
                default:
                    cout << "Enter correct num ";
                    d = 0;
                    exit(0);
                    cout << "\a";
                    break;
                }
            } while (d == 1);
        }
        else if (op == 3) { break; }
        else
        {
            cout << "Enter correct num ";
            exit(0);
            cout << "\a";
        }

    }

    return 0;
}