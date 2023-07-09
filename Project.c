#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

struct marks
{
	char cname1[20],cname2[20],cname3[20],cname4[20],cname5[20];
	float m1,m2,m3,m4,m5,avg,gpa;
};
typedef struct marks marks;

struct record
{
	char fname[20],lname[20],city[20],dpt[20],section[3];
	int rnum,age;
	float ec1,ec2,ec3;
	float fees,dc,paid,total;
	marks mks;
};
typedef struct record record;

//Initializing Global Variables
record rcd[50];
int count = 0;
int e_count1=0, e_count2=0, e_count3=0;

//Declaring Functions
void mainpage();
void date();
int login();
void main_menu();
void sort();

void dataManagement();
void displayInfo();
void schPro();
void eventMng();
void fees();

void displayDpt();
void displaySec();
void displayAll();
void displayBatch();

void editfees();
void dispFees();

void dispPro();
void sortMarks();
void dispSPros();
void top10();

void addRcd();
void searchRcd();
void modifyRcd();
void countRcd();
void deleteRcd();
void createAcc();

void eventDtls();
void eventApp();
void cancel();
void eventR();

int main()
{
	int x;
	
	mainpage();
	x=login();
	if (x==0)
	{
		printf ("No permission to enter the system!");
		return 0;
	}
	main_menu();
}


void mainpage()
{
	int i=0;
	system("cls");
	date();
	printf ("\n");
	printf ("\t\t\t------------------------------------\n");
	printf ("\t\t\t| STUDENT RECORD MANAGEMENT SYSTEM |\n");
	printf ("\t\t\t------------------------------------\n");
	printf ("\n\n");
	printf ("\t\t\t");
	system ("pause");
	printf ("\n\t\t\tLoading");
	for(i=0;i<5;i++)
	{
	    sleep(1);
	    printf (".");
	}
}
void date()
{
	time_t t;   
    time(&t);
    printf ("\n\n\n");
	printf ("\t\t\t\t\t\t%s \n", ctime(&t));
}


int login()
{
	char username[20],pass[20];
	int x,i=0;
	while (i!=3)
	{
		system("cls");
		date();
		printf ("\n");
		printf ("\t\t\t------------------------------------\n");
		printf ("\t\t\t| STUDENT RECORD MANAGEMENT SYSTEM |\n");
		printf ("\t\t\t------------------------------------\n");
		printf ("\n\n");
		printf ("\t\t\t");
		printf ("Attempts remaining: %d", 3-i);
		printf ("\n\n");
		printf ("\t\t\t");
		printf ("Username: ");
		scanf ("%s", username);
		printf ("\n\n\t\t\t");
		printf ("Password: ");
		scanf ("%s", pass);
		
		x=verify(username,pass);
		if (x==2)
		{
			printf ("Login Successful!");
			getch();
			break;	
		}
		else if (x==1)
			printf ("Incorrect Password!");
		else
			printf ("Incorrect Username!");
		i++;	
		getch();
	}
	if (i!=3)
		return 1;
	else
		return 0;	
}
int verify(char name[20], char str2[20])
{
	FILE *fp, *fp1;
	int flag =0,n=0,i;
	char un[20],pwd[20];
	
	fp = fopen ("username.txt","r");
	if (fp == NULL)
	{
		printf ("\nError 404. Login Failed.");
		exit (1);
	}
	while ((fscanf (fp,"%s",un))==1)
	{
		if (strcmp(name,un)==0)
		{
			flag++;
			break;
		}
		n++;
	}
	if (flag==0)
	{
		return flag;
	}
	
	fclose(fp);	
	
	fp1 = fopen("password.txt","r");
	for (i=0;i<=n;i++)
		fscanf(fp1,"%s",pwd);
	
	if (strcmp(pwd,str2)==0)
		return flag+1;
	else
	{
		return flag;
	}
	
	fclose(fp1);
		
}

