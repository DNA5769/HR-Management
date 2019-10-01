#define D 3500
#define D_r 512

#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

class Employee
{
private:
	int empID;
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
	char* Get_username();
	//Returns username
	char* Get_password();
	//Returns password
	void Set_acc_details(char username[], char password[]);
	//Sets username and password
	void Setup_net_sal();
	void Calculate_net_sal();
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
	fstream f;
	f.open("Account.dat", ios::out | ios::binary);

	strcpy(acc.username, username);
	strcpy(acc.password, password);

	f.write((char*)&acc, sizeof(acc));
	f.close();
}

void Employee::Setup_net_sal()
{
	sal.HRA = 0.4 * sal.basic;
	sal.PF = 0.12 * sal.basic;
	sal.DA = 500;
	sal.MA = 800;
	sal.TA = 200;

	sal.net_sal = sal.grade_pay + sal.basic + sal.HRA + sal.DA + sal.MA + sal.TA - sal.PF;
	sal.tax = 0.1 * sal.net_sal;

	sal.net_sal -= sal.tax;
}

void Employee::Calculate_net_sal()
{
	sal.net_sal = sal.grade_pay + sal.basic + sal.HRA + sal.DA + sal.MA + sal.TA - sal.PF - sal.tax;
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
	void Line2(int x, int y1, int y2, char ch);
	//Creates a line from (x, y1) to (x, y2) of specified character 'ch'
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
	void Delayed_text(int x, int y, char string[]);
	//Creates a small welcome sign
	void Star_top_L();        //     These 4 functions
	void Star_top_R();        //     are used to create the '*'
	void Star_bottom_L();     //     borders in the in
	void Star_bottom_R();     //     Program::Main_menu()
	void Main_menu_sign();
	//Displays 'MAIN MENU' in Program::Main_menu()
	void Wave_ting(char ch);
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

void Design::Line2(int x, int y1, int y2, char ch)
{
	for(int i = y1; i <= y2; ++i)
	{
		gotoxy(x, i);
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
	gotoxy(42 + i, 8);
	cout << ' ';
	}
	for(int j = 0; j < 19; ++j)
	{
	gotoxy(42 + j, 14);
	cout << ' ';
	}
}

void Design::ClearChangePasswordMessage()
{
	int i;

	//Clears long message
	for(i = 0; i < 54; ++i)
	{
	gotoxy(16 + i, 17);
	cout << ' ';
	}
	for(i = 0; i < 54; ++i)
	{
		gotoxy(16 + i, 18);
	cout << ' ';
	}
	for(i = 0; i < 54; ++i)
	{
	gotoxy(16 + i, 19);
	cout << ' ';
	}
	for(i = 0; i < 55; ++i)
	{
	gotoxy(16 + i, 20);
	cout << ' ';
	}
}

void Design::ClearStrength()
{
	 for(int i = 0; i < 50; ++i)
	{
	gotoxy(23 + i, 11);
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

void Design::Wave_ting(char ch)
{
	int z,x;

	for(x=5;x<=17;x+=6)
	{
	for(z=3;z<=6;z++,x++)
	{
		gotoxy(z,x);
		cout<<ch;
	}
	}

	for(x=9;x<20;x+=10)
	{
	gotoxy(6,x);
	cout<<ch;
	}

	for(z=6;z>2;z--)
	{
	for(x=10;x<15;z--,x++)
	{
		gotoxy(z,x);
		cout<<ch;
	}
	}

	for(x=4;x<=15;x+=10)
	{
	gotoxy(2,x);
	cout<<ch;
	}

	for(z=6;z>2;z--)
	{
	for(x=20;x<24;z--,x++)
	{
		gotoxy(z,x);
		cout<<ch;
	}
	}

	for(x=5;x<=17;x+=6)
	{
	for(z=75;z<=78;z++,x++)
	{
		gotoxy(z,x);
		cout<<ch;
	}
	}

	for(x=9;x<20;x+=10)
	{
	gotoxy(79,x);
	cout<<ch;
	}

	for(z=78;z>77;z--)
	{
	for(x=10;x<14;z--,x++)
	{
		gotoxy(z,x);
		cout<<ch;
	}
	}

	for(x=4;x<=25;x+=10)
	{
	gotoxy(75,x);
	cout<<ch;
	}

	for(z=78;z>75;z--)
	{
	for(x=20;x<24;z--,x++)
	{
		gotoxy(z,x);
		cout<<ch;
	}
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
	long StringToInt(char str[]);
	float StringToFloat(char str[]);
	int IntCheck(char str[]);
	int FloatCheck(char str[]);
	int WordCheck(char str[]);
	int EmpNoCheck(int n);
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

float Help::StringToFloat(char str[])
{
	return atof(str);
}

int Help::IntCheck(char str[])
{
	for(int i = 0; str[i] != 0; ++i)
		if(!isdigit(str[i]))
			return 0;

	return 1;
}

int Help::FloatCheck(char str[])
{
	for(int i = 0; str[i] != 0; ++i)
		if(!isdigit(str[i]) && str[i] != '.')
			return 0;

	return 1;
}

int Help::WordCheck(char str[])
{
	for(int i = 0; str[i] != 0; ++i)
		if(isdigit(str[i]))
			return 0;

	return 1;
}

int Help::EmpNoCheck(int n)
{
	int found = 0;
	fstream f;
	Employee E;

	f.open("Employee.dat", ios::in | ios::binary);
	while(f.read((char*)&E, sizeof(E)))
		if(E.Get_empID() == n)
			found = 1;

	if(found == 1)
		return 0;
	else
		return 1;
}

										///////////////////////////////////////////

class Program : public Employee, public Design, public Help
{
private:
protected:
public:
	void Login();
	void Main_menu();
	int Add_emp();
	int Search_menu();
	int Search_empno();
	int Search_name();
	int Search_dept();
	int Search_desig();
	int Search_age();
	int Salary_slip();
	int Modify_menu();
	void Modify_name(int id);
	void Modify_telno(int id);
	void Modify_desig(int id);
	void Modify_dept(int id);
	void Modify_grade_pay(int id);
	void Modify_SD(int id);
	int Reports();
	int Reports(int id);
	int Change_password();
	int Logs();
	int Exit(char ch);
};

void Program::Login()
{
	fstream f;
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
		  f.open("Logs.txt", ios::app);
		  f << '\n';
		  f.close();
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

		Border('*');
		Box(27, 4, 24, 16, '!');

		switch(option)
		{
		case 49:
			Line(28, 50, 6, '*');
			gotoxy(29, 5);
			cout << "->";
			break;
		case 50:
			Line(28, 50, 6, '*');
			Line(28, 50, 8, '*');
			gotoxy(29, 7);
			cout << "->";
			break;
		case 51:
			Line(28, 50, 8, '*');
			Line(28, 50, 10, '*');
			gotoxy(29, 9);
			cout << "->";
			break;
		case 52:
			Line(28, 50, 10, '*');
			Line(28, 50, 12, '*');
			gotoxy(29, 11);
			cout << "->";
			break;
		case 53:
			Line(28, 50, 12, '*');
			Line(28, 50, 14, '*');
			gotoxy(29, 13);
			cout << "->";
			break;
		case 54:
			Line(28, 50, 14, '*');
			Line(28, 50, 16, '*');
			gotoxy(29, 15);
			cout << "->";
			break;
		case 55:
			Line(28, 50, 16, '*');
			Line(28, 50, 18, '*');
			gotoxy(29, 17);
			cout << "->";
			break;
		case 56:
			Line(28, 50, 18, '*');
			gotoxy(29, 19);
			cout << "->";
			break;
		}

		gotoxy(31, 5);
		cout << "1. Add Employee";
		gotoxy(31, 7);
		cout << "2. Search Employee";
		gotoxy(31, 9);
		cout << "3. Salary Slip";
		gotoxy(31, 11);
		cout << "4. Modify Details";
		gotoxy(31, 13);
		cout << "5. Reports";
		gotoxy(31, 15);
		cout << "6. Change Password";
		gotoxy(31, 17);
		cout << "7. Logs";
		gotoxy(31, 19);
		cout << "8. Exit";

		gotoxy(25, 22);
		cout << "Select your desired option (1-8)";
		gotoxy(20, 23);
		cout << "Press 'Enter' to finalize your selection: ";
		gets(selection);

		if(selection[0] >= 49 && selection[0] <= 56 && strlen(selection) == 1)
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
				Logs();
				break;
			case 56:
				if(!Exit('M'))         //If user says 'No' while exit confirmation, it returns 0 and displays menu
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

int Program::Add_emp()
{
	fstream f, f_log;
	Employee E;
	int N, r, cleared;
	char resp[20];

	int empid, age, grade_pay;
	char name[20], desig[20], dept[20], empid_c[20], age_c[20], telno_c[20], grade_pay_c[20];
	float basic, HRA, DA, tax, TA, MA, PF;
	long telno;

	_add_emp:
	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(33, 3);
	cout << "Add New Employee";

	Line(3, 78, 11, '*');
	Line(3, 78, 16, '*');
	gotoxy(23, 13);
	cout << "Enter number of employees to be added:\n";
	gotoxy(41, 14);
	gets(resp);

	if(!IntCheck(resp))
	{
		gotoxy(35, 22);
		cout << "Invalid Input!";
		Delay(2000);
		Line(35, 50, 22, ' ');
		goto _add_emp;
	}

	N = StringToInt(resp);

	f.open("Employee.dat", ios::app | ios::binary);
	f_log.open("Logs.txt", ios::app);
	for(int i = 1; i <= N; ++i)
	{
		reset_add:
		cleared = 0;
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

		if(!EmpNoCheck(empid))
		{
			gotoxy(29, 22);
			cout << "Employee " << empid << " already exists!";
			Delay(2000);
			Line(29, 70, 22, ' ');
			goto empid_check;
		}

		name_check:
		Line(45, 60, 8, ' ');
		gotoxy(45, 8);
		gets(name);

		if(!WordCheck(name) || strlen(name) == 0)
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
		  cout << "+973 ";
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
		gotoxy(21, 22);
		cout << "Designations: Manager, Executive, Assistant";
		Line(45, 60, 14, ' ');
		gotoxy(45, 14);
		gets(desig);

		if(!WordCheck(desig) || strlen(desig) == 0 || (strcmp(desig, "Manager") != 0 && strcmp(desig, "Executive") != 0 && strcmp(desig, "Assistant") != 0))
		{
			Line(21, 70, 22, ' ');
			gotoxy(35, 22);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 22, ' ');
			goto desig_check;
		}
		Line(21, 70, 22, ' ');

		dept_check:
		Line(45, 60, 16, ' ');
		gotoxy(45, 16);
		gets(dept);

		if(!WordCheck(dept) || strlen(dept) == 0)
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
		cout << "$ ";
		gets(grade_pay_c);

		if(!FloatCheck(grade_pay_c) || strlen(grade_pay_c) == 0)
		{
			gotoxy(35, 22);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 22, ' ');
			goto grade_pay_check;
		}
		else
			grade_pay = StringToFloat(grade_pay_c);

		if(grade_pay <= 3600 || grade_pay >= 9999)
		{
			gotoxy(22, 22);
			cout << "Grade Pay should be between $3600 and $9999";
			Delay(2000);
			Line(22, 75, 22, ' ');
			goto grade_pay_check;
		}

		resp_check:
		Line(13, 78, 22, ' ');
		Line(13, 78, 23, ' ');
		gotoxy(13, 22);
		cout << "Are you sure you want this employee to be recorded? (Yes/No)";
		gotoxy(38, 23);
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

			if(!strcmp(desig, "Manager"))
				E.Set_basic(2100);
			else if(!strcmp(desig, "Executive"))
				E.Set_basic(1800);
			else if(!strcmp(desig, "Assistant"))
				E.Set_basic(1500);

			E.Setup_net_sal();

			f.write((char*)&E, sizeof(E));
			f_log << "Employee " << empid << " has been added" << endl;

			if(i != N)
			{
				Line(13, 78, 22, ' ');
				Line(13, 78, 23, ' ');
				gotoxy(31, 21);
				cout << "Writing into database";
				Delayed_text(52, 21, ".....");
				gotoxy(29, 22);
				cout << "Employee Recorded Sucessfully";
				Delay(2000);

				addemp_exit_check1:
				if(cleared == 0)
				{
					gotoxy(25, 23);
					cout << "Press Enter to continue or Esc to exit";
				}
				else
				{
					gotoxy(25, 22);
					cout << "Press Enter to continue or Esc to exit";
				}
				gotoxy(100, 100);
				r = getch();

				if(r == 27)
					return 0;
				else if(r != 13)
				{
					cleared = 1;
					Line(13, 78, 21, ' ');
					Line(13, 78, 22, ' ');
					Line(13, 78, 23, ' ');
					gotoxy(35, 22);
					cout << "Invalid Input!";
					Delay(2000);
					Line(35, 50, 22, ' ');
					goto addemp_exit_check1;
				}
			}
			else
			{
				Line(13, 78, 22, ' ');
				Line(13, 78, 23, ' ');
				gotoxy(31, 22);
				cout << "Writing into database";
				Delayed_text(52, 22, ".....");
				gotoxy(29, 23);
				cout << "Employee Recorded Sucessfully";
				gotoxy(100, 100);
				getch();
			}
		}
		else if(!strcmpi(resp, "No") || !strcmpi(resp, "N"))
				goto reset_add;
		else
			goto resp_check;
	}
	f.close();
	f_log.close();
}

int Program::Search_menu()
{
	clrscr();

    char selection[20];
	int option = 49;
	do
	{
        Wave_ting('*');
        Line(3, 78, 4, '_');
        gotoxy(33, 3);
        cout << "Search Employee";
		Border('*');
		Box(21, 7, 36, 10, '!');

		switch(option)
		{
		case 49:
			Line(21, 57, 9, '*');
			gotoxy(23, 8);
			cout << "->";
			break;
		case 50:
			Line(21, 57, 9, '*');
			Line(21, 57, 11, '*');
			gotoxy(23, 10);
			cout << "->";
			break;
		case 51:
			Line(21, 57, 11, '*');
			Line(21, 57, 13, '*');
			gotoxy(23, 12);
			cout << "->";
			break;
		case 52:
			Line(21, 57 , 13, '*');
			Line(21, 57, 15, '*');
			gotoxy(23, 14);
			cout << "->";
			break;
		case 53:
			Line(21, 57, 15, '*');
			Line(21, 57, 17, '*');
			gotoxy(23, 16);
			cout << "->";
			break;

		}

		gotoxy(25, 8);
		cout << "1. Search Employee by Name";
		gotoxy(25, 10);
		cout << "2. Search Employee by Dept.";
		gotoxy(25, 12);
		cout << "3. Search Employee by Desig.";
		gotoxy(25, 14);
		cout << "4. Search Employee by Age";
		gotoxy(25, 16);
		cout << "5. Back to Main menu";


		gotoxy(25, 22);
		cout << "Select your desired option (1-5)";
		gotoxy(20, 23);
		cout << "Press 'Enter' to finalize your selection: ";
		gets(selection);

		if(selection[0] >= 49 && selection[0] <= 53 && strlen(selection) == 1)
			option = selection[0];
		else if(strlen(selection) == 0)
		{
			switch(option)
			{
			case 49:
				Search_name();
				break;
			case 50:
				Search_dept();
				break;
			case 51:
				Search_desig();
				break;
			case 52:
				Search_age();
				break;
			case 53:
				return 0;
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
	 clrscr();
	 }while(6 != 9);

}



int Program::Search_name()
{

	Employee E;
	char r, Eempname[35];
	fstream fin;
	int count;
	next:
	clrscr();
	Border('*');

	Line(3, 78, 11, '*');
	Line(3, 78, 15, '*');
	Line(3, 78, 4, '_');
	gotoxy(33, 3);
	cout << "Search Employee";

	resp_check:
	Line(25, 75, 13, ' ');
	gotoxy(25, 13);
	cout<< "Enter the Employee Name: ";
	gets(Eempname);

	if(!WordCheck(Eempname) || strlen(Eempname) == 0)
	{
		gotoxy(35, 22);
		cout << "Invalid Input!";
		Delay(2000);
		Line(35, 50, 22, ' ');
		goto resp_check;
	}

	count = 0;
	fin.open("Employee.dat",ios::in | ios::binary);
	while(fin.read((char*)&E,sizeof(E)))
		if(!strcmp(E.Get_name(), Eempname))
			++count;
	fin.close();

	if(count>=1)
	{
		Line(25, 70, 13, ' ');
		gotoxy(30, 13);
		if(count == 1)
			cout << count << " Employee found";
		else
			cout << count << " Employees found";
		gotoxy(100, 100);
		getch();

		fin.open("Employee.dat",ios::in | ios::binary);
		while(fin.read((char*)&E,sizeof(E)))
			if(!strcmp(E.Get_name(), Eempname))
				Reports(E.Get_empID());
		fin.close();
	}
	else
	{

		gotoxy(31, 21);
		cout << "Searching database";
		Delayed_text(49, 21, "....");
		gotoxy(32, 22);
		cout << "Employee Not Found!";
		gotoxy(23, 23);
		cout << "Press Esc to exit or Enter to try again";
		gotoxy(100, 100);
		r = getch();

		if(r == 13)
			goto next;
		else
			return 0;
	}
}

int Program::Search_dept()
{
	Employee E;
	char r, EempDept[35];
	fstream fin;
	int count;

	next:
	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(33, 3);
	cout << "Search Employee";

	Line(3, 78, 11, '*');
	Line(3, 78, 15, '*');
	resp_check:
	Line(25, 75, 13, ' ');
	gotoxy(25,13);
	cout << "Enter the Employee's Department: ";
	gets(EempDept);

	if(!WordCheck(EempDept) || strlen(EempDept) == 0)
	{
		gotoxy(35, 22);
		cout << "Invalid Input!";
		Delay(2000);
		Line(35, 50, 22, ' ');
		goto resp_check;
	}

	count = 0;
	fin.open("Employee.dat",ios::in | ios::binary);
	while(fin.read((char*)&E,sizeof(E)))
		if(!strcmp(E.Get_dept(), EempDept))
			++count;
	fin.close();

	if(count>=1)
	{
		Line(25, 70, 13, ' ');
		gotoxy(30, 13);
		if(count == 1)
			cout << count << " Employee found";
		else
			cout << count << " Employees found";
		gotoxy(100, 100);
		getch();

		fin.open("Employee.dat",ios::in | ios::binary);
		while(fin.read((char*)&E,sizeof(E)))
			if(!strcmp(E.Get_dept(), EempDept))
				Reports(E.Get_empID());
		fin.close();
	}
	else
	{

		gotoxy(31, 21);
		cout << "Searching database";
		Delayed_text(49, 21, "....");
		gotoxy(32, 22);
		cout << "Employee Not Found!";
		gotoxy(23, 23);
		cout << "Press Esc to exit or Enter to try again";
		gotoxy(100, 100);
		r = getch();

		if(r == 13)
			goto next;
		else
			return 0;
	}
}

int Program::Search_desig()
{
	Employee E;
	char r, EempDesig[45];
	fstream fin;
	int count;

	next:
	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(33, 3);
	cout << "Search Employee";

	Line(3, 78, 11, '*');
	Line(3, 78, 15, '*');
	resp_check:
	Line(25, 75, 13, ' ');
	gotoxy(25,13);
	cout << "Enter the Employee's Designation: ";
	gets(EempDesig);

	if(!WordCheck(EempDesig) || strlen(EempDesig) == 0)
	{
		gotoxy(35, 22);
		cout << "Invalid Input!";
		Delay(2000);
		Line(35, 50, 22, ' ');
		goto resp_check;
	}

	count = 0;
	fin.open("Employee.dat",ios::in | ios::binary);
	while(fin.read((char*)&E,sizeof(E)))
		if(!strcmp(E.Get_desig(), EempDesig))
			++count;
	fin.close();

	if(count>=1)
	{
		Line(25, 70, 13, ' ');
		gotoxy(30, 13);
		if(count == 1)
			cout << count << " Employee found";
		else
			cout << count << " Employees found";
		gotoxy(100, 100);
		getch();

		fin.open("Employee.dat",ios::in | ios::binary);
		while(fin.read((char*)&E,sizeof(E)))
			if(!strcmp(E.Get_desig(), EempDesig))
				Reports(E.Get_empID());
		fin.close();
	}
	else
	{

		gotoxy(31, 21);
		cout << "Searching database";
		Delayed_text(49, 21, "....");
		gotoxy(32, 22);
		cout << "Employee Not Found!";
		gotoxy(23, 23);
		cout << "Press Esc to exit or Enter to try again";
		gotoxy(100, 100);
		r = getch();

		if(r == 13)
			goto next;
		else
			return 0;
	}
}

int Program::Search_age()
{
	Employee E;
	char age_c[20];
	int age;
	char r;
	fstream fin;
	int count;

	next:
	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(33, 3);
	cout << "Search Employee";

	Line(3, 78, 11, '*');
	Line(3, 78, 15, '*');
	resp_check:
	Line(25, 75, 13, ' ');
	gotoxy(25,13);
	cout << "Enter the Employee's Age ";
	gets(age_c);

	if(!IntCheck(age_c) || strlen(age_c) == 0)
	{
		gotoxy(35, 22);
		cout << "Invalid Input!";
		Delay(2000);
		Line(35, 50, 22, ' ');
		goto resp_check;
	}
	else
		age = StringToInt(age_c);

	count = 0;
	fin.open("Employee.dat",ios::in | ios::binary);
	while(fin.read((char*)&E,sizeof(E)))
		if(E.Get_age() == age)
			++count;
	fin.close();

	if(count>=1)
	{
		Line(25, 70, 13, ' ');
		gotoxy(30, 13);
		if(count == 1)
			cout << count << " Employee found";
		else
			cout << count << " Employees found";
		gotoxy(100, 100);
		getch();

		fin.open("Employee.dat",ios::in | ios::binary);
		while(fin.read((char*)&E,sizeof(E)))
			if(E.Get_age() == age)
				Reports(E.Get_empID());
		fin.close();
	}
	else
	{

		gotoxy(31, 21);
		cout << "Searching database";
		Delayed_text(49, 21, "....");
		gotoxy(32, 22);
		cout << "Employee Not Found!";
		gotoxy(23, 23);
		cout << "Press Esc to exit or Enter to try again";
		gotoxy(100, 100);
		r = getch();

		if(r == 13)
			goto next;
		else
			return 0;
	}
}

int Program::Salary_slip()
{
	fstream f;
	Employee E;
	int id, found;
	char r, id_c[20];

	_reset:
	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(39, 3);
	cout << "Salary slip";

	Line(3, 78, 11, '*');
	Line(3, 78, 16, '*');
	gotoxy(34, 13);
	cout << "Enter the Employee ID";
	gotoxy(41, 14);
	gets(id_c);

    if(!IntCheck(id_c) || strlen(id_c) == 0)
	{
		gotoxy(35, 22);
		cout << "Invalid Input!";
		Delay(2000);
		Line(35, 50, 23, ' ');
		goto _reset;
	}
	else
		id = StringToInt(id_c);

	found = 0;
	f.open("Employee.dat", ios::in | ios::binary);
	while(f.read((char*)&E, sizeof(E)))
		if(id==E.Get_empID())
		{
			found = 1;

			clrscr();
			Border('*');

			Line(3, 78, 4, '_');
			gotoxy(39, 3);
			cout << "Salary slip";

			gotoxy(5, 6);
			cout << "Employee ID:";
			gotoxy(18, 6);
			cout << E.Get_empID();
			gotoxy(5, 7);
			cout << "Name:";
			gotoxy(11, 7);
			cout << E.Get_name();
			gotoxy(32, 6);
			cout << "Age:";
			gotoxy(37, 6);
			cout << E.Get_age();
			gotoxy(32, 7);
			cout << "Tel:";
			gotoxy(37, 7);
			cout << E.Get_telno();
			gotoxy(55, 6);
			cout << "Designation:";
			gotoxy(68, 6);
			cout << E.Get_desig();
			gotoxy(55, 7);
			cout << "Department:";
			gotoxy(67, 7);
			cout << E.Get_dept();
			Line(6, 20, 30, ':');

			gotoxy(5, 10);
			cout << "Earnings";
			gotoxy(31,10);
			cout << "Amount";

			gotoxy(5, 13);
			cout << "Basic Pay:";
			gotoxy(31, 13);
			cout << "+" << E.Get_basic();

			gotoxy(5, 14);
			cout << "HRA:";
			gotoxy(31, 14);
			cout << "+" << E.Get_HRA();

			gotoxy(5, 15);
			cout << "MA:";
			gotoxy(31, 15);
			cout << "+" << E.Get_MA();

			gotoxy(5, 16);
			cout<<"DA:";
			gotoxy(31, 16);
			cout << "+" << E.Get_DA();

			gotoxy(5, 17);
			cout << "TA:";
			gotoxy(31, 17);
			cout << "+" << E.Get_TA();

			gotoxy(5, 20);
			cout << "Total Earnings:";
			gotoxy(31,20);
			cout << E.Get_basic() + E.Get_TA() + E.Get_MA() + E.Get_DA() + E.Get_HRA();

			gotoxy(44, 10);
			cout << "Deductions";
			gotoxy(65, 10);
			cout << "Amount";

			gotoxy(44,13);
			cout << "Tax:";
			gotoxy(65,13);
			cout << "-" << E.Get_tax();

			gotoxy(44,14);
			cout << "PF:";
			gotoxy(65,14);
			cout << "-" << E.Get_PF();

			gotoxy(44, 20);
			cout << "Total Deductions:";
			gotoxy(65,20);
			cout << E.Get_PF() + E.Get_tax();

			gotoxy(5,23);
			cout << "Net Salary: $" << E.Get_grade_pay() << " + Total Earnings - Total Deductions = $" << E.Get_net_sal();

			Border('*');
			Line(4, 77, 8, '_');
			Line(3, 78, 11, '_');
			Line(3, 78, 21,'_');
			Line(3, 78, 18, '_');
			Line(3, 78, 24, '_');
			Line2(40, 9, 21, '|');
			Line2(3, 5, 24, '|');
			Line2(78, 5, 24, '|');
			Line2(22, 9, 18, '|');
			Line2(60, 9, 18, '|');
			break;
		}
		f.close();

	if(found == 0)
	{
		clrscr();
		Border('*');
		Line(3, 78, 4, '_');
		gotoxy(39, 3);
		cout << "Salary Slip";
		Line(3, 78, 11, '*');
		Line(3, 78, 16, '*');
		gotoxy(31, 13);
		cout << "Selected ID does not exist";
		gotoxy(25, 14);
		cout << "Press Enter to try again or Esc to exit";
		gotoxy(100, 100);
		_resp_check:
		r = getch();

		if(r == 13)
			goto _reset;
		else if(r ==  27)
			return 0;
		else
		{
			Line(29, 70, 13, ' ');
			Line(23, 70, 14, ' ');
			gotoxy(30, 14);
			cout << "Invalid Input!";
			Delay(D);
			Line(30, 70, 14, ' ');
			goto _resp_check;
		}
	}

	gotoxy(100, 100);
	getch();
}

int Program::Modify_menu()
{
	char selection[20];
	int option = 49, exit;

	fstream f;
	Employee E;
	int ID, found = 0;

	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(35, 3);
	cout << "Modify Details";

	Line(3, 78, 11, '*');
	Line(3, 78, 16, '*');
	gotoxy(8, 13);
	cout << "Enter Employee ID of the employee whose details are to be modified:\n";
	gotoxy(39, 14);
	cin >> ID;

	f.open("Employee.dat", ios::in | ios::out | ios::binary);

	while(f.read((char*)&E, sizeof(E)))
		if(E.Get_empID() == ID)
		{
			found == 1;

			gotoxy(31, 21);
			cout << "Searching database";
			Delayed_text(49, 21, "....");
			gotoxy(35, 22);
			cout << "Employee Found!";
			gotoxy(100, 100);
			getch();

			do
			{
				//Display Menu
				_modmenu:
				clrscr();
				Star_top_L();
				Star_bottom_R();
				Line(2, 20, 2, ' ');
				Line(2, 20, 3, ' ');

					 Line(3, 78, 4, '_');
				gotoxy(35, 3);
				cout << "Modify Details";

				Border('*');
				Box(24, 6, 33, 14, '!');

				switch(option)
				{
				case 49:
					Line(25, 56, 8, '*');
					gotoxy(26, 7);
					cout << "->";
					break;
				case 50:
					Line(25, 56, 8, '*');
					Line(25, 56, 10, '*');
					gotoxy(26, 9);
					cout << "->";
					break;
				case 51:
					Line(25, 56, 10, '*');
					Line(25, 56, 12, '*');
					gotoxy(26, 11);
					cout << "->";
					break;
				case 52:
					Line(25, 56, 12, '*');
					Line(25, 56, 14, '*');
					gotoxy(26, 13);
					cout << "->";
					break;
				case 53:
					Line(25, 56, 14, '*');
					Line(25, 56, 16, '*');
					gotoxy(26, 15);
					cout << "->";
					break;
				case 54:
					Line(25, 56, 16, '*');
					Line(25, 56, 18, '*');
					gotoxy(26, 17);
					cout << "->";
					break;
				case 55:
					Line(25, 56, 18, '*');
					gotoxy(26, 19);
					cout << "->";
					break;
				}

				gotoxy(28, 7);
				cout << "1. Change Name";
				gotoxy(28, 9);
				cout << "2. Change Telephone number";
				gotoxy(28, 11);
				cout << "3. Change Designation";
				gotoxy(28, 13);
				cout << "4. Change Department";
				gotoxy(28, 15);
				cout << "5. Change Grade Pay";
				gotoxy(28, 17);
				cout << "6. Change Salary Details";
				gotoxy(28, 19);
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
						Modify_name(ID);
						break;
					case 50:
						Modify_telno(ID);
								break;
					case 51:
						Modify_desig(ID);
								break;
					case 52:
						Modify_dept(ID);
								break;
					case 53:
						Modify_grade_pay(ID);
								break;
					case 54:
						Modify_SD(ID);
						break;
			case 55:
			if(!Exit('N'))         //If user says 'No' while exit confirmation, it returns 0 and displays menu
							goto _modmenu;
			else
							return 0;
			break;
			}
		}
		else
		{
			Line(25, 67, 22, ' ');
			Line(20, 66, 23, ' ');
			gotoxy(35, 22);
			cout << "Invalid Selection";
			Delay(2000);
		}

			}while(6 != 9);

			getch();
		}

	if(found == 0)
	{
		gotoxy(31, 21);
		cout << "Searching database";
		Delayed_text(49, 21, "....");
		gotoxy(32, 22);
		cout << "Employee Not Found!";
	}

	getch();
}

void Program::Modify_name(int id)
{
	fstream f, f_log;
	Employee E;
	char name[20];

	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(35, 3);
	cout << "Modify Details";

	gotoxy(20, 9);
	cout << "Current Name: ";
	Box(35, 8 ,25, 2, '-');

	gotoxy(19, 13);
	cout << "Modified Name: ";
	Box(35, 12 ,25, 2, '-');
	Line(3, 78, 17, '_');

	f.open("Employee.dat", ios::in | ios::out | ios::binary);
	f_log.open("Logs.txt", ios::app);
	while(f.read((char*)&E, sizeof(E)))
		if(E.Get_empID() == id)
		{
			_modname:
			Line(37, 55, 13, ' ');
			gotoxy(37, 9);
			cout << E.Get_name();
			gotoxy(37, 13);
			gets(name);

			if(!strcmpi(E.Get_name(), name))
			{
				gotoxy(24, 21);
				cout << "New name cannot be same as current name";
				Delay(D);
				Line(24, 70, 21, ' ');
				goto _modname;
			}
			else if(!WordCheck(name) || strlen(name) == 0)
			{
				gotoxy(34, 21);
				cout << "Invalid Input!";
				Delay(D);
				Line(30, 70, 21, ' ');
				goto _modname;
			}
			else
			{

		f_log << "Employee " << E.Get_empID() <<"'s Name has been modified from " << E.Get_name() << " to " << name << endl;

				E.Set_name(name);
				f.seekp(f.tellg() - sizeof(E), ios::beg);
				f.write((char*)&E, sizeof(E));

				gotoxy(30, 21);
				cout << "Overwriting to database";
				Delayed_text(53, 21, "....");
				gotoxy(32, 22);
				cout << "Modification Sucessful!";
				gotoxy(100, 100);
				getch();
			}
		}
	f_log.close();
	f.close();

}

void Program::Modify_telno(int id)
{
	fstream f, f_log;
	Employee E;
	char telno[20];
	long tel;

	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(35, 3);
	cout << "Modify Details";

	gotoxy(19, 9);
	cout << "Current Tel. Number: ";
	Box(40, 8 ,25, 2, '-');

	gotoxy(18, 13);
	cout << "Modified Tel. Number: ";
	Box(40, 12 ,25, 2, '-');
	Line(3, 78, 17, '_');

	f.open("Employee.dat", ios::in | ios::out | ios::binary);
	f_log.open("Logs.txt", ios::app);
	while(f.read((char*)&E, sizeof(E)))
		if(E.Get_empID() == id)
		{
			_modtelno:
			Line(42, 55, 13, ' ');
			gotoxy(42, 9);
			cout << "+973 " << E.Get_telno();
			gotoxy(42, 13);
			cout << "+973 ";
			gets(telno);

			if(!IntCheck(telno) || strlen(telno) == 0)
			{
				gotoxy(34, 21);
				cout << "Invalid Input!";
				Delay(D);
				Line(30, 70, 21, ' ');
				goto _modtelno;
			}
			if(E.Get_telno() == StringToInt(telno))
			{
				gotoxy(22, 21);
				cout << "New number cannot be same as current number";
				Delay(D);
				Line(22, 70, 21, ' ');
				goto _modtelno;
			}
			else
			{

				tel = StringToInt(telno);

		f_log << "Employee " << E.Get_empID() << "'s Telephone number has been modified from " << E.Get_telno() <<" to " << tel << endl;

				E.Set_telno(tel);
				f.seekp(f.tellg() - sizeof(E), ios::beg);
				f.write((char*)&E, sizeof(E));

				gotoxy(30, 21);
				cout << "Overwriting to database";
				Delayed_text(53, 21, "....");
				gotoxy(32, 22);
				cout << "Modification Sucessful!";
				gotoxy(100, 100);
				getch();
			}
		}
	f.close();

}

void Program::Modify_desig(int id)
{
	fstream f, f_log;
	Employee E;
	char desig[20];

	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(35, 3);
	cout << "Modify Details";

	gotoxy(18, 9);
	cout << "Current Designation: ";
	Box(39, 8 ,25, 2, '-');

	gotoxy(17, 13);
	cout << "Modified Designation: ";
	Box(39, 12 ,25, 2, '-');
	Line(3, 78, 17, '_');

	f.open("Employee.dat", ios::in | ios::out | ios::binary);
	f_log.open("Logs.txt", ios::app);
	while(f.read((char*)&E, sizeof(E)))
		if(E.Get_empID() == id)
		{
			_moddesig:
			Line(41, 55, 13, ' ');
			gotoxy(41, 9);
			cout << E.Get_desig();
			gotoxy(41, 13);
			gets(desig);

			if(!strcmpi(E.Get_desig(), desig))
			{
				gotoxy(16, 21);
				cout << "New designation cannot be same as current designation";
				Delay(D);
				Line(16, 70, 21, ' ');
				goto _moddesig;
			}
			else if(!WordCheck(desig) || strlen(desig) == 0)
			{
				gotoxy(34, 21);
				cout << "Invalid Input!";
				Delay(D);
				Line(30, 70, 21, ' ');
				goto _moddesig;
			}
			else
			{
		f_log << "Employee " << E.Get_empID() <<"'s Designation has been modified from " << E.Get_desig() << " to " << desig << endl;

				E.Set_desig(desig);
				f.seekp(f.tellg() - sizeof(E), ios::beg);
				f.write((char*)&E, sizeof(E));

				gotoxy(30, 21);
				cout << "Overwriting to database";
				Delayed_text(53, 21, "....");
				gotoxy(32, 22);
				cout << "Modification Sucessful!";
				gotoxy(100, 100);
				getch();
			}
		}
	f_log.close();
	f.close();

}

void Program::Modify_dept(int id)
{
	fstream f, f_log;
	Employee E;
	char dept[20];

	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(35, 3);
	cout << "Modify Details";

	gotoxy(18, 9);
	cout << "Current Department: ";
	Box(39, 8 ,25, 2, '-');

	gotoxy(17, 13);
	cout << "Modified Department: ";
	Box(39, 12 ,25, 2, '-');
	Line(3, 78, 17, '_');

	f.open("Employee.dat", ios::in | ios::out | ios::binary);
	f_log.open("Logs.txt", ios::app);
	while(f.read((char*)&E, sizeof(E)))
		if(E.Get_empID() == id)
		{
			_moddept:
			Line(41, 55, 13, ' ');
			gotoxy(41, 9);
			cout << E.Get_dept();
			gotoxy(41, 13);
			gets(dept);

			if(!strcmpi(E.Get_dept(), dept))
			{
				gotoxy(17, 21);
				cout << "New department cannot be same as current department";
				Delay(D);
				Line(17, 70, 21, ' ');
				goto _moddept;
			}
			else if(!WordCheck(dept) || strlen(dept) == 0)
			{
				gotoxy(34, 21);
				cout << "Invalid Input!";
				Delay(D);
				Line(30, 70, 21, ' ');
				goto _moddept;
			}
			else
			{
		f_log << "Employee " << E.Get_empID() << "'s Department has been modified from " << E.Get_dept() << " to " << dept << endl;

				E.Set_dept(dept);
				f.seekp(f.tellg() - sizeof(E), ios::beg);
				f.write((char*)&E, sizeof(E));

				gotoxy(30, 21);
				cout << "Overwriting to database";
				Delayed_text(53, 21, "....");
				gotoxy(32, 22);
				cout << "Modification Sucessful!";
				gotoxy(100, 100);
				getch();
			}
		}
	f_log.close();
	f.close();

}
void Program::Modify_grade_pay(int id)
{
	fstream f, f_log;
	Employee E;
	char grade_pay[20];
	float gp;

	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(35, 3);
	cout << "Modify Details";

	gotoxy(21, 9);
	cout << "Current Grade Pay: ";
	Box(40, 8 ,25, 2, '-');

	gotoxy(20, 13);
	cout << "Modified Grade Pay: ";
	Box(40, 12 ,25, 2, '-');
	Line(3, 78, 17, '_');

	f.open("Employee.dat", ios::in | ios::out | ios::binary);
	f_log.open("Logs.txt", ios::app);
	while(f.read((char*)&E, sizeof(E)))
		if(E.Get_empID() == id)
		{
			_modgp:
			Line(42, 55, 13, ' ');
			gotoxy(42, 9);
			cout << "$ " << E.Get_grade_pay();
			gotoxy(42, 13);
			cout << "$ ";
			gets(grade_pay);

			if(!FloatCheck(grade_pay) || strlen(grade_pay) == 0)
			{
				gotoxy(34, 21);
				cout << "Invalid Input!";
				Delay(D);
				Line(30, 70, 21, ' ');
				goto _modgp;
			}
			if(E.Get_grade_pay() == StringToFloat(grade_pay))
			{
				gotoxy(19, 21);
				cout << "New grade pay cannot be same as current grade pay";
				Delay(D);
				Line(19, 70, 21, ' ');
				goto _modgp;
			}
			else
			{
				gp = StringToFloat(grade_pay);

		f_log << "Employee " << E.Get_empID() << "'s grade pay has been modified from " << E.Get_grade_pay() << " to " << gp << endl;

				E.Set_grade_pay(gp);
				E.Calculate_net_sal();
				f.seekp(f.tellg() - sizeof(E), ios::beg);
				f.write((char*)&E, sizeof(E));

				gotoxy(30, 21);
				cout << "Overwriting to database";
				Delayed_text(53, 21, "....");
				gotoxy(32, 22);
				cout << "Modification Sucessful!";
				gotoxy(100, 100);
				getch();
			}
		}
	f_log.close();
	f.close();

}

void Program::Modify_SD(int id)
{
	fstream f, f_log;
	Employee E;
	int cleared;
	char basic_c[20], HRA_c[20], DA_c[20], tax_c[20], TA_c[20], MA_c[20], PF_c[20], resp[20];
	float basic, HRA, DA, tax, TA, MA, PF;

	f.open("Employee.dat", ios::in | ios::out | ios::binary);
	f_log.open("Logs.txt", ios::app);
	while(f.read((char*)&E, sizeof(E)))
	if(E.Get_empID() == id)
	{
		reset_add:
		cleared = 0;
		clrscr();
		Border('*');
		Line(3, 78, 4, '_');
		gotoxy(35, 3);
		cout << "Modify Details";

		gotoxy(47 ,6);
		cout << "Current       Modified";
		gotoxy(6, 7);
		cout << "Basic";
		gotoxy(6, 9);
		cout << "HRA";
		gotoxy(6, 11);
		cout << "DA";
		gotoxy(6, 13);
		cout << "Tax";
		gotoxy(6, 15);
		cout << "TA";
		gotoxy(6, 17);
		cout << "MA";
		gotoxy(6, 19);
		cout << "PF";
		gotoxy(14, 7);
		cout << "-";
		gotoxy(14, 9);
		cout << "-";
		gotoxy(14, 11);
		cout << "-";
		gotoxy(14, 13);
		cout << "-";
		gotoxy(14, 15);
		cout << "-";
		gotoxy(14, 17);
		cout << "-";
		gotoxy(14, 19);
		cout << "-";
		gotoxy(57, 7);
		cout << ":";
		gotoxy(57, 9);
		cout << ":";
		gotoxy(57, 11);
		cout << ":";
		gotoxy(57, 13);
		cout << ":";
		gotoxy(57, 15);
		cout << ":";
		gotoxy(57, 17);
		cout << ":";
		gotoxy(57, 19);
		cout << ":";
		gotoxy(47, 7);
		cout << "$ " << E.Get_basic();
		gotoxy(47, 9);
		cout << "$ " << E.Get_HRA();
		gotoxy(47, 11);
		cout << "$ " << E.Get_DA();
		gotoxy(47, 13);
		cout << "$ " << E.Get_tax();
		gotoxy(47, 15);
		cout << "$ " << E.Get_TA();
		gotoxy(47, 17);
		cout << "$ " << E.Get_MA();
		gotoxy(47, 19);
		cout << "$ " << E.Get_PF();
		Line(3, 78, 20, '_');

		//Getting Employee Details as Input
		basic_check:
		Line(61, 78, 7, ' ');
		gotoxy(61, 7);
		cout << "$ ";
		gets(basic_c);

		if(!FloatCheck(basic_c) || strlen(basic_c) == 0)
		{
			gotoxy(35, 23);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 23, ' ');
			goto basic_check;
		}
		else
			basic = StringToFloat(basic_c);

		HRA_check:
		Line(61, 78, 9, ' ');
		gotoxy(61, 9);
		cout << "$ ";
		gets(HRA_c);

		if(!FloatCheck(HRA_c) || strlen(HRA_c) == 0)
		{
			gotoxy(35, 23);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 23, ' ');
			goto HRA_check;
		}
		else
			HRA = StringToFloat(HRA_c);

		DA_check:
		Line(61, 78, 11, ' ');
		gotoxy(61, 11);
		cout << "$ ";
		gets(DA_c);

		if(!FloatCheck(DA_c) || strlen(DA_c) == 0)
		{
			gotoxy(35, 23);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 23, ' ');
			goto DA_check;
		}
		else
			DA = StringToFloat(DA_c);

		tax_check:
		Line(61, 78, 13, ' ');
		gotoxy(61, 13);
		cout << "$ ";
		gets(tax_c);

		if(!FloatCheck(tax_c) || strlen(tax_c) == 0)
		{
			gotoxy(35, 23);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 23, ' ');
			goto tax_check;
		}
		else
			tax = StringToFloat(tax_c);

		TA_check:
		Line(61, 78, 15, ' ');
		gotoxy(61, 15);
		cout << "$ ";
		gets(TA_c);

		if(!FloatCheck(TA_c) || strlen(TA_c) == 0)
		{
			gotoxy(35, 23);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 23, ' ');
			goto tax_check;
		}
		else
			TA = StringToFloat(TA_c);

		MA_check:
		Line(61, 78, 17, ' ');
		gotoxy(61, 17);
		cout << "$ ";
		gets(MA_c);

		if(!FloatCheck(MA_c) || strlen(MA_c) == 0)
		{
			gotoxy(35, 23);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 23, ' ');
			goto MA_check;
		}
		else
			MA = StringToFloat(MA_c);

		PF_check:
		Line(61, 78, 19, ' ');
		gotoxy(61, 19);
		cout << "$ ";
		gets(PF_c);

		if(!FloatCheck(PF_c) || strlen(PF_c) == 0)
		{
			gotoxy(35, 23);
			cout << "Invalid Input!";
			Delay(2000);
			Line(35, 50, 23, ' ');
			goto PF_check;
		}
		else
			PF = StringToFloat(PF_c);

		resp_check:
		Line(13, 78, 22, ' ');
		Line(13, 78, 23, ' ');
		gotoxy(13, 22);
		cout << "Are you sure you want these details to be modified? (Yes/No)";
		gotoxy(38, 23);
		gets(resp);

		if(!strcmpi(resp, "Yes") || !strcmpi(resp, "Y"))
		{
			E.Set_basic(basic);
			E.Set_HRA(HRA);
			E.Set_DA(DA);
			E.Set_tax(tax);
			E.Set_TA(TA);
			E.Set_MA(MA);
			E.Set_PF(PF);
			E.Calculate_net_sal();

			f.seekp(f.tellg() - sizeof(E), ios::beg);
			f.write((char*)&E, sizeof(E));

			Line(13, 78, 22, ' ');
			Line(13, 78, 23, ' ');
			gotoxy(30, 22);
			cout << "Overwriting to database";
			Delayed_text(53, 22, "....");
			gotoxy(32, 23);
			cout << "Modification Sucessful!";
            gotoxy(100, 100);
			getch();
		}
		else if(!strcmpi(resp, "No") || !strcmpi(resp, "N"))
				goto reset_add;
		else
			goto resp_check;
	}
	f_log.close();
	f.close();
}

