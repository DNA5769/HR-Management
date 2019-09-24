#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*  I M P O R T A N T   M E S S A G E
*   For Employee::Login()
*   Username - ISB
*   Password - cs
*   - Sasuke Uchiha
*/

class Employee
{
private:
HEAD
    int empno;
	 char name[20];
	 int age;
=======
	int empID;
    char name[20];
	int age;
 master
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
		float grade_pay;
		float net_sal;
	}sal;

	struct login_details
	{
		char username[20];
		char password[20];
	}acc;
protected:
public:
 HEAD
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
=======
    char* Get_username();
	//Returns username
    char* Get_password();
    //Returns password
	void Set_acc_details(char username[], char password[]);
    //Sets username and password
    int Get_empID();
	//Returns empID
    char* Get_name();
	//Returns name
	int Get_age();
	//Returns age
	long Get_telno();
	//Returns telno
	char* Get_desig();
	//Returns desig
	char* Get_dept();
	//Returns dept
	float Get_basic();
	float Get_HRA();
	float Get_DA();
	float Get_tax();
	float Get_TA();
	float Get_MA();
	float Get_PF();
	float Get_grade_pay();
	float Get_net_sal();
	void Set_empID(int id);
	//Sets empID
	void Set_name(char n[]);
	//Sets name
	void Set_age(int a);
	//Sets age
	void Set_telno(long tel);
	//Sets telno
	void Set_desig(char des[]);
	//Sets desig
	void Set_dept(char dep[]);
	//Sets dept
	void Set_basic(float bas);
	void Set_HRA(float hra);
	void Set_DA(float da);
	void Set_tax(float tx);
	void Set_TA(float ta);
	void Set_MA(float ma);
	void Set_PF(float pf);
	void Set_grade_pay(float grade);
	void Set_net_sal(float net);
 master
};

char* Employee::Get_username()
{
	fstream f;
    f.open("Account.dat", ios::in | ios::binary);

	f.read((char*)&acc, sizeof(acc));
	f.close();

	 return acc.username;
}

char* Employee::Get_password()
{
    fstream f;
	 f.open("Account.dat", ios::in | ios::binary);

	f.read((char*)&acc, sizeof(acc));
	f.close();

    return acc.password;
}

void Employee::Set_acc_details(char username[], char password[])
{
HEAD
	 fstream f;
	 f.open("Account.dat", ios::out | ios::binary);

	 strcpy(acc.username, username);
	 strcpy(acc.password, password);

	 f.write((char*)&acc, sizeof(acc));
=======
    fstream f;
	f.open("Account.dat", ios::out | ios::binary);

    strcpy(acc.username, username);
	strcpy(acc.password, password);

	f.write((char*)&acc, sizeof(acc));
	f.close();
 master
}

int Employee::Get_empID()
{return empID;}

char* Employee::Get_name()
{return name;}

int Employee::Get_age()
{return age;}

long Employee::Get_telno()
{return telno;}

char* Employee::Get_desig()
{return desig;}

char* Employee::Get_dept()
{return dept;}

HEAD
													 ///////////////////////////////////////////
=======
float Employee::Get_basic()
{return sal.basic;}

float Employee::Get_HRA()
{return sal.HRA;}

float Employee::Get_DA()
{return sal.DA;}

float Employee::Get_tax()
{return sal.tax;}

float Employee::Get_TA()
{return sal.TA;}

float Employee::Get_MA()
{return sal.MA;}

float Employee::Get_PF()
{return sal.PF;}

float Employee::Get_grade_pay()
{return sal.grade_pay;}

float Employee::Get_net_sal()
{return sal.net_sal;}

void Employee::Set_empID(int id)
{empID = id;}

void Employee::Set_name(char n[])
{strcpy(name, n);}

void Employee::Set_age(int a)
{age = a;}

void Employee::Set_telno(long tel)
{telno = tel;}

void Employee::Set_desig(char des[])
{strcpy(desig, des);}

void Employee::Set_dept(char dep[])
{strcpy(dept, dep);}

void Employee::Set_basic(float bas)
{sal.basic = bas;}

void Employee::Set_HRA(float hra)
{sal.HRA = hra;}

void Employee::Set_DA(float da)
{sal.DA = da;}

void Employee::Set_tax(float tx)
{sal.tax = tx;}

void Employee::Set_TA(float ta)
{sal.TA = ta;}

