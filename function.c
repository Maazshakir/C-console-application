#include <stdio.h>
#include <stdlib.h>

#define FILENAME "user.txt"
char FILESIZE[150];
int FILESTORAGE = 150;

//int *date;
int openexistingfile();
void optionprinting();
void readfile();
int email_validator();
int Email_Error(int d);
int Phone_validator();
int Namevalidator();
void NewBankaccount();
int Amount_Validator();
int Interest_validator();
void MyBalance();
float Interestcalculator(int file_amount, int file_Interest, int file_YY, int file_MM, int or_year, int or_month);
int transfer();
int datelen();
int date();
int pointvalidator();
int valuevalidator();
int realvalue(char b);
int DateError();
int datevalidator();

// Date section

int date(int*day,int*month,int*year){
    char date[11];
    int validator1=0,validator2=0,validator3=0;
    Datestart3:
    printf("Enter th e date (right format : 2021.12.21.) : ");
    scanf("%s",&date);
    validator1 = datelen(&date);

    if(validator1 != 11){
        printf("Date Error!\n");
        goto Datestart3;
    }
    validator2 = pointvalidator(&date);
    if(validator2 == 1){
        printf("Date Error!\n");
        goto Datestart3;
    }
    validator3 = valuevalidator(&date,&day,&month,&year);
    if(validator3==1){
        goto Datestart3; 
    }
}

int datelen(char*date){
    int i=0;
    for(i=0; date[i] != '\0';i++){
    }
    return i;
}
int pointvalidator(char*date){
    if(date[4] != '.' || date[7] != '.' || date[10] != '.'){
        return 1;
    }
    return 0;
}

int valuevalidator(char*date,int**day,int**month,int**year){
    int Year0,Year1,Year2,Year3,Month0,Month1,Day0,Day1;
    int Year,Month,Day,validator4;

    Year0 = realvalue(date[0]);
    Year1 = realvalue(date[1]);
    Year2 = realvalue(date[2]);
    Year3 = realvalue(date[3]);

    Month0 = realvalue(date[5]);
    Month1 = realvalue(date[6]);

    Day0 = realvalue(date[8]);
    Day1 = realvalue(date[9]);

    Year = Year0*1000 + Year1*100 + Year2*10 + Year3;
    Month = Month0*10 + Month1;
    Day = Day0*10 + Day1;

    **day = Day;
    **month = Month;
    **year = Year; 

    validator4 = datevalidator(Year,Month,Day);
    if(validator4 == 1){
        return 1;
    }

}

int realvalue(char b){

    int a;

    switch(b){
        case '0':
            a = 0;break;
        case '1':
            a = 1;break;
        case '2':
            a = 2;break;
        case '3':
            a = 3;break;
        case '4':
            a = 4;break;
        case '5':
            a = 5;break;
        case '6':
            a = 6;break;
        case '7':
            a = 7;break;
        case '8':
            a = 8;break;
        case '9':
            a = 9;break;     
    }
    return a;
}

int datevalidator(int Year,int Month,int Day){
    int b;
    if ((Year < 1900) || Month <= 0 || Month > 12 || Day <= 0 || Day > 31)
    {
        printf("Enter the date in correct format: DATE ERROR!\n");
        DateError();
    }
    else if (Month == 2 && Day > 29)
    {
        printf("There are max 29 days in feburary: Date error\n\n");
        DateError();
    }
    else if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && (Day > 30))
    {
        printf("The month have max 30 days: Date Error\n\n");
        DateError();
        b = DateError();
        if (b == 1)
        {
            return 1;
        }
        return 0;
    }
}
int DateError()
{
    int a, b = 0;
switchstart:
    printf("Would you like to try again? if yes enter 1 else enter 0 to exit program:  ");
    b = scanf("%d", &a);
    if (b != 1)
    {
        printf("\nProgram Stopped working!! Please enter 1 or 0 next time Byee!");
        exit(1);
    }
    switch (a)
    {
    case 0:
        exit(1);
        break;
    case 1:
        system("cls");
        return 1;
        break;
    default:
        printf("\n\nPlease enter a valid number\n");
        goto switchstart;
        break;
    }
    return 0;
}

