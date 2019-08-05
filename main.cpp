#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*  I M P O R T A N T   M E S S A G E
*   Hey Aradhan and Noman
*   For Employee::Login()
*   Username - Batman
*   Password - Watchdog$2key
*   - Sasuke Uchiha
*/
              //blah
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
    void ClearChangePasswordBox();
    //Clears login details entry boxes
    void ClearChangePasswordMessage();
    //Clears login messages
    void ClearStrength();
    //Clears password strength
    void Animation_Spiral(char ch, int limit, float delay);
    //Creates a spiral animation, if limit = 13 then it will take up full screen, delay = 100 is an optimum value
    //Could be a fun way to display a border
    void Delay(int a);
    //Creates a delay which can be adjusted using 'a'
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

void Design::ClearChangePasswordBox()
{
    for(int i = 0; i < 19; ++i)
    {
        gotoxy(42 + i, 10);
        cout << ' ';
    }
    for(int j = 0; j < 19; ++j)
    {
        gotoxy(42 + j, 16);
        cout << ' ';
    }
}

void Design::ClearChangePasswordMessage()
{
    int i;

    //Clears long message
    for(i = 0; i < 54; ++i)
    {
        gotoxy(16 + i, 19);
        cout << ' ';
    }
    for(i = 0; i < 54; ++i)
    {
        gotoxy(16 + i, 20);
        cout << ' ';
    }
    for(i = 0; i < 54; ++i)
    {
        gotoxy(16 + i, 21);
        cout << ' ';
    }
    for(i = 0; i < 54; ++i)
    {
        gotoxy(16 + i, 22);
        cout << ' ';
    }
}

void Design::ClearStrength()
{
    for(int i = 0; i < 50; ++i)
    {
        gotoxy(23 + i, 13);
        cout << ' ';
    }
}

void Design::Animation_Spiral(char ch, int limit, float delay)
{
    int i;
    int l = 78, d = 24, r = 77, u = 23;
    int x = 1, y = 1;

    for(int j = 1; j <= limit; ++j)
    {
        if(x != 1 && y != 1)
        {
            gotoxy(x, y);
            cout << ch;
            Delay(delay);
        }

        for(i = 1; i <= l; ++i)
        {
            gotoxy(x + i, y);
            cout << ch;
            Delay(delay);
        }
        x += l;
        for(i = 1; i <= d; ++i)
        {
            gotoxy(x, y + i);
            cout << ch;
            Delay(delay * 1.5);
        }
        y += d;
        for(i = 1; i <= r; ++i)
        {
            gotoxy(x - i, y);
            cout << ch;
            Delay(delay);
        }
        x -= r;
        for(i = 1; i <= u; ++i)
        {
            gotoxy(x, y - i);
            cout << ch;
            Delay(delay * 1.5);
        }
        y -= u;

        l -= 2;
        d -= 2;
        u -= 2;
        r -= 2;
    }
}

void Design::Delay(int a)
{
    for(int i = 0; i <= a; ++i)
        for(int j = 0; j <= a; ++j)
            cout << "";
}

                                        ///////////////////////////////////////////

class Help
{
private:
protected:
public:
    int NumberCount(char sent[]);
    //Checks number count
    int UpperCount(char sent[]);
    //Checks uppercase letter count
    int SpecialCount(char sent[]);
    //Checks special character count
};

int Help::NumberCount(char sent[])
{
    int count = 0;

    for(int i = 0; sent[i] != 0; ++i)
        if((sent[i] == '0' || sent[i] == '1' || sent[i] == '2' || sent[i] == '3' || sent[i] == '4' ||
           sent[i] == '5' || sent[i] == '6' || sent[i] == '7' || sent[i] == '8' || sent[i] == '9') && isdigit(sent[i]))
            ++count;

    return count;
}

int Help::SpecialCount(char sent[])
{
    int count = 0;

    for(int i = 0; sent[i] != 0; ++i)
        if(!isalpha(sent[i]) && !isdigit(sent[i]))
            ++count;

    return count;
}

int Help::UpperCount(char sent[])
{
    int count = 0;

    for(int i = 0; sent[i] != 0; ++i)
        if(isupper(sent[i]) && isalpha(sent[i]))
            ++count;

    return count;
}

                                        ///////////////////////////////////////////