void Employee::Set_MA(float ma)
{sal.MA = ma;}

void Employee::Set_PF(float pf)
{sal.PF = pf;}

void Employee::Set_grade_pay(float grade)
{sal.grade_pay = grade;}

void Employee::Set_net_sal(float net)
{sal.net_sal = net;}

                                        ///////////////////////////////////////////
 master

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
     HEAD
	 void ClearLoginMessage();
	 //Clears login messages
    void ClearChangePasswordBox();
	 //Clears login details entry boxes
	 void ClearChangePasswordMessage();
=======
    void ClearLoginMessage();
	//Clears login messages
    void ClearChangePasswordBox();
    //Clears login details entry boxes
	void ClearChangePasswordMessage();
 master
    //Clears login messages
	 void ClearStrength();
	//Clears password strength
	void Animation_Spiral(int limit, float delay, char ch);
	 //Creates a spiral animation, if limit = 13 then it will take up full screen, delay = 100 is an optimum value
	//Could be a fun way to display a border
    void Delay(int a);
	//Creates a delay which can be adjusted using 'a'
	void Delayed_text(int x, int y, char string[]);
	//Creates a small welcome sign
 HEAD
	void Star_top_L();
	void Star_top_R();
	void Star_bottom_L();
	void Star_bottom_R();
	void Main_menu_sign();
=======
	void Star_top_L();        //     These 4 functions
	void Star_top_R();        //     are used to create the '*'
	void Star_bottom_L();     //     borders in the in
	void Star_bottom_R();     //     Program::Main_menu()
	void Main_menu_sign();
	//Displays 'MAIN MENU' in Program::Main_menu()
 master
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
 HEAD
	 for(int j = 0; j < 19; ++j)
	 {
=======
	for(int j = 0; j < 19; ++j)
    {
 master
        gotoxy(36 + j, 16);
		  cout << ' ';
	 }
}

void Design::ClearLoginMessage()
{
 HEAD
	 for(int i = 0; i < 23; ++i)
	 {
        gotoxy(30 + i, 19);
		  cout << ' ';
	 }
=======
	for(int i = 0; i < 23; ++i)
    {
        gotoxy(30 + i, 19);
        cout << ' ';
    }
master
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
 HEAD
		  gotoxy(42 + i, 10);
=======
		gotoxy(42 + i, 8);
 master
        cout << ' ';
	 }
	 for(int j = 0; j < 19; ++j)
    {
HEAD
		  gotoxy(42 + j, 16);
		  cout << ' ';
=======
		  gotoxy(42 + j, 14);
        cout << ' ';
 master
    }
}

void Design::ClearChangePasswordMessage()
{
	 int i;

	 //Clears long message
	 for(i = 0; i < 54; ++i)
    {
 HEAD
		  gotoxy(16 + i, 19);
		  cout << ' ';
    }
	 for(i = 0; i < 54; ++i)
	 {
        gotoxy(16 + i, 20);
=======
		  gotoxy(16 + i, 17);
        cout << ' ';
    }
	 for(i = 0; i < 54; ++i)
    {
		gotoxy(16 + i, 18);
 master
		  cout << ' ';
	 }
    for(i = 0; i < 54; ++i)
	 {
 HEAD
		  gotoxy(16 + i, 21);
=======
		gotoxy(16 + i, 19);
master
        cout << ' ';
	 }
	 for(i = 0; i < 55; ++i)
    {
 HEAD
		  gotoxy(16 + i, 22);
		  cout << ' ';
=======
		  gotoxy(16 + i, 20);
        cout << ' ';
 master
    }
}

void Design::ClearStrength()
{
	 for(int i = 0; i < 50; ++i)
    {
 HEAD
		  gotoxy(23 + i, 13);
		  cout << ' ';
=======
		  gotoxy(23 + i, 11);
        cout << ' ';
 master
    }
}

