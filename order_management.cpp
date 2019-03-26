#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;

class start_of_day{
    public:
};
class inventory_management{
    public:
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
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
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