void main_menu()
{
	int choice;
	do
	{
		system("cls");
		date();
		printf ("\n");
		printf ("\t\t\t------------------------------------\n");
		printf ("\t\t\t| STUDENT RECORD MANAGEMENT SYSTEM |\n");
		printf ("\t\t\t------------------------------------\n");
		printf ("\n\n\t\t\t");
		printf ("1. DATA MANAGEMENT");
		printf ("\n\n\t\t\t");
		printf ("2. INFORMATION DISPLAY");
		printf ("\n\n\t\t\t");
		printf ("3. FEES MANAGEMENT");
		printf ("\n\n\t\t\t");
		printf ("4. EVENT MANAGEMENT");
		printf ("\n\n\t\t\t");
		printf ("5. SCHOLARSHIP PROGRAMME");
		printf ("\n\n\t\t\t");
		printf ("6. CREATE NEW ACCOUNT");
		printf ("\n\n\t\t\t");
		printf ("7. EXIT");
		printf ("\n\n\t\t\tEnter your choice: ");
		scanf ("%d", &choice);
		switch (choice)
		{
			case 1: 
				dataManagement();
				getch();
				system("cls");
				break;
			case 2:
				displayInfo();
				getch();
				system("cls");
				break;
			case 3: 
				fees();
				getch();
				system("cls");
				break;
			case 4: 
				eventMng();
				getch();
				system("cls");
				break;
			case 5:
				schPro();
				getch();
				system("cls");
				break;
			case 6:
				createAcc();
				getch();
				system("cls");
				break;
			case 7:
				break;	
			default:
				printf ("Invalid Input! Please try again!");
				continue;										
		}  
	} while (choice!=7);
	printf ("\n\n\n\n\t\t\t\tTHANK YOU EVERYONE! ;)");
}
void dataManagement()
{
	int ans;
	do
	{
		system ("cls");
		date();
		printf ("\n\n\t\t\t");
		printf ("1. ADD RECORD");
		printf ("\n\n\t\t\t");
		printf ("2. MODIFY RECORD");
		printf ("\n\n\t\t\t");
		printf ("3. DELETE RECORD");
		printf ("\n\n\t\t\t");
		printf ("4. BACK TO MAIN MENU");
		printf ("\n\n\t\t\tEnter your choice: ");
		scanf ("%d", &ans);
		switch(ans)
		{
		case 1:
			addRcd();
			getch();
			break;
		case 2: 
			modifyRcd();
			getch();
			break;	
		case 3:
			deleteRcd();
			getch();
			break;
		case 4:
			break;
		default:
			printf ("Invalid Input! Please try again.");
			getch();
			break;	
		}			
	} while (ans!=4);
}

void displayInfo()
{
	int ans;
	do
	{
		system ("cls");
		date();
		printf ("\n\n\t\t\t");
		printf ("1. SEARCH RECORD");
		printf ("\n\n\t\t\t");
		printf ("2. DISPLAY SECTION INFORMATION");
		printf ("\n\n\t\t\t");
		printf ("3. DISPLAY DEPARTMENT INFORMATION");
		printf ("\n\n\t\t\t");
		printf ("4. DISPLAY BATCH INFORMATION");
		printf ("\n\n\t\t\t");
		printf ("5. DISPLAY ALL RECORDS");
		printf ("\n\n\t\t\t");
		printf ("6. DISPLAY COUNT OF STUDENTS");
		printf ("\n\n\t\t\t");
		printf ("7. BACK TO MAIN MENU");
		printf ("\n\n\t\t\tEnter your choice: ");
		scanf ("%d", &ans);
		switch(ans)
		{
			case 1:
				searchRcd();
				getch();
				break;
			case 2: 
				displaySec();
				getch();
				break;	
			case 3:
				displayDpt();
				getch();
				break;
			case 4:
				displayBatch();
				getch();
				break;	
			case 5:
				displayAll();
				getch();
				break;	
			case 6:
				countRcd();
				getch();
				break;
			case 7:
				break;		
			default:
				printf ("Invalid Input! Please try again.");
				getch();
				break;	
		}
	} while (ans!=7);
}

void addRcd()
{
	int num,i,flag=0;
	while (1)
	{
		system("cls");
		printf ("\n\t\t\tSTUDENT INFORMATION");
		printf ("\n\n\t\t\tEnter Student Roll Number: ");
		scanf ("%d", &num);
		for (i=0;i<count;i++)
		{
			if (rcd[i].rnum==num)
			{
				printf ("\n\t\t\tIncorrect ID! ID already Reserved. Please try again.");
				getch();
				flag=1;
			}
		}
		if (flag==1)
			continue;
		else
			rcd[count].rnum=num;
			
		printf ("\n\t\t\tEnter Student name: ");
		scanf ("%s", rcd[count].fname);
		printf ("\n\t\t\tEnter Last name: ");
		scanf ("%s", rcd[count].lname);
		printf ("\n\t\t\tEnter City: ");
		scanf ("%s", rcd[count].city);
		printf ("\n\t\t\tEnter Student Deprtment: ");
		scanf ("%s", rcd[count].dpt);
		printf ("\n\t\t\tEnter the Section of Student: ");
		scanf ("%s", rcd[count].section);
		printf ("\n\t\t\tEnter Student age: ");
		scanf ("%d", &rcd[count].age);
		printf ("\n\n\t\t\tRecord added successfully!");
		printf ("\n\n\t\tFirst Name\tLast Name\tCity\tDepartment\tRoll #\tAge\tSection");
		printf ("\n\t\t%s\t\t%s\t\t%s\t\t%s\t%d\t%d\t%s",rcd[count].fname,rcd[count].lname,rcd[count].city,rcd[count].dpt,rcd[count].rnum,rcd[count].age,rcd[count].section);
		getch();
		system ("cls");
		printf ("\n\t\t\tACADEMIC INFORMATION");
		printf ("\n\n\t\t\tEnter first course name: ");
		scanf ("%s", rcd[count].mks.cname1);
		printf ("\n\t\t\tEnter marks of %s: ", rcd[count].mks.cname1);
		scanf ("%f", &rcd[count].mks.m1);
		printf ("\n\n\t\t\tEnter second course name: ");
		scanf ("%s", rcd[count].mks.cname2);
		printf ("\n\t\t\tEnter marks of %s: ", rcd[count].mks.cname2);
		scanf ("%f", &rcd[count].mks.m2);
		printf ("\n\n\t\t\tEnter third course name: ");
		scanf ("%s", rcd[count].mks.cname3);
		printf ("\n\t\t\tEnter marks of %s: ", rcd[count].mks.cname3);
		scanf ("%f", &rcd[count].mks.m3);
		printf ("\n\n\t\t\tEnter fourth course name: ");
		scanf ("%s", rcd[count].mks.cname4);
		printf ("\n\t\t\tEnter marks of %s: ", rcd[count].mks.cname4);
		scanf ("%f", &rcd[count].mks.m4);
		printf ("\n\n\t\t\tEnter fifth course name: ");
		scanf ("%s", rcd[count].mks.cname5);
		printf ("\n\t\t\tEnter marks of %s: ", rcd[count].mks.cname5);
		scanf ("%f", &rcd[count].mks.m5);
		printf ("\n\n\t\t\tMarks added successfully!");
		printf ("\n\n\tCourses: \t\t%s\t%s\t%s\t%s\t%s",rcd[count].mks.cname1,rcd[count].mks.cname2,rcd[count].mks.cname3,rcd[count].mks.cname4,rcd[count].mks.cname5);
		printf ("\n\tMarks: \t\t\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f",rcd[count].mks.m1,rcd[count].mks.m2,rcd[count].mks.m3,rcd[count].mks.m4,rcd[count].mks.m5);
		rcd[count].mks.avg = (rcd[count].mks.m1+rcd[count].mks.m2+rcd[count].mks.m3+rcd[count].mks.m4+rcd[count].mks.m5)/5;
		
		if (rcd[count].mks.avg>=86)
		{
			rcd[count].mks.gpa=4;
		}
		else
			rcd[count].mks.gpa=4-(86-rcd[count].mks.avg)/12; 		//Formula for GPA below 4 (FAST system)
		
		count++;
		break;
	}
}