void Design::Animation_Spiral(int limit, float delay, char ch)
{
	int i;
    int l = 78, d = 24, r = 77, u = 23;
    int x = 1, y = 1;

    for(int j = 1; j <= limit; ++j)
 HEAD
	 {
		  if(x != 1 && y != 1)
=======
    {
        if(x != 1 && y != 1)
 master
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

void Design::Delayed_text(int x, int y, char string[])
{
	for(int a=0; string[a] != 0;a++)
	{
		Delay(1024);
		gotoxy(x + a, y);
		cout << string[a];

	}
}
void Design::Star_top_L()
{
    int z,x;
    z=3;
    x=1;

    for(int a = 13; a >= 1; a--)
    {
        gotoxy(z,x);
        for(int b = 1; b <= a; b++)
            cout << "*";

        cout << '\n';
	x++;
    }
}
void Design::Star_top_R()
{
    int z,x;
    z=66;
    x=1;

    for(int a = 1; a <= 13; a++)
    {
        gotoxy(z,x);
        for(int b = 1; b < a; b++)
            cout<<" ";
        for(int c = 13; c >= a; c--)
            cout<<"*";

        cout << '\n';
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
            cout << "*";

        cout << '\n';
        x++;
    }

}
void Design::Star_bottom_R()
{
    int z,x;
    z=66;
    x=13;
    for(int a = 3; a <= 14; a++)
	{
        gotoxy(z,x);
        for(int b = 14; b > a; b--)
            cout << " ";
        for(int c = 2; c <= a; c++)
            cout << "*";

        cout << '\n';
        x++;
    }
}
 HEAD
void Design::Main_menu_sign()
{
 int z,x;
 x=11;
 for(int a=1;a<=3;a++)
  {
	z=3;
	gotoxy(z,x);
	 for(int b=1;b<=7;b++)
	  {
	  z+=3;

	  gotoxy(z,x);
	  cout<<"|";
	  }
	x++;
 }
  for(int c=1;c<=2;c++)
	{
	 if(c=1)
	 {
		gotoxy(7,11);
		cout<<"\\";
	  }
	 if(c=2)
	 {
		gotoxy(8,11);
		cout<<"/";
		}
	}
	x=10;
  for(int d=1;d<=2;d++)
  {
	gotoxy(13,x);
	cout<<"__";
	x+=2;
  }
  x=10;


  z=22;
  x=11;


  for(int e=1;e<=2;e++,z++,x++)
  {
	gotoxy(z,x);
	cout<<"\\";

	}


x=11;
for(int f=1;f<=3;f++)
  {
	z=51;
	gotoxy(z,x);
	 for(int g=1;g<=8;g++)
	  {
	  z+=3;
		if(z!=63)
		{
		gotoxy(z,x);
		cout<<"|";
		}
	  }
	x++;
  }

for(int h=1;h<=2;h++)
	{
	 if(h=1)
	 {
		gotoxy(55,11);
		cout<<"\\";
	  }
	 if(h=2)
	 {
		gotoxy(56,11);
		cout<<"/";
		}
	}

z=61;
x=10;
for(int i=1;i<=3;i++)
 {
 gotoxy(z,x);
 if(i==2)
  {

  cout<<"--";

  }
 else if(i==1)
  {

  cout<<"___";
  x++;
  }
 else
  {
  cout<<"___";
  }
 x++;
 }
z=67;
x=11;
for(int j=1;j<=2;j++,z++,x++)
  {
	gotoxy(z,x);
	cout<<"\\";

	}
 z=73;
 x=13;
  gotoxy(z,x);
  cout<<"__";

}


									///////////////////////////////////////////
=======

void Design::Main_menu_sign()
{
    int z,x;
    x = 11;

    for(int a = 1; a <= 3; a++)
    {
        z=3;
        gotoxy(z,x);
        for(int b = 1; b <= 7; b++)
        {
            z += 3;

            gotoxy(z,x);
            cout << "|";
        }
        x++;
    }

    for(int c = 1; c <= 2; c++)
	{
		if(c == 1)
		{
			gotoxy(7,11);
			cout << "\\";
		}

		if(c == 2)
		{
			gotoxy(8,11);
			cout << "/";
		}
	}

	x = 10;

	for(int d = 1; d <= 2; d++)
	{
		gotoxy(13,x);
        cout << "__";
        x+=2;
    }

    x = 10;
    z = 22;
    x = 11;

    for(int e = 1; e <= 2; e++, z++, x++)
    {
        gotoxy(z,x);
        cout << "\\";
	}

    x=11;
    for(int f = 1; f <= 3; f++)
    {
        z=51;
        gotoxy(z,x);
        for(int g = 1; g <= 8; g++)
        {
            z+=3;
			if(z != 63)
            {
                gotoxy(z,x);
                cout << "|";
            }
        }
        x++;
    }

    for(int h = 1; h <= 2; h++)
	{
		if(h == 1)
		{
			gotoxy(55,11);
			cout << "\\";
		}
		if(h == 2)
		{
			gotoxy(56,11);
			cout << "/";
		}
	}

    z = 61;
    x = 10;

    for(int i = 1; i <= 3; i++)
    {
        gotoxy(z,x);
		if(i == 2)
            cout << "--";
        else if(i==1)
        {
            cout << "___";
            x++;
        }
        else
            cout << "___";

        x++;
    }

    z = 67;
    x = 11;

    for(int j = 1; j <= 2; j++, z++, x++)
    {
        gotoxy(z,x);
        cout << "\\";
	}

    z = 73;
    x = 13;

    gotoxy(z,x);
    cout << "__";

}

										///////////////////////////////////////////
 master

class Help
{
private:
protected:
public:
	int NumberCount(char sent[]);
    //Checks number count
	int UpperCount(char sent[]);
	 //Checks uppercase letter count
HEAD
	 int SpecialCount(char sent[]);
	 //Checks special character count
=======
    int SpecialCount(char sent[]);
	//Checks special character count
	long StringToInt(char str[]);
	int IntCheck(char str[]);

 master
};

int Help::NumberCount(char sent[])
{
    int count = 0;

    for(int i = 0; sent[i] != 0; ++i)
        if((sent[i] == '0' || sent[i] == '1' || sent[i] == '2' || sent[i] == '3' || sent[i] == '4' ||
HEAD
			  sent[i] == '5' || sent[i] == '6' || sent[i] == '7' || sent[i] == '8' || sent[i] == '9') && isdigit(sent[i]))
				++count;
=======
           sent[i] == '5' || sent[i] == '6' || sent[i] == '7' || sent[i] == '8' || sent[i] == '9') && isdigit(sent[i]))
            ++count;
    master

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

 HEAD
	 for(int i = 0; sent[i] != 0; ++i)
		  if(isupper(sent[i]) && isalpha(sent[i]))
=======
    for(int i = 0; sent[i] != 0; ++i)
        if(isupper(sent[i]) && isalpha(sent[i]))
 master
            ++count;

    return count;
}

long Help::StringToInt(char str[])
{
	long N = 0, n, p;

	p = strlen(str);
	--p;

	for(int i = 0; str[i] != 0; ++i)
	{
		n = str[i] - '0';
		n = n * pow(10, p);

		N += n;
		--p;
	}

	return N;
}

int Help::IntCheck(char str[])
{
	for(int i = 0; str[i] != 0; ++i)
		if(!isdigit(str[i]))
			return 0;

	return 1;
}

										///////////////////////////////////////////

class Program : public Employee, public Design, public Help
{
private:
protected:
public:
    void Login();
HEAD
	 void Main_menu();
	 void Add_emp();
    void Search_menu();
	 void Search_empno();
	 void Search_name();
=======
    void Main_menu();
	void Add_emp();
    void Search_menu();
    void Search_empno();
	void Search_name();
 master
    void Search_dept();
	void Salary_slip();
	void Modify_menu();
	void Reports();
HEAD
    void Change_password();
	 int Exit();
=======
	int Change_password();
    int Exit();
 master
};

void Program::Login()
{
    char username[50], password[50], pass;
	int p, tries = 0;

	Delayed_text(38, 8, "WELCOME");

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
 HEAD
            gotoxy(54, 16);
		  else
=======
	    gotoxy(54, 16);
	else
 master
				gotoxy(36 + p, 16);
		  pass = getch();

		  if(pass == 13)
 HEAD
        {
				password[p] = '\0';
				break;
        }
		  else if(pass == 8)
		  {
            if(p != 0)
				{
=======
	{
	    password[p] = '\0';
				break;
	}
	else if(pass == 8)
		  {
	    if(p != 0)
	    {
 master
					 if(p <= 19)
		{
					gotoxy(35 + p, 16);
						  cout << ' ';
 HEAD
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
=======
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
 master
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
	char selection[20];
	int option = 49;

	do
	{
		//Display Menu
		_menu:
		clrscr();
		Star_top_R();
		Star_top_L();
		Star_bottom_L();
		Star_bottom_R();
		Main_menu_sign();
 HEAD
		if(init_msg_check == 0)
		{
			gotoxy(20, 22);
			cout << "Scroll through options 1-7 and press enter";
			init_msg_check = 1;
		}
		_invalid:          //So that screen doesn't get cleared if we use invalid selections
=======

 master
		Border('*');
		Box(27, 6, 24, 14, '!');

		switch(option)
		{
		case 49:
			Line(28, 50, 8, '*');
			gotoxy(29, 7);
			cout << "->";
			break;
		case 50:
			Line(28, 50, 8, '*');
			Line(28, 50, 10, '*');
			gotoxy(29, 9);
			cout << "->";
			break;
		case 51:
			Line(28, 50, 10, '*');
			Line(28, 50, 12, '*');
			gotoxy(29, 11);
			cout << "->";
			break;
		case 52:
			Line(28, 50, 12, '*');
			Line(28, 50, 14, '*');
			gotoxy(29, 13);
			cout << "->";
			break;
		case 53:
			Line(28, 50, 14, '*');
			Line(28, 50, 16, '*');
			gotoxy(29, 15);
			cout << "->";
			break;
		case 54:
			Line(28, 50, 16, '*');
			Line(28, 50, 18, '*');
			gotoxy(29, 17);
			cout << "->";
			break;
		case 55:
			Line(28, 50, 18, '*');
			gotoxy(29, 19);
			cout << "->";
			break;
		}

		gotoxy(31, 7);
		cout << "1. Add Employee";
		gotoxy(31, 9);
		cout << "2. Search Employee";
		gotoxy(31, 11);
		cout << "3. Salary Slip";
		gotoxy(31, 13);
		cout << "4. Modify Details";
		gotoxy(31, 15);
		cout << "5. Reports";
		gotoxy(31, 17);
		cout << "6. Change Password";
		gotoxy(31, 19);
		cout << "7. Exit";

		gotoxy(25, 22);
		cout << "Select your desired option (1-7)";
		gotoxy(20, 23);
		cout << "Press 'Enter' to finalize your selection: ";
		gets(selection);

		if(selection[0] >= 49 && selection[0] <= 55 && strlen(selection) == 1)
			option = selection[0];
		else if(strlen(selection) == 0)
		{
			switch(option)
			{
			case 49:
				Add_emp();
				break;
			case 50:
				Search_menu();
				break;
			case 51:
				Salary_slip();
				break;
			case 52:
				Modify_menu();
				break;
			case 53:
				Reports();
				break;
			case 54:
				Change_password();
				break;
			case 55:
				if(!Exit())         //If user says 'No' while exit confirmation, it returns 0 and displays menu
					goto _menu;
				break;
			}
		}
		else
		{
			Line(25, 67, 22, ' ');
			Line(20, 66, 23, ' ');
			gotoxy(30, 22);
			cout << "Invalid Selection";
			Delay(2000);
		}

	 }while(6 != 9);
}

void Program::Add_emp()
{
	fstream f;
	Employee E;
	int N;
	char resp[20];

	int empid, age, grade_pay;
	char name[20], desig[20], dept[20], empid_c[20], age_c[20], telno_c[20], grade_pay_c[20];
	long telno;

	_add_emp:
	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(35, 3);
	cout << "Add New Employee";

	Line(3, 78, 11, '*');
	Line(3, 78, 16, '*');
	gotoxy(23, 13);
	cout << "Enter number of employees to be added:\n";
	gotoxy(39, 14);
	gets(resp);

	if(!isdigit(resp[0]))
		goto _add_emp;

	N = resp[0] - '0';

	f.open("Employee.dat", ios::app | ios::binary);
	for(int i = 1; i <= N; ++i)
	{
		reset_add:
		clrscr();
		Border('*');
		Line(3, 78, 4, '_');
		gotoxy(35, 3);
		cout << "Add New Employee";

		gotoxy(5, 6);
		cout << "Employee ID";
		gotoxy(5, 8);
		cout << "Name";
		gotoxy(5, 10);
		cout << "Age";
		gotoxy(5, 12);
		cout << "Telephone Number";
		gotoxy(5, 14);
		cout << "Designation";
		gotoxy(5, 16);
		cout << "Department";
		gotoxy(5, 18);
		cout << "Grade Pay";
		gotoxy(39, 6);
		cout << ":";
		gotoxy(39, 8);
		cout << ":";
		gotoxy(39, 10);
		cout << ":";
		gotoxy(39, 12);
		cout << ":";
		gotoxy(39, 14);
		cout << ":";
		gotoxy(39, 16);
		cout << ":";
		gotoxy(39, 18);
		cout << ":";
		Line(3, 78, 19, '_');

		//Getting Employee Details as Input
		empid_check:
		Line(45, 60, 6, ' ');
		gotoxy(45, 6);
		gets(empid_c);

		if(!IntCheck(empid_c) || strlen(empid_c) == 0)
		{
			gotoxy(35, 22);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 22, ' ');
			goto empid_check;
		}
		else
			empid = StringToInt(empid_c);

		name_check:
		gotoxy(45, 8);
		gets(name);

		if(strlen(name) == 0)
		{
		gotoxy(35, 22);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 22, ' ');
			goto name_check;
		}

		age_check:
		Line(45, 60, 10, ' ');
		gotoxy(45, 10);
		gets(age_c);

		if(!IntCheck(age_c) || strlen(age_c) == 0)
		{
		gotoxy(35, 22);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 22, ' ');
			goto age_check;
		}
		else
			age = StringToInt(age_c);

		telno_check:
		Line(45, 60, 12, ' ');
		gotoxy(45, 12);
		gets(telno_c);

		if(!IntCheck(telno_c) || strlen(telno_c) == 0)
		{
		gotoxy(35, 22);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 22, ' ');
			goto telno_check;
		}
		else
			telno = StringToInt(telno_c);

		desig_check:
		gotoxy(45, 14);
		gets(desig);

		if(strlen(desig) == 0)
		{
		gotoxy(35, 22);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 22, ' ');
			goto desig_check;
		}

		dept_check:
		gotoxy(45, 16);
		gets(dept);

		if(strlen(dept) == 0)
		{
			gotoxy(35, 22);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 22, ' ');
			goto dept_check;
		}

		grade_pay_check:
		Line(45, 60, 18, ' ');
		gotoxy(45, 18);
		gets(grade_pay_c);

		if(!IntCheck(grade_pay_c) || strlen(grade_pay_c) == 0)
		{
		gotoxy(35, 22);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 22, ' ');
			goto grade_pay_check;
		}
		else
			grade_pay = StringToInt(grade_pay_c);

		resp_check:
		Line(13, 78, 21, ' ');
		Line(13, 78, 22, ' ');
		gotoxy(13, 21);
		cout << "Are you sure you want this employee to be recorded? (Yes/No)";
		gotoxy(38, 22);
		gets(resp);

		if(!strcmpi(resp, "Yes") || !strcmpi(resp, "Y"))
		{
			E.Set_empID(empid);
			E.Set_name(name);
			E.Set_age(age);
			E.Set_telno(telno);
			E.Set_desig(desig);
			E.Set_dept(dept);
			E.Set_grade_pay(grade_pay);

			f.write((char*)&E, sizeof(E));

			Line(13, 78, 21, ' ');
			Line(13, 78, 22, ' ');
			gotoxy(31, 21);
			cout << "Writing into database";
			Delayed_text(52, 21, ".....");
			gotoxy(29, 22);
			cout << "Employee Recorded Sucessfully";
		}
		else if(!strcmpi(resp, "No") || !strcmpi(resp, "N"))
				goto reset_add;
		else
			goto resp_check;

		getch();
	}
	f.close();
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

    clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(35, 3);
	cout << "Search Employee";
	getch();
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

