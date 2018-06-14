#include "stdafx.h"

#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::getline; using std::string;
#include <iomanip>
using std::setprecision; using std::setw;

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
* void display_all(vector<Student> v)
* displays all students in the container v
* sorted by id, shows name, total credits and gpa nicely formatted
* param v: container of Students
*/
void display_all(vector<Student> v)
{
	
	if (v.empty())
		cout << "\nNO STUDENTS EXIST\n";
	else
	{
		cout << std::left;
		cout << "\n" << setw(3) << "ID"
			<< setw(30) << "NAME"
			<< setw(10) << "CREDITS"
			<< setw(4) << "GPA" << "\n";
		cout << "\n===============================================\n";

		cout << std::fixed << setprecision(2);
		for (Student s : v)
		{
			cout << setw(3) << s.get_id() 
				<< setw(30) << s.get_name() 
				<< setw(10) << s.get_credits()
				<< setw(4) << s.get_gpa() << "\n";
		} // end for
	} // end else
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
	for (auto &ch : c.subject)
		ch = toupper(ch);
	cout << "\n\tENTER COURSE NUMBER: ";
	cin >> c.course_number;
	cout << "\n\tENTER SECTION: ";
	cin >> c.section;
	cout << "\n\tENTER CREDITS: ";
	cin >> c.credits;
	cout << "\n\tENTER GRADE: ";
	cin >> c.grade;

	if (c.credits + s.get_credits() > 18)
		cout << "\n\tSTUDENT CANNOT EXCEED 18 CREDITS";
	else
	{
		s.add_class(c);
		update_container(s, v);			// update student entry in container
		cout << "\n\n\tCOURSE ADDED\n";
	} // end else
}

/**
  * void remove_course(Student& s, vector<Student>& v, vector<Course> exist_c)
  * removes a course from a Student using s.remove_class(Course) method
  * param s: Student to add a course to
  * param v: container of Students
  * param exist_c: container of current courses Student s is enrolled in
  */
void remove_course(Student& s, vector<Student>& v, vector<Course> exist_c)
{
	string rem_subj;
	int rem_num;

	cout << "\n\tENTER SUBJECT: ";
	cin >> rem_subj;
	// convert subject to uppercase
	for (auto &ch : rem_subj)
		ch = toupper(ch);

	cout << "\n\tENTER COURSE NUMBER: ";
	cin >> rem_num;

	Course rem_course;
	auto c = exist_c.begin();
	for (; c != exist_c.end(); ++c)
	{
		if (rem_subj == c->subject && rem_num == c->course_number)
		{
			rem_course = *c;
			break;
		}
	}

	if (c == exist_c.end())
		cout << "\n\tSTUDENT NOT ENROLLED IN COURSE\n";
	else
	{
		s.remove_class(rem_course);
		update_container(s, v);			// update student entry in container
		cout << "\n\n\tCOURSE REMOVED\n";
	}
}

/**
* void edit_course_grade(Student& s, vector<Student>& v, vector<Course> exist_c)
* edits a current Course grade that Student s is enrolled in
* param s: Student to add a course to
* param v: container of Students
* param exist_c: container of current courses Student s is enrolled in
* param subj: string subject of the course to edit
* param c_num: int course number
*/
void edit_course_grade(Student& s, vector<Student>& v, vector<Course>& exist_c)
{
	string course_subj;
	int course_num;

	cout << "\n\tSELECT WHICH CLASS GRADE TO EDIT";
	cout << "\n\n\tSUBJECT: ";
	cin >> course_subj;
	for (auto& z : course_subj)
		z = toupper(z);
	cout << "\n\tCOURSE NUMBER: ";
	cin >> course_num;

	Course c_to_edit;
	auto c = exist_c.begin();
	for (; c != exist_c.end(); ++c)
	{
		if (course_subj == c->subject && course_num == c->course_number)
		{
			float new_grade;
			cout << "\n\tENTER NEW GRADE: ";
			cin >> new_grade;

			c_to_edit = *c;
			c_to_edit.grade = new_grade;
			break;
		}
	}
	if (c == exist_c.end())
		cout << "\n\tSTUDENT NOT ENROLLED IN COURSE\n";
	else
	{
		s.edit_class_grade(c_to_edit);
		cout << "\n\n\tGRADE CHANGED\n";
		//update_container(s, v);
	}
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
	cout << "\n\n\tSTUDENT ADDED\n";
}

/**
* void remove_student(vector<Student> v)
* removes a student record from the container of Students
* param v: container of Students
*/
void remove_student(vector<Student>& v)
{
	int rem_id;
	cout << "\n\tENTER ID OF STUDENT TO REMOVE: ";
	cin >> rem_id;

	if (rem_id > v.size() || rem_id <= 0)
		cout << "\n\tINVALID ID\n";
	else
	{
		bool removed = false;
		for (auto i = 0; i < v.size(); ++i)
		{
			// update id's
			if (removed) 
			{
				v[i].set_id( v[i].get_id() - 1 );
			} // end removed if
			else
			{
				if (rem_id == v[i].get_id())
				{
					v.erase( v.begin() + i );
					removed = true;
					--i;
				} // end check id if
			} // end inner else
		} // end for
		cout << "\n\tSTUDENT REMOVED AND IDS UPDATED\n";
	} // end outer else
}

/**
* void search_student(vector<Student> v)
* searches for a Student in the container based off of user input of ID
* param v: param v: container of Students
*/
void search_student(vector<Student> v)
{
	int search_id;
	cout << "\n\tENTER ID OF STUDENT: ";
	cin >> search_id;

	if (search_id > v.size() || search_id <= 0)
		cout << "\n\tINVALID ID\n";
	else
	{
		Student found;
		for (auto i = 0; i < v.size(); ++i)
		{
			if (search_id == v[i].get_id())
			{
				found = v[i];
				break;
			} // end found if
		} // end for

		cout << "\n" << found << "\n";
	} // end else
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
	cout << "\n\n\tNAME CHANGED";
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
					cout << "\n\t   (1-2): ";
					cin >> ch;

					switch (ch)
					{
					case '1':
						change_name(*s);
						break;

					case '2':
					{
						char edit_ch;
						do
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

							cout << "\n\t1) ADD A COURSE";
							cout << "\n\t2) REMOVE A COURSE";
							cout << "\n\t3) EDIT A GRADE";
							cout << "\n\t   (1-3 OR 0 TO RETURN): ";
							cin >> edit_ch;

							switch (edit_ch)
							{
							case '1':
								add_course(*s, v);
								break;

							case '2':
								remove_course(*s, v, existing_courses);
								break;

							case '3':
								edit_course_grade(*s, v, existing_courses);
								break;
							} // end switch (edit_ch)

						} while (edit_ch != '0');
					}
					}
				} while (ch != '0');

				break;
			} // end if
		} // end for

		  // id doesn't exist
		if (s == v.end())
			cout << "\n\tID DOESN'T EXIST\n";
	} while (id != 0);
}