void searchRcd()
{
	int num,i,flag=0;
	system("cls");
	printf ("\n\n\t\t\tEnter the Roll Number of student: ");
	scanf ("%d", &num);
	for (i=0;i<=count; i++)
	{
		if (rcd[i].rnum==num)
		{
			printf ("\n\n\t\t\tRecord Found!");
			printf ("\n\n\t\tFirst Name\tLast Name\tCity\tDepartment\tRoll #\tAge\tSection");
			printf ("\n\t\t%s\t\t%s\t\t%s\t\t%s\t%d\t%d\t%s",rcd[i].fname,rcd[i].lname,rcd[i].city,rcd[i].dpt,rcd[i].rnum,rcd[i].age,rcd[i].section);
			flag=1;
			break;
		}
	}
	if (flag==0)
		printf ("\n\n\t\t\tNo record found for roll number %d", num);
}

void modifyRcd()
{
	int i,flag=0,roll_num,num,choice;
	char str[20];
	while (1)
	{
		system("cls");
		printf ("\n\n\t\t\tEnter the RollNumber of the Student: ");
		scanf ("%d", &roll_num);
		printf ("\n\n\t\t\t1. First Name\n\t\t\t2. Last Name\n\t\t\t3. City\n\t\t\t4. Department\n\t\t\t5. Roll Number\n\t\t\t6. Age\n\t\t\t7. Section\n\n\t\t\tWhat do want to modify?  ");
		scanf ("%d", &choice);
		
		for (i=0;i<=count;i++)
		{
			if (rcd[i].rnum==roll_num)
			{
				flag=1;
				break;
			}
		}
		
		if (flag==0)
		{
			printf ("No record found for roll number: %d", roll_num);
			getch();
			continue;
		}
	
		switch(choice)
		{
			case 1:
				printf ("\n\n\t\t\tEnter Student's First Name: ");
				scanf ("%s", str);
				strcpy(rcd[i].fname,str);
				break;
			case 2:
				printf ("\n\n\t\t\tEnter Student's Last Name: ");
				scanf ("%s", str);
				strcpy (rcd[i].lname,str);
				break;
			case 3:
				printf ("\n\n\t\t\tEnter Student's City: ");
				scanf ("%s", str);
				strcpy(rcd[i].city,str);
				break;
			case 4: 
				printf ("\n\n\t\t\tEnter Student's New Department: ");
				scanf ("%s", str);
				strcpy(rcd[i].dpt,str);
				break;
			case 5: 
				printf ("\n\n\t\t\tEnter Student's New Roll Number: ");
				scanf ("%d", &num);
				rcd[i].rnum=num;
				break;
			case 6: 
				printf ("\n\n\t\t\tEnter Student's Age: ");
				scanf ("%d", &num);
				rcd[i].age=num;
				break;
			case 7:
				printf ("\n\n\t\tEnter Student's new section: ");
				scanf ("%s", str);
				strcpy(rcd[i].section,str);
				break;	
			default: 
				printf ("\n\n\t\t\tIncorrect Selection!");
				getch();
				continue;
				break;						
		}
		break;
	}
	printf ("\n\t\t\tChanges made succesfully!");
	printf ("\n\n\t\tFirst Name\tLast Name\tCity\tDepartment\tRoll #\tAge\tSection");
	printf ("\n\t\t%s\t\t%s\t\t%s\t\t%s\t%d\t%d\t%s",rcd[i].fname,rcd[i].lname,rcd[i].city,rcd[i].dpt,rcd[i].rnum,rcd[i].age,rcd[i].section);
	
}

