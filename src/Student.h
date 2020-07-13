/*
 * Student.h
 *
 *  Created on: 2020Äê7ÔÂ13ÈÕ
 *      Author: cxz
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include<iostream>
using namespace std;

struct Student{
	string name;
	int score;
	bool operator<(const Student& t){
		return (score!=t.score)?(score>t.score):(name<t.name);
	}
	friend ostream& operator<<(ostream& os,const Student& student){
		os<<"Student:"<<student.name<<" "<<student.score<<endl;
		return os;
	}
};




#endif /* STUDENT_H_ */