int Program::Reports()
{
	fstream f;
	Employee E;
	char id_c[20];
	int id, r, found;

	_reset:
	found = 0;
	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(39, 3);
	cout << "Reports";

	Line(3, 78, 11, '*');
	Line(3, 78, 16, '*');
	gotoxy(32, 13);
	cout << "Enter the Employee ID";
	gotoxy(40, 14);
	gets(id_c);

	if(!IntCheck(id_c) || strlen(id_c) == 0)
	{
		gotoxy(35, 22);
		cout << "Invalid Input!";
		Delay(2000);
		Line(35, 50, 23, ' ');
		goto _reset;
	}
	else
		id = StringToInt(id_c);

	f.open("Employee.dat", ios::in | ios::binary);
	while(f.read((char*)&E, sizeof(E)))
		if(id == E.Get_empID())
		{
			 found = 1;
			clrscr();
			Border('*');
			Line(3, 78, 4, '_');
			gotoxy(39, 3);
			cout << "Reports";
			Line2(25, 5, 24, '|');
			Delay(D_r);

			gotoxy(5, 6);
			cout << "Employee ID";
			gotoxy(32, 6);
			cout << E.Get_empID();
			Delay(D_r);

			gotoxy(5, 9);
			cout << "Name";
			gotoxy(32, 9);
			cout << E.Get_name();
			Delay(D_r);

			gotoxy(5, 12);
			cout << "Age";
			gotoxy(32, 12);
			cout << E.Get_age();
			Delay(D_r);

			gotoxy(5, 15);
			cout << "Telephone Number";
			gotoxy(32, 15);
			cout << "+973 " << E.Get_telno();
			Delay(D_r);

			gotoxy(5, 18);
			cout << "Designation";
			gotoxy(32, 18);
			cout << E.Get_desig();
			Delay(D_r);

			gotoxy(5, 21);
			cout << "Department";
			gotoxy(32, 21);
			cout << E.Get_dept();
			Delay(D_r);

			gotoxy(5, 24);
			cout << "Net salary";
			gotoxy(32, 24);
			cout << "$ " << E.Get_net_sal();
			Delay(D_r);

			Line(3, 24, 7, '_');
			Line(3, 24, 10, '_');
			Line(3, 24, 13, '_');
			Line(3, 24, 16, '_');
			Line(3, 24, 19, '_');
			Line(3, 24, 22, '_');

			Line(26, 78, 7, '_');
			Line(26, 78, 10, '_');
			Line(26, 78, 13, '_');
			Line(26, 78, 16, '_');
			Line(26, 78, 19, '_');
			Line(26, 78, 22, '_');

				gotoxy(100, 100);
				getch();

			break;
		}
	 f.close();

	 if(found == 0)
	 {
		  clrscr();
		  Border('*');

		  Line(3, 78, 4, '_');
		  gotoxy(39, 3);
		  cout << "Reports";

		  Line(3, 78, 11, '*');
		  Line(3, 78, 16, '*');
		  gotoxy(29, 13);
		  cout<<"Selected ID does not exist";
		  gotoxy(23, 14);
		  cout<<"Press Enter to try again or Esc to exit";
		  _resp_check:
		  Line(35, 50, 15, ' ');
		  gotoxy(100, 100);
		  r = getch();

		  if(r == 13)
				goto _reset;
		  else if(r ==  27)
				return 0;
		  else
		  {
				Line(29, 70, 13, ' ');
				Line(23, 70, 14, ' ');
				gotoxy(30, 14);
				cout << "Invalid Input!";
				Delay(D);
				Line(30, 70, 14, ' ');
				goto _resp_check;
		  }
	 }
}

