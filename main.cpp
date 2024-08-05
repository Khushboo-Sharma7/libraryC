#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class bookshop{
    public:
        void control_panel();
        void add_book();
        void show_book();
        void check_book();
        void update_book();
        void del_book();
};

void bookshop::control_panel()
{
    system("cls");
    cout <<"----Control Panel----";
    cout <<"\n1. ADD BOOK";
    cout<<"\n2. DISPLAY BOOKS";
    cout<<"\n3. CHECK PARTICULAR BOOK";
    cout <<"\n4. UPDATE BOOK";
    cout <<"\n5. DELETE A BOOK";
    cout <<"\n6. EXIT";
}

void bookshop::add_book()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name,a_name,b_id;
    cout <<"\n\t\t\tADD BOOKS";
    cout <<"\nBook ID:";
    cin>>b_id;
    cout <<"\nBook Name:";
    cin>>b_name;
    cout <<"\nAuthor Name:";
    cin>>a_name;
    cout <<"\nNO of books:";
    cin>>no_copy;

    file.open("book.txt",ios::out|ios::app);
    file<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
    file.close();
}
void bookshop::show_book()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name,b_id,a_name;
    cout <<"\n---ALL BOOKS---";

    file.open("book.txt",ios::in);
    if(!file)
        cout <<"\nFile Opening Error";
    else
    {
        cout <<"\n\n\nBook ID\t\tBook"<<"\t\tAuthor\t\tNO.of BOOks\n\n";
        file>>b_id>>b_name;
        file>>a_name>>no_copy;

        while(!file.eof())
        {
            cout <<" "<<b_id
            <<"\t\t"<<b_name
            <<"\t\t"<<a_name
            <<"\t\t"<<no_copy
            <<"\n\n";
            file >>b_id>>b_name;
            file>>a_name>>no_copy;
        }
        system("pause");
        file.close();
    }
}

void bookshop::check_book()
{
    system("cls");
    fstream file;
    int no_copy,count=0;
    string b_id,b_name,a_name,b_idd;

    cout << "\n\n\t\t\t\tCheck "
         << "Particular Book";

    file.open("book.txt",ios::in);
    if(!file)
        cout <<"\n\nFile Opening Error";
    else{
        cout <<"\n\nBook ID:";
        cin>>b_idd;
        file>>b_id>>b_name;
        file>>a_name>>no_copy;

        while(!file.eof())
        {
            if(b_idd==b_id)
            {
                system("cls");
                cout <<"\n\n\t\t\t\t"<<"Check Particular Book";
                cout <<"\n\nBook ID:"<<b_id;
                cout <<"\nName:"<<b_name;
                cout <<"\nAuthor:"<<a_name;
                cout <<"\nNo. of Books:"<<no_copy;
                cout <<endl <<endl;
                count++;
                break;
            }
            file>>b_id>>b_name;
            file>>a_name>>no_copy;
        }
        system("pause");
        file.close();
        if(count==0)
        cout<<"\n\nBook ID Not Found....";
    }
}

void bookshop::update_book()
{
    system("cls");
    fstream file1,file;
    int no_copy,no_co,count=0;
    string b_name,b_na,a_name,a_na,b_idd,b_id;

    cout <<"----UPDATE BOOK RECORD----";
    file1.open("book1.txt",ios::app|ios::out);
    file.open("book.txt",ios::in);

    if(!file)
    cout<<"\nFile Opening Error!!!";
    else{
        cout <<"\nEnter Book ID:";
        cin>>b_id;
        file>>b_idd>>b_name>>a_name>>no_copy;
        while(!file.eof())
        {
            if(b_id==b_idd)
            {
                system("cls");
                cout <<"---UPDATE BOOK RECORD---";
                cout <<"\nEnter new book name:";
                cin>>b_na;
                cout<<"\nEnter Author name:";
                cin>>a_na;
                cout<<"\nEnter No of Books";
                cin>>no_co;
                file1 <<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n\n";
                count++;
            }
            else
                file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n\n";
            file>>b_idd>>b_name>>a_name>>no_copy;
        }
    if(count==0)
    cout<<"\n\nBook ID NOT FOUND....";
    }
    cout<<endl;
    system("pause");

    file1.close();
    file.close();
    remove("book.txt");
    rename("book1.txt","book.txt");
}

void bookshop::del_book()
{
    system("cls");
    fstream file1,file;
    int no_copy,no_co,count=0;
    string b_name,b_na,a_name,a_na,b_idd,b_id;

    cout <<"----DELETE BOOK RECORD----";
    file1.open("book1.txt",ios::app|ios::out);
    file.open("book.txt",ios::in);

    if(!file)
    cout<<"\nFile Opening Error!!!";
    else{
        cout <<"\nEnter Book ID:";
        cin>>b_id;
        file>>b_idd>>b_name>>a_name>>no_copy;
        while(!file.eof())
        {
            if(b_id==b_idd)
            {
                system("cls");
                cout <<"---DELETE BOOK RECORD---";
                cout <<"Book Deleted Successfully";
                count++;
            }
            else
                file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n\n";
            file>>b_idd>>b_name>>a_name>>no_copy;
        }
    if(count==0)
    cout<<"\n\nBook ID NOT FOUND....";
    }
    cout<<endl;
    system("pause");

    file1.close();
    file.close();
    remove("book.txt");
    rename("book1.txt","book.txt");
}
void bookshoprecord()
{
    int choice;
    char x;
    bookshop b;
    while(1)
    {
        b.control_panel();
        cout <<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                do{
                    b.add_book();
                    cout<<"Another book?(y/n):";
                    cin>>x;
                }
                while(x=='y');
                break;
            case 2:
                b.show_book();
                break;
            case 3:
                b.check_book();
                break;
            case 4:
                b.update_book();
                break;
            case 5:
                b.del_book();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout<<"INVALID CHOICE!!!";
        }
    }
}

int main()
{
    bookshoprecord();
    return 0;
}