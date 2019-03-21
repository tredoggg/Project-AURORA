#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;

class Accounts{
    int id,currency_code, balance;
    char first_name[10],last_name[15],type;
    char middle_initial;


    public:
        void open_account(){
            srand(time(0));
            id = rand();
            cout << "Account Number: " << id << endl;
            cout << "Enter Customers First Name: " << endl;
            cin.ignore();
            cin.getline(first_name,10);
            cout << "Enter Customers Middle Initial: " << endl;
            cin >> middle_initial;
            cout << "Enter Customers Last Name: " << endl;
            cin.ignore();
            cin.getline(last_name,15);
            cout << "Enter Currency Code: " << endl;
            cin >> currency_code;
            cout << "Enter the account type (Chequing/Savings): " << endl;
            cin >> type;
            type=toupper(type);
            cout << "Enter starting balance: " << endl;
            cin >> balance;
            cout << "New Account created!!!" << endl;
            cout << "Press Enter to return back to the main menu: " << endl;

            string filename = std::to_string(id);

            ofstream customer;
            string abs_file_path = "C:\\banking_app\\Transaction\\" + filename + ".txt";
            customer.open(abs_file_path);
            customer << "Opening Balance: $" << balance << endl;
            customer.close();

            ofstream customer_master;
            customer_master.open("C:\\banking_app\\Accounts_master\\accounts.txt",ios_base::app);
            customer_master << id << " ";
            customer_master << first_name << " ";
            customer_master << middle_initial<< " ";
            customer_master << last_name << " ";
            customer_master << currency_code << " ";
            customer_master << type << " ";
            customer_master << balance << " ";
            customer_master << "\n";
            customer_master.close();
        }
        void closing_account(){
            balance = 0;
            auto filename = std::to_string(id);
            cout << "Enter account number: " << endl;
            cin >> filename;
            ofstream customer;
            string abs_file_path = "C:\\banking_app\\Transaction\\" + filename + ".txt";
            customer.open(abs_file_path,ios_base::app);
            customer << "Closing Balance: $" << balance << endl;
            cout << "The following account " << filename << " is now closed!!!" << endl;
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
		cout<<"\n\n\t04. Close Account";
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
                break;
            case 2:
                break;
            case 3:
                Accounts openingObject;
                openingObject.open_account();
                break;
            case 4:
                Accounts closingObject;
                closingObject.closing_account();
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
