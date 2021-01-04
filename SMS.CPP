/* Student Management System Project
Password to run project : abcde
*/

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip.h>

struct address
{
	int houseno;
	char building[30];
	char area[30];
	char city[30];
	long int pincode;
};

struct student
{
	int studid;
	int std;
	char name[20];
	address addr;
	int submarks[3];
}s[100];
int search(int);

int passwords()
{
	char p[10];
	int i=0;
	gotoxy(33,10);
	cout<<"ENTER THE PASSWORD\n";
	gotoxy(33,12);
	do
	{
	p[i]=getch();
	cout<<"*";
	i++;
	}
	while(p[i-1]!='\r');
	p[i-1]='\0';
	gotoxy(30,20);
	if (strcmp(p,"abcde")==0)

		return 1;

	else
		return 0;
}
void main()
{
	void mainmenu(int);
	int totstud=0;
	//textcolor(MAGENTA);
	//textbackground(WHITE);
	clrscr();
	cout<<"\t%%      %%      ";
	cout<<"\n\t%%      %% %%%%%%% %%      %%%%%% %%%%%% %%%%%%%%%% %%%%%%%";
	cout<<"\n\t%%      %% %%      %%      %%     %%  %% %%  %%  %% %%       ";
	cout<<"\n\t%%  %%  %% %%%%%   %%      %%     %%  %% %%  %%  %% %%%%%      ";
	cout<<"\n\t%%  %%  %% %%      %%      %%     %%  %% %%      %% %%           ";
	cout<<"\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%% %%%%%% %%      %% %%%%%%%     ";
	cout<<"\n\n\t\t\t        $$$$$$$$  $$$$$        ";
	cout<<"\n\t\t\t           $$     $   $      ";
	cout<<"\n\t\t\t           $$     $$$$$    ";

	cout<<"\n\n\n\tCOMPUTER   PROJECT  (********  STUDENT MANAGEMENT SYSTEM>>  *******)";
	cout<<" \n\n\n\t\t     press any KEY???? to continue: ";

	getch();
	clrscr();
	cout<<"\n\n\t\t\t    HILLWOODS SCHOOL\n" ;
	cout<<"\t\t\t ************************\n";
	int passwords();
	for(int i=0;i<3;i++)
	{
		if(!passwords())
		{
			clrscr();
			cout<<"\nWrong password try once more\n";
		}
		else
		{
			goto menu;
		}
	}
	if(i==3)
	{
		clrscr();
		cout<<"\n\n\t\t\t all attempts failed.....";
		cout<<"\n\n\n\t\t\t see you.................. ";
		getch();
		exit(0);
	}
	menu:;
	clrscr();
	mainmenu(totstud);	
}
void mainmenu(int totstud)
{
	void adddetail(int);
	void updatedetail(int);
	void displaydetail(int);
	void showresult(int);
	void sort(int);
	int deletestudent(int);
	int choice;

	do
	{
		cout<<"\n\t\t\tMAIN MENU";
		cout << "\n\t\t--------------------------";
		cout << "\n\t\t1. Add Student Detail";
		cout << "\n\t\t2. Update Student Detail";
		cout << "\n\t\t3. Display Student Detail";
		cout << "\n\t\t4. Delete Student Detail";
		cout << "\n\t\t5. Show Result";
		cout << "\n\t\t6. Sort by Standard / Class";
		cout << "\n\t\t9. Exit";
		cout << "\n\t\t--------------------------";
		cout << "\nEnter choice : ";
		cin >> choice;

		switch (choice)
		{
			case 1 :	if (totstud==99)
						cout << "\nOnly 100 student details can be stored!!!";
					else
					{
						totstud++;
						adddetail(totstud-1);
					}
					break;
			case 2 :
					if (totstud==0)
						cout << "\nSorry, no records exists!!!";
					else
						updatedetail(totstud);
					break;
			case 3 :
					if (totstud==0)
						cout << "\nSorry, no records exists!!!";
					else
						displaydetail(totstud);
					break;
			case 4 :
					if (totstud==0)
						cout << "\nSorry, no records exists!!!";
					else
						totstud=deletestudent(totstud);
					break;


			case 5 :
					if (totstud==0)
						cout << "\nSorry, no records exists!!!";
					else
						showresult(totstud);
					break;
			case 6 :
					if (totstud==0)
						cout << "\nSorry, no records exists!!!";
					else
						sort(totstud);
					break;
			case 9 :
					exit(0);
			default : cout << "\nInvalid Choice!!!";
		}


	}while(choice!=9);
}

