#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME data[i].name
#define ENG  data[i].eng
#define MATH data[i].math
#define PHYS data[i].phys
#define MEAN data[i].mean

typedef struct student{
	char name[20];
	int eng;
	int math;
	int phys;
}STUDENT;

STUDENT data[]={
	{"Tuan", 82, 72, 58},
	{"Nam", 77, 82, 79},
	{"Khanh", 52, 62, 39},
	{"Phuong", 61, 82, 88}
};

STUDENT *p;

// MAIN
void main() {
	p = &data[0];

	int leng = sizeof(data) / sizeof(data[0]);

	printf("------------- 2C:\n");
	for (int i = 0; i < leng ; ++i) {
		printf("%20s\t %d\t %d\t %d\t \n", NAME, ENG, MATH, PHYS);
      	p++;
	}
	printf("\n");
}
