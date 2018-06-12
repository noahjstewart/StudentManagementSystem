#include "stdafx.h"

#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::getline; using std::string;

#include "Student.h"
#include "ConsoleFunctions.h"

/**
* void display_menu()
* displays main menu options
*/
void display_menu()
{
	cout << "\n\tMAIN MENU\n";
	cout << "\n\t1) ADD STUDENT RECORD";
	cout << "\n\t2) EDIT CURRENT STUDENT RECORD";
	cout << "\n\t3) DELETE STUDENT RECORD";
	cout << "\n\t4) SEARCH";
	cout << "\n\t5) DISPLAY ALL STUDENTS";
	cout << "\n\t6) EXIT";
	cout << "\n\n\tSELECT AN OPTION (1-6): ";
}

/**
* void update_container(Student& s, vector<Student>& v)
* updates a Student entry within the container
* param s: Student to add a course to
* param v: container of Students
*/
void update_container(Student& s, vector<Student>& v)
{
	for (auto& student : v)
		if (student.get_id() == s.get_id())
			student = s;
}

/**
* void add_course(Student& s, vector<Student>& v)
* adds a course to a Student using s.add_class(Course) method
* param s: Student to add a course to
* param v: container of Students
*/
void add_course(Student& s, vector<Student>& v)
{
	Course c;
	cout << "\n\tENTER SUBJECT: ";
	cin >> c.subject;
	// convert subject to uppercase
	for (auto &c : c.subject)
		c = toupper(c);
	cout << "\n\tENTER COURSE NUMBER: ";
	cin >> c.course_number;
	cout << "\n\tENTER SECTION: ";
	cin >> c.section;
	cout << "\n\tENTER CREDITS: ";
	cin >> c.credits;
	cout << "\n\tENTER GRADE: ";
	cin >> c.grade;

	s.add_class(c);
	update_container(s, v);			// update student entry in container
}

/**
* void add_student(vector<Student> v)
* adds a student record to the container of Students
* param v: container of Students
*/
void add_student(vector<Student>& v)
{
	Student s;
	string name;

	cout << "\n\tENTER NAME OF STUDENT: ";
	cin.get();
	getline(cin, name);

	s.set_id( v.size() + 1 );
	s.set_name(name);
	v.push_back(s);

	cout << "\tID OF " << s.get_name() << ": " << v.size() << endl;

	char ch = '0';
	do
	{
		cout << "\n\tADD A COURSE? (y/n): ";
		cin >> ch;

		if (ch == 'y')
			add_course(s, v);

	} while (tolower(ch) != 'n');
}

/**
* void change_id(Student& s)
* changes id of a current student
*/
void change_id(Student& s)
{
	int new_id;
	cout << "\n\tENTER NEW ID: ";
	cin >> new_id;

	s.set_id(new_id);
}

/**
* void change_name(Student& s)
* changes name of a current student
*/
void change_name(Student& s)
{
	string name;
	cout << "\n\tENTER NEW NAME: ";
	cin.get();
	getline(cin, name);

	s.set_name(name);
}

/**
* void change_course_subj(Course& c)
* changes subject of a current student
*/
void change_course_subj(Course& c)
{
	string subj;
	cout << "\n\tENTER NEW SUBJECT: ";
	cin.get();
	getline(cin, subj);
	for (auto& m : subj)
		m = toupper(m);

	c.subject = subj;
}

/**
* void edit_student(vector<Student> v)
* edits a student record if it exists
* param v: container of Students
*/
void edit_student(vector<Student>& v)
{
	int id;
	do
	{
		cout << "\n\tENTER STUDENT ID TO EDIT (0 TO RETURN TO MAIN MENU): ";
		cin >> id;
		if (id == 0)
			break;

		auto s = v.begin();
		for (; s != v.end(); ++s)
		{
			if (s->get_id() == id)
			{
				char ch = '0';
				do
				{
					cout << "\n\n\tSELECT WHAT YOU WISH TO EDIT ABOUT " << s->get_name() << " (0 TO RETURN)";
					cout << "\n\t1) NAME";
					cout << "\n\t2) CLASSES";
					cout << "\n\t(1-2): ";
					cin >> ch;

					switch (ch)
					{
					case '1':
						change_name(*s);
						break;

					case '2':
					{
						// display current courses
						vector<Course> existing_courses = s->get_classes();
						cout << "  ----------------------------------------\n";
						cout << "\n\tCURRENT COURSES:\n";
						if (existing_courses.empty())
							cout << "NONE\n";
						else
							for (auto c : existing_courses)
								cout << "\n" << c << endl;

						// TODO: options for adding, removing, or editing courses (switch statement)

						cout << "\n\t";


						//	string course_subj;
						//	int course_num;
						//	cout << "\n\tSELECT WHICH CLASS TO EDIT";
						//	cout << "\n\n\tSUBJECT: ";
						//	cin >> course_subj;
						//	for (auto& z : course_subj)
						//		z = toupper(z);
						//	cout << "\n\tCOURSE NUMBER: ";
						//	cin >> course_num;

						//	auto clss = existing_courses.begin();
						//	for (; clss != existing_courses.end(); ++clss)
						//	{
						//		if (clss->course_number == course_num && clss->subject == course_subj)
						//		{

						//			char sel_ch = '0';
						//			do
						//			{
						//				cout << "\n\tSELECT WHAT TO EDIT (0 TO RETURN)";
						//				cout << "\n\t1) SUBJECT";
						//				cout << "\n\t2) COURSE NUMBER";
						//				cout << "\n\t3) SECTION";
						//				cout << "\n\t4) CREDITS";
						//				cout << "\n\t5) GRADE";
						//				cout << "\n\t(1-5): ";
						//				cin >> sel_ch;

						//				switch (sel_ch)
						//				{
						//				case '1':
						//				{
						//					change_course_subj(*clss);
						//					break;
						//				}
						//				case '2':
						//				{
						//					break;
						//				}
						//				case '3':
						//				{
						//					break;
						//				}
						//				case '4':
						//				{
						//					break;
						//				}
						//				case '5':
						//					break;
						//				}

						//			} while (sel_ch != '0');
						//			break;
						//		} // end if
						//	} // end for
						//	if (clss == existing_courses.end())
						//		cout << "\n\tSTUDENT NOT ENROLLED IN COURSE";
						//	break;
					} // end case '3'
					} // end switch
				} while (ch != '0');

				break;
			} // end if
		} // end for

		  // id doesn't exist
		if (s == v.end())
			cout << "\n\tID DOESN'T EXIST";
	} while (id != 0);
}