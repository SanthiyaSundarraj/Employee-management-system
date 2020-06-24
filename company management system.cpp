#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<windows.h>
using namespace std;
//global variable declaration
int k=7,r=0,flag=0;

#define clrscr system("cls");

void gotoxy(int x, int y)           //definition of gotoxy function//                                               
{
 HANDLE Manipulador;
 COORD  Coordenadas;
 Manipulador=GetStdHandle(STD_OUTPUT_HANDLE);
 Coordenadas.X=x;
 Coordenadas.Y=y;
 SetConsoleCursorPosition(Manipulador,Coordenadas);
}
struct date
{int mm,dd,yy;};

ofstream fout;
ifstream fin;

class employee
{int empno,dept;
char name[25];
date d,j;
public:
void add()
{cout<<"\n\n\tEmployee No: ";
cin>>empno;
cout<<"\n\n\tName of the Employee: ";
cin>>name;
cout<<"\n\n\tDepartment: ";
cin>>dept;
cout<<"\n\n\tDate of Birth (dd-mm-yy): ";
cin>>d.mm;
cin>>d.dd;
cin>>d.yy;
cout<<"\n\n\tDate of Joining (dd-mm-yy): ";
cin>>j.mm;
cin>>j.dd;
cin>>j.yy;
}
void show()
{cout<<"\n\tEmployee No: ";
cout<<empno;
cout<<"\n\n\tName of the Employee: ";
cout<<name;
cout<<"\n\n\tDepartment: ";
cout<<dept;
cout<<"\n\n\tDate of Birth (dd-mm-yy): ";
cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
cout<<"\n\n\tDate of Joining (dd-mm-yy): ";
cout<<j.mm<<"-"<<j.dd<<"-"<<j.yy;
}
void report()
{
gotoxy(3,k);
cout<<empno;
gotoxy(10,k);
puts(name);
gotoxy(20,k);
cout<<dept;
}
int retno()
{return(empno);}
int retd()
{return(dept);}
};

class Salary: public employee
{float basic,gross,deduction,da,hra,ot,oth,pf,lic,fadv,coops,hdfc,netpay;
int abdys;
public:
void add();
void show();
void report();
void calculate();
void pay();
}sal;

void Salary::add()
{employee::add();
cout<<"\n\n\tBasic Pay: ";
cin>>basic;
cout<<"\n\n\tDays Absent: ";
cin>>abdys;
cout<<"\n\n\tOvertime Hours: ";
cin>>oth;
cout<<"\n\n\tLoans and Savings\n";
cout<<"\n\n\tLIC: ";
cin>>lic;
cout<<"\n\n\tHDFC: ";
cin>>hdfc;
cout<<"\n\n\tCo Operative Society: ";
cin>>coops;
calculate();
fout.write((char *)&sal,sizeof(sal));
fout.close();
}
void Salary::calculate()
{hra=basic*0.1;
da=basic*0.225;
ot=oth*700;
pf=basic*0.1275;
fadv=100;
gross=basic+hra+da+ot;
deduction=pf+lic+fadv+coops+hdfc;
netpay=gross-deduction;
}

void Salary::show()
{fin.open("database.dat",ios::binary);
fin.read((char*)&sal,sizeof(sal));
employee::show();
cout<<"\n\n\tNet pay: ";
cout<<netpay;
fin.close();
}

void Salary::report()
{employee::report();
gotoxy(30,k);
cout<<basic;
gotoxy(42,k);
cout<<gross;
gotoxy(52,k);
cout<<deduction;
gotoxy(67,k);
cout<<netpay;
k=k+1;
if(k==50)
{gotoxy(25,50);
cout<<"PRESS ANY KEY TO CONTINUE...";
getch();
k=7;
clrscr;
gotoxy(30,3);
cout<<" EMPLOYEE DETAILS ";
gotoxy(3,5);
cout<<"CODE";
gotoxy(10,5);
cout<<"NAME";
gotoxy(20,5);
cout<<"DEPT";
gotoxy(30,5);
cout<<"BASIC";
gotoxy(40,5);
cout<<"GROSS PAY";
gotoxy(52,5);
cout<<"DEDUCTION";
gotoxy(67,5);
cout<<"NETPAY";}
}

