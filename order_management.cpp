#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;

class start_of_day{
    public:
};
class inventory_management{
    public:
        void list_all_items(){
            string line;
            ifstream filename ("inventory.txt");
            if (filename.is_open()){
                while (getline (filename,line)){
                    cout << line << endl;
                }
                filename.close();
            }else cout << "Unable to open systemlog.txt!!!";
            cout << endl;
            cout << endl;
            cout << "Press Enter to return back to Inventory Management Menu!!!" << endl;
        }
        void add_an_item(){
            int id;
            string product;
            int quantity;
            double price, tax,tax_rate=0.165;
            char taxable;

            srand(time(0));
            id = rand();
            cout << "Item ID: " << id << endl;
            cout << "Enter Product Name: " << endl;
            cin >> product;
            cout << "Enter Quantity of Product: " << endl;
            cin >> quantity;
            cout << "Is Item Taxable [T/NT]: " << endl;
            cin >> taxable;
            cout << "Enter cost per item: $" << endl;
            cin >> price;
            if(taxable=='T'){
                tax=price*tax_rate;
                cout << tax << endl;
                price=price+tax;
                cout << std::setprecision(2) << price << endl;
            }else{
                price=price;
            }
            cout << endl;
            cout << endl;
            cout << "Press Enter to return back to Inventory Management Menu!!!" << endl;

            string filename = "inventory.txt";
            ofstream inventorylog;
            inventorylog.open(filename, ios_base::app);
            inventorylog << id << " ";
            inventorylog << product << " ";
            inventorylog << quantity << " ";
            inventorylog << taxable << " ";
            inventorylog << price << " ";
            inventorylog << "\n";
            inventorylog.close();
        }
        void remove_item(){
            string deleteline,line;
            cout << "Which item do you want to remove? ";
            cin >> deleteline;
            ifstream file;
            ofstream temp_file;
            file.open("inventory.txt");
            temp_file.open("temp.txt");
            while (getline(file,line)){
                    if(line!=deleteline)
                    //line.replace(line.find(deleteline),deleteline.length(),"");
                        temp_file<<line<<endl;
            }
            temp_file.close();
            file.close();

            remove("inventory.txt");
            rename("temp.txt","inventory.txt");
            }
};
class sales_management{
    public:
};
class view_system_log{
    public:
        void view_logs(){
            string line;
            ifstream filename ("systemlog.txt");
            if (filename.is_open()){
                while (getline (filename,line)){
                    cout << line << endl;
                }
                filename.close();
            }else cout << "Unable to open systemlog.txt!!!";
        }
};
class exit_application{
    char choice;
    public:
        void close_app(){
        auto system_start = chrono::system_clock::now();
        auto system_end = chrono::system_clock::now();
        std::chrono::duration<double> elapse_second=system_end-system_start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(system_end);
        cout << "Are you sure you want to exit this application [Y/N]?: " << endl;
        cin >> choice;
        choice=toupper(choice);
        if(choice='Y'){
            string filename = "systemlog.txt";
            ofstream systemlog;
            systemlog.open(filename, ios_base::app);
            systemlog << "Exit System: " <<ctime(&end_time);
            systemlog.close();
        }else{
        }
        }
};
class WaitingQueue{
public:
    void is_emty(bool){
    }
    void is_full(bool){
    }
    void size(){
    }
    void enqueue(){
    }
    void dequeue(){
    }
};

int main(){
    int option;
    do{
        main_menu:
        {
        system("cls");
        cout<<"\n\n\n\tIrie Call Center Operations Limited";
        cout<<"\n\n\n\tOrder Management System";
        cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t1. Start of Day";
		cout<<"\n\n\t2. Inventory Management";
		cout<<"\n\n\t3. Sales Management";
		cout<<"\n\n\t4. View System Log";
		cout<<"\n\n\t5. Exit Application";
		cout<<"\n\n\tPlease Select An Option From The Menu(1-5): ";
        cin >> option;
        system("cls");
        }
        switch(option)
        {
            case 1:
                break;
            case 2:
                do{
                        system("cls");
                        cout<<"\n\n\n\tIrie Call Center Operations Limited";
                        cout<<"\n\n\n\tInventory Management Menu";
                        cout<<"\n\n\t1. List All Items";
                        cout<<"\n\n\t2. Add an Item";
                        cout<<"\n\n\t3. Remove an Item";
                        cout<<"\n\n\t4. Return to Main Menu";
                        cout<<"\n\n\tPlease Select An Option From The Menu(1-4): ";
                        cin >> option;
                        system("cls");
                        switch(option)
                        {
                            case 1:
                                inventory_management viewinvObject;
                                viewinvObject.list_all_items();
                                break;
                            case 2:
                                inventory_management addinvObject;
                                addinvObject.add_an_item();
                                break;
                            case 3:
                                inventory_management removeObject;
                                removeObject.remove_item();
                                break;
                            case 4:
                                goto main_menu;
                                break;
                            default:cout<<"\a";
                        }
                        cin.ignore();
                        cin.get();
                    }while(option!=4);
                break;
            case 3:
                       do{
                        system("cls");
                        cout<<"\n\n\n\tIrie Call Center Operations Limited";
                        cout<<"\n\n\n\tSales Management Menu";
                        cout<<"\n\n\t1. Create a Sales Receipt";
                        cout<<"\n\n\t2. Create a Receipt";
                        cout<<"\n\n\t3. Show All Sales";
                        cout<<"\n\n\t4. Return to Main Menu";
                        cout<<"\n\n\tPlease Select An Option From The Menu(1-4): ";
                        cin >> option;
                        system("cls");
                        switch(option)
                        {
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                goto main_menu;
                                break;
                            default:cout <<"\a";
                        }
                        cin.ignore();
                        cin.get();
                    }while(option!=4);
                break;
            case 4:
                view_system_log viewObject;
                viewObject.view_logs();
                break;
            case 5:
                exit_application closingObject;
                closingObject.close_app();
                break;
            default:cout << "\a";
        }
        cin.ignore();
        cin.get();
    }while(option!=5);
    return 0;
}
