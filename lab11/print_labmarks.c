// program that will read a command line argument that is the class
// print out the lab marks, names, student ids and total lab mark of everone in the class
// Dean Hou and Isheeta Sinha
// z5163159 and z5164929
// week 11 lab

// mostly given as starting point for COMP1511 lab 11
// need to write code for the printing out of the studentsof a class

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STUDENT_NAME_LENGTH 128
#define MAX_GRADE_STRING_LENGTH 22
#define MAX_LAB_NAME_LENGTH 32
#define MAX_LINE_LENGTH 4096

struct student {
    int              zid;
    char             name[MAX_STUDENT_NAME_LENGTH + 1];
    char             lab_name[MAX_LAB_NAME_LENGTH + 1];
    char             lab_grades[MAX_GRADE_STRING_LENGTH + 1];
    struct student   *next;
};

struct student *read_students_file(char filename[]);
struct student *read_student(FILE *stream);
double grades2labmark(char grades[]);

int main(int argc, char *argv[]) {
    // CHANGE THIS CODE
    double grades;
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <marks-file> <class-name>\n", argv[0]);
        return 1;
    }
    
    struct student *student_list = read_students_file(argv[1]);
    // printf("Students file read into linked list (pointer=%p)\n", student_list);
    
    while (student_list != NULL) { // while not the last element in the struct, last is NULL
    	if (strcmp(student_list->lab_name, argv[2]) == 0) { // string compare the lab_name to given lab name, if 0, then comparison is true
    		grades = grades2labmark(student_list->lab_grades); // find grade using previous function
    		printf("%d %-30s %-12s %-22s %4.1lf\n",
    	 		student_list->zid, // pointers to the specific part of the string indicating the information to be printed
    	 		student_list->name,
    	 		student_list->lab_name,
    	 		student_list->lab_grades,
    	 		grades);
    	}
    	student_list = student_list->next; // go to next student in the list
	}
    return 0;
}
	

double grades2labmark(char grades[]) {
	int loopCount = 0;
	double sumGrades= 0;
	while (grades[loopCount] != '\0') {
		if (grades[loopCount] == 'A') {
			sumGrades = sumGrades + 1;
		} else if (grades[loopCount] == '+') {
			sumGrades = sumGrades + 0.2;
		}  else if (grades[loopCount] == 'B') {
			sumGrades = sumGrades + 0.8;
		} else if (grades[loopCount] == 'C') {
			sumGrades = sumGrades + 0.5;
		} else if (grades[loopCount] == '.') {
			sumGrades = sumGrades + 0;	
		}
		loopCount++;
	}
	if (sumGrades > 10) {
		sumGrades = 10;
	}
	return sumGrades; 	
}

// DO NOT CHANGE THE CODE BELOW HERE - DO NOT CHANGE read_students_file

// read_students_file reads a file where line contains information for 1 student
// it creates a linked of student structs containing the information
// it returns a pointer to the head of the list

struct student *read_students_file(char filename[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr,"warning file %s could not  be opened for reading\n", filename);
        return NULL;
    }

    struct student *first_student = NULL;
    struct student *last_student = NULL;
    struct student *s;
    while ((s = read_student(fp)) != NULL) {
        if (last_student == NULL) {
            first_student = s;
            last_student = s;
        } else {
            last_student->next = s;
            last_student = s;
        }
    }

    fclose(fp);
    return first_student;
}

// DO NOT CHANGE read_student

// read_student mallocs a student struct
// and reads a line in this format:
//
// 5099703 Tsun Bordignon thu13-sitar A+A+CABAB..A.
//
// stores the values in the struct field
// and returns a pointer to the struct

struct student *read_student(FILE *stream) {
    char line[MAX_LINE_LENGTH];

    struct student *s = malloc(sizeof (struct student));
    assert(s);

    if (fgets(line, MAX_LINE_LENGTH, stream) == NULL) {
        free(s);
        return NULL;
    }

    char *newline_ptr = strchr(line, '\n');
    assert(newline_ptr);
    *newline_ptr = '\0';

    char *space_ptr = strrchr(line, ' ');
    assert(space_ptr);
    strncpy(s->lab_grades, space_ptr + 1, MAX_GRADE_STRING_LENGTH);
    s->lab_grades[MAX_GRADE_STRING_LENGTH] = '\0';
    *space_ptr = '\0';

    space_ptr = strrchr(line, ' ');
    assert(space_ptr);
    strncpy(s->lab_name, space_ptr + 1, MAX_LAB_NAME_LENGTH);
    s->lab_name[MAX_LAB_NAME_LENGTH] = '\0';
    *space_ptr = '\0';

    space_ptr = strchr(line, ' ');
    assert(space_ptr);
    strncpy(s->name, space_ptr + 1, MAX_STUDENT_NAME_LENGTH);
    s->name[MAX_STUDENT_NAME_LENGTH] = '\0';
    *space_ptr = '\0';

    s->zid = atoi(line);
    s->next = NULL;
    return s;
}