void Salary::pay()
{show();
cout<<"\n\n\n\t\t*********************************************";
cout<<"\n\t\t                 ENTERPRISES                  ";
cout<<"\n\t\t*********************************************";
cout<<"\n\n\t\tBASIC SALARY                 :"<<basic;
cout<<"\n\t\tDEARNESS ALLOWANCE           :"<<da;
cout<<"\n\t\tHOUSE RENT ALLOWANCE         :"<<hra;
cout<<"\n\t\tOVER TIME HOURS              :"<<oth;
cout<<"\n\t\tOVER TIME WAGES              :"<<ot;
cout<<"\n\t\tGROSS PAY                    :"<<gross;
cout<<"\n\n\n\n\n\n\t\tPROVIDENT FUND               :"<<pf;
cout<<"\n\t\tLIC                          :"<<lic;
cout<<"\n\t\tFESTIVAL ADVANCE             :"<<fadv;
cout<<"\n\t\tHDFC                         :"<<hdfc;
cout<<"\n\t\tCO-OP S                      :"<<coops;
cout<<"\n\n\n\t\tNET PAY                      :Rs."<<netpay;
cout<<"\n\t\t*********************************************";
//earnings
gotoxy(14,21);
cout<<"E";
gotoxy(14,22);
cout<<"A";
gotoxy(14,23);
cout<<"R";
gotoxy(14,24);
cout<<"N";
gotoxy(14,25);
cout<<"I";
gotoxy(14,26);
cout<<"N";
gotoxy(14,27);
cout<<"G";
gotoxy(14,28);
cout<<"S";
//deductions
gotoxy(14,31);
cout<<"D";
gotoxy(14,32);
cout<<"E";
gotoxy(14,33);
cout<<"D";
gotoxy(14,34);
cout<<"U";
gotoxy(14,35);
cout<<"C";
gotoxy(14,36);
cout<<"T";
gotoxy(14,37);
cout<<"I";
gotoxy(14,38);
cout<<"O";
gotoxy(14,39);
cout<<"N";
gotoxy(14,40);
cout<<"S";
}

