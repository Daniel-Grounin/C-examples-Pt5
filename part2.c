/* Assignment 5: Author- Daniel Grounin*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//version 2 of struct
typedef struct{
	char name[30];
	int grade;
}course;

typedef struct{
	char name[30];
	int num_of_courses;
	course* arr;
}student;

//init student size and courses
student* initialize(int* pSize) {
	student* s_arr = NULL;
	printf("Enter amount of students :\n");
	scanf("%d", pSize);
	//alloc amount of students
	s_arr = (student*)malloc((*pSize) * sizeof(student));
	//run on amount of student with proper allocation of courses
	for (int i = 0; i < *pSize; i++) {
		printf("Enter student's name:\n");
		scanf("%s", s_arr[i].name);

		printf("Enter number of courses:\n");
		scanf("%d", &s_arr[i].num_of_courses);
		//allocate amount of courses
		s_arr[i].arr = (course*)malloc(s_arr[i].num_of_courses * sizeof(course));
		//free up the memory
		if (s_arr[i].arr == NULL) {
			printf("Not Enough Memory\n");
			free(s_arr);
			exit(1);
		}
		//amount of courses
		for (int j = 0; j < s_arr[i].num_of_courses; j++) {
			printf("Enter Courses name:\n");
			scanf("%s", s_arr[i].arr[j].name);

			printf("Enter Grade of %s:\n", s_arr[i].arr[j].name);//corse garde
			scanf("%d", &s_arr[i].arr[j].grade);
		}
	}
	if (s_arr == NULL)
		printf("Not Enough Memory\n");
	exit(1);

	return s_arr;
}

//func prints courses grade & average grade
void print_student(student* stu, int size, char* name) {
	int sum = 0;
	for (int i = 0; i < size; i++){//compare student name to saved archive of names
		if (strcmp(stu[i].name, name) == 0){
			for (int j = 0; j < stu[i].num_of_courses; j++){
				//average calculation
				sum += stu[i].arr[j].grade;
				printf("Course: %s , Grade is %d \n", stu[i].arr[j].name , stu[i].arr[j].grade);
			}
			printf("Average grade is %d for student name`s %s", sum / stu[i].num_of_courses, stu[i].name);
			return;
		}
	}
	printf("didn't found such name\n");
}

void print_course(student* stu, int size, char* name) {
	for (int i = 0; i < size; i++){
		for (int j = 0; j < stu[i].num_of_courses; j++)
			if (strcmp(stu[i].arr[j].name, name) == 0){
			printf("Student name %s studies %s\n", stu[i].name, stu[i].arr[j].name);
			printf("Grade is %d \n", stu[i].arr[j].grade);
			return;
			}
	}
		printf("didn't found such course\n");
}

//updates
void update(student* stu, int size, char* sname, char* cname, int grade) {
	for (int i = 0; i < size; i++) {
		if (strcmp(stu[i].name, sname) == 0) {
			for (int j = 0; j < stu[i].num_of_courses; j++)
				if (strcmp(stu[i].arr[j].name, cname) == 0)
					stu[i].arr[j].grade = grade;
			return;
		}
		stu[i].num_of_courses++;
		stu[i].arr = (course*)realloc(stu[i].arr, stu[i].num_of_courses * sizeof(course));
		stu[i].arr[stu[i].num_of_courses - 1].grade = grade;
		strcpy(stu[i].arr[stu[i].num_of_courses - 1].name, cname);
		return;
	}
	printf("didn't found such name\n");
}

void common( student* stu, int size, char* s1, char* s2) {
	int flag = 0;
	for (int i = 0; i < size; i++){
		if (strcmp(stu[i].name, s1) == 0){
			for (int j = 0; j < size; j++){
				if (strcmp(stu[j].name, s2) == 0){
					flag = 1;
					for (int k = 0; k < stu[i].num_of_courses; k++){
						for (int g = 0; g < stu[j].num_of_courses; g++){
							if (strcmp(stu[i].arr[k].name, stu[j].arr[g].name) == 0){
								printf("The course is: %s \n", stu[i].arr[k].name);
							}
						}
					}
				}
			}
		}
	}
	if (flag == 0) {
		printf("didn't found such name\n");
	}

}

//free memory alloc
void free_Memory(student* students, int size){
	for (int i = 0; i < size; i++)
		free(students[i].arr);
	free(students);
}

int main() {
	int size, grade;
	char name[30], course[30], name2[30];
	student* Student = NULL;
	Student = initialize(&size);
	printf("Please enter students names:\n");
	scanf("%s\n", name);
	printf("Please enter the courses name : \n");
	scanf("%s\n", course);
	printf("last one ,please enter the courses grades: \n");
	scanf("%d", &grade);
	update(Student, size, name, course, grade);
	puts("\n");

	printf("Enter student name to view information\n");
	scanf("%s", name);
	print_student(Student, size, &name);
	printf("Enter course name to find all students within the course ,and their grades:\n");
	scanf("%s", course);

	print_course(Student, size, &course);
	printf("Enter 2 students name ,to show their common courses :\n ");
	scanf("%s %s", name,name2);

	common(Student, size, &name, &name2);
	free_Memory(Student, size);
	return 0;
}
