#include <stdio.h>
#include <string.h>
#define NumStd 5
#define Ncourses 2
struct course
{
    char name[50];
    float grade;
};
struct STUDENT
{
    char fullName[50];
    int birthYear;
    int birthMonth;
    int birthDay;
    long long int studentNumber;
    char gender[10];
    struct course courses[Ncourses];
};
void writeToFile(struct STUDENT students[], const char *Fn, int *Num)
{
    FILE *file = fopen(Fn, "wb");
    if (file == NULL)
    {
        printf("error opening file\n");
        return;
    }
    fwrite(students, sizeof(struct STUDENT), *Num, file);
    printf("saved succussfully!\n");
    fclose(file);
}
void addingInfo(const char *Fn, struct STUDENT students[], int *Num)
{
    for (int i = 0; i < *Num; i++)
    {
        printf("student %d fullname:\n", i + 1);
        scanf("%s", students[i].fullName);
        printf("student %d gender:\n", i + 1);
        scanf("%s", students[i].gender);
        printf("student %d birth year:\n", i + 1);
        scanf("%d", &students[i].birthYear);
        printf("student %d birth month:\n", i + 1);
        scanf("%d", &students[i].birthMonth);
        printf("student %d birth day:\n", i + 1);
        scanf("%d", &students[i].birthDay);
        printf("student %d student number:\n", i + 1);
        scanf("%lld", &students[i].studentNumber);
        for (int j = 0; j < Ncourses; j++)
        {
            printf("course %d name:\n", j + 1);
            scanf("%s", students[i].courses[j].name);
            printf("course %d grade:\n", j + 1);
            scanf("%f", &students[i].courses[j].grade);
        }
    }
    FILE *file = fopen(Fn, "wb");
    if (file == NULL)
    {
        printf("error opening file\n");
        return;
    }
    fwrite(students, sizeof(struct STUDENT), *Num, file);
    fclose(file);
}
void changeFullName(const char *Fn, long long int stdnum, char Newname[], int *Num)
{
    FILE *file = fopen(Fn, "rb+");
    if (file == NULL)
    {
        printf("error opening file\n");
        return;
    }
    struct STUDENT students[*Num];
    fread(students, sizeof(struct STUDENT), *Num, file);
    for (int i = 0; i < *Num; i++)
    {
        if (students[i].studentNumber == stdnum)
        {
            strcpy(students[i].fullName, Newname);
            fseek(file, 0, SEEK_SET);
            fwrite(students, sizeof(struct STUDENT), *Num, file);
            fclose(file);
            printf("changed succussfully!\n");

            return;
        }
    }
    printf("student not found!\n");
}
void changeBirthYear(const char *Fn, long long int stdnum, int Newyear, int *Num)
{
    FILE *file = fopen(Fn, "rb+");
    if (file == NULL)
    {
        printf("error opening file\n");
        return;
    }
    struct STUDENT students[*Num];
    fread(students, sizeof(struct STUDENT), *Num, file);

    for (int i = 0; i < *Num; i++)
    {
        if (students[i].studentNumber == stdnum)
        {
            students[i].birthYear = Newyear;
            fseek(file, 0, SEEK_SET);
            fwrite(students, sizeof(struct STUDENT), *Num, file);
            fclose(file);
            printf("changed succussfully!\n");
            return;
        }
    }
    printf("student not found!\n");
}
void changeBirthMonth(const char *Fn, long long int stdnum, int Newmonth, int *Num)
{
    FILE *file = fopen(Fn, "rb+");
    if (file == NULL)
    {
        printf("error opening file\n");
        return;
    }
    struct STUDENT students[*Num];
    fread(students, sizeof(struct STUDENT), *Num, file);
    for (int i = 0; i < *Num; i++)
    {
        if (students[i].studentNumber == stdnum)
        {
            students[i].birthMonth = Newmonth;
            fseek(file, 0, SEEK_SET);
            fwrite(students, sizeof(struct STUDENT), *Num, file);
            fclose(file);
            printf("changed succussfully!\n");
            return;
        }
    }
    printf("student not found!\n");
}
void changeBirthDay(const char *Fn, long long int stdnum, int Newday, int *Num)
{
    FILE *file = fopen(Fn, "rb+");
    if (file == NULL)
    {
        printf("error opening file\n");
        return;
    }
    struct STUDENT students[*Num];
    fread(students, sizeof(struct STUDENT), *Num, file);
    for (int i = 0; i < *Num; i++)
    {
        if (students[i].studentNumber == stdnum)
        {
            students[i].birthDay = Newday;
            fseek(file, 0, SEEK_SET);
            fwrite(students, sizeof(struct STUDENT), *Num, file);
            fclose(file);
            printf("changed succussfully!\n");
            return;
        }
    }
    printf("student not found!\n");
}
void changeStudentNumber(const char *Fn, long long int stdnum, int Newstdnum, int *Num)
{
    FILE *file = fopen(Fn, "rb+");
    if (file == NULL)
    {
        printf("error opening file\n");
        return;
    }
    struct STUDENT students[*Num];
    fread(students, sizeof(struct STUDENT), *Num, file);
    for (int i = 0; i < *Num; i++)
    {
        if (students[i].studentNumber == stdnum)
        {
            students[i].studentNumber = Newstdnum;
            fseek(file, 0, SEEK_SET);
            fwrite(students, sizeof(struct STUDENT), *Num, file);
            fclose(file);
            printf("changed succussfully!\n");
            return;
        }
    }
    printf("student not found!\n");
}
void changeGender(const char *Fn, long long int stdnum, char Newgender[], int *Num)
{
    FILE *file = fopen(Fn, "rb+");
    if (file == NULL)
    {
        printf("error opening file\n");
        return;
    }
    struct STUDENT students[*Num];
    fread(students, sizeof(struct STUDENT), *Num, file);
    for (int i = 0; i < *Num; i++)
    {
        if (students[i].studentNumber == stdnum)
        {
            strcpy(students[i].gender, Newgender);
            fseek(file, 0, SEEK_SET);
            fwrite(students, sizeof(struct STUDENT), *Num, file);
            fclose(file);
            printf("changed succussfully!\n");
            return;
        }
    }
    printf("student not found!\n");
}
void changeGrades(const char *Fn, long long int stdnum, char course[], float Newgrade, int *Num)
{
    FILE *file = fopen(Fn, "rb+");
    if (file == NULL)
    {
        printf("error opening file\n");
        return;
    }
    struct STUDENT students[*Num];
    fread(students, sizeof(struct STUDENT), *Num, file);
    for (int i = 0; i < *Num; i++)
    {
        if (students[i].studentNumber == stdnum)
        {
            for (int j = 0; j < Ncourses; j++)
            {
                if (strcmp(course, students[i].courses[j].name) == 0)
                {
                    students[i].courses[j].grade = Newgrade;
                    fseek(file, 0, SEEK_SET);
                    fwrite(students, sizeof(struct STUDENT), *Num, file);
                    fclose(file);
                    printf("changed succussfully!\n");
                    return;
                }
            }
            printf("course name not found!\n");
        }
    }
    printf("student not found!\n");
}
void removeStudents(const char *Fn, long long int stdnum, int *Num)
{
    FILE *file = fopen(Fn, "rb+");
    if (file == NULL)
    {
        printf("error opening file\n");
        return;
    }
    struct STUDENT students[*Num];
    fread(students, sizeof(struct STUDENT), *Num, file);
    for (int i = 0; i < *Num; i++)
    { 
        if(*Num==1 && students[i].studentNumber == stdnum )
        {
            (*Num)--;
            printf("removed successfully!\n");
            return;
        }
        if (students[i].studentNumber == stdnum)
        {
            for (int j = (*Num) - 1; j > i; j--)
            {
                strcpy(students[j - 1].fullName, students[j].fullName);
                students[j - 1].birthYear = students[j].birthYear;
                students[j - 1].birthMonth = students[j].birthMonth;
                students[j - 1].birthDay = students[j].birthDay;
                students[j - 1].studentNumber = students[j].studentNumber;
                strcpy(students[j - 1].gender, students[j].gender);
                for (int k = 0; k < Ncourses; k++)
                {
                    strcpy(students[j - 1].courses[k].name, students[j].courses[k].name);
                    students[j - 1].courses[k].grade = students[j].courses[k].grade;
                    (*Num)--;
                    fseek(file, 0, SEEK_SET);
                    fwrite(students, sizeof(struct STUDENT), *Num, file);
                    fclose(file);
                    printf("removed successfully!\n");
                    return;
                }
            }
        }
    }
    printf("student not found!\n");
}
void readFromFile(const char *Fn, int *Num)
{
    FILE *file = fopen(Fn, "rb");
    if (file == NULL)
    {
        printf("error opening file\n");
        return;
    }
    struct STUDENT students[*Num];
    fread(students, sizeof(struct STUDENT), *Num, file);
    fclose(file);
    if(*Num==0)
    {
        printf("no students to present!\n");
        return ;
    }
    printf("students information:\n");
    for (int i = 0; i < *Num; i++)
    {

        printf("  student %d\n", i + 1);
        printf("full name:%s\n", students[i].fullName);
        printf("gender:%s\n", students[i].gender);
        printf("student number:%lld\n", students[i].studentNumber);
        printf("birth date: %d/%d/%d\n", students[i].birthYear, students[i].birthMonth, students[i].birthDay);
        printf("courses:\n");
        for (int j = 0; j < Ncourses; j++)
        {
            printf("%s %f\n", students[i].courses[j].name, students[i].courses[j].grade);
        }
    }
}
int main()
{
    const char *Fn = "D:/project.c.txt";
    struct STUDENT students[NumStd];
    int n, a, s, Num;
    printf("please enter your required option:\n");
    printf("1.inputting students information\n");
    printf("2.exit\n");
    scanf("%d", &n);
    if (n == 2)
    {
        return 0;
    }
    else
    {
        printf("how many students you want to be included?\n");
        scanf("%d", &Num);
        addingInfo(Fn, students, &Num);
        do
        {
            printf("1.removing students\n");
            printf("2.editing students information\n");
            printf("3.editing students grades\n");
            printf("4.saving in a file\n");
            printf("5.read information from file\n");
            printf("6.exit\n");
            scanf("%d", &a);
            switch (a)
            {
            case 1:
            {
                long long int stdnum;
                printf("please input student's student number:\n");
                scanf("%lld", &stdnum);
                removeStudents(Fn, stdnum, &Num);
                break;
            }
            case 2:
            {
                printf("which information you want to be changed?\n");
                printf("1.fullname\n");
                printf("2.birth year\n");
                printf("3.birth month\n");
                printf("4.birth day\n");
                printf("5.student number\n");
                printf("6.gender\n");
                scanf("%d", &s);
                switch (s)
                {
                case 1:
                {
                    long long int stdnum;
                    char Newname[50];
                    printf("please input student's student number:\n");
                    scanf("%lld", &stdnum);
                    printf("please input the new fullname:\n");
                    scanf("%s", Newname);
                    changeFullName(Fn, stdnum, Newname, &Num);
                    break;
                }
                case 2:
                {
                    long long int stdnum;
                    int Newyear;
                    printf("please input student's student number:\n");
                    scanf("%lld", &stdnum);
                    printf("please input the new birth year:\n");
                    scanf("%d", &Newyear);
                    changeBirthYear(Fn, stdnum, Newyear, &Num);
                    break;
                }
                case 3:
                {
                    long long int stdnum;
                    int Newmonth;
                    printf("please input student's student number:\n");
                    scanf("%lld", &stdnum);
                    printf("please input the new birth month:\n");
                    scanf("%d", &Newmonth);
                    changeBirthMonth(Fn, stdnum, Newmonth, &Num);
                    break;
                }
                case 4:
                {
                    long long int stdnum;
                    int Newday;
                    printf("please input student's student number:\n");
                    scanf("%lld", &stdnum);
                    printf("please input the new birth day:\n");
                    scanf("%d", &Newday);
                    changeBirthDay(Fn, stdnum, Newday, &Num);
                    break;
                }
                case 5:
                {
                    long long int stdnum;
                    int Newstdnum;
                    printf("please input student's student number:\n");
                    scanf("%lld", &stdnum);
                    printf("please input the new student number:\n");
                    scanf("%d", &Newstdnum);
                    changeStudentNumber(Fn, stdnum, Newstdnum, &Num);
                    break;
                }
                case 6:
                {
                    long long int stdnum;
                    char Newgender[10];
                    printf("please input student's student number:\n");
                    scanf("%lld", &stdnum);
                    printf("please input the new gender:\n");
                    scanf("%s", Newgender);
                    changeGender(Fn, stdnum, Newgender, &Num);
                    break;
                }
                }
                break;
            }
            case 3:
            {

                long long int stdnum;
                char course[50];
                float Newgrade;
                printf("please input student's student number:\n");
                scanf("%lld", &stdnum);
                printf("please input the course name:\n");
                scanf("%s", course);
                printf("please input the new grade:\n");
                scanf("%f", &Newgrade);
                changeGrades(Fn, stdnum, course, Newgrade, &Num);
                break;
            }
            case 4:
            {
                writeToFile(students, Fn, &Num);
                break;
            }
            case 5:
            {
                readFromFile(Fn, &Num);
                break;
            }
            }

        } while (a != 6);
    }

    return 0;
}