#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define MAX 1000


bool isLettersRepeating(const char *firstLetter, const char *secondLetter);
/*� ���������� ������ �������� ������ ��  �����, � ������� ����������� ������ ������ ���������� �����*/
int  main(){
	system("chcp 1251");


	char line[MAX];
	int found = 0;
	printf("������� ������\n");
	fgets(line, MAX,stdin);

	char *firstLetter;                                     
	char *secondLetter;                                     
	char *space;                                   
	firstLetter = &line[0];
	secondLetter = &line[1];
	space = firstLetter ;                             
	

	do                                              
	{
		secondLetter++;
		firstLetter++;
		if (isLettersRepeating(firstLetter,secondLetter))                     
		{
			found = 1;                             
		}
		if ((*secondLetter == ' ') || (*secondLetter == '\0'))       

		{

			if (found == 0)                            
			{
				firstLetter = space;                        
				while ((*space++ = *secondLetter++) != '\0');
				secondLetter = firstLetter + 1;                     
				space = firstLetter;
			}
			else
			{
				space = secondLetter;
				found = 0;
			}
		}
		
	} while (*firstLetter != '\0');
	printf("������ �� ������� ��� ������������� ����\n");
	puts(line);                                 //����� ����������
	system("pause");	
}
bool isLettersRepeating(const char *firstLetter, const char *secondLetter) {
	if ((*firstLetter == *secondLetter) && (((*firstLetter >= 'A')
		&& (*firstLetter <= 'Z')) || ((*firstLetter >= 'a')
		&& (*firstLetter <= 'z') || ((*firstLetter >= '�')
		&& (*firstLetter <= '�') || ((*firstLetter >= '�')
		&& (*firstLetter <= '�')))))) {
		return true;
	}
	return false;
}