class Program : public Employee, public Design, public Help
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
    void Change_password();
    int Exit();
};

void Program::Login()
{
    char username[50], password[50], pass;
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
    while(6 != 9)
    {
        if(p > 18)
            gotoxy(54, 16);
        else
            gotoxy(36 + p, 16);
		  pass = getch();

        if(pass == 13)
        {
            password[p] = '\0';
            break;
        }
        else if(pass == 8)
        {
            if(p != 0)
            {
                if(p <= 19)
                {
                    gotoxy(35 + p, 16);
                    cout << ' ';
                }
                --p;
                password[p] = 0;
            }
        }
        else if(p > 18)
        {
            password[p] = pass;
            ++p;
            password[p] = 0;
        }
        else
        {
            password[p] = pass;
            cout << '*';
            ++p;
            password[p] = 0;
        }
    }

    //Checking login details
    ClearLoginMessage();
    if(!strcmp(username, Get_username()) && !strcmp(password, Get_password()))
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
            Delay(4000);
            exit(0);
        }

        gotoxy(32, 20);
        cout << "You have " << 6 - tries << " tries left";
        goto _pass;
    }
}

void Program::Main_menu()
{
    int option;

    do
    {
        //Display Menu
        _menu:
        clrscr();
        Border('*');
        gotoxy(32, 10);
        cout << "1. Add Employee";
        gotoxy(32, 11);
        cout << "2. Search Employee";
        gotoxy(32, 12);
        cout << "3. Salary";
        gotoxy(32, 13);
        cout << "4. Reports";
        gotoxy(32, 14);
        cout << "5. Change Password";
        gotoxy(32, 15);
        cout << "6. Exit";

        gotoxy(30, 17);
        cout << "Choose an option: ";
        cin >> option;

        switch(option)
        {
        case 1:
            Add_emp();
            break;
        case 2:
            Search_menu();
            break;
        case 3:
            Salary_menu();
            break;
        case 4:
            Reports();
            break;
        case 5:
            Change_password();
            break;
        case 6:
            if(!Exit())         //If user says 'No' while exit confirmation, it returns 0 and displays menu
                goto _menu;
            break;
        default:
            gotoxy(30, 18);
            cout << "Invalid option!!!";
            Delay(2000);
            goto _menu;
        }

    }while(option != 6);
}

void Program::Add_emp()
{
    /*
     *  Hey Noman,
     *  Write the code for adding an employee here
     *  Create an input function in class Employee
     *  And use that to ass employees
     *  - Sasuke Uchiha
     */
}

void Program::Search_menu()
{
    clrscr();
    cout << "Bruh";
}

void Program::Search_empno()
{
    clrscr();
    cout << "Bruh";
}

void Program::Search_name()
{
    clrscr();
    cout << "Bruh";
}

void Program::Search_dept()
{
    clrscr();
    cout << "Bruh";
}

void Program::Salary_menu()
{
    clrscr();
    cout << "Bruh";
}

void Program::Salary_GetDetails()
{
    clrscr();
    cout << "Bruh";
}

void Program::Salary_slip()
{
    clrscr();
    cout << "Bruh";
}

void Program::Reports()
{
    clrscr();
    cout << "Bruh";
}

