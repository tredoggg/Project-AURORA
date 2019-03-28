#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string.h>
#include <time.h>
#include <iomanip>
using namespace std;

#define SIZE 10

class WaitingQueue
{
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    WaitingQueue(int size = SIZE);

    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool is_Empty();
    bool is_Full();
};

WaitingQueue::WaitingQueue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

void WaitingQueue::dequeue()
{
    if(is_Empty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing" << arr[front] << '\n';

    front = (front + 1) % capacity;
    count--;
}
void WaitingQueue::enqueue(int item)
{
    if(is_Full())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting" << item << '\n';

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

int WaitingQueue::peek()
{
    if(is_Empty())
    {
        cout << "UnderFlow\nProgram Terminiated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

int WaitingQueue::size(){
    return count;
}

bool WaitingQueue::is_Empty(){
    return (size() == 0);
}
bool WaitingQueue::is_Full(){
    return (size() == capacity);
}
class start_of_day{
    public:
        void start_location(){
        auto system_start = chrono::system_clock::now();
        auto system_end = chrono::system_clock::now();
        std::chrono::duration<double> elapse_second=system_end-system_start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(system_end);
        WaitingQueue customer(10);
        cout << "Location has successfully started!!!" << endl;
        string filename = "systemlog.txt";
        ofstream systemlog;
        systemlog.open(filename, ios_base::app);
        systemlog << "Start System: " <<ctime(&end_time);
        systemlog.close();
        }
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
            char taxable[10];

            srand(time(0));
            id = rand();
            cout << "Item ID: " << id << endl;
            cout << "Enter Product Name: " << endl;
            cin >> product;
            cout << "Enter Quantity of Product: " << endl;
            cin >> quantity;
            cout << "Is Item Taxable [TA/NT]: " << endl;
            cin >> taxable;
            cout << "Enter cost per item: $" << endl;
            cin >> price;
            if(strcmp(taxable, "TA")){
                tax=price*tax_rate;
                cout << tax << endl;
                price=price+tax;
                cout << std::setprecision(2) << price << endl;
            }else if(strcmp(taxable,"NT")){
                price=price-tax;
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
    void create_sales_rep(){
        int sales_id;
        string first_name;
        string last_name;
        string email;
        char gender;

        srand(time(0));
        sales_id = rand();
        cout << "Sales Representative ID#: "<< sales_id << endl;
        cout << "Please enter first name: " << endl;
        cin >> first_name;
        if(first_name.empty()){
            cout << "Please enter a valid input!!!" << endl;
        }
        cout << "Please enter last name: " << endl;
        cin >> last_name;
        if(last_name.empty()){
            cout << "Please enter a valid input!!!" << endl;
        }
        cout << "Please enter email address: " << endl;
        cin >> email;
        if(email.empty()){
            cout << "Please enter a valid input!!!" << endl;
        }
        cout << "Please enter gender: " << endl;
        cin >> gender;
        gender = toupper(gender);
       // if(gender.empty()){
       //     cout << "Please enter a valid input!!!" << endl;
        //}
        if (gender!='M'||gender!='F'){
            cout << "Please enter valid input [M/F]: " << endl;
            cin >> gender;
        }
        cout << endl;
        cout << endl;
        cout << "Press Enter to return back to Inventory Management Menu!!!" << endl;

        string filename = "salesreps.txt";
        ofstream saleslog;
        saleslog.open(filename, ios_base::app);
        saleslog << sales_id << " ";
        saleslog << first_name << " ";
        saleslog << last_name << " ";
        saleslog << email << " ";
        saleslog << gender << " ";
        saleslog << "\n";
        saleslog.close();

    }
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
        //do{
        //}while(!choice)
        if(choice='Y'){
            string filename = "systemlog.txt";
            ofstream systemlog;
            systemlog.open(filename, ios_base::app);
            systemlog << "Exit System: " <<ctime(&end_time);
            systemlog.close();
            exit(EXIT_SUCCESS);
        }else if(choice='N'){
            //goto main_menu;
        }
        }
};

int main(){
    int option;
    do{
        main_menu:
        {
        system("cls");
        cout<<"\n\n\n\t       Irie Call Center Operations Limited";
        cout<<"\n\t-----------------------------------------------";
        cout<<"\n\t             Order Management System";
        cout<<"\n\t-----------------------------------------------";
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
                start_of_day startObject;
                startObject.start_location();
                break;
            case 2:
                do{
                        system("cls");
                        cout<<"\n\n\n\t        Irie Call Center Operations Limited";
                        cout<<"\n\t-----------------------------------------------";
                        cout<<"\n\t            Inventory Management Menu";
                        cout<<"\n\t-----------------------------------------------";
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
                        cout<<"\n\n\n\t        Irie Call Center Operations Limited";
                        cout<<"\n\t-----------------------------------------------";
                        cout<<"\n\t              Sales Management Menu";
                        cout<<"\n\t-----------------------------------------------";
                        cout<<"\n\n\t1. Create a Sales Representative";
                        cout<<"\n\n\t2. Create a Receipt";
                        cout<<"\n\n\t3. Print a Receipt";
                        cout<<"\n\n\t4. Show All Sales";
                        cout<<"\n\n\t5. Return to Main Menu";
                        cout<<"\n\n\tPlease Select An Option From The Menu(1-5): ";
                        cin >> option;
                        system("cls");
                        switch(option)
                        {
                            case 1:
                                sales_management createrepObject;
                                createrepObject.create_sales_rep();
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                break;
                            case 5:
                                goto main_menu;
                                break;
                            default:cout <<"\a";
                        }
                        cin.ignore();
                        cin.get();
                    }while(option!=5);
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