void Program::Salary_slip()
{
	/*
	 *  Hey Kassim,
	 *  Write the code of a salary MENU here similar to Main Menu
	 *  Where user can enter numbers and choose either Details or Salary Slip
	 *  Create necessary functions in Employee
	 *  - Sasuke Uchiha
	 */
	Employee E;
	int id;
	clrscr();
	Border('*');
	gotoxy(35, 3);
	 cout << "Salary Slip";


	Line(3, 78, 4, '_');
	Line(3, 78, 11, '*');

	gotoxy(5, 13);
	cout<<"Enter Employee ID of the employee whose salary slip are to be displayed:\n";

	Line(3, 78, 16, '*');

    getch();

}

void Program::Modify_menu()
{
    fstream f_find;
	Employee E;
	int ID;

	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(35, 3);
	cout << "Modify Details";

	Line(3, 78, 11, '*');
	Line(3, 78, 16, '*');
	gotoxy(7, 13);
	cout << "Enter Employee ID of the employee whose details are to be modified:\n";
	gotoxy(39, 14);
	cin >> ID;

	f_find.open("Employee.dat", ios::in | ios::binary);

	while(f_find.read((char*)&E, sizeof(E)))
	{

	}

	getch();
}

void Program::Reports()
{
	/*
	 *  Hey Madesh,
	 *  Write the code for creating a tabular representation of every detail of every employee
	 *  Create an input function in class Employee
	 *  - Sasuke Uchiha
	 */

	Employee E;
	int id;
    clrscr();
	Border('*');


	Line(3, 78, 4, '_');
	gotoxy(35, 3);
	cout << "Reports";

    Line(3, 78, 11, '*');
	gotoxy(35, 12);
	cout << "Enter the Id no";
	Line(3, 78, 14, '*');
	getch();

}