void Program::Change_password()
{
    int p, number, upper, special;
    char pass, new_password[50], confirm_password[50], strength[20];

    clrscr();
    Border('*');
    strcpy(strength, "");

    gotoxy(23, 10);
    cout << "New Password: ";
    Box(41, 9, 20, 2, '-');
    gotoxy(23, 13);
    cout << "Strength: " << strength;
    gotoxy(23, 16);
    cout << "Confirm Password: ";
    Box(41, 15, 20, 2, '-');
    gotoxy(16, 19);
    cout << "- Password should be atleast 8 characters long";
    gotoxy(16, 20);
    cout << "- Password should contain atleast one number";
    gotoxy(16, 21);
    cout << "- Password should contain atleast one uppercase letter";
    gotoxy(16, 22);
	 cout << "- Password should contain atleast one special character";


    //Getting new password
    _newpass:
    ClearChangePasswordBox();
    p = 0;
    strcpy(new_password, "");
    strcpy(confirm_password, "");
    strcpy(strength, "");
    while(6 != 9)
    {
        if(p > 18)
            gotoxy(60, 10);
        else
            gotoxy(42 + p, 10);
        pass = getch();

        if(pass == 13)
        {
            new_password[p] = '\0';
            break;
        }
        else if(pass == 8)
        {
            if(p != 0)
            {
                if(p <= 19)
                {
                    gotoxy(41 + p, 10);
                    cout << ' ';
                }
                --p;
                new_password[p] = 0;
            }
        }
        else if(p > 18)
        {
            new_password[p] = pass;
            ++p;
            new_password[p] = 0;
        }
        else
        {
            new_password[p] = pass;
            cout << '*';
            ++p;
            new_password[p] = 0;
        }

        //Checking and Updating Strength
        number = NumberCount(new_password);
        special = SpecialCount(new_password);
        upper = UpperCount(new_password);
        if(strlen(new_password) < 8)
            strcpy(strength, "Very weak");
        else if(number == 0 && upper == 0 && special == 0)
            strcpy(strength, "Weak");
        else if(   (!(number > 0) && upper > 0 && special > 0)
                || (number > 0 && !(upper > 0) && special > 0)
                || (number > 0 && upper > 0 && !(special > 0)))
            strcpy(strength, "Good");
        else if(number > 1 && upper > 1 && special > 1)
            strcpy(strength, "Very Strong");
        else if(   (number > 0 && upper > 1 && special > 1)
                || (number > 1 && upper > 0 && special > 1)
                || (number > 1 && upper > 1 && special > 0))
            strcpy(strength, "Strong");
        else if(number > 0 && upper > 0 && special > 0)
            strcpy(strength, "Satisfactory");
        ClearStrength();
        gotoxy(23, 13);
        cout << "Strength: " << strength;
    }

    //Getting confirmation
    p = 0;
    while(6 != 9)
    {
        if(p > 18)
            gotoxy(60, 16);
        else
            gotoxy(42 + p, 16);
        pass = getch();

        if(pass == 13)
        {
            confirm_password[p] = '\0';
            break;
        }
        else if(pass == 8)
        {
            if(p != 0)
            {
                if(p <= 19)
                {
                    gotoxy(41 + p, 16);
                    cout << ' ';
                }
                --p;
                confirm_password[p] = 0;
            }
        }
        else if(p > 18)
        {
            confirm_password[p] = pass;
            ++p;
            confirm_password[p] = 0;
        }
        else
        {
            confirm_password[p] = pass;
            cout << '*';
            ++p;
            confirm_password[p] = 0;
        }
    }

    //Checking if confirmation is relevant
    ClearChangePasswordMessage();
    if(strcmp(new_password, confirm_password))
    {
        gotoxy(33, 19);
        cout << "Passwords don't match";
        goto _newpass;
    }
    else
    {
        if(strlen(new_password) < 8)
        {
            gotoxy(29, 19);
            cout << "Password isn't long enough";
            goto _newpass;
        }
        else if(number == 0)
        {
            gotoxy(27, 19);
            cout << "Password doesn't include numbers";
            goto _newpass;
        }
        else if(upper == 0)
        {
            gotoxy(22, 19);
            cout << "Password doesn't include uppercase letters";
            goto _newpass;
        }
        else if(special == 0)
        {
            gotoxy(21, 19);
            cout << "Password doesn't include special characters";
            goto _newpass;
        }
        else if(!strcmp(new_password, Get_password()))
        {
            gotoxy(21, 19);
            cout << "New password can't be your old password";
            goto _newpass;
        }
        else
        {
            Set_acc_details(Get_username(), new_password);
            gotoxy(29, 19);
            cout << "Password change sucessful";
            Delay(2000);
        }
    }
}

int Program::Exit()
{
    char response[3];

    gotoxy(25, 18);
    cout << "Are you sure you want to exit?";
    gotoxy(37, 19);
    gets(response);

    if(!strcmpi(response, "Yes") || !strcmpi(response, "Y"))
        exit(0);
    else if(!strcmpi(response, "No") || !strcmpi(response, "N"))
        return 0;
}

                                        ///////////////////////////////////////////

int main()
{
    Employee E;
    Design D;
    Program P;

    cout << "I am alone and I need love" << endl;
    getch();
}