int Program::Reports(int id)
{
	fstream f;
	Employee E;

	f.open("Employee.dat", ios::in | ios::binary);
	while(f.read((char*)&E, sizeof(E)))
		if(id == E.Get_empID())
		{
			clrscr();
			Border('*');
			Line(3, 78, 4, '_');
			gotoxy(39, 3);
			cout << "Reports";
			Line2(25, 5, 24, '|');
			Delay(D_r);

			gotoxy(5, 6);
			cout << "Employee ID";
			gotoxy(32, 6);
			cout << E.Get_empID();
			Delay(D_r);

			gotoxy(5, 9);
			cout << "Name";
			gotoxy(32, 9);
			cout << E.Get_name();
			Delay(D_r);

			gotoxy(5, 12);
			cout << "Age";
			gotoxy(32, 12);
			cout << E.Get_age();
			Delay(D_r);

			gotoxy(5, 15);
			cout << "Telephone Number";
			gotoxy(32, 15);
			cout << "+973 " << E.Get_telno();
			Delay(D_r);

			gotoxy(5, 18);
			cout << "Designation";
			gotoxy(32, 18);
			cout << E.Get_desig();
			Delay(D_r);

			gotoxy(5, 21);
			cout << "Department";
			gotoxy(32, 21);
			cout << E.Get_dept();
			Delay(D_r);

			gotoxy(5, 24);
			cout << "Net salary";
			gotoxy(32, 24);
			cout << "$ " << E.Get_net_sal();
			Delay(D_r);

			Line(3, 24, 7, '_');
			Line(3, 24, 10, '_');
			Line(3, 24, 13, '_');
			Line(3, 24, 16, '_');
			Line(3, 24, 19, '_');
			Line(3, 24, 22, '_');

			Line(26, 78, 7, '_');
			Line(26, 78, 10, '_');
			Line(26, 78, 13, '_');
			Line(26, 78, 16, '_');
			Line(26, 78, 19, '_');
			Line(26, 78, 22, '_');

			gotoxy(100, 100);
				getch();

			break;
		}
	 f.close();
}

