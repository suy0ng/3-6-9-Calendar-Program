#include <stdio.h>
#include <windows.h>

int main()
{
	int mon = 6, j = 1,k = 1;
	// 처음화면 출력
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("              =====================================================             \n");
	printf("                          2022                 CALANDER                         \n");
	printf("              =====================================================             \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	Sleep(1700); //2초 대기
	system("cls"); //콘솔화면 지우기

	printf("                                  2022년 %d월                               \n", mon);
	printf("     ===============================================================       \n");
	printf("  \tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT          \n");

	for (int i = 1; i < 6; i++) 
	{
		printf("   \t");
		for (j = 1 ; j < 8; j++)
		{
			printf("%d\t", k);
			k++;
			if (k > 30) break;
		}
		printf("\n");
	}

}