#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x, int y)
{
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw_start_Calendar()
{
	CursorView();
	time_t timer;
	struct tm* t;
	timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
	t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기
	int year = t->tm_year;

	printf("\n");
	printf("  ");
	for (int i = 0; i < 59; i++)
		printf("=");
	for (int i = 0; i < 13; i++)
		printf("\n");
	for (int j = 0; j < 20; j++)
		printf(" ");
	printf("  %d ", year);
	printf("CALENDAR");
	printf("\n");
	for (int i = 0; i < 13; i++)
		printf("\n");
	printf("  ");
	for (int i = 0; i < 59; i++)
		printf("=");
}

void draw_Calendar() {
	//현재 시간 구하기
	time_t timer;
	struct tm* t;
	timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
	t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기

	int month = t->tm_mon + 1, i, oneweek = t->tm_wday - 1, day = t->tm_mday, year = t->tm_year + 1900, pin_day = 1; //현재시간을 각각의 변수에 대입 한다 ( + 영기 변수에 대해 주석 달아줘)
	char q = 'd'; //주석 필요


	while (1) {
		CursorView(); //Cosor를 보이지않게 한다
		if (q == 'd' || q == 'D' || q == 'a' || q == 'A') {
			printf("\n\t\t\t%4d년\t%2d월 %2d일\n", year, month, day);
			printf("\n ");
			for (i = 0; i < 59; i++)
				printf("=");
			printf("\n\n\n");
			printf("\tSun\tMon\tTue\tWed\tThu\tFri\tSat\n\n\n");
			pin_day = 1; //현재의 시간을 구해 달력의 위부분을 그린다


			switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: //31일 까지있는 달의 달력를 그린다
				for (; pin_day <= 31; pin_day++) {
					if (pin_day == 1)
						for (i = 1; i < oneweek; i++)
							printf("\t");
					printf("\t%2d", pin_day);
					oneweek++;
					if (oneweek > 7) {
						printf("\n\n\n\n");
						oneweek = 1;
					}
				}
				printf("\n\n\n");
				break;


			case 4:
			case 6:
			case 9:
			case 11: // 30일 까지있는달의 달력을 그린다
				for (; pin_day <= 30; pin_day++) {
					if (pin_day == 1)
						for (i = 1; i < oneweek; i++)
							printf("\t");
					printf("\t%2d", pin_day);
					oneweek++;
					if (oneweek > 7) {
						printf("\n\n\n\n");
						oneweek = 1;
					}
				}
				printf("\n\n\n");
				break;


			case 2: //2월달의 달력을 그린다
				if (year % 400 == 0 && year % 100 == 0 || year % 4 == 0) //윤년을 구한다  
				{
					for (; pin_day <= 29; pin_day++) //윤년의 2월 달력 그리기
					{
						if (pin_day == 1)
							for (i = 1; i < oneweek; i++)
								printf("\t");
						printf("\t%2d", pin_day);
						oneweek++;
						if (oneweek > 7) {
							printf("\n\n\n\n");
							oneweek = 1;
						}
					}
					printf("\n\n\n");
				}

				else //윤년이 아닌 년도의 2월 달력구하기 
				{
					for (; pin_day <= 28; pin_day++) {
						if (pin_day == 1)
							for (i = 1; i < oneweek; i++)
								printf("\t");
						printf("\t%2d", pin_day);
						oneweek++;
						if (oneweek > 7) {
							printf("\n\n\n\n");
							oneweek = 1;
						}
					}
					printf("\n\n\n");
				}
				break;
				printf("\n\n\n");
				break;
			}
		}

		gotoxy(4, 10);
		printf("---");
		q = _getch(); //변수 q를 버퍼없이 입력받는다

		if (q == 'd' || q == 'D') // d 또는 D를 입력받으면 Month가 앞으로 한달 이동한다
		{
			month++;
			if (month == 13) {
				month = 1;
				year++;
			}
			system("cls");
		}
		else if (q == 'a' || q == 'A') // A 또는 a를 입력받으면 Month가 뒤로 한달 이동한다
		{
			switch (month) {
			case 2:
			case 3:
				oneweek -= 3;
				if (year % 400 == 0 && year % 100 == 0 || year % 4 == 0)
					oneweek--;
				break;
			case 4:
			case 5:
			case 6:
			case 7:
			case 9:
			case 10:
			case 11:
			case 12:
				oneweek -= 5;
				break;
			case 1:
			case 8:
				oneweek -= 6;
				break;
			}
			month--;
			if (oneweek <= 0)
				oneweek += 7;
			if (month == 0) {
				month = 12;
				year--;
			}
			system("cls");
		}
		else {
			printf("");
		}
		pin_day = 1;

	}
}



int main()
{
	draw_start_Calendar(); //달력의 첫화면 출력

	Sleep(2000); // 2초 대기
	system("cls"); //화면 삭제
	
	draw_Calendar(); //달력출력

}