int Program::Change_password()
{
	fstream f_log;
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
				f_log.open("Logs.txt", ios::app);
				f_log << "Password of account has been changed from " << Get_password() << " to " << new_password << endl;
				f_log.close();

				Set_acc_details(Get_username(), new_password);
				gotoxy(29, 17);
				cout << "Password change sucessful";
				gotoxy(100, 100);
				getch();
		  }
	 }
}

int Program::Logs()
{
	fstream f;
	char r, str[100];
	int line;

	clrscr();
	Border('*');

	Line(3, 78, 4, '_');
	gotoxy(38, 3);
	cout << "Logs";

	line = 0;
	f.open("Logs.txt", ios::in);
	while(!f.eof())
	{
		gotoxy(4, 6 + line);
		f.getline(str, 100, '\n');
		cout << str << endl;
		line++;

		if(line == 18)
		{
			line = 0;
			gotoxy(100, 100);
			r = getch();

			if(r == 27)
			{
				f.close();
				return 0;
			}
			else if(r == 13)
			{
                 clrscr();
				Border('*');

				Line(3, 78, 4, '_');
				gotoxy(38, 3);
				cout << "Logs";
			}
		}
	}
	f.close();

	gotoxy(100, 100);
	getch();
}

int Program::Exit(char ch)
{
	char response[3];

	if(ch == 'N')
	 {
		  Line(20, 62, 23, ' ');
		  gotoxy(22, 22);
		  cout << "Are you sure you want to exit? (Yes/No)";
		exit_resp1:
		  Line(20, 62, 23, ' ');
		  gotoxy(37, 23);
		  gets(response);

		  if(!strcmpi(response, "Yes") || !strcmpi(response, "Y"))
				return 1;
		  else if(!strcmpi(response, "No") || !strcmpi(response, "N"))
				return 0;
		  else
			goto exit_resp1;

	 }
	 else if(ch == 'M')
	 {
		  Line(20, 62, 23, ' ');
		  gotoxy(22, 22);
		  cout << "Are you sure you want to exit? (Yes/No)";
		exit_resp2:
		  Line(20, 62, 23, ' ');
		  gotoxy(37, 23);
		  gets(response);

		  if(!strcmpi(response, "Yes") || !strcmpi(response, "Y"))
				exit(0);
		  else if(!strcmpi(response, "No") || !strcmpi(response, "N"))
				return 0;
		  else
			goto exit_resp2;

	}
}

													 ///////////////////////////////////////////

int main()
{
	Employee E;
	Design d;
	Help H;
	Program P;

	P.Main_menu();
	getch();
}