int main()
{cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout<<setprecision(2);
menu:
clrscr;
gotoxy(25,2);
cout<<"Company Employee Management";
gotoxy(25,3);
cout<<"===========================\n\n";
cout<<"\n\t\t1.Salary Report\n\n";
cout<<"\t\t2.Edit Database\n\n";
cout<<"\t\t3.Search\n\n";
cout<<"\t\t4.Pay Slip\n\n";
cout<<"\t\t5.Exit\n\n";
cout<<"\t\tPlease Enter Required Option: ";
int ch;
cin>>ch;
switch(ch)
{case 1:ss:
	clrscr;
	gotoxy(25,2);
	cout<<"Salary Statement";
	gotoxy(25,3);
	cout<<"================\n\n";
	cout<<"\n\t\t1.All Employees\n\n";
	cout<<"\t\t2.Department wise\n\n";
	cout<<"\t\t3.Back to Main menu\n\n";
	cout<<"\t\tPlease Enter Required Option: ";
	int cho;
	cin>>cho;
	if(cho==1)
	{clrscr;
	gotoxy(30,3);
	cout<<" EMPLOYEE DETAILS ";
	gotoxy(3,5);
	cout<<"CODE";
	gotoxy(10,5);
	cout<<"NAME";
	gotoxy(20,5);
	cout<<"DEPT";
	gotoxy(30,5);
	cout<<"BASIC";
	gotoxy(40,5);
	cout<<"GROSS PAY";
	gotoxy(52,5);
	cout<<"DEDUCTION";
	gotoxy(67,5);
	cout<<"NETPAY";
	fin.open("database.dat",ios::binary);
	if(!fin)
	{cout<<"\n\nFile Not Found...";
	goto menu;}
	fin.seekg(0);
	while(!fin.eof())
	{fin.read((char*)&sal,sizeof(sal));
	if(!fin.eof())
	sal.report();}
	getch();
	fin.close();}
	if(cho==2)
	{flag=0;
	cout<<"\n\t\tEnter Department: ";
	int de;
	cin>>de;
	clrscr;
	gotoxy(30,3);
	cout<<" EMPLOYEE DETAILS ";
	gotoxy(3,5);
	cout<<"CODE";
	gotoxy(10,5);
	cout<<"NAME";
	gotoxy(20,5);
	cout<<"DEPT";
	gotoxy(30,5);
	cout<<"BASIC";
	gotoxy(40,5);
	cout<<"GROSS PAY";
	gotoxy(52,5);
	cout<<"DEDUCTION";
	gotoxy(67,5);
	cout<<"NETPAY";
	fin.open("database.dat",ios::binary);
	if(!fin)
	{cout<<"\n\nFile Not Found...";
	goto menu;}
	fin.seekg(0);
	while(!fin.eof())
	{fin.read((char*)&sal,sizeof(sal));
	if(!fin.eof())
	{int x=sal.employee::retd();
	if(x==de)
	{flag=1;
	sal.report();}}}
	if(flag==0)
	{cout<<"\n\n\n\t\tDepartment doesnot exist...";
	getch();
	fin.close();
	goto ss;}
	getch();
	fin.close();}
	if(cho==3)
	{goto menu;}
	goto ss;
case 2:
	db:
	clrscr;
	gotoxy(25,2);
	cout<<"Employee Database";
	gotoxy(25,3);
	cout<<"=================\n\n";
	cout<<"\n\t\t1.Add Employee Details\n";
	cout<<"\t\t2.Edit Employee Details\n\n";
	cout<<"\t\t3.Delete Employee\n\n";
	cout<<"\t\t4.Back to Main Menu ";
	int apc;
	cin>>apc;
		switch(apc)
		{case 1:{fout.open("database.dat",ios::binary|ios::app);
		sal.add();
		cout<<"\n\t\tEmployee Added Successfully!";
		getch();
		goto db;
		}
			
		case 2:
		{
		int eno;
		flag=0;
		cout<<"\n\n\tEnter Employee Number to be Edited :";
		cin>>eno;
		fin.open("database.dat",ios::binary);
		fout.open("database.dat",ios::binary|ios::app);
		if(!fin)
		{cout<<"\n\nFile Not Found...";
		goto menu;}
		fin.seekg(0);
		r=0;
		while(!fin.eof())
		{fin.read((char*)&sal,sizeof(sal));
		if(!fin.eof())
		{r++;
		int x=sal.employee::retno();
		if(x==eno)
		{flag=1;
		fout.seekp((r-1)*sizeof(sal));
		clrscr;
		cout<<"\n\t\tCurrent Details are\n";
		sal.show();
		cout<<"\n\n\t\tEnter New Details\n";
		sal.add();
		cout<<"\n\t\tEmployee Details editted";
		}}}
		if(flag==0)
		{cout<<"\n\t\tEmployee No does not exist...Please Retry!";
		getch();
		goto db;}
		fin.close();
		getch();
		goto db;
		}
		
		case 3:{
		flag=0;
		int eno;
		cout<<"\n\n\tEnter Employee Number to be deleted :";
		cin>>eno;
		fin.open("database.dat",ios::binary);
		if(!fin)
		{cout<<"\n\nFile Not Found...";
		goto menu;}
		fstream tmp;
		tmp.open("temp.dat",ios::binary|ios::out);
		fin.seekg(0);
		while(fin.read((char*)&sal, sizeof(sal)))
		{int x=sal.employee::retno();
		if(x!=eno)
		tmp.write((char*)&sal,sizeof(sal));
		else
		{flag=1;}}
		fin.close();
		tmp.close();
		fout.open("database.dat",ios::trunc|ios::binary);
		fout.seekp(0);
		tmp.open("temp.dat",ios::binary|ios::in);
		if(!tmp)
		{cout<<"Error in File";
		goto db;}
		while(tmp.read((char*)&sal,sizeof(sal)))
		fout.write((char*)&sal,sizeof(sal));
		tmp.close();
		fout.close();
		if(flag==1)
		cout<<"\n\t\tEmployee Succesfully Deleted";
		else if (flag==0)
		cout<<"\n\t\tEmployee does not Exist! Please Retry";
		getch();
		goto db;}
		
		case 4: goto menu;
		default: cout<<"\n\n\t\tWrong Choice!!! Retry";
		getch();
		goto db;
		}
case 3:{
clrscr;
cout<<"\n\n\t\tEnter Employee Number to be found: ";
	flag=0;
	int eno;
	cin>>eno;
	fin.open("database.dat",ios::binary);
	if(!fin)
	{cout<<"\n\nFile Not Found...";
	goto menu;}
	fin.seekg(0);
	while(fin.read((char*)&sal, sizeof(sal)))
	{int x=sal.employee::retno();
	if(x==eno)
	{flag=1;
	cout<<"\n\n\t\tEmployee Details are \n";
	cout<<"\t\t====================\n";
	sal.show();}}
	fin.close();
	if(flag==0) cout<<"\n\t\tEmployee does not exist....Please Retry!";
	getch();
	goto menu;
	}
case 4:{
	clrscr;
	flag=0;
	int eno;
	cout<<"\n\n\t\tEnter Employee Number :";
	cin>>eno;
	fin.open("database.dat",ios::binary);
	if(!fin)
	{cout<<"\n\nFile Not Found...\nProgram Terminated!";
	goto menu;}
	fin.seekg(0);
	while(fin.read((char*)&sal,sizeof(sal)))
	{int x=sal.employee::retno();
	if(x==eno)
	{sal.pay();
	flag=1;
	break;}}
	if(flag==0)
	cout<<"\n\t\tEmployee does not exist....Please Retry!";
	getch();
	fin.close();
	goto menu;
	}
case 5:{
clrscr;
gotoxy(20,20);
cout<<"ARE YOU SURE, YOU WANT TO EXIT (Y/N)?";
char yn;
cin>>yn;
if((yn=='Y')||(yn=='y'))
{gotoxy(17,20);
cout<<"PROGRAM ENDED..\n\n\n";
getch();
exit(0);}
else if((yn=='N')||(yn=='n'))
goto menu;
else{goto menu;}
default:cout<<"\n\n\t\tWrong Choice....Please Retry!";
getch();
goto menu;
}
}
}