//----------------------------------------------------------------------------------
int openexistingfile()
{
    char b[150], filename[99];
    FILE *file = NULL;
filestart:
    while (1)
    {
        printf("Enter the name of the file that you would like to open:(max 99 char.) ");
        scanf("%99s", &filename);

        for(int i=0;filename[i] != '\0';i++){
            if(filename[i] != FILENAME[i]){
                system("cls");
                printf("Enter the correct file name\n");
                goto filestart;

                }

        }

        file = fopen(filename, "r");
        if (file == NULL)
        {
            printf("\n Enter the valid file name\n");
        }
        else
        {
            break;
        }
    }
    printf("\n\nFile sucessfully read\n\n");
    fclose(file);
    return 0;
}

void optionprinting()
{
    printf("\n\n\nPlease choose from following options\n\n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("1: Clients data list\t2: Money Transfer\t3: New Bank account\t4:My Bank details\t5:Exit Program\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
}
// main case functions
void readfile()
{
    system("cls");
    char b[150];
    FILE *file = NULL;
    file = fopen(FILENAME, "r");
    printf("Name\t   Email    \tS.Bal.\t  Tel.No.  \t   Date    \tInterest\n\n");
    while (fgets(b, sizeof(b), file))
    {
        printf("%s", b);
    }
    fclose(file);
}
typedef struct Date
{
    int year;
    int month;
    int day;
} Date;
typedef struct Userdata
{
    char Name[15];
    char Email[20];
    char Phone_number[15];
    int total_amount;
    Date date;
    int interest;
} Userdata;

void NewBankaccount(int DD, int MM, int YY)
{
    system("cls");
    FILE *file;
    file = fopen(FILENAME, "a");
    int i = 0;
    Userdata *User;

    User = (Userdata *)malloc(sizeof(Userdata));

    //Name ----Namestart1
    int Namevalidate;
Namestart:
    printf("Enter your name : ");
    scanf("%s", User[i].Name);
    getchar();
    Namevalidate = Namevalidator(&User[i].Name);
    if (Namevalidate == 2)
    {
        goto Namestart;
    }

    //Email ---
    int Emailvalidate, Emailerror, loop = 1;
Emailstart:
    printf("Write your email address\n");
    scanf("%s", User[i].Email);
    getchar();
    Emailvalidate = email_validator(&User[i].Email);
    if (Emailvalidate == 2)
    {
        goto Emailstart;
    }
    //Interest
    int Interest_validate, inter, choice;
Intereststart:
    printf("Enter the interest rate: ");
    inter = scanf("%d", &User[i].interest);
    if (inter != 1)
    {
        printf("Please enter numbers only!\n\n Would you like to try again?(1(yes)/0(No)");
        getchar();
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            goto Intereststart;
        case 2:
            exit(1);
            break;
        }
    }
    getchar();
    Interest_validate = Interest_validator(User[i].interest);
    if (Interest_validate == 2)
    {
        goto Intereststart;
    }
    //Phone Number-----Phonestart1
    int PhoneValidator;
Phonestart1:
    printf("Enter your Phone Number:  ");
    scanf("%s", &User[i].Phone_number);
    getchar();
    PhoneValidator = Phone_validator(&User[i].Phone_number);
    if (PhoneValidator == 2)
    {
        goto Phonestart1;
    }
    //Amount
    int amountvalidate, integer2, choice1;
Amountstart1:
    printf("Enter the total amount (max 1000000): ");
    integer2 = scanf("%d", &User[i].total_amount);
    if (integer2 != 1)
    {
        printf("Please enter numbers only!\n\n Would you like to try again?(1(yes)/0(No)");
        getchar();
        scanf("%d", &choice1);
        getchar();
        switch (choice1)
        {
        case 1:
            goto Amountstart1;
        case 2:
            exit(1);
            break;
        }
    }
    amountvalidate = Amount_Validator(User[i].total_amount);
    if (amountvalidate == 2)
    {
        goto Amountstart1;
    }
    fprintf(file, "%s\t%s\t%d\t%11s\t", User[i].Name, User[i].Email, User[i].total_amount, User[i].Phone_number);
    if (DD < 10 && MM < 10)
    {
        fprintf(file, "%4d.0%d.0%d.\n", YY, MM, DD);
    }
    if (DD < 10 && MM >= 10)
    {
        fprintf(file, "%4d.%2d.0%d.\t", YY, MM, DD);
    }
    if (MM < 10 && DD >= 10)
    {
        fprintf(file, "%4d.0%d.%2d.\t", YY, MM, DD);
    }
    if (MM >= 10 && DD >= 10)
    {
        fprintf(file, "%4d.%2d.%2d.\t", YY, MM, DD);
    }
    fprintf(file, "%d\n", User[i].interest);
    fclose(file);
    free(User);
}

