#include <stdio.h>
#include <windows.h>

int main()
{
	int mon = 6, j = 1,k = 1;
	// ó��ȭ�� ���
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
	Sleep(1700); //2�� ���
	system("cls"); //�ܼ�ȭ�� �����

	printf("                                  2022�� %d��                               \n", mon);
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