#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

char schedule[40][12][31];

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

void Schedule()
{
	int schedule_month, schedule_day;
	printf("\n\n\n");
	printf("일정을 추가하실 날짜를 입력해주세요 (M / D) (뛰어 쓰기 필수!!) >> ");
	scanf("%d / %d", &schedule_month, &schedule_day);


}

void draw_start_Calendar()
{
    //현재 날짜 구하기
	CursorView();
	time_t timer;
	struct tm* t;
	timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
	t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기
	int year = t->tm_year;

	// 켈린더의 첫 시작화면을 출력합니다
	printf("\n");
	printf("  "); //2칸 뛰어쓰기
	for (int i = 0; i < 59; i++) // '=' 59번 출력
		printf("=");
	for (int i = 0; i < 13; i++) // 13줄 \n
		printf("\n");
	for (int j = 0; j < 20; j++) // 20칸 뛰기
		printf(" ");
	printf("  %d ", year); // 현재 년도 출력
	printf("CALENDAR");
	printf("\n");
	for (int i = 0; i < 13; i++) //13줄 \n
		printf("\n");
	printf("  "); // 2칸 뛰어 쓰기
	for (int i = 0; i < 59; i++) // '=' 59번 출력
		printf("=");
}

void draw_Calendar() {
    time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기
    int month = t->tm_mon + 1, i, oneweek = t->tm_wday - 1, day = t->tm_mday, year = t->tm_year + 1900, pin_day = 1, past_day = 0, reader = 0;//day : 상단 출력용, pin_day : 달력 출력용
    char q = 'd';


    while (1) {
        CursorView();

        if (q == 'd' || q == 'D' || q == 'a' || q == 'A') {
            printf("\n\t\t\t%4d년\t%2d월 %2d일\n", year, month, day);
            printf("\n ");
            for (i = 0; i < 59; i++)
                printf("=");
            printf("\n\n\n");
            printf("\tSun\tMon\tTue\tWed\tThu\tFri\tSat\n\n\n");
            pin_day = 1;

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

            for (i = 1; i < oneweek; i++) {
                if (i == 1) {
                    switch (month) {
                    case 1:
                    case 2:
                    case 4:
                    case 6:
                    case 8:
                    case 9:
                    case 11:
                        past_day = 31 - oneweek + 2;
                        break;
                    case 5:
                    case 7:
                    case 10:
                    case 12:
                        past_day = 30 - oneweek + 2;
                        break;
                    case 3:
                        past_day = 28 - oneweek + 2;
                        if (year % 400 == 0 && year % 100 == 0 || year % 4 == 0)
                            past_day++;
                        break;
                    }
                }
                printf("\t%2d", past_day);
                past_day++;
            }

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                for (; pin_day <= 31; pin_day++) {
                    printf("\t%2d", pin_day);
                    oneweek++;
                    if (oneweek > 7) {
                        printf("\n\n\n\n");
                        oneweek = 1;
                    }
                }
                break;


            case 4:
            case 6:
            case 9:
            case 11:
                for (; pin_day <= 30; pin_day++) {
                    printf("\t%2d", pin_day);
                    oneweek++;
                    if (oneweek > 7) {
                        printf("\n\n\n\n");
                        oneweek = 1;
                    }
                }
                break;


            case 2:
                if (year % 400 == 0 && year % 100 == 0 || year % 4 == 0) {
                    for (; pin_day <= 29; pin_day++) {
                        printf("\t%2d", pin_day);
                        oneweek++;
                        if (oneweek > 7) {
                            printf("\n\n\n\n");
                            oneweek = 1;
                        }
                    }
                }

                else {
                    for (; pin_day <= 28; pin_day++) {
                        printf("\t%2d", pin_day);
                        oneweek++;
                        if (oneweek > 7) {
                            printf("\n\n\n\n");
                            oneweek = 1;
                        }
                    }
                }
                break;
            }
        }


        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

        past_day = 1;
        reader = 0;
        for (i = oneweek; i < 15; i++) {
            printf("\t%2d", past_day);
            past_day++;
            reader++;
            if (i == 7) {
                if (reader < 5)
                    printf("\n\n\n\n");
                else
                    break;
            }
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        gotoxy(4, 10);
        printf("---");
        q = _getch();

        if (q == 'd' || q == 'D') {
            month++;
            if (month == 13) {
                month = 1;
                year++;
            }

            //COORD pos = { 0 , 0 };
            //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            system("cls");
        }

        else if (q == 'a' || q == 'A') {
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

            //COORD pos = { 0 , 0 };
            //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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
	Schedule();
}
