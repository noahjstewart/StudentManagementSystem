#include "stdafx.h"

#include <sstream>
using std::ostringstream;
#include <iomanip>
using std::setprecision;

#include "Student.h"

/**
* output operator for Course struct
* generates formatted output for a Course
*/
ostream& operator<<(ostream& out, const Course& c)
{
	ostringstream oss;
	oss << "COURSE: ";
	oss << c.subject << " " << c.course_number << " SECTION " <<
		c.section << endl;
	oss << "CREDITS: " << c.credits << endl;
	oss << std::fixed << setprecision(1) << "GRADE: " << c.grade;

	string res = oss.str();
	out << res;
	return out;
}

/**
* output operator for Student class
* generates formatted output for a Student
* uses the output operator associated with Course struct
*/
ostream& operator<<(ostream& out, const Student& s)
{
	ostringstream oss;
	oss << "STUDENT ID: " << s.id << endl;
	oss << "STUDENT NAME: " << s.name << endl << endl;
	for (Course c : s.classes)
	{
		oss << c << endl;
		oss << "===================================" << endl;
	}
	oss << "TOTAL CREDITS: " << s.total_credits << endl;
	oss << "OVERALL GPA: " << s.gpa << endl;

	string res = oss.str();
	out << res;
	return out;
}

// getters

/**
* int Student::get_id()
* returns ID of a student as an int
*/
int Student::get_id()
{
	return id;
}

/**
* string Student::get_name()
* returns the name of a student as string
*/
string Student::get_name()
{
	return name;
}

/**
* int Student::get_credits()
* returns total credits of a student as an int
*/
int Student::get_credits()
{
	return total_credits;
}

/**
* vector<Course> Student::get_classes()
* returns the classes of a student as a vector<Course>
*/
vector<Course>& Student::get_classes()
{
	return classes;
}

/**
* int Student::get_credits()
* returns total credits of a student as an int
*/
float Student::get_gpa()
{
	return gpa;
}

// setters

/**
* void Student::set_name(string n)
* sets a Student's name
* param n: name string
*/
void Student::set_name(string n)
{
	for (auto& c : n)
		c = toupper(c);
	name = n;
}

/**
* void Student::set_id(int i)
* sets a Student's ID
* param i: ID int
*/
void Student::set_id(int i)
{
	id = i;
}

// methods

/**
* void Student::add_class(Course c)
* adds a Course to a Student's classes vector
* adds to Student's total credits
* recalculates Student's GPA
* param c: Course to be added
*/
void Student::add_class(Course c)
{
	classes.push_back(c);
	total_credits += c.credits;
	gpa = this->calculate_gpa(classes);
}

/**
* void Student::calculate_gpa(vector<Course> v)
* calculates a Student's GPA
* param v: vector of Courses
*/
float Student::calculate_gpa(vector<Course> v)
{
	float sum = 0.0;
	for (Course c : v)
		sum += c.grade * c.credits;

	return sum / total_credits;
}