void displaySec()
{
	int i,c=0;
	char sec[3];
	while(1)
	{
		system ("cls");
		printf ("\n\n\t\t\tEnter the Section: ");
		scanf ("%s", sec);
		sort();
		printf ("\n\n\t\tThe records are as follows: ");
		printf ("\n\n\t\tFirst Name\tLast Name\tCity\tDepartment\tRoll #\tAge\tSection");
		for (i=0;i<count;i++)
		{
			if (strcmp(rcd[i].section,sec)==0)
			{
				printf ("\n\t\t%s\t\t%s\t\t%s\t\t%s\t%d\t%d\t%s",rcd[i].fname,rcd[i].lname,rcd[i].city,rcd[i].dpt,rcd[i].rnum,rcd[i].age,rcd[i].section);
				c++;
			}
		}
		if (c!=0)
		{
			printf ("\n\t\t\tThere are %d students of Section %s. ",c,sec);
			break;
		}
		else
		{
			printf ("\n\t\t\tIncorrect Section Input!");
			getch();
			continue;
		}	
	}
}

void displayDpt()
{
	int i,c=0;
	char dep[20];
	while(1)
	{
		system ("cls");
		printf ("\n\n\t\t\tEnter the Department: ");
		scanf ("%s", dep);
		sort();
		printf ("\n\n\t\tThe records are as follows: ");
		printf ("\n\n\t\tFirst Name\tLast Name\tCity\tDepartment\tRoll #\tAge\tSection");
		for (i=0;i<count;i++)
		{
			if (strcmp(rcd[i].dpt,dep)==0)
			{
				printf ("\n\t\t%s\t\t%s\t\t%s\t\t%s\t%d\t%d\t%s",rcd[i].fname,rcd[i].lname,rcd[i].city,rcd[i].dpt,rcd[i].rnum,rcd[i].age,rcd[i].section);
				c++;
			}
		}
		if (c!=0)
		{
			printf ("\n\t\t\tThere are %d students of Department %s. ",c,dep);
			break;
		}
		else
		{
			printf ("\n\t\t\tIncorrect Section Input!");
			getch();
			continue;
		}	
	}
}

void displayAll()
{
	int i;
	system("cls");
	sort();
	printf ("\n\n\t\tThe records are as follows: ");
	printf ("\n\n\t\tFirst Name\tLast Name\tCity\tDepartment\tRoll #\tSection\tAge");
	for (i=0;i<count;i++)
	{
		printf ("\n\t\t%s\t\t%s\t\t%s\t\t%s\t%d\t%s\t%d",rcd[i].fname,rcd[i].lname,rcd[i].city,rcd[i].dpt,rcd[i].rnum,rcd[i].section,rcd[i].age);
	}
}

void displayBatch()
{
	char a;
	int c1=0,c2=0,c3=0,c4=0,i;
	record fmen[5],soph[5],jun[5],sen[5];
	system("cls");
	sort();
	for (i=0; i<count; i++)
	{
		a=rcd[i].section[0];
		if (a=='1' || a=='2')
		{
			fmen[c1]=rcd[i];
			c1++;
		}
		else if (a=='3' || a=='4')
		{
			soph[c2]=rcd[i];
			c2++;
		}
		else if (a=='5' || a=='6')
		{
			jun[c3]=rcd[i];
			c3++;
		}
		else
		{
			sen[c4]=rcd[i];
			c4++;
		}
	}
	printf ("\n\t\t\t\tThe Freshmen of Batch of 2021");
	printf ("\n\n\t\tFirst Name\tLast Name\tCity\tDepartment\tRoll #\tAge\tSection");
	for (i=0; i<c1; i++)
	{
		printf ("\n\t\t%s\t\t%s\t\t%s\t\t%s\t%d\t%d\t%s",fmen[i].fname,fmen[i].lname,fmen[i].city,fmen[i].dpt,fmen[i].rnum,fmen[i].age,fmen[i].section);
	}
	printf ("\n\n\t\t\t\tThe Sophomores of Batch 2020");
	printf ("\n\n\t\tFirst Name\tLast Name\tCity\tDepartment\tRoll #\tAge\tSection");
	for (i=0; i<c2; i++)
	{
		printf ("\n\t\t%s\t\t%s\t\t%s\t\t%s\t%d\t%d\t%s",soph[i].fname,soph[i].lname,soph[i].city,soph[i].dpt,soph[i].rnum,soph[i].age,soph[i].section);
	}
	printf ("\n\n\t\t\t\tThe Juniors of Batch 2019");
	printf ("\n\n\t\tFirst Name\tLast Name\tCity\tDepartment\tRoll #\tAge\tSection");
	for (i=0; i<c3; i++)
	{
		printf ("\n\t\t%s\t\t%s\t\t%s\t\t%s\t%d\t%d\t%s",jun[i].fname,jun[i].lname,jun[i].city,jun[i].dpt,jun[i].rnum,jun[i].age,jun[i].section);
	}
	printf ("\n\n\t\t\t\tThe Seniors of Batch 2018");
	printf ("\n\n\t\tFirst Name\tLast Name\tCity\tDepartment\tRoll #\tAge\tSection");
	for (i=0; i<c4; i++)
	{
		printf ("\n\t\t%s\t\t%s\t\t%s\t\t%s\t%d\t%d\t%s",sen[i].fname,sen[i].lname,sen[i].city,sen[i].dpt,sen[i].rnum,sen[i].age,sen[i].section);
	}
}

