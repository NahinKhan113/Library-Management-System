#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
int mainmenu();
char books[100000];int dd,mm;
int login()
{
    //for login;
    char user_n[10],pw[6],p[6];
a:  printf("\n\n\t\tUser Name:\t");scanf(" %[^\n]",&user_n);
    printf("\t\tPassword:\t");scanf(" %[^\n]",&pw);
    printf("\n%s\t%s\n",user_n,pw);
    if((strcmp(user_n,"iut")==0)&& (strcmp(pw,"oic")==0))
    {
        printf("Login Successful\nPress Any Key to Continue...");getch();system("cls");
        do{printf("Give Date Only(dd):\t");scanf("%i",&dd);}while(dd>31);
        do{printf("Give Month Only(dd):\t");scanf("%i",&mm);}while(mm>12);printf("\nPress Any Key to continue...");getch();
        printf("Switching to Main Menu...");
        mainmenu();
    }
    else
    {printf("User Name or Password Incorrect");goto a;}
}
int welcome()
{
    //for welcome screen
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
                       int ForgC;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xFF) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    printf("\t\t\t***Welcome to IUT library Facility***");
    login();
    mainmenu();
}
struct Books
{
int book_id;
char title[50];
char author[50];
int student_id;
int date;
int month;
}book;
int issue()
{
    //to issue book
    int sl,i=0;
    system("cls");
    printf("ISSUE BOOK:\n");
    FILE *fptr;
    fptr=fopen("Book.txt","a");
    printf("Serial No.");scanf("%i",&book.book_id);
    printf("Book Name:");scanf(" %[^\n]",&book.title);book.title[0]=toupper(book.title[0]);
    printf("Writer Name:");scanf(" %[^\n]",&book.author);book.author[0]=toupper(book.author[0]);
    printf("Issued to Student ID:");scanf("%i",&book.student_id);book.date=dd;book.month=mm;
    fprintf(fptr,"%i %s %s %i %i.%i\n\n",book.book_id,book.title,book.author,book.student_id,book.date,book.month);
    fclose(fptr);
    for(i=0;i<50;i++)
    {
        printf("-");
    }

    printf("\nSwitching to Main Menu. Press Any Key to Continue...");
    getch();
    mainmenu();
}
int view()
{
    //to view book
    int i;system("cls");
    printf("\nVIEW BOOK:\n");
    FILE *fp;
    fp=fopen("Book.txt","r");
    if(fp==NULL)
	{
		printf("\n\n\t\t RECORD EMPTY");
		getch();
	}
    else
	{
		printf("\nName\t\tWriter\t\tSTD_ID\t\tDate.Month\n");
    while ( fgets ( books, 1000000, fp ) != NULL )
    printf ( "%s" , books ) ;
		printf("\n");
		for(i=0;i<95;i++)
		printf("-");
	}
    fclose(fp);
    for(i=0;i<50;i++)
    {
        printf("-");
    }

    printf("\nSwitching to Main Menu. Press Any Key to Continue...");
    getch();
    mainmenu();
}
int search()
{
    //to search book
    int i,found=0;
	char id[40];
	FILE *sfile;
	system("cls");
	printf("SEARCH BOOK:\n");
	sfile=fopen("Book.txt","rb");

	printf("\n\t\tSEARCH BOOKS LIST\n\n");

	printf("\nEnter Book Name to Search:");
	fflush(stdin);
	scanf("%s",&id);
	id[0]=toupper(id[0]);
    printf("\n================================================================================\n");
	while(fscanf(sfile,"%i %s %s %i %i.%i\n\n",&book.book_id,book.title,book.author,&book.student_id,&book.date,&book.month)!=EOF)
	{
		if(strcmp(id,book.title)==0)
		{
			found=1;
			printf("ID:\t%i\n",book.book_id);
			printf("Title:\t%s\n",book.title);
			printf("Author:\t%s\n",book.author);
			printf("Student ID:\t%i\n",book.student_id);
			printf("Date:\t%i.%i",book.date,book.month);
			break;
		}
	}
		if(!found) printf("\n\n\tNo Record");
		fclose(sfile);
        printf("\n");
		for(i=0;i<50;i++)
    {
        printf("-");
    }

    printf("\nSwitching to Main Menu. Press Any Key to Continue...");
		getch();
		mainmenu();
}
int delete_book()
{
    //to delete a data
    int i,target,found;
    system("cls");
    printf("DELETE BOOK:\n");
    FILE *fptr,*fp;
    fptr=fopen("Book.txt","r");
    printf("Give Book ID for Delete: ");
    scanf("%i",&target);
    fp=fopen("Xbook.txt","w+");
    if(fptr==NULL)
	{
		printf("\n\tNo Record in File!\n");
		for(i=0;i<50;i++)
    {
        printf("-");
    }
    printf("\nSwitching to Main Menu. Press Any Key to Continue...");
		getch();
		mainmenu();
	}
	else
	{
	    while(fscanf(fptr,"%i %s %s %i %i.%i\n\n",&book.book_id,book.title,book.author,&book.student_id,&book.date,&book.month)!=EOF)
        {
            if(target!=book.book_id)
			{
				fprintf(fp,"%i %s %s %i %i.%i\n\n",book.book_id,book.title,book.author,book.student_id,book.date,book.month);
			}
			else
			{
				found=1;
			}
		}
		if(!found)
		{
			printf("\nRecord Not Found");
		}
		else
		{
			printf("\n\tRecord Deleted Successfully.....");
		}
		fclose(fptr);
		fclose(fp);
		remove("Book.txt");
		rename("Xbook.txt","Book.txt");printf("\n");
    for(i=0;i<50;i++)
    {
        printf("-");
    }

    printf("\nSwitching to Main Menu. Press Any Key to Continue...");
        getch();
		mainmenu();
    }
}
int mainmenu()
{
    system("cls");
    int a;
    printf("1. ISSUE BOOK\n2. VIEW BOOK\n3. SEARCH BOOK\n4. DELETE BOOK\n5. DELETE FILE\n6. Exit\n\tChoose your option(1-6):\t");scanf("%d",&a);
    switch(a)
    {
    case 1:
        issue();
        break;
    case 2:
        view();
        break;
    case 3:
        search();
        break;
    case 4:
        delete_book();
        exit(0);
        break;
    case 5:
        remove("Book.txt");mainmenu();
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("Wrong Entry!!");getch();
        exit(0);
    }
}
int main()
{
    welcome();
    return 0;
}
