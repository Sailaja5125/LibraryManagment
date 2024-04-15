#include <stdio.h>
#include <stdlib.h>
struct user
{
    char name[40];
    int id;
    double phone_no;
}u;
struct book
{
    char book_name[100];
    char author_name[100];
    int quantity;
}b; 
// rent list 
struct rent{
    struct user u;
    struct book b;
    char Receivingdate[10];
    char Returningdate[10];
}r;
void addUser()
{
    int no_users;
    printf("Enter the no. of users you want to enter :");
    scanf("%d", &no_users);
    int i = 0;
    while (i < no_users)
    {
        FILE *ul = fopen("userlist.txt", "ab+");
        if (ul != NULL)
        {
            printf("enter the name\n");
            scanf("%s", u.name);
            printf("enter id \n");
            scanf("%d", &u.id);
            printf("enter Phone number \n");
            scanf("%lf", &u.phone_no);
            fprintf(ul, "%s\t %d\t %.lf\n", u.name, u.id ,u.phone_no);
            printf("Users added successfully\n");
        }
        else
        {
            printf("unable to open the file ..");
        }
        i++;
        fclose(ul);
    }
}
void rentuser()
{ 
    char date[10];
    char returndate[10];
    FILE *rl = fopen("rentlist.txt", "ab+");
    printf("enter the name\n");
    scanf("%s", r.u.name);
    printf("enter id \n");
    scanf("%d", &r.u.id);
    printf("enter book_name \n");
    scanf("%s", r.b.book_name);
      printf("enter author_name \n");
    scanf("%s", r.b.author_name);
    printf("enter date \n");
    scanf("%s", r.Receivingdate);
    printf("Returning enter date \n");
    scanf("%s", r.Returningdate);
    fprintf(rl, "%s %d %s %s %s", r.u.name, r.u.id,r.b.book_name,r.Receivingdate,r.Returningdate);
    printf("-------------------------invoice------------------------\n");
    printf("name : %s \n id : %d \n book : %s \n author : %s \n Rented on : %s \n Return On : %s \n", r.u.name, r.u.id,r.b.book_name,r.Receivingdate,r.Returningdate);
}
void addBooks()
{
    int no_books;
    printf("Enter the no. of books you want to add :");
    scanf("%d", &no_books);
    int i = 0;
    while (i < no_books)
    {
        FILE *bl = fopen("booklist.txt", "ab+");
        if (bl != NULL)
        {
            printf("enter the book name\n");
            scanf("%s", b.book_name);
            printf("enter author \n");
            scanf("%s", b.author_name);
            printf("enter quantity \n");
            scanf("%d", &b.quantity);
            fprintf(bl, "%s\t %s\t %d \n", b.book_name, b.author_name ,b.quantity);
            printf("Books added successfully\n");
        }
        else
        {
            printf("unable to open the file ..");
        }
        i++;
        fclose(bl);
    }
}
int main()
{
    //switch statement
    int Entry;
    printf("......................Welcome to Library........................\n");
    printf("To add user press 1\n To rent a book press 2\n To addbooks press 3\n");
    scanf("%d",&Entry);
    switch (Entry)
    {
    case 1:
       addUser();
        break;
    case 2:
       rentuser();
        break;
    case 3:
       addBooks();
       break; 
    default: printf("Thankyou !!");
        break;
    }
    return 0;
}