int Program::Change_password()
{
	 int p, number, upper, special;
	 char pass, new_password[50], confirm_password[50], strength[20];

	 clrscr();
	 Border('*');
	 strcpy(strength, "");

	 gotoxy(35, 3);
	 cout << "Change Password";
	 Line(3, 78, 4, '_');
	 gotoxy(23, 8);
	 cout << "New Password: ";
	 Box(41, 7, 20, 2, '-');
	 gotoxy(23, 11);
	 cout << "Strength: " << strength;
	 gotoxy(23, 14);
	 cout << "Confirm Password: ";
	 Box(41, 13, 20, 2, '-');
	 gotoxy(16, 17);
	 cout << "- Password should be atleast 8 characters long";
	 gotoxy(16, 18);
	 cout << "- Password should contain atleast one number";
	 gotoxy(16, 19);
	 cout << "- Password should contain atleast one uppercase letter";
	 gotoxy(16, 20);
	 cout << "- Password should contain atleast one special character";
	 gotoxy(53, 23);
	 cout << " Press Esc to go back";


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
				gotoxy(60, 8);
		  else
				gotoxy(42 + p, 8);
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
						  gotoxy(41 + p, 8);
						  cout << ' ';
					 }
					 --p;
					 new_password[p] = 0;
				}
		  }
		  else if(pass == 27)
				return 0;
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
		  gotoxy(23, 11);
		  cout << "Strength: " << strength;
	 }

	 //Getting confirmation
	 p = 0;
	 while(6 != 9)
	 {
		  if(p > 18)
				gotoxy(60, 14);
		  else
				gotoxy(42 + p, 14);
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
						  gotoxy(41 + p, 14);
						  cout << ' ';
					 }
					 --p;
					 confirm_password[p] = 0;
				}
		  }
		  else if(pass == 27)
				goto _newpass;
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
		  gotoxy(33, 17);
		  cout << "Passwords don't match";
		  goto _newpass;
	 }
	 else
	 {
		  if(strlen(new_password) < 8)
		  {
				gotoxy(29, 17);
				cout << "Password isn't long enough";
				goto _newpass;
		  }
		  else if(number == 0)
		  {
				gotoxy(27, 17);
				cout << "Password doesn't include numbers";
				goto _newpass;
		  }
		  else if(upper == 0)
		  {
				gotoxy(22, 17);
				cout << "Password doesn't include uppercase letters";
				goto _newpass;
		  }
		  else if(special == 0)
		  {
				gotoxy(21, 17);
				cout << "Password doesn't include special characters";
				goto _newpass;
		  }
		  else
		  {
				Set_acc_details(Get_username(), new_password);
				gotoxy(29, 17);
				cout << "Password change sucessful";
				Delay(3500);
		  }
	 }
}

int Program::Exit()
{
	char response[3];

	Line(20, 62, 23, ' ');
	gotoxy(22, 22);
	cout << "Are you sure you want to exit? (Yes/No)";
	exit_resp:
	Line(20, 62, 23, ' ');
	gotoxy(37, 23);
	gets(response);

	if(!strcmpi(response, "Yes") || !strcmpi(response, "Y"))
		exit(0);
	else if(!strcmpi(response, "No") || !strcmpi(response, "N"))
		return 0;
	else
		goto exit_resp;
}

													 ///////////////////////////////////////////

int main()
{
	Employee E;
	Design D;
	Help H;
	Program P;

	P.Main_menu();
	getch();
}
