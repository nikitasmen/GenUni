#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_OF_STUDENTS 100
#define MAX_GRADES_ENTRIES 1000

int students[MAX_NUM_OF_STUDENTS][2]; 
int grades[MAX_GRADES_ENTRIES][3];
int student_count = 0;
int grade_count = 0;

/*
Function Name: insert_student
-----------------------------------
Description: This function inserts a student into the students array.
Parameters:
 - int student_id: ID of the student.
 - int semester: Semester of the student.
Returns:
 - int: 1 if the student was added successfully, 0 otherwise.
*/
int insert_student(int student_id, int semester) {
    if (student_count >= MAX_NUM_OF_STUDENTS) {
        return 0;
    }

    for (int i = 0; i < student_count; i++) {
        if (students[i][0] == student_id) {
            return 0; 
        }
    }

    students[student_count][0] = student_id;
    students[student_count][1] = semester;
    student_count++;
    return 1;
}

/*
Function Name: insert_grade
-----------------------------------
Description: This function inserts a grade for a course for a student.
Parameters:
 - int student_id: ID of the student.
 - int course_id: ID of the course.
 - int grade: Grade for the course.
Returns:
 - int: 1 if the grade was added successfully, 0 otherwise.
*/
int insert_grade(int student_id, int course_id, int grade) {
    if (grade_count >= MAX_GRADES_ENTRIES) {
        return 0;
    }

    int student_exists = 0;
    for (int i = 0; i < student_count; i++) {
        if (students[i][0] == student_id) {
            student_exists = 1;
            break;
        }
    }

    if (!student_exists) {
        return 0; 
    }

    for (int i = 0; i < grade_count; i++) {
        if (grades[i][0] == student_id && grades[i][1] == course_id) {
            return 0;
        }
    }

    grades[grade_count][0] = student_id;
    grades[grade_count][1] = course_id;
    grades[grade_count][2] = grade;
    grade_count++;
    return 1;
}

/*
Function Name: delete_student
-----------------------------------
Description: This function deletes a student and all their grades.
Parameters:
 - int student_id: ID of the student to be deleted.
Returns:
 - int: 1 if the student was deleted successfully, 0 otherwise.
*/
int delete_student(int student_id) {
    int student_index = -1;
    for (int i = 0; i < student_count; i++) {
        if (students[i][0] == student_id) {
            student_index = i;
            break;
        }
    }

    if (student_index == -1) {
        return 0;
    }

    for (int i = student_index; i < student_count - 1; i++) {
        students[i][0] = students[i + 1][0];
        students[i][1] = students[i + 1][1];
    }
    student_count--;

    for (int i = 0; i < grade_count; ) {
        if (grades[i][0] == student_id) {
            for (int j = i; j < grade_count - 1; j++) {
                grades[j][0] = grades[j + 1][0];
                grades[j][1] = grades[j + 1][1];
                grades[j][2] = grades[j + 1][2];
            }
            grade_count--;
        } else {
            i++;
        }
    }

    return 1;
}

/*
Function Name: print_semester_avg_grade
-----------------------------------
Description: This function prints the average grade of a given semester.
Parameters:
 - int semester: The semester for which to calculate the average grade.
Returns:
 - void
*/
void print_semester_avg_grade(int semester) {
    int total_grades = 0;
    int grade_count_in_semester = 0;

    for (int i = 0; i < grade_count; i++) {
        int student_id = grades[i][0];
        for (int j = 0; j < student_count; j++) {
            if (students[j][0] == student_id && students[j][1] == semester) {
                total_grades += grades[i][2];
                grade_count_in_semester++;
                break;
            }
        }
    }

    if (grade_count_in_semester == 0) {
        printf("No grades found for semester %d.\n", semester);
    } else {
        printf("Average grade for semester %d: %.2f\n", semester, (float)total_grades / grade_count_in_semester);
    }
}

int main() {
    insert_student(100, 3);
    insert_student(200, 7);
    insert_student(300, 2);

    insert_grade(100, 101, 85);
    insert_grade(200, 102, 90);
    insert_grade(300, 103, 78);
    insert_grade(100, 104, 95);

    print_semester_avg_grade(3);
    print_semester_avg_grade(7);

    delete_student(100);

    print_semester_avg_grade(3);

    return 0;
}
