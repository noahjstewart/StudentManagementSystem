#pragma once
#include "stdafx.h"

#include <iostream>
using std::cin; using std::cout; using std::endl; using std::ostream;
#include <vector>
using std::vector;
#include <string>
using std::string;

struct Course
{
	string subject;
	int course_number;
	int section;
	int credits;
	float grade;
	friend ostream& operator<<(ostream&, const Course&);
};

class Student
{
private:
	// ctors

	// members
	int id;
	string name;
	int total_credits;
	vector<Course> classes;
	float gpa;

public:
	// getters
	int get_id();
	string get_name();
	int get_credits();
	vector<Course>& get_classes();
	float get_gpa();

	// setters
	void set_name(string);
	void set_id(int);

	// methods
	void edit_class_grade(Course);
	void remove_class(Course);
	void add_class(Course);
	float calculate_gpa();

	// << operator
	friend ostream& operator<<(ostream&, const Student&);
};