void MyBalance(int year, int month, int day)
{
    system("cls");
    char NameByUser[10];
    Userdata *list;
    list = malloc(1 * sizeof(Userdata));
    int i = 0;

    FILE *file = NULL;
    file = fopen(FILENAME, "r");
    Userdata temp;
    //User Name Input
    printf("Enter the name of the user(max 10 char) : ");
    scanf("%s", &NameByUser);
    //File scan
    while (fscanf(file, "%[^\t]\t%[^\t]\t%d\t%[^\t]\t%d.%d.%d.\t%d",
                  temp.Name, temp.Email, &temp.total_amount, temp.Phone_number, &temp.date.year, &temp.date.month,
                  &temp.date.day, &temp.interest) != EOF)
    {
        list[i] = temp;
        i++;
        list = realloc(list, (i + 1) * sizeof(Userdata));
    }

    fclose(file);
    i--;
    //printing the specific line
    int totallogic, k;
    float AmountafterInterest = 0;
    char *check;
    list = realloc(list, (i + 1) * sizeof(Userdata));
    for (int j = 0; j < i; j++)
    {
        totallogic = 0;
        check = list[j].Name;
        for (k = 0; NameByUser[k] != '\0'; k++)
        {
            if (check[k + 1] == NameByUser[k])
            {
                totallogic++;
            }
        }
        if (k == totallogic)
        {
            printf("Email : %s\n", list[j].Email);
            printf("Phone number : %s\n", list[j].Phone_number);
            printf("Base amount : %d\n", list[j].total_amount);
            printf("-------Interest : %d----------\n", list[j].interest);
            printf("---------Opening date : %d.%02d.%02d.----------\n", list[j].date.year, list[j].date.month, list[j].date.day);
            AmountafterInterest = Interestcalculator(list[j].total_amount, list[j].interest, list[j].date.year, list[j].date.month, year, month);
            printf("---------Amount after interest : %.02f----------", AmountafterInterest);
            break;
        }
        else if (k != totallogic && j + 1 == i)
        {
            printf("No match");
        }
    }
}

