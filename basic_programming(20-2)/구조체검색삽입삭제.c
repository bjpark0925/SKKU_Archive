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
STUDENT students[100];
int studentsCount = 0;

int insertStruct();

STUDENT deleteStruct(int);

//updateStruct();
int retrieveStruct(int);

void printAll();

int main()
{
	int nNumber, nIndex;
	STUDENT returnData;

	//insert
	for (int i = 0; i < 3; i++) insertStruct();
	printAll();

	// delete
	printf("delete number >> ");
	scanf("%d", &nNumber);
	returnData = deleteStruct(nNumber);
	if (returnData.nSchoolNumber < 0) {
		printf("NOT FOUND!!\n\n");
	}
	else {
		printAll();
		printf("DELETED!!\n\n");
		printf("------------------------------------------------------------\n");
		printf("%13d | %10s | %10s | %6.2lf\n",
			returnData.nSchoolNumber,
			returnData.strDepartment,
			returnData.strName,
			returnData.lfGrade);
	}

	// update => 찾아서 delete하고 insert하기

	//retrieve
	printf("retrieve number >> ");
	scanf("%d", &nNumber);

	nIndex = retrieveStruct(nNumber);

	if (nIndex < 0) {
		printf("NOT FOUND!!\n\n");
	}
	else {
		printf("FOUND!!\n\n");
		printf("------------------------------------------------------------\n");
		printf("%13d | %10s | %10s | %6.2lf\n",
			students[nIndex].nSchoolNumber,
			students[nIndex].strDepartment,
			students[nIndex].strName,
			students[nIndex].lfGrade);
	}

	return 0;
}

void printAll()
{
	system("cls");
	printf("\n\n");
	printf("============================================================\n");
	printf("%13s | %10s | %10s | %6s\n", "School Number", "Department", "Name", "Grade");

	for (int i = 0; i < studentsCount; i++) {
		printf("------------------------------------------------------------\n");
		printf("%13d | %10s | %10s | %6.2lf\n",
			students[i].nSchoolNumber,
			students[i].strDepartment,
			students[i].strName,
			students[i].lfGrade);
	}
	printf("============================================================\n");

	return 0;
}

int insertStruct()
{
	printf("School Number >> ");
	scanf("%d", &students[studentsCount].nSchoolNumber);
	printf("Department >> ");
	scanf("%s", students[studentsCount].strDepartment);
	printf("Name >> ");
	scanf("%s", students[studentsCount].strName);
	printf("Grade >> ");
	scanf("%lf", &students[studentsCount++].lfGrade);

	//studentsCount++;

	return 1;

}//insertStruct()

int retrieveStruct(int number)
{

	int result = -1;

	for (int i = 0; i < studentsCount; i++) {
		if (number == students[i].nSchoolNumber) {
			result = i;
			break;
		}

	}

	return result;
}//retrieveStruct()

STUDENT deleteStruct(int number)
{
	STUDENT result;
	int index;

	index = retrieveStruct(number);
	if (index < 0) {
		result.nSchoolNumber = -1;
	}
	else {
		result = students[index];
		students[index] = students[studentsCount-1];
		studentsCount--;
	}

	return result;

}//deleteStruct
