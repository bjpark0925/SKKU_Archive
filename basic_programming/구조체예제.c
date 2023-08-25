#pragma warning (disable:4996)
#include <stdio.h>

//define
typedef struct Student_Info {
	int nSchoolNumber;
	char strDepartment[40];
	char strName[40];
	double lfGrade;
}STUDENT;

//declare
//struct Student_Info student1;
STUDENT student1[5] = {
	{200012456,"Computer", "Hong", 4.3},
	{200022456,"Education", "Han", 4.0},
	{200032456,"Computer", "Son", 3.8},
	{200042456,"Education", "Kang", 4.1},
	{200052456,"Computer", "Kim", 3.4}
};

int main()
{
	STUDENT* pStudent;
	pStudent = student1;
	/*printf("School Number >> ");
	scanf("%d", &student1.nSchoolNumber);
	printf("Department >> ");
	scanf("%s", student1.strDepartment);
	printf("Name >> ");
	scanf("%s", student1.strName);
	printf("Grade >> ");
	scanf("%lf", &student1.lfGrade);
	*/

	printf("============================================================\n");
	printf("%13s | %10s | %10s | %6s\n", "School Number", "Department", "Name", "Grade");

	for (int i = 0; i < 5; i++, pStudent++) {
		printf("------------------------------------------------------------\n");
		printf("%13d | %10s | %10s | %6.2lf\n",
			pStudent -> nSchoolNumber,
			student1[i].strDepartment,
			student1[i].strName,
			student1[i].lfGrade);
	}
	printf("============================================================\n");

	return 0;
}