int transfer()
{
    system("cls");
    char NameByUser[10];
    Userdata *User1;
    User1 = malloc(1 * sizeof(Userdata));
    int i = 0;

    FILE *file = NULL;
    file = fopen(FILENAME, "r");
    Userdata temp;
    //User Name Input
    printf("Enter the name of the transferer : ");
    scanf("%s", &NameByUser);

    int transfer_Amount;

    printf("Enter the amount :");
    scanf("%d", &transfer_Amount);
    //File scan
    while (fscanf(file, "%[^\t]\t%[^\t]\t%d\t%[^\t]\t%d.%d.%d.\t%d",
                  temp.Name, temp.Email, &temp.total_amount, temp.Phone_number, &temp.date.year, &temp.date.month,
                  &temp.date.day, &temp.interest) != EOF)
    {
        User1[i] = temp;
        i++;
        User1 = realloc(User1, (i + 1) * sizeof(Userdata));
    }

    fclose(file);
    //rename("user.txt","log.txt");

    i--;
    //printing the specific line
    int totallogic, k, transfererMoney = 0;
    float AmountafterInterest = 0;
    char *check;
    User1 = realloc(User1, (i + 1) * sizeof(Userdata));


    FILE *Newfile = fopen("user(4).txt", "w");
    if (Newfile == NULL)
    {
        printf("File opening problem!");
        return 0;
    }

    for (int j = 0; j < i; j++)
    {
        totallogic = 0;
        check = User1[j].Name;
        for (k = 0; NameByUser[k] != '\0'; k++)
        {
            if (check[k + 1] == NameByUser[k])
            {
                totallogic++;
            }
        }
        if (k == totallogic)
        {
            if (User1[j].total_amount < transfer_Amount)
            {
                printf("You dont have enough money");
                fclose(Newfile);
                remove("user(4).txt");
                return 0;
            }
            else if (User1[j].total_amount >= transfer_Amount)
            {
                transfererMoney = User1[j].total_amount - transfer_Amount;
                printf("transferamount is %d\n", transfererMoney);
                fprintf(Newfile, "%s\t", User1[j].Name);
                fprintf(Newfile, "%s\t", User1[j].Email);
                fprintf(Newfile, "%d\t", transfererMoney);
                fprintf(Newfile, "%11s\t", User1[j].Phone_number);
                fprintf(Newfile, "%4d.%02d.%02d.\t", User1[j].date.year, User1[j].date.month, User1[j].date.day);
                fprintf(Newfile, "%d", User1[j].interest);
                break;
            }
        }
        else if (k != totallogic && j + 1 == i)
        {
            printf("No match");
            fclose(Newfile);
            remove("user(4).txt");
            return 0;
        }
    }
    //--------------transferieee----------------------------------
    char NameByUser1[10];
    printf("Enter the name of transferiee: ");
    scanf("%s", NameByUser1);
    int transferieeMoney = 0;

    for (int j = 0; j < i; j++)
    {
        totallogic = 0;
        check = User1[j].Name;
        for (k = 0; NameByUser1[k] != '\0'; k++)
        {
            if (check[k + 1] == NameByUser1[k])
            {
                totallogic++;
            }
        }
        if (k == totallogic)
        {
            transferieeMoney = User1[j].total_amount + transfer_Amount;
            printf("transferieeamount is %d\n", transferieeMoney);
            fprintf(Newfile, "%s\t", User1[j].Name);
            fprintf(Newfile, "%s\t", User1[j].Email);
            fprintf(Newfile, "%d\t", transferieeMoney);
            fprintf(Newfile, "%11s\t", User1[j].Phone_number);
            fprintf(Newfile, "%4d.%02d.%02d.\t", User1[j].date.year, User1[j].date.month, User1[j].date.day);
            fprintf(Newfile, "%d", User1[j].interest);
            break;
        }
        else if (k != totallogic && j + 1 == i)
        {
            printf("No match");
            fclose(Newfile);
            remove("user(4).txt");
            return 0;
        }
    }
    printf("transferer money is :%d and transferiee money is : %d", transfererMoney, transferieeMoney);

    //--------------------------------------------
    for (int j = 0; j < i; j++)
    {
        totallogic = 0;
        check = User1[j].Name;
        for (k = 0; NameByUser1[k] != '\0'; k++)
        {
            if (check[k + 1] == NameByUser1[k] || check[k + 1] == NameByUser[k])
            {
                totallogic++;
            }
        }
        if (k != totallogic)
        {
            fprintf(Newfile, "%s\t", User1[j].Name);
            fprintf(Newfile, "%s\t", User1[j].Email);
            fprintf(Newfile, "%d\t", User1[j].total_amount);
            fprintf(Newfile, "%11s\t", User1[j].Phone_number);
            fprintf(Newfile, "%4d.%02d.%02d.\t", User1[j].date.year, User1[j].date.month, User1[j].date.day);
            fprintf(Newfile, "%d", User1[j].interest);
        }
        else if (k != totallogic && j + 1 == i)
        {
            printf("No match");
            return 0;
        }
    }
    fprintf(Newfile, "\n");

    //------------------------------LOGFILE-----------------------------------------------------

    FILE *log = fopen("log.txt", "a");

    if (log == NULL)
    {
        log = fopen("log.txt", "w");
    }

    for (int j = 0; j < i; j++)
    {
        fprintf(log, "%s\t", User1[j].Name);
        fprintf(log, "%s\t", User1[j].Email);
        fprintf(log, "%d\t", User1[j].total_amount);
        fprintf(log, "%11s\t", User1[j].Phone_number);
        fprintf(log, "%4d.%02d.%02d.\t", User1[j].date.year, User1[j].date.month, User1[j].date.day);
        fprintf(log, "%d", User1[j].interest);
    }
    fprintf(log, "\n\n");
    //--------------file close--------------------------

    fclose(log);
    fclose(file);
    fclose(Newfile);

    remove(FILENAME);
    rename("user(4).txt", FILENAME);
    
}

