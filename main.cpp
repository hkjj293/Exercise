#include <iostream>
//#include <time.h>
#include "l1.h"
#include "l2.h"
#include "l3.h"
#include "l4.h"
#include "l5.h"
#include "l6.h"
#include "l7.h"
#include "l8.h"
#include "l9.h"
//#include "exercise.h"

const int LESSON_DONE = 9;

void lessons_init(lesson**& lessons);
void terminate_lessons(lesson**& lessons);

int main()
{
	lesson** lessons;
	lessons_init(lessons);
	/*
	for (int i = 0; i < LESSON_DONE; i++) {
		lessons[i]->ans();
	}
	*/
	lessons[8]->ans();
	terminate_lessons(lessons);
	return 0;
}

void lessons_init(lesson**& lessons) {
	lessons = new lesson* [LESSON_DONE];
	lessons[0] = (lesson*)new l1();
	lessons[1] = (lesson*)new l2();
	lessons[2] = (lesson*)new l3();
	lessons[3] = (lesson*)new l4();
	lessons[4] = (lesson*)new l5();
	lessons[5] = (lesson*)new l6();
	lessons[6] = (lesson*)new l7();
	lessons[7] = (lesson*)new l8();
	lessons[8] = (lesson*)new l9();
}

void terminate_lessons(lesson**& lessons) {
	for (int i = 0; i < LESSON_DONE; i++) {
		delete lessons[i];
		lessons[i] = NULL;
	}
	delete[] lessons;
	lessons = NULL;
}



