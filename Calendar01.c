#include <stdio.h>
#include <windows.h>
#include <time.h>

enum Days {SUN,MON,TUE,WED,THU,FRI,SAT};

int main()
{
	time_t timer;
	struct tm* t;
	timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
	t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기

	
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


}