void countRcd()
{
	printf ("\n\n\n\n\n\t\t\tThe number of students are: %d", count);
}

void deleteRcd()
{
	int num,i,flag=0;
	system("cls");
	printf ("\n\n\t\t\tEnter the roll number of the student to be deleted: ");
	scanf ("%d", &num);
	for (i=0;i<count;i++)
	{
		if (rcd[i].rnum == num)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf ("\t\t\tNo such record found.");
		exit(1);
	}
	else
	{
		while (i<count)
		{
			rcd[i]=rcd[i+1];
			i++;
		}
	}
	count--;
	printf ("\n\n\t\t\tRecord Deleted! The number of students are now %d", count);
}

void sort()
{
	int i,j;
	record temp;
	for (i=0; rcd[i].rnum!=0; i++)
	{
		for (j=i; rcd[j+1].rnum!=0; j++)
		{
			if (rcd[j].rnum>rcd[j+1].rnum)
			{
				temp = rcd[j];
				rcd[j]=rcd[j+1];
				rcd[j+1]=temp;
			}
		}
	}
}

void schPro()
{
	int ans;
	do
	{
		system ("cls");
		date();
		printf ("\n\n\t\t\t");
		printf ("1. DISPLAY PROGRAMME DETAILS");
		printf ("\n\n\t\t\t");
		printf ("2. DISPLAY ELIGIBLE STUDENTS FOR SPECIFIC PROGRAMMES");
		printf ("\n\n\t\t\t");
		printf ("3. TOP 10 STUDENTS");
		printf ("\n\n\t\t\t");
		printf ("4. BACK TO MAIN MENU");
		printf ("\n\n\t\t\tEnter your choice: ");
		scanf ("%d", &ans);
		switch(ans)
		{
			case 1:
				dispPro();
				getch();
				system("cls");
				break;
			case 2:
				dispSPros();
				getch();
				system("cls");
				break;
			case 3:
				top10();
				getch();
				system("cls");
				break;
			case 4:
				break;
			default:
				printf ("Invalid Input! Please try again.");
				getch();
				system("cls");
				break;			
				
		}
	} while(ans!=4);
}

void sortMarks()
{
	record temp;
	int i,j;
	for (i=0; i<count; i++)
	{
		for (j=i; j<count; j++)
		{
			if (rcd[j].mks.avg<rcd[j+1].mks.avg)
			{
				temp = rcd[j];
				rcd[j]=rcd[j+1];
				rcd[j+1]=temp;
			}
		}
	}
}

void dispPro()
{
	system("cls");
	printf ("\n\n\t\t\tSCHOLARSHIP PROGRAMMES");
	printf ("\n\n\t1. HEC Scholarship: ");
	printf ("\n\t--------------------");
	printf ("\n\tThe details are as follows: ");
	printf ("\n\t\ta. Eligible for top 3 students of Each Semester.");
	printf ("\n\t\tb. Covers full tution fees.");
	printf ("\n\t\tc. Covers full extra curricular activity fees.");
	printf ("\n\n\t2. OSAF Financial Assistance: ");
	printf ("\n\t-----------------------------");
	printf ("\n\tThe details are as follows: ");
	printf ("\n\t\ta. Eligible for top 4-10 students.");
	printf ("\n\t\tb. Covers 50%% tution fees.");
	printf ("\n\t\tc. Covers no extra curricular activity fees.");
	printf ("\n\n\t3. PEEF Scholarship: ");
	printf ("\n\t---------------------");
	printf ("\n\tThe details are as follows: ");
	printf ("\n\t\ta. Eligible for students having 3.5 or above CGPA");
	printf ("\n\t\tb. Covers 25%% of tution fees. ");
	printf ("\n\t\tc. Covers no extra curricular activity fees.");
	getch();	
}
	
void dispSPros() 
{
	int i;
	system ("cls");
	sortMarks();
	printf ("\n\t\tEligible Scholars for HEC Scholarship: \n");
	printf ("\n\tName\tL Name\tMarks\tGPA\n");
	for (i=0; i<3; i++)
	{
		printf ("\n\t%s\t%s\t%.2f\t%.2f", rcd[i].fname, rcd[i].lname, rcd[i].mks.avg,rcd[i].mks.gpa); 
	}
	printf ("\n\n\t\tEligible Scholars for OSAF Scholarship: \n");
	printf ("\n\tName\tL Name\tMarks\tGPA\n");
	for (i=3;i<10;i++)
	{
		printf ("\n\t%s\t%s\t%.2f\t%.2f", rcd[i].fname, rcd[i].lname, rcd[i].mks.avg, rcd[i].mks.gpa);
	}
	printf ("\n\n\t\tEligible Scholars for PEEC Scholarship: \n");
	printf ("\n\tName\tL Name\tMarks\tGPA\n");
	for (i=10; i<count; i++)
	{
		if (rcd[i].mks.gpa>=3.5)
		{
			printf ("\n\t%s\t%s\t%.2f\t%.2f", rcd[i].fname, rcd[i].lname, rcd[i].mks.avg,rcd[i].mks.gpa);
		}
	}
	sort();
}	

