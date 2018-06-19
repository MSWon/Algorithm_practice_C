#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 

typedef struct
{
	char type;
	char security[14];
	char country[16];
	char name[16];
	int age;
	float gpa;

} STUDENT;


int main()
{
	STUDENT student[10];
	int state;
	int j;
	int i;
	float gpa;
	char res;
	char str[200];
	char *copy;
	char *pToken;
	char str2[200];



	FILE *fpp;
	FILE *out;

	fpp = fopen("C:\\Users\\Big Data Guru\\Desktop\\input.txt", "r");

	if (fpp == NULL) {
		printf("File open Error!");
		return 1;
	}

	for (i = 0; i <10; i++) {

		fgets(str, sizeof(str), fpp);

		str[strlen(str) - 1] = '\0';

		student[i].type = str[0];

		pToken = strtok(str, "  ");




		if (student[i].type == 'K') {

			pToken = strtok(NULL, "  ");
			for (j = 0; j < 15; j++)
			{
				student[i].security[j] = pToken[j];
			}

		}
		else if (student[i].type == 'F') {

			pToken = strtok(NULL, "  ");
			for (j = 0; j < 17; j++)
			{
				student[i].country[j] = pToken[j];
			}

		}



		pToken = strtok(NULL, "  ");
		for (j = 0; j < 17; j++)
		{
			student[i].name[j] = pToken[j];
		}


		pToken = strtok(NULL, "  ");
		student[i].age = strtol(pToken, NULL, 10);



		pToken = strtok(NULL, "  ");
		student[i].gpa = atof(pToken);


	}


	state = fclose(fpp);

	if (state != 0)
	{
		printf("File close Error!");
		return 1;
	}

	int min = 100;
	int tmp;

	for (i = 1; i < 10; i++)
	{
		if (student[i].type == 'F')
		{
			if (student[i].age < min) {
				min = student[i].age;
				tmp = i;
			}
		}
	}


	float max = -100;
	int cmp;

	for (i = 1; i < 10; i++)
	{
		if (student[i].type == 'K')
		{
			if (student[i].gpa > max) {
				max = student[i].gpa;
				cmp = i;
			}
		}
	}


	out = fopen("C:\\Users\\Big Data Guru\\Desktop\\output.txt", "w");

	fprintf(out, "Information of youngest student among foreign students\n");
	fprintf(out, "Name of student:%s\n", student[tmp].name);
	fprintf(out, "Age of student:%d\n", student[tmp].age);
	fprintf(out, "GPA of student:%.2f\n", student[tmp].gpa);
	fprintf(out, "Country of student:%s\n", student[tmp].country);

	fprintf(out, "Information of student with highest GPA among korean students\n");
	fprintf(out, "Name of student:%s\n", student[cmp].name);
	fprintf(out, "Age of student:%d\n", student[cmp].age);
	fprintf(out, "GPA of student:%.2f\n", student[cmp].gpa);
	fprintf(out, "Country of student:%s\n", student[cmp].security);

	fclose(out);

	return 0;
}