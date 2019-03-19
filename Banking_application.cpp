#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class Accounts{
    int id,currency_code;
    char first_name[10],last_name[15],type[10];
    char middle_initial;

    public:
        void open_account(){
            id = rand();
            cout << "Account Number: " << id << endl;
            cout << "Enter Customers First Name: " << endl;
            cin >> first_name;
            cout << "Enter Customers Middle Initial: " << endl;
            cin >> middle_initial;
            cout << "Enter Customers Last Name: " << endl;
            cin >> last_name;
            cout << "Enter Currency Code: " << endl;
            cin >> currency_code;
            cout << "Enter Account Type: " << endl;
            cin >> type;


            auto filename = std::to_string(id);
            ofstream customer;
            customer.open(filename.c_str());
            customer << id << endl;
            customer << first_name << endl;
            customer << middle_initial << endl;
            customer << last_name << endl;
            customer << currency_code << endl;
            customer << type << endl;
            customer.close();
        }
        void closing_account(){
        }
        void list_accounts(){
        }
        void account_balance(){
        }
};
class Transactions{
    public:
        void create_trans(){
        }
        void save_trans(){
        }
        void show_trans(){
        }
};
class Log{
    public:
        void add_to_queue(){
        }
        void take_from_queue(){
        }
        void items_in_queue(){
        }
        void is_queue_emty(){
        }
        void is_queue_full(){
        }
};
class CustomerQueue{
    public:
};
int main()
{
    int option;
    do{
        system("cls");
        cout<<"\n\n\n\tWelcome to AFC Cooperative Credit Union Limited";
        cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. Open Branch";
		cout<<"\n\n\t02. Close Branch";
		cout<<"\n\n\t03. Open Account";
		cout<<"\n\n\t04. Open Account";
		cout<<"\n\n\t05. Process Transaction";
		cout<<"\n\n\t06. Get Account Balance";
		cout<<"\n\n\t07. View All Accounts";
		cout<<"\n\n\t08. View System Log";
		cout<<"\n\n\t09. Exit";
		cout<<"\n\n\tPlease Select An Option From The Menu(1-9): ";
		cin>>option;
        system("cls");
        switch(option)
        {
            case 1:
                Accounts accountsObject;
                accountsObject.open_account();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                cout << "Thank you for using AFC Cooperative Credit Union Limited!!!" << endl << endl;
                break;
            default:cout << "\a";
        }
        cin.ignore();
        cin.get();
    }while(option!=9);
    return 0;
}