//-------------------------------------------------------------------
int Interest_validator(int Interest)
{
    if (Interest >= 100)
    {
        printf("invalid Interest format, Please enter 2 digit number");
        return 2;
    }
    else
    {
        return 1;
    }
}

float Interestcalculator(int file_amount, int file_Interest, int file_YY, int file_MM, int or_year, int or_month)
{
    int Yeartoday, Monthtoday, Interestcount;
    Yeartoday = (or_year) - (file_YY);
    Monthtoday = (or_month - file_MM);
    int value = file_amount;

    //amount*(1+rate)^Years
    float inter = 1 + (file_Interest * .01), temp, c = 1;

    if (Yeartoday > 0 && Monthtoday >= 0)
    {

        for (int i = 0; i <= Yeartoday; i++)
        {
            temp = inter;
            c = c * temp;
        }
    }
    else if (Yeartoday > 0 && Monthtoday < 0)
    {

        for (int i = 0; i <= (Yeartoday - 1); i++)
        {
            temp = inter;
            c = c * temp;
        }
    }
    else if (Yeartoday < 1)
    {
        printf("No interest calculated!\n");
    }

    return file_amount * c;
}
//Amount section

int Amount_Validator(int amount)
{
    if (amount > 1000000)
    {
        printf("Please enter less amount , we cannot accept that much money!\n");
        return 2;
    }
    else
    {
        return 1;
    }
}
/*

// Email Section
*/
int email_validator(char *email)
{
    int i, part1 = 0, part2 = 0;

    for (i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            part1 = i;
        }
        if (email[i] == '.')
        {
            part2 = i;
        }
    }
    if ((part1 > 2) && (part2 - part1 > 2))
    {
        return 1;
    }
    else
    {
        printf("invalid email format\n\n");
        return 2;
    }
    return 0;
}
/*
// Phone Section
*/

int Phone_validator(char *number1)
{
    int i, part1 = 0, part2 = 0;

    for (i = 0; number1[i] != '\0'; i++)
    {
        if (number1[i] < '0' || number1[i] > '9')
        {
            printf("Please enter numbers only\n");
            return 2;
        }
        if (i >= 11)
        {
            printf("Number too long, please 11 digit enter numbers only\n");
            return 2;
        }
    }
    if ((number1[0] != '0') || (number1[1] != '6'))
    {
        printf("\nPlease enter your hungarian number\n\n");
        return 2;
    }

    if (i < 11)
    {
        printf("Number too short, please enter 11 digit number\n");
        return 2;
    }
    return 0;
}

//Name

int Namevalidator(char *namev)
{
    int a, i;
    for (i = 0; namev[i] != '\0'; i++)
    {
        if (i > 9)
        {
            printf("Too long name please enter a name shorter than 10 characters \n");
            return 2;
        }
    }

    for (i = 0; namev[i] != '\0'; i++)
    {
        if ((namev[i] >= 'a' && namev[i] <= 'z') || (namev[i] >= 'A' && namev[i] <= 'Z'))
        {
            a++;
        }
    }
    if (a == i)
    {
        return 1;
    }
    printf("invalid name format\n");
    return 2;
}

//----------------------------------------------------------------------------------------------------
