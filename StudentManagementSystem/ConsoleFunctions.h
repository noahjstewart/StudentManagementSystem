#pragma once
#include "stdafx.h"

#include "Student.h"

void display_menu();
void update_container(Student&, vector<Student>&);
void update_student(Student&, Course&);
void add_course(Student&, vector<Student>&);
void edit_course_grade(Student&, vector<Student>&, vector<Course>&);
void add_student(vector<Student>&);
void remove_student(vector<Student>&);
void change_name(Student&);
void change_course_subj(Course&);
void edit_student(vector<Student>&);