void checkSch()
{
	int i;
	sortMarks();
	for (i=0; i<3; i++)
	{
		rcd[i].fees = 0;
		rcd[i].ec1=0;
		rcd[i].ec2=0;
		rcd[i].ec3=0;
	}
	for (i=3;i<10;i++)
	{
		rcd[i].fees = 150000;
		rcd[i].fees /= 2;
	}
	for (i=10; i<count; i++)
	{
		if (rcd[i].mks.gpa>=3.5)
		{
			rcd[i].fees = 150000;
			rcd[i].fees *= 0.75;
		}
	}
}

void top10() 
{
	int i;
	system("cls");
	sortMarks();
	printf ("\n\n\t\t\t\tTOP 10 POSITION HOLDERS");
	printf ("\n\n\t\tName\tL Name\tMarks\tGPA\n");
	for (i=0;i<10;i++)
	{
		printf ("\n\t%s\t%s\t%.2f\t%.2f", rcd[i].fname, rcd[i].lname, rcd[i].mks.avg,rcd[i].mks.gpa);
	}
	sort();
}

void eventMng()
{
	int ans;
	do
	{
		system ("cls");
		date();
		printf ("\n\n\t\t\t");
		printf ("1. EVENT DETAILS");
		printf ("\n\n\t\t\t");
		printf ("2. EVENT APPLICATION");
		printf ("\n\n\t\t\t");
		printf ("3. EVENT RESERVATIONS");
		printf ("\n\n\t\t\t");
		printf ("4. CANCEL RESERVATION");
		printf ("\n\n\t\t\t");
		printf ("5. BACK TO MAIN MENU");
		printf ("\n\n\t\t\tEnter your choice: ");
		scanf ("%d", &ans);
		switch(ans)
		{
		case 1:
			eventDtls();
			getch();
			break;
		case 2: 
			eventApp();
			getch();
			break;	
		case 3:
			eventR();
			getch();
			break;
		case 4:
			cancel();
			getch();
			break;
		case 5:
			break;	
		default:
			printf ("Invalid Input! Please try again.");
			getch();
			break;	
		}			
	} while (ans!=5);
}

void eventDtls()
{
	system ("cls");
	printf ("\n\n\t\t\tEVENT DETAILS");
	printf ("\n\n\t1. The Grand Debate: ");
	printf ("\n\t--------------------");
	printf ("\n\tThe details are as follows: ");
	printf ("\n\t\ta. Charges are 400 per student.");
	printf ("\n\t\tb. Reserved only for 20 Students.");
	printf ("\n\t\tc. Eligible for All Students.");
	printf ("\n\n\t2. FAST X Squid Game: ");
	printf ("\n\t----------------------");
	printf ("\n\tThe details are as follows: ");
	printf ("\n\t\ta. Charges are 600 per student.");
	printf ("\n\t\tb. Reserved only for 25 Students.");
	printf ("\n\t\tc. Eligible for Students above 18.");
	printf ("\n\n\t3. Picnic Party 2k21: ");
	printf ("\n\t---------------------");
	printf ("\n\tThe details are as follows: ");
	printf ("\n\t\ta. Charges are 700 per student.");
	printf ("\n\t\tb. Reserved for 20 students.");
	printf ("\n\t\tc. Eligible for Seniors only.");
}

void eventApp()
{
	int i,num,x,flag=0;
	char a;
	while (1)
	{
		system("cls");
		printf ("\n\n\t\tEnter the Roll Number of Student: ");
		scanf ("%d", &num);
		for (i=0; i<count; i++)
		{
			if (rcd[i].rnum==num)
			{
				flag=1;
				break;
			}
		}
		if (flag==0)
		{
			printf ("\n\t\tNo such Student of Roll Number %d exists.", num);
			getch();
			continue;
		}
		printf ("\n\n\t\t\t1. The Grand Debate");
		printf ("\n\n\t\t\t2. FAST X Squid Game");
		printf ("\n\n\t\t\t3. Picnic Party 2k21");
		printf ("\n\n\t\t\tEnter the choice of Application: ");
		scanf ("%d", &x);
		switch(x)
		{
			case 1:
				if (e_count1>20)
				{
					printf ("\n\t\t\tEvent 1 is fully reserved. Please try another event.");
					getch();
					continue;
					
				}
				if (rcd[i].ec1==0)
				{
					rcd[i].ec1=400;
					e_count1++;
				}
				else
				{
					printf ("\n\t\t\tStudent %d already reserved event. Please try again.", num);
					getch();
					continue;
				}
				break;
			case 2:
				if (rcd[i].ec2==0)
				{
					if (rcd[i].age>18)
					{
					rcd[i].ec2=600;
					e_count2++;
					}
					else
					{
						printf ("\n\t\t\tStudent %d is not above 18. Please try again!");
						getch();
						continue;
					}
				}
				else
				{
					printf ("\n\t\t\tStudent %d already reserved event. Please try again.", num);
					getch();
					continue;
				}	
				break;
			case 3:
				a=rcd[i].section[0];
				if (rcd[i].ec3==0)
				{
					if (a == '7' || a == '8')
					{
					rcd[i].ec3=700;
					e_count3++;	
					}
					else
					{
						printf ("\n\t\t\tStudent %d is not a Senior. Please try again.");
						getch();
						continue;
					}
				}
				else
				{
					printf ("\n\t\t\tStudent %d already reserved event. Please try again.", num);
					getch();
					continue;
				}
				break;
			default:
				printf ("Invalid Input! Please try again.");
				getch();
				continue;
				break;			
		}
		break; 				//This break is for getting out of the infinite loop.
	}
	printf ("\n\t\t\tStudent %d has now reserved Event %d", num, x);
}

