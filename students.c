#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 100
#define MAX_STUDENTS 70

typedef struct{
    int id;
    char student_name[MAX_NAME_LEN];
}Student;

Student students[MAX_STUDENTS];

int number_of_students = 0;
const char* STUDENT_FILE = "students.txt";
const char* ABSENT_INFO_FILE = "students_absent.txt";

void load_students(const char* filename);
void add_student_to_file(const char* filename, Student s);
void attendance(const char* filename);
void view_students(void);
void add_student(const char* filename);
void save_absent_info(const char* filename, Student s);

int main(){
    load_students(STUDENT_FILE);
    int response = 0;
    while (1){
        printf("\n-----Class Managment System-----\n");
        printf("1. Attendance\n");
        printf("2. View Students\n");
        printf("3. Add students\n");
        printf("4. Exit \n");
        printf("Enter your response : ");
        scanf("%d", &response);

        if (response == 4){
            break;
        }
        switch (response){
            case 1:
                attendance(ABSENT_INFO_FILE);
                break;
            case 2:
                view_students();
                break;
            case 3: 
                add_student(STUDENT_FILE); 
                break;
            default:
                printf("Please enter a valid choice!");
        }
    }
    return 0;
}

void attendance(const char* filename){
    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);
    printf("Type 1 for Present and 0 for Absent\n");
    int present = 0;
    int absent = 0;
    Student students_absent[MAX_STUDENTS];
    for (int i=0; i<number_of_students; i++){
            int rollcall = 0; 
            printf("%s : ", students[i].student_name);
            scanf("%d",&rollcall);
            if (rollcall){
                present++;
            }
            else{
                students_absent[absent++] = students[i];
            }
    }
    printf("\nStudents Present are : %d\n", present);
    printf("Students absent are : %d\n", absent);
    printf("\n");
    printf("--Absent Students--\n");

    FILE *file = fopen(filename, "a");
    fprintf(file,"\n");
    fprintf(file, "%s", asctime(tm_info));
    fclose(file);

    for (int i=0; i<absent; i++){
        printf("%s %d\n", students_absent[i].student_name, students_absent[i].id);
        save_absent_info(ABSENT_INFO_FILE, students_absent[i]);
    }
    printf("\n");
}

void save_absent_info(const char* filename, Student s){
    FILE *file = fopen(filename, "a");
    if (!file){
        printf("No students in file found , starting frehs\n");
        return;
    }
    fprintf(file , "%d %s\n", s.id, s.student_name);
    fclose(file);
    
}

void view_students(void){
    printf("\n--Student List--\n");
    printf("\n");
    for (int i=0; i<number_of_students;i++){
        printf("%d %s\n", students[i].id, students[i].student_name);
    }
}

void load_students(const char* filename){
    FILE *file = fopen(filename, "r");
    if (!file){
        printf("No students in file found , starting frehs\n");
        return;
    }
    number_of_students = 0;
    while(fscanf(file, "%d %49s", &students[number_of_students].id, students[number_of_students].student_name)==2){
        number_of_students++;
    }
    fclose(file);
}

void add_student_to_file(const char* filename, Student s){
    FILE *file = fopen(filename,"a");
    if (!file){
        printf("Error openning the file ");
    }
    fprintf(file,"%d %s\n",s.id , s.student_name);
    fclose(file);
}

void add_student(const char* filename){
    Student s;
    printf("Enter Student ID: ");
    scanf("%d",&s.id);
    printf("Enter Student Name: ");
    scanf("%49s", s.student_name);
    students[number_of_students] = s;
    number_of_students++;
    add_student_to_file(STUDENT_FILE, s);
    printf("\n");
    printf("Student added with ID %d.\n", s.id);

}