void adddetail(int index)
{
	cout << "\nEnter student id: ";
	cin >> s[index].studid;
	cout << "\nEnter standard/class: ";
	cin >> s[index].std;
	cout << "\nEnter student name: ";
	gets(s[index].name);
	cout << "\nEnter student address: ";
	cout << "\nEnter house no:";
	cin >> s[index].addr.houseno;
	cout << "\nEnter building: ";
	gets(s[index].addr.building);
	cout << "\nEnter area: ";
	gets(s[index].addr.area);
	cout << "\nEnter city: ";
	gets(s[index].addr.city);
	cout << "\nEnter pincode: ";
	cin >> s[index].addr.pincode;
	cout << "\nEnter subject marks: ";
	for(int j=0;j<3;j++)
	{
		cout << "\nEnter Marks["<<j<<"]: ";
		cin >> s[index].submarks[j];
	}


}
void updatedetail(int totstud)
{
	int index=search(totstud);
	int choice,i;
	if(index==-1)
		cout << "\nStudent does not exists!!!";
	else
	{
		do
		{
		cout << "\n\t\t--------------------------";
		cout << "\n\t\t1. To Update Student Class";
		cout << "\n\t\t2. To Update Student Address";
		cout << "\n\t\t3. To Update Student Marks";
		cout << "\n\t\t4. To Goto Main Menu";
		cout << "\n\t\t--------------------------";
		cout << "\nEnter choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		cout << "\nEnter new standard/class: ";
		cin >> s[index].std;
		break;
		case 2:
		cout << "\nEnter new student address: ";
		cout << "\nEnter house no:";
		cin >> s[index].addr.houseno;
		cout << "\nEnter building: ";
		gets(s[index].addr.building);
		cout << "\nEnter area: ";
		gets(s[index].addr.area);
		cout << "\nEnter city: ";
		gets(s[index].addr.city);
		cout << "\nEnter pincode: ";
		cin >> s[index].addr.pincode;
		break;
		case 3:
		cout << "\nEnter new subject marks: ";
		for(i=0;i<3;i++)
		{
			cout << "\nEnter Marks["<<i<<"]: ";
			cin >> s[index].submarks[i];
		}
		case 4:
		mainmenu(totstud);
		break;
		default:
		cout << "\nInvalid Choice!!!";
		}
		}while(choice!=4);
	}
}
void displaydetail(int totstud)
{
	int index=search(totstud);
	if(index==-1)
		cout << "\nStudent does not exists!!!";
	else
	{

		cout << "\nStudent ID: " << s[index].studid;
		cout << "\nStandard: " << s[index].std;
		cout << "\nStudent Name: " << s[index].name;
		cout << "\nStudent Address:\n" << s[index].addr.houseno;
		cout << "-" << s[index].addr.building;
		cout << ",\n" << s[index].addr.area;
		cout << ",\n" << s[index].addr.city;
		cout << "-" << s[index].addr.pincode;
		cout << "\nScience Marks:" << s[index].submarks[0];
		cout << "\nEnglish Marks:" << s[index].submarks[1];
		cout << "\nComputer Marks:" << s[index].submarks[2];
	}
}
void showresult(int totstud)
{
	int totmarks=0;
	float percent;
	cout << "\n\nStudNo\tStudName\t\tStandard\tTotalMarks\tPercent";
	cout << "\n--------------------------------------------------------------------------------";
	for (int index=0;index<totstud;index++)
	{
		cout << "\n" << setw(6) << s[index].studid << "\t";
		cout.setf(ios::left);
		cout << setw(24) << s[index].name;
		cout.unsetf(ios::right);
		cout << setw(8) << s[index].std << "\t";
		totmarks=0;
		for(int j=0;j<3;j++)
		{
			totmarks+=s[index].submarks[j];
		}
		percent = totmarks/3.0;
		cout.setf(ios::right);

		cout << setw(9) << totmarks << "\t";
		cout.setf(ios::fixed);
		cout << setw(7) << setprecision(2) << percent;
		cout.unsetf(ios::fixed);
	}
	cout << "\n--------------------------------------------------------------------------------";

}
int deletestudent(int totstud)
{
	int ind=search(totstud);
	for (int i=ind;i<totstud;i++)
	{
		s[ind]=s[ind+1];
	}
	totstud--;
	cout << "\nStudent Record Deleted Successfully";
	return totstud;
}

int search(int totstud)
{
	char name[30];
	cout << "\nEnter Student name : ";
	gets(name);
	for (int i=0;i<totstud;i++)
	{
		//cout << "\n"<< s[i].name << ":" << name;
		if (strcmp(s[i].name,name)==0)
		{
			return i;
		}
	}
	return -1;
}
void sort(int totstud)
{
	student temp;
	for (int i=totstud-1;i>0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(s[j].std>s[j+1].std)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	cout << "\nStandardwise Student Details\n";
	cout << "\nStandard\tStudID\tStudName";
	for(i=0;i<totstud;i++)
	{
		cout << "\n" << setw(8) << s[i].std << "\t";
		cout << setw(6) << s[i].studid << "\t";
		cout << s[i].name;
	}
}