void cancel()
{
	int i,num,flag=0,x;
	while (1)
	{
		system("cls");
		printf ("\n\n\t\t\tEnter Student Roll Number: ");
		scanf ("%d", &num);
		for (i=0; i<count; i++)
		{
			if (rcd[i].rnum==num)
			{
				flag=1;
				break;
			}
		}
		if (flag==0)
		{
			printf ("\n\t\t\tNo Student with Roll Number %d exists.", num);
			getch();
			continue;
		}
		printf ("\n\n\t\t\t1. The Grand Debate");
		printf ("\n\n\t\t\t2. FAST X Squid Game");
		printf ("\n\n\t\t\t3. Picnic Party 2k21");
		printf ("\n\n\t\t\tEnter the choice of Deletion: ");
		scanf ("%d", &x);
		switch (x)
		{
			case 1:
				if (rcd[i].ec1!=0)
				{
					rcd[i].ec1=0;
					e_count1--;
				}
				else
				{
					printf ("\n\t\t\tStudent %d has never reserved Event 1", num);
					getch();
					continue;
				}
				break;
			case 2:
				if (rcd[i].ec2!=0)
				{
					rcd[i].ec2=0;
					e_count2--;
				}
				else
				{
					printf ("\n\t\t\tStudent %d has never reserved Event 2", num);
					getch();
					continue;
				}	
				break;
			case 3:
				if (rcd[i].ec3!=0)
				{
					rcd[i].ec3=0;
					e_count3--;
				}
				else
				{
					printf ("\n\t\t\tStudent %d has never reserved Event 3", num);
					getch();
					continue;
				}
				break;
			default:
				printf ("\n\t\t\tInvalid Input! Please try again.");
				getch();
				break;			
		}
		printf ("\n\t\t\tStudent %d has now cancelled Event %d", num, x);
		break;
	}
}

void eventR()
{
	int i;
	system("cls");
	printf ("\n\n\t\t\t\tThe Grand Debate");
	printf ("\n\t\t\t\t----------------");
	printf ("\n\n\t\t\tName\tL Name\tRoll #\tAge\tSection\n");
	for (i=0; i<count; i++)
	{
		if (rcd[i].ec1!=0)
		{
			printf ("\n\t\t\t%st%s\t%d\t%d\t%s", rcd[i].fname, rcd[i].lname, rcd[i].rnum, rcd[i].age, rcd[i].section);
		}
	}
	printf ("\n\n\t\t\tThere are %d Reservations for The Grand Debate.", e_count1);
	
	printf ("\n\n\t\t\t\tFAST X Squid Game");
	printf ("\n\t\t\t\t-----------------");
	printf ("\n\n\t\t\tName\tL Name\tRoll #\tAge\tSection\n");
	for (i=0; i<count; i++)
	{
		if (rcd[i].ec2!=0)
		{
			printf ("\n\t\t\t%st%s\t%d\t%d\t%s", rcd[i].fname, rcd[i].lname, rcd[i].rnum, rcd[i].age, rcd[i].section);
		}
	}
	printf ("\n\n\t\t\tThere are %d Reservations for FAST X Squid Game.", e_count2);
	
	printf ("\n\n\t\t\t\tPicic Party 2k21");
	printf ("\n\t\t\t\t----------------");
	printf ("\n\n\t\t\tName\tL Name\tRoll #\tAge\tSection\n");
	for (i=0; i<count; i++)
	{
		if (rcd[i].ec3!=0)
		{
			printf ("\n\t\t\t%st%s\t%d\t%d\t%s", rcd[i].fname, rcd[i].lname, rcd[i].rnum, rcd[i].age, rcd[i].section);
		}
	}
	printf ("\n\n\t\t\tThere are %d Reservations for Picnic Party 2k21.", e_count3);
}

