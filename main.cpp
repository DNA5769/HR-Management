#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Employee
{
private:
    int empno;
    char name[20];
    int age;
    long telno;
    char desig[10];
    char dept[10];
    struct sal_info
    {
        float basic;
        float HRA;
        float DA;
        float tax;
    }sal;
protected:
    struct login_details
    {
        char username[20];
        char password[20];
    }acc;
public:
    char* Get_username();
    //Returns username
    char* Get_password();
    //Returns password
    void Set_acc_details(char username[], char password[]);
    //Sets username and password
    int Get_empno();
    //Returns empno
    char* Get_name();
    //Returns name
    char* Get_dept();
    //Returns dept
};

char* Employee::Get_username()
{
    fstream f;
    f.open("Account.dat", ios::in | ios::binary);

    f.read((char*)&acc, sizeof(acc));

    return acc.username;
}

char* Employee::Get_password()
{
    fstream f;
    f.open("Account.dat", ios::in | ios::binary);

    f.read((char*)&acc, sizeof(acc));

    return acc.password;
}

void Employee::Set_acc_details(char username[], char password[])
{
    fstream f;
    f.open("Account.dat", ios::out | ios::binary);

    strcpy(acc.username, username);
    strcpy(acc.password, password);

    f.write((char*)&acc, sizeof(acc));
}

int Employee::Get_empno()
{return empno;}

char* Employee::Get_name()
{return name;}

char* Employee::Get_dept()
{return dept;}

                                        ///////////////////////////////////////////

class Design
{
private:
protected:
public:
    void Border(char ch);
    //Creates a border using specified character 'ch'
    void Box(int x, int y, int l, int b, char ch);
    //Creates a box on (x ,y) coordinate of specified character 'ch' and dimensions lxb
    void ClearLoginBox();
    //Clears login details entry boxes
    void ClearLoginMessage();
    //Clears login messages
};

void Design::Border(char ch)
{
    for(int i = 2; i <= 78; ++i)
    {
        gotoxy(i, 2);
        cout << ch;
        gotoxy(i, 24);
        cout << ch;
    }
    for(int j = 2; j <= 24; ++j)
    {
        gotoxy(2, j);
        cout << ch;
        gotoxy(78, j);
        cout << ch;
    }
}

void Design::ClearLoginBox()
{
    for(int i = 0; i < 19; ++i)
    {
        gotoxy(36 + i, 13);
        cout << ' ';
    }
    for(int j = 0; j < 19; ++j)
    {
        gotoxy(36 + j, 16);
        cout << ' ';
    }
}

void Design::ClearLoginMessage()
{
    for(int i = 0; i < 23; ++i)
    {
        gotoxy(30 + i, 19);
        cout << ' ';
    }
    for(int j = 0; j < 23; ++j)
    {
        gotoxy(30 + j, 20);
        cout << ' ';
    }
}

void Design::Box(int x, int y, int l, int b, char ch)
{
    if(ch == '-')
    {
        for(int i = 1; i < l; ++i)
        {
            gotoxy(x + i, y);
            cout << ch;
            gotoxy(x + i, y + b);
            cout << ch;
        }
        ch = '|';
        for(int j = 1; j < b; ++j)
        {
            gotoxy(x, y + j);
            cout << ch;
            gotoxy(x + l, y + j);
            cout << ch;
        }
    }
    else
    {
        for(int i = 0; i <= l; ++i)
        {
            gotoxy(x + i, y);
            cout << ch;
            gotoxy(x + i, y + b);
            cout << ch;
        }
        for(int j = 0; j <= b; ++j)
        {
            gotoxy(x, y + j);
            cout << ch;
            gotoxy(x + l, y + j);
            cout << ch;
        }
    }
}

                                        ///////////////////////////////////////////

class Program : public Employee, public Design
{
private:
protected:
public:
    void Login();
    void Main_menu();
    void Add_emp();
    void Search_menu();
    void Search_empno();
    void Search_name();
    void Search_dept();
    void Salary_menu();
    void Salary_GetDetails();
    void Salary_slip();
    void Reports();
};

void Program::Login()
{
    char username[20], password[20], pass;
    int p, tries = 0;

    /*
     *  Hey Aradhan,
     *  Make sure you do your triangles and welcome thingy over here
     *  before all the border stuff
     *  Work on Main_menu() if you can
     *  - Sasuke Uchiha
     */

    //Display
    Border('*');
    gotoxy(25, 13);
    cout << "Username: ";
    Box(35, 12, 20, 2, '-');
    gotoxy(25, 16);
    cout << "Password: ";
    Box(35, 15, 20, 2, '-');

    //Receives username as input
    _pass:
    ClearLoginBox();
    gotoxy(36, 13);
    gets(username);

    //Receives password as input
    p = 0;
    gotoxy(36, 16);
    while(6 != 9)
    {
        pass = getch();

        if(pass == 13)
        {
            password[p] = '\0';
            break;
        }
        else if(pass == 8)
        {
            if(p == 0)
                continue;

            gotoxy(35 + p, 16);
            cout << ' ';
            gotoxy(35 + p, 16);
            --p;
            continue;
        }
        else if(p >= 19)
        {
            password[p] = pass;
            ++p;
        }
        else
        {
            password[p] = pass;
            cout << '*';
            ++p;
        }
    }

    //Checking login details
    ClearLoginMessage();
    if(!strcmp(username, "Reee") && !strcmp(password, "watchdogs2key")) //IMP - These are login details. Ha
    {
        gotoxy(35, 19);
        Main_menu();
    }
    else
    {
        tries++;

        if(strcmp(username, "Reee"))
        {
            gotoxy(33, 19);
            cout << "Username not found";
        }
        else
        {
            gotoxy(32, 19);
            cout << "Password is incorrect";
        }

        if(tries == 6)
        {
            gotoxy(33, 20);
            cout << "Access Unauthorized!";
            getch(); //You can put your delay function here
            exit(0);
        }

        gotoxy(32, 20);
        cout << "You have " << 6 - tries << " tries left";
        goto _pass;
    }
}

void Program::Main_menu()
{
    clrscr();
    cout << "Bruh";
}

void Program::Add_emp()
{

}

void Program::Search_menu()
{

}

void Program::Search_empno()
{

}

void Program::Search_name()
{

}

void Program::Search_dept()
{

}

void Program::Salary_menu()
{

}

void Program::Salary_GetDetails()
{

}

void Program::Salary_slip()
{

}

void Program::Reports()
{

}

                                        ///////////////////////////////////////////

int main()
{
    Employee E;
    Design D;
    Program P;

    P.Login();
}
