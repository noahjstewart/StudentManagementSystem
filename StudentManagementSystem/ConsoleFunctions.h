#pragma once
#include "stdafx.h"

#include "Student.h"

void display_menu();
void update_container(Student&, vector<Student>&);
void add_course(Student&, vector<Student>&);
// remove course
void add_student(vector<Student>&);
void change_id(Student&);
void change_name(Student&);
void change_course_subj(Course&);
void edit_student(vector<Student>&);