void fees()
{
	int ans;
	do
	{
		system ("cls");
		date();
		printf ("\n\n\t\t\t");
		printf ("1. EDIT FEES");
		printf ("\n\n\t\t\t");
		printf ("2. DISPLAY STUDENT FEES");
		printf ("\n\n\t\t\t");
		printf ("3. BACK TO MAIN MENU");
		printf ("\n\n\t\t\t");
		printf ("\n\n\t\t\tEnter your choice: ");
		scanf ("%d", &ans);
		switch(ans)
		{
		case 1:
			editfees();
			getch();
			break;
		case 2: 
			dispFees();
			getch();
			break;	
		case 3:
			break;
		default:
			printf ("Invalid Input! Please try again.");
			getch();
			break;	
		}			
	} while (ans!=3);
}

void editfees()
{
	int num,i,flag=0;
	while (1)
	{
		system("cls");
		printf ("\n\n\t\t\tEnter the Roll # to edit fee status.");
		scanf ("%d", &num);
		for (i=0; i<count; i++)
		{
			if (rcd[i].rnum==num)
			{
				flag=1;
				break;
			}
		}
		if (flag==0)
		{
			printf ("\n\t\tNo such Student of Roll Number %d exists.", num);
			getch();
			continue;
		}
		printf ("\n\n\t\t\tEnter DC Charges (if any): ");
		scanf ("%f", &rcd[i].dc);
		printf ("\n\t\t\tEnter paid amount (if paid): ");
		scanf ("%f", &rcd[i].paid);
		printf ("\n\n\t\t\tFee status editted succesfully!");
		getch();
		break;
	}
}

void dispFees()
{
	int num,i,flag=0;
	while (1)
	{
		system("cls");
		printf ("\n\n\t\t\tEnter the Roll # to display fees: ");
		scanf ("%d", &num);
		for (i=0; i<count; i++)
		{
			if (rcd[i].rnum==num)
			{
				flag=1;
				break;
			}
		}
		if (flag==0)
		{
			printf ("\n\t\tNo such Student of Roll Number %d exists.", num);
			getch();
			continue;
		}
		system ("cls");
		printf ("\n\n\t\t\tFEES MANAGEMENT");
		printf ("\n\n\tFirst Name:\t%s\n\tLast Name:\t%s\n\tRoll #:\t%d\n\tSection:\t%s", rcd[i].fname,rcd[i].lname,rcd[i].rnum,rcd[i].section);
		printf ("\n\t\t\t---------------");
		checkSch();
		printf ("\n\nTution Fees: \t\t\t\t %.2f", rcd[i].fees);
		printf ("\n\nExtra Curricular Activities:\n\tTGD:\t\t\t\t %.2f\n\tF X SG:\t\t\t\t %.2f\n\tPP 2k21:\t\t\t %.2f\n\t",rcd[i].ec1,rcd[i].ec2,rcd[i].ec3);
		printf ("\n\nDC Charges: \t\t\t\t %.2f", rcd[i].dc);
		printf ("\n\nAmount Paid: \t\t\t\t %.2f", rcd[i].paid);
		printf ("\n\t\t\t---------------");
		rcd[i].total = rcd[i].fees+rcd[i].ec1+rcd[i].ec2+rcd[i].ec3+rcd[i].dc-rcd[i].paid; 
		printf ("\n\nTotal Fees: \t\t\t\t %.2f", rcd[i].total);
		break;
	}
}

void createAcc()
{
	FILE *ptr,*ptrr;
	char str[25],str1[25],temp[25];
	int x;
	
	while(1)
	{
		system("cls");
		printf ("\n\n\t\t\tEnter username: ");
		scanf ("%s", str);
		
		x=strlen(str);
		
		if (x>20||x<4)
		{
			printf ("\n\t\t\tUsername should be in between 4-20 characters!");
			getch();
			continue;
		}
		
		strcpy(temp,str);
		
		if (strcmp(strlwr(temp),str)==0)
		{
			printf ("\n\n\t\t\tThere should at least be one Upper Case letter!");
			getch();
			continue;
		}
		
		strcpy(temp,str);
		
		if (strcmp(strupr(temp),str)==0)
		{
			printf ("\n\n\t\t\tThe should at least be one Lower Case letter!");
			getch();
			continue;
		}
		
		printf ("\n\n\t\t\tEnter password: ");
		scanf ("%s", str1);
		
		x=strlen(str1);
		
		if (x>20||x<4)
		{
			printf ("\n\t\t\tUsername should be in between 4-20 characters!");
			getch();
			continue;
		}
		
		strcpy(temp,str1);
		
		if (strcmp(strlwr(temp),str1)==0)
		{
			printf ("\n\n\t\t\tThere should at least be one Upper Case letter!");
			getch();
			continue;
		}
		
		strcpy(temp,str);
		
		if (strcmp(strupr(temp),str1)==0)
		{
			printf ("\n\n\t\t\tThe should at least be one Lower Case letter!");
			getch();
			continue;
		}
		break;
	}
	ptr = fopen("username.txt","a");
	
	if (ptr == NULL)
	{
		printf ("\nError 404. Account Setup Failed.");
		exit (1);
	}
	
	fflush(stdin);
	fprintf (ptr, "\n%s", str);
	
	ptrr = fopen("password.txt","a");
	fflush(stdin);
	fprintf (ptrr, "\n%s", str1);
	printf ("\n\n\t\t\tAccount Creation Successful!");
}


