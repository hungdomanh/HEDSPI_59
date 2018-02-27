#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME data[i].name
#define ENG  data[i].eng
#define MATH data[i].math
#define PHYS data[i].phys
#define MEAN data[i].mean

struct student{
	char name[20];
	int eng;
	int math;
	int phys;
	double mean;
};

static struct student data[]={
	{"Tuan", 82, 72, 58, 0.0},
	{"Nam", 77, 82, 79, 0.0},
	{"Khanh", 52, 62, 39, 0.0},
	{"Phuong", 61, 82, 88, 0.0}
}; 

// FUNCTION & PROCEDUCE
void PrintAvgScore();
void PrintGrade();
char GetGrade(int mean) {
	if (mean <= 100) {
		if (mean < 90) {
			if (mean < 80) {
				if (mean < 70) {
					if (mean < 60) {
						return 'D';
					}
					return 'C';
				}
				return 'B';
			}
			return 'A';
		}
		return 'S';
	}
}

// MAIN
void main() {
	printf("---------- 2A:\n");
	PrintAvgScore();
	printf("---------- 2B:\n");
	PrintGrade();
	printf("\n");
}

void PrintAvgScore() {
	int leng = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < leng; ++i) {
		MEAN = ((float)ENG + (float)MATH + (float)PHYS) / 3 ;

		printf("%20s\t %d\t %d\t %d\t %.1f\t \n", NAME, ENG, MATH, PHYS, MEAN);
	}
}

void PrintGrade() {
	int leng = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < leng; ++i) {
		MEAN = ((float)ENG + (float)MATH + (float)PHYS) / 3 ;

		printf("%20s\t %d\t %d\t %d\t %.1f\t %c\t \n", NAME, ENG, MATH, PHYS, MEAN, GetGrade(MEAN));
	}
}
