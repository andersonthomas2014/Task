#pragma once
#include <iostream>
#include <cmath>
#include<string>
#include<cstring>
class Student
{
private: char *Name, *Surname, *Middle_name, *DOB, *Address, *P_Number, *Faculty; char Course;
	   /*В конце решил пусть будет закрытым конструктор копирования*/
	   Student(const Student &student) : 
		   Name(student.Name), Surname(student.Surname), Middle_name(Middle_name), 
		   DOB(student.DOB), Address(student.Address), P_Number(student.P_Number),
		   Faculty(student.Faculty), Course(student.Course)
	   {

	   }
public: 
	/*Конструктор по умолчанию*/
	Student() {
	Name = new char[64]{""};
	Surname = new char[64]{"No_SurName"};
	Middle_name = new char[64]{ "No_Middle_name" };
	DOB = new char[64]{ "No_DOB" };
	Address = new char[64]{ "No_Address" };
	P_Number = new char[64]{ "No_P_Number" };
	Faculty = new char[64]{ "No_Faculty" };
	Course=0;
	}
	/*Деструктор*/
	~Student() {
		delete[] Name; 
		delete[] Surname; 
		delete[] Middle_name; 
		delete[] DOB; 
		delete[] Address; 
		delete[] P_Number; 
		delete[] Faculty; 
		
	  }
	/*Соответствующие геттеры*/
	const char* getName() const { return Name; }
	const char* getSurname() const { return Surname; }
	const char* getMiddle_name() const { return Middle_name; }
	const char* getDOB() const { return DOB; }
	const char* getAddress() const { return Address; }
	const char* getP_Number() const { return P_Number; }
	const char* getFaculty() const { return Faculty; }
	char getCourse() { return Course; }
	/*И сеттеры*/
	void setName(char* str) {  strcpy_s(Name, 64, str); }
	void setSurname(char* str) {   strcpy_s(Surname, 64, str); }
	void setMiddle_name(char* str) {   strcpy_s(Middle_name, 64, str); }
	void setDOB(char* str) {  strcpy_s(DOB, 64, str); }
	void setAddress(char* str) {  strcpy_s(Address, 64,str); }
	void setP_Number(char* str) {   strcpy_s(P_Number, 64, str); }
	void setFaculty(char* str) {  strcpy_s(Faculty, 64, str); }
	void setCourse(char str) { Course = str; }

	
};

