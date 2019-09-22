#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*  I M P O R T A N T   M E S S A G E
*   For Employee::Login()
*   Username - ISB
*   Password - cs
*   - Sasuke Uchiha
*/

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
		float TA;
		float MA;
		float PF;
	}sal;

	struct login_details
	{
		char username[20];
		char password[20];
	}acc;
protected:
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
	void Line(int x1, int x2, int y, char ch);
	//Creates a line from (x1, y) to (x2, y) of specified character 'ch'
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
	void Animation_Spiral(int limit, float delay, char ch);
    //Creates a spiral animation, if limit = 13 then it will take up full screen, delay = 100 is an optimum value
	//Could be a fun way to display a border
    void Delay(int a);
	//Creates a delay which can be adjusted using 'a'
	 void Intro(int x, int y);
	//Creates a small welcome sign
	void Star_top_L();
	void Star_top_R();
	void Star_bottom_L();
	void Star_bottom_R();
};

void Design::Border(char ch)
{
	for(int i = 2; i <= 79; ++i)
	{
		gotoxy(i, 1);
		cout << ch;
		gotoxy(i, 25);
		cout << ch;
	}
	for(int j = 2; j <= 24; ++j)
	{
		gotoxy(2, j);
        cout << ch;
		gotoxy(79, j);
        cout << ch;
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

void Design::Line(int x1, int x2, int y, char ch)
{
	for(int i = x1; i <= x2; ++i)
	{
		gotoxy(i, y);
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
	 for(i = 0; i < 55; ++i)
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

void Design::Animation_Spiral(int limit, float delay, char ch)
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

void Design::Intro(int x, int y)
{
	char sign[]="WELCOME";
	for(int a=0;a<7;a++)
	{
		Delay(1024);
		gotoxy(x + a, y);
		cout << sign[a];

	}
}
void Design::Star_top_L()
{
 int z,x;
 z=3;
 x=1;
 for(int a=13;a>=1;a--)
  {
	gotoxy(z,x);
	for(int b=1;b<=a;b++)
	 {
	  cout<<"*";
	 }
	cout<<'\n';
	x++;
  }
}
void Design::Star_top_R()
{
 int z,x;
 z=66;
 x=1;

 for(int a=1;a<=13;a++)
  {
	gotoxy(z,x);
	for(int b=1;b<a;b++)
	 {
	  cout<<" ";
	 }
	for(int c=13;c>=a;c--)
	 {
	  cout<<"*";
	  }
	cout<<'\n';
	 x++;
  }

}
void Design::Star_bottom_L()
{
int z,x;
z=3;
x=13;
for(int a=1;a<=13;a++)
 {
  gotoxy(z,x);
  for(int b=1;b<=a;b++)
	{
	 cout<<"*";
	}
 cout<<'\n';
 x++;
 }

}
void Design::Star_bottom_R()
{
  int z,x;
  z=66;
  x=13;
  for(int a=3;a<=14;a++)
	{
	 gotoxy(z,x);
	 for(int b=14;b>a;b--)
	  {
		cout<<" ";
	  }
	 for(int c=2;c<=a;c++)
	 {
	 cout<<"*";
	 }
	cout<<'\n';
	x++;
  }
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
	void Modify_menu();
	void Reports();
    void Change_password();
    int Exit();
};

void Program::Login()
{
    char username[50], password[50], pass;
	int p, tries = 0;

	Intro(38,8);

	 /*
     *  Hey Aradhan,
     *  Make sure you do your triangles and welcome thingy over here
	  *  before all the border stuff
     *  Work on Main_menu() if you can
     *  - Sasuke Uchiha
	  */

	//Display
	Animation_Spiral(1, 100, '*');
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

		  if(strcmp(username, Get_username()))
		  {
			gotoxy(33, 19);
			cout << "Username not found";
		}
		  else if(strcmp(password, Get_password()))
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
	int selection, option = 49, init_msg_check = 0;

	do
	{
		//Display Menu
		_menu:
		clrscr();
		Star_top_R();
		Star_top_L();
		Star_bottom_L();
		Star_bottom_R();
		if(init_msg_check == 0)
		{
			gotoxy(20, 22);
			cout << "Scroll through options 1-7 and press enter";
			init_msg_check = 1;
		}
		_invalid:          //So that screen doesn't get cleared if we use invalid selections
		Border('*');
		Box(28, 6, 24, 14, '!');

		switch(option)
		{
		case 49:
			Line(29, 51, 8, '*');
			gotoxy(29, 7);
			cout << "->";
			break;
		case 50:
			Line(29, 51, 8, '*');
			Line(29, 51, 10, '*');
			gotoxy(29, 9);
			cout << "->";
			break;
		case 51:
			Line(29, 51, 10, '*');
			Line(29, 51, 12, '*');
			gotoxy(29, 11);
			cout << "->";
			break;
		case 52:
			Line(29, 51, 12, '*');
			Line(29, 51, 14, '*');
			gotoxy(29, 13);
			cout << "->";
			break;
		case 53:
			Line(29, 51, 14, '*');
			Line(29, 51, 16, '*');
			gotoxy(29, 15);
			cout << "->";
			break;
		case 54:
			Line(29, 51, 16, '*');
			Line(29, 51, 18, '*');
			gotoxy(29, 17);
			cout << "->";
			break;
		case 55:
			Line(29, 51, 18, '*');
			gotoxy(29, 19);
			cout << "->";
			break;
		}

		gotoxy(32, 7);
		cout << "1. Add Employee";
		gotoxy(32, 9);
		cout << "2. Search Employee";
		gotoxy(32, 11);
		cout << "3. Salary Slip";
		gotoxy(32, 13);
		cout << "4. Modify Details";
		gotoxy(32, 15);
		cout << "5. Reports";
		gotoxy(32, 17);
		cout << "6. Change Password";
		gotoxy(32, 19);
		cout << "7. Exit";

		gotoxy(100, 100);    //So that the cursor isnt visible on the screen
		selection = getch();

		if(selection == 13)
		{
			switch(option)
			{
			case 49:
				Add_emp();
				goto _menu;
				break;
			case 50:
				Search_menu();
				goto _menu;
				break;
			case 51:
				Salary_menu();
				goto _menu;
				break;
			case 52:
				Modify_menu();
				goto _menu;
				break;
			case 53:
				Reports();
				break;
			case 54:
				Change_password();
				goto _menu;
				break;
			case 55:
				if(!Exit())         //If user says 'No' while exit confirmation, it returns 0 and displays menu
					goto _menu;
				break;
			}
		}

		if(selection >= 49 && selection <= 55)
			option = selection;
		else
			goto _invalid;

	 }while(option != 7);
}

void Program::Add_emp()
{
	clrscr();
	/*
	 *  Hey Noman,
	 *  Write the code for adding an employee here
	 *  Create an input function in class Employee
	 *  And use that to add employees
	 *  - Sasuke Uchiha
	 */
}

void Program::Search_menu()
{
	 clrscr();
	/*
	 *  Hey Aradhan,
	 *  Write the code of a search employee MENU here similar to Main Menu
	 *  Where user can enter numbers and choose their method of searching employee
	 *  Create necessary functions in Employee
	 *  - Sasuke Uchiha
	 */
}

void Program::Search_empno()
{
	 clrscr();
}

void Program::Search_name()
{
	 clrscr();
}

void Program::Search_dept()
{
	 clrscr();
}

void Program::Salary_menu()
{
	 clrscr();
	/*
	 *  Hey Kassim,
	 *  Write the code of a salary MENU here similar to Main Menu
	 *  Where user can enter numbers and choose either Details or Salary Slip
	 *  Create necessary functions in Employee
	 *  - Sasuke Uchiha
	 */
}

void Program::Salary_GetDetails()
{
	 clrscr();
}

void Program::Salary_slip()
{
	 clrscr();
}

void Program::Modify_menu()
{
	 clrscr();
}

void Program::Reports()
{
	 clrscr();
	/*
	 *  Hey Madesh,
	 *  Write the code for creating a tabular representation of every detail of every employee
	 *  Create an input function in class Employee
	 *  - Sasuke Uchiha
	 */
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

	gotoxy(22, 22);
	 cout << "Are you sure you want to exit? (Yes/No)";
	gotoxy(37, 23);
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

	P.Login();
	getch();
}
