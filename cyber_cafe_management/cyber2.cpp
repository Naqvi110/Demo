#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<windows.h>
#define SIZE 55
using namespace std;
char buffer[SIZE + 1];
class cyber
 {
    char id[15];
    char name[20];
    char designation[15];
    char time_taken[10];
    char Gender[5];
    char address[10];
public:
    void getData();
    void putData();
    void pack();
    void unpack();
    void insert();
    void display();
    void modify(char *key);
    void search(char *key);
};

void cyber::getData()
{
    cout << "Enter Your id: ";
    cin >> id;
    cout<< "Enter Your name: ";
    cin>> name;
    cout<<"Enter Your designation: ";
    cin >> designation;
    cout<<"Enter the time_taken by you: ";
    cin >> time_taken;
    cout<<"Enter the gender: ";
    cin>>Gender;
    cout<<"Enter the address: ";
    cin>>address;
}

void cyber::putData()
{
    cout << id << "\t\t" << name << "\t\t" << designation << "\t\t" << time_taken <<"\t\t" <<Gender <<"\t\t" <<address << endl;
}

void cyber::pack()
{
    strcpy(buffer, id); strcat(buffer, "|");
    strcat(buffer, name); strcat(buffer, "|");
    strcat(buffer, designation); strcat(buffer, "|");
    strcat(buffer, time_taken); strcat(buffer,"|");
    strcat(buffer, Gender); strcat(buffer,"|");
    strcat(buffer,address);
    while(strlen(buffer) < SIZE - 1)
    {
        strcat(buffer, "#");
    } //here len of buffer is SIZE - 1
    strcat(buffer, "\n"); //now len of buffer becomes = SIZE
}

void cyber::unpack()
{
    char *p;
    p = strtok(buffer, "|"); strcpy(id, p);
    p = strtok(NULL, "|"); strcpy(name, p);
    p = strtok(NULL, "|"); strcpy(designation, p);
    p = strtok(NULL, "|"); strcpy(time_taken, p);
    p = strtok(NULL,"|"); strcpy(Gender,p);
    p = strtok(NULL, "#"); strcpy(address, p);
}

void cyber::insert()
 {
    getData();
    pack(); //packs the data into buffer
    ofstream fout("record.txt", ios::app);
    fout << buffer;
    fout.close();

}

void cyber::display()
{
    ifstream fin("record.txt");
    while(!fin.eof())
    {
        fin.getline(buffer, SIZE + 1, '\n');
        if(fin.fail()) break;
        unpack();
        putData();
    }
    fin.close();
}

void cyber::search(char *key)
{
    ifstream fin("record.txt");
    int count = 0;
    while(!fin.eof())
    {
        fin.getline(buffer, SIZE + 1, '\n');
        if(fin.fail()) break;
        unpack();
        if(strcmp(id, key) == 0)
        {
            putData();
            count++;
        }
    }
    cout << "Total records found: " << count << endl;
    fin.close();
}

void cyber::modify(char *key)
{
    ifstream fin("record.txt");
    ofstream fout("temp.txt");
    int count = 0;
    while(!fin.eof())
    {
        fin.getline(buffer, SIZE + 1, '\n');
        if(fin.fail()) break;
        unpack();
        if(strcmp(id, key) == 0)
        {
            getData();
            count++;
        }
        pack();
        fout << buffer;
    }
    if(count == 0)
        cout << "ID not found." << endl;
    else
        cout << "Modified. " << endl;
        fin.close();
        fout.close();
        remove("record.txt");
        rename("temp.txt", "record.txt");
}

int main()
{
    string url;
    int a;
    int b=0;
    int choice1;
    char choice;
    char choice3;
    char admin;
    string admin1;
    admin1;
    int password;
    password=786;
    cyber s;
    char key[15];
    label4: cout<<"**WELCOME TO CYBER CAFE MANAGEMENT SYSTEM**\n\n";
    cout<<"---TERMS AND CONDITIONS--\n";
    cout<<"* Price: 50 Rs/hour *\n";
    cout<<"* Maintain Silence *\n";
    cout<<"* Do not open or delete any file *\n";
    cout<<"Are you an Admin?(Y/N): ";
    cin >>admin;
    if(admin == 'Y' || admin == 'y')
    {
        cout <<"Enter your name: ";
        cin >>admin1;
       label6:  cout <<"Enter Password: ";
        cin >>password;
        if(password==786)
        {
            goto label;
        }
        else
        {
            cout<<"Invalid password!!\n";
            goto label5;
        }
    }
    else if(admin =='N'|| admin =='n')
    {
        cout<<"Would you like to perform any operation?(Y/N): ";
        cin >> choice;
        if(choice == 'Y'|| choice =='y')
        {
            do
            {
                cout <<"\n1.Log in to the cyber cafe\n"
                //<< "2.Modify your details\n"
                << "2.Exit\n" << endl;
                cout<<"Enter your choice: ";
                cin >> choice1;
                switch(choice1)
                {
                    case 1:
                        s.insert();
                        cout << "Done!\n"<<"You Have successfully Logged in to the cyber cafe, Now you can perform any operation\n" << endl;
                        cout <<"Enter url: ";
                        cin >>url;
                        //cout <<"Enter How many times you want to open the url:? ";
                        //cin >>a;
                       // while(b<a)
                        {
                            ShellExecute(NULL,"open",url.c_str(),NULL,NULL,SW_SHOWNORMAL);
                            //a++;
                        }
                        //break;
                   // case 2:
                        //cout << "Enter your id to be modified: ";
                        //cin >> key;
                        //s.modify(key);
                        //cout << "Done!" << endl;
                        //break;
                           default:
                               goto label1;
                }
            }while(1);
        }
        else if(choice =='N'|| choice =='n')
        {
            cout<<"Kindly Leave the cafe!!\n";
            goto label1;
        }
    }
    label: do
    {
        cout<<"1.Insert the candidate\n"
        << "2.Display the candidates records\n"
        << "3.Search the candidate\n"
        << "4.Modify the candidate record\n"
        << "5.Exit\n" << endl;
        cout<<"Enter your choice: ";
        cin >> choice1;
        switch(choice1)
        {
            case 1:
                s.insert();
                cout << "Done!" << endl;
                break;
            case 2:
                cout << "The contents of the candidates are: " << endl;
                s.display();
                cout << "Done!" << endl;
                break;
            case 3:
                cout << "Enter the key id: ";
                cin >> key;
                s.search(key);
                cout << "Done!" << endl;
                break;
            case 4:
                cout << "Enter the id to modify: ";
                cin >> key;
                s.modify(key);
                cout << "Done!" << endl;
                break;

                default:
                label1:   exit(0);


        }
    }while(1);

    label2: cout<<"Kindly give the answer in y/n!!\n\n";
                    goto label4;
                    label5: cout<<"Try again\n";
                    goto label6;
}
