#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

char schedule[40][12][31][1000];

void draw_Calendar();

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

void add_Schedule()
{
	int schedule_month = 0, schedule_day = 0, schedule_year = 0; //스케줄을 입력받을 날짜을 저장하는 변수 선언
	char add_answer = 'P'; //실행을 할수있게 하는 변수 선언
	gotoxy(2, 33); // 출력 이동

	schedule_month = 0, schedule_day = 0, schedule_year = 0;
	add_answer = 'P';

	if (add_answer == 'P')
	{
		for (int i = 0; i < 59; i++) printf("="); // 분리선 생성
		printf("\n");
		printf("\n     일정을 추가하시겠습니까? ( Y / N ) : "); // 일정 추가 여부 출력
		scanf("%c", &add_answer); //add_answer에 대답저장
		printf("\n    "); //4칸 뛰어 쓰기
		for (int i = 0; i < 59; i++) printf("="); // 분리선 생성
		printf("\n");
	}

	//일정을 추가하지 않는다 했을때
	if (add_answer == 'n' || add_answer == 'N')
	{
		printf("\n        입력창을 종료합니다. \n"); //입력창 종료 전 안내문 출력
		system("cls"); //화면 지우기
		return 0; //함수 종료
	}

	//일정을 추가한다 했을 떄
	else if (add_answer == 'y' || add_answer == 'Y')
	{
		printf("\n    일정을 추가하실 날짜을 선택해주세요: "); //일정을 추가할 날짜를 입력받는다.
		scanf("%d %d %d", &schedule_year, &schedule_month, &schedule_day); //일정을 추가할 날짜를 입력받는다

		// 연도 범위 제한
		if (schedule_year > 2062 || schedule_year < 2022)
		{
			printf("\n     지원이 되지않는 범위입니다. 2022년 기준 2022 ~ 2062년 까지 입력 가능합니다.\n"); //입력할수있는 년도 범위을 안내해주는 안내문 출력
			Sleep(500); //0.5초 대기
			printf("\n    입력창을 종료합니다. 입력창을 다시 실행시켜주십시오. \n"); //입력창을 종료시킨다고 안내문을 출력한다
			Sleep(500); //0.5초 대기
			printf("\n    입력창을 종료합니다. \n"); //입력창 종료 전 안내문 출력
			Sleep(500); //0.5초 대기
			system("cls"); //콘솔화면 초기화
			return 0;

		}

		//월 범위 초과 또는 0이하
		if (schedule_month > 12 || schedule_month <= 0)
		{
			printf("\n    날짜를 다시확인 부탁드립니다.\n"); //날짜를 다시확인을 부탁하는 안내문 출력
			Sleep(500); //0.5초 대기
			printf("\n    입력창을 종료합니다. 입력창을 다시 실행시켜주십시오. \n"); //입력창을 종료시킨다고 안내문을 출력한다
			Sleep(500); //0.5초 대기
			printf("\n    입력창을 종료합니다. \n"); //입력창 종료 전 안내문 출력
			Sleep(500); //0.5초 대기
			system("cls"); //콘솔화면 초기화
			return 0;
		}

		//일 범위 초과 또는 0이하
		switch (schedule_day)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (schedule_day < 31 || schedule_day <= 0)
			{
				printf("\n      날짜를 다시확인 부탁드립니다.\n"); //날짜를 다시확인을 부탁하는 안내문 출력
				Sleep(500); //0.5초 대기
				printf("\n    입력창을 종료합니다. 입력창을 다시 실행시켜주십시오. \n"); //입력창을 종료시킨다고 안내문을 출력한다
				Sleep(500); //0.5초 대기
				printf("\n      입력창을 종료합니다. \n"); //입력창 종료 전 안내문 출력
				Sleep(500); //0.5초 대기
				system("cls"); //콘솔화면 초기화
				return 0;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (schedule_day < 30 || schedule_day <= 0)
			{
				printf("\n    날짜를 다시확인 부탁드립니다.\n"); //날짜를 다시확인을 부탁하는 안내문 출력
				Sleep(500); //0.5초 대기
				printf("\n    입력창을 종료합니다. 입력창을 다시 실행시켜주십시오. \n"); //입력창을 종료시킨다고 안내문을 출력한다
				Sleep(500); //0.5초 대기
				printf("\n      입력창을 종료합니다. \n"); //입력창 종료 전 안내문 출력
				Sleep(500); //0.5초 대기
				system("cls"); //콘솔화면 초기화
				return 0;
			}
			break;
		case 2:
			if (schedule_year % 400 == 0 || (schedule_year % 100 != 0 && schedule_year % 4 == 0)) 
			{
				if (schedule_day < 29 || schedule_day <= 0)
				{
					printf("\n    날짜를 다시확인 부탁드립니다.\n"); //날짜를 다시확인을 부탁하는 안내문 출력
					Sleep(500); //0.5초 대기
					printf("\n    입력창을 종료합니다. 입력창을 다시 실행시켜주십시오. \n"); //입력창을 종료시킨다고 안내문을 출력한다
					Sleep(500); //0.5초 대기
					printf("\n    입력창을 종료합니다. \n"); //입력창 종료 전 안내문 출력
					Sleep(500); //0.5초 대기
					system("cls"); //콘솔화면 초기화
					return 0;
				}
			}
			else
			{
				if (schedule_day < 28 || schedule_day <= 0)
				{
					printf("\n    날짜를 다시확인 부탁드립니다.\n"); //날짜를 다시확인을 부탁하는 안내문 출력
					Sleep(500); //0.5초 대기
					printf("\n    입력창을 종료합니다. 입력창을 다시 실행시켜주십시오. \n"); //입력창을 종료시킨다고 안내문을 출력한다
					Sleep(500); //0.5초 대기
					printf("\n    입력창을 종료합니다. \n"); //입력창 종료 전 안내문 출력
					Sleep(500); //0.5초 대기
					system("cls"); //콘솔화면 초기화
					return 0;
				}
			}

		}

		printf("\n    %d년 %d월 %d일의 일정을 추가해주세요! : ", schedule_year, schedule_month, schedule_day); //일정을 추가할수있게하는 문장을 출력한다.
		scanf("%s", schedule[schedule_year - 2022][schedule_month][schedule_day]); //일정을 입력받습니다
		printf("\n    일정을 추가하겠습니다.\n"); //일정을 추가하겠다는 안내문 출력
		Sleep(500); //0.5초 대기
		printf("\n    입력창을 종료합니다. \n"); //입력창 종료 전 안내문 출력
		Sleep(2000); // 2초 대기
		system("cls"); //콘솔화면 초기화
	}

	else // y 또는 n 이 아닌 문자를 입력했을경우
	{
	printf("\n     입력창을 종료합니다. 입력창을 다시 실행시켜주십시오. \n"); //입력창을 종료시킨다고 안내문을 출력한다
	Sleep(500); //0.5초 대기
	printf("\n      입력창을 종료합니다. \n"); //입력창 종료 전 안내문 출력
	Sleep(500); //0.5초 대기
	system("cls");
	}

}

void draw_start_Calendar()
{
	CursorView();
	time_t timer;
	struct tm* t;
	timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
	t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기
	int year = t->tm_year + 1900;

	printf("\n"); //한칸 뛰어쓰기
	printf("  "); // 빈칸 출력
	for (int i = 0; i < 59; i++) //'='출력 
		printf("=");
	for (int i = 0; i < 13; i++) // 줄바꿈 14번
		printf("\n");
	for (int j = 0; j < 20; j++) //빈칸 출력
		printf(" ");
	printf("  %d ", year); //연도 출력 
	printf("CALENDAR"); //캘린더 출력 
	printf("\n"); //줄바꿈
	for (int i = 0; i < 13; i++) //14번 줄바꿈
		printf("\n");
	printf("  "); //빈 칸 출력
	for (int i = 0; i < 59; i++) //'='출력 
		printf("=");

	Sleep(2000); // 2초 대기
	system("cls"); //화면 삭제
}

void view_Schedule() 
{
	gotoxy(3, 67); printf("===================================");
	gotoxy(4, 67); printf("                                   ");
	gotoxy(5, 67); printf("                                   ");
	gotoxy(6, 67); printf("                                   ");
}

void draw_Calendar() {
	time_t timer;
	struct tm* t;
	timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
	t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기

	int month = t->tm_mon + 1, i, oneweek, day = t->tm_mday, year = t->tm_year + 1900; // month : 월 관련 전체 관여, i = for문 돌리기용, oneweek = 날짜를 요일에 맞춰서 출력할 수 있게 해주는 함수, day : 상단 날짜 출력용, year : 상단 년도 출력용
	int pin_day = 1, past_day = 0, next_day = 0, reader1 = 0, reader2 = 0, next_day_oneweek = 0; // pin_day : 달력 출력용, past_day : 저번 달 날짜 출력용, nex_day : 다음 달 날짜 출력용, reader1, 2 : 달력 높이 조절용, next_day_oneweek : 다음 달 날짜 요일 출력 도우미
	char q = 'd'; //입력 받는 용도

	while (day > 7)//1일로부터 
		day -= 7;
	oneweek = t->tm_wday - day + 2;
	if (oneweek <= 0) {
		oneweek += 7;
	}
	//+ 2를 하는 이유 : 일요일이 첫번째 숫자인 기준으로 이 코드의 oneweek 변수의 단위는 1 ~ 7인데, tm_wday 함수의 단위는 0 ~ 6이라 + 1을 해 줘야 하고
	//1일 기준으로 흐른 날짜는 오늘 날짜 - 1이기 때문에 + 1을 또 해서 + 2이다

	day = t->tm_mday; //oneweek 초기화를 위해 day 값을 변경했으므로 day 값을 다시 초기화

	while (1) {
		

		// 'd', 'D', 'a', 'A', 'w', 'W', 's', 'S'를 눌렀으면 달력 출력
		if (q == 'd' || q == 'D' || q == 'a' || q == 'A' || q == 'w' || q == 'W' || q == 's' || q == 'S' || q == 'c' || q == 'C' ) {
			printf("\n\t\t\t%4d년\t%2d월 %2d일\n", year, month, day);
			printf("\n    ");
			for (i = 0; i < 59; i++)
				printf("=");
			printf("\n\n\n");
			printf("\tSun\tMon\tTue\tWed\tThu\tFri\tSat\n\n\n");
			pin_day = 1;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); //저번 달 날짜 회색으로 출력


			// 저번 달 날짜 출력
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
						past_day = 31 - oneweek + 2; // 저번 달이 31일 일 경우
						break;
					case 5:
					case 7:
					case 10:
					case 12:
						past_day = 30 - oneweek + 2; // 저번 달이 30일 일 경우
						break;
					case 3:
						past_day = 28 - oneweek + 2; // 저번 달이 28일 일 경우
						if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) // 윤년
							past_day++;
						break;
					}
				}
				printf("\t%2d", past_day);
				past_day++;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 색 다시 흰색으로 바꾸기


			// 이번 달 날짜 출력
			switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				for (; pin_day <= 31; pin_day++) { // 31일인 달
					printf("\t%2d", pin_day);
					oneweek++;
					if (oneweek > 7) {
						printf("\n\n\n\n");
						oneweek = 1;
					}
				}
				oneweek -= 3;
				break;


			case 4:
			case 6:
			case 9:
			case 11:
				for (; pin_day <= 30; pin_day++) { // 30일인 달
					printf("\t%2d", pin_day);
					oneweek++;
					if (oneweek > 7) {
						printf("\n\n\n\n");
						oneweek = 1;
					}
				}
				oneweek -= 2;
				break;


			case 2:
				if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) { // 윤년
					for (; pin_day <= 29; pin_day++) {
						printf("\t%2d", pin_day);
						oneweek++;
						if (oneweek > 7) {
							printf("\n\n\n\n");
							oneweek = 1;
						}
					}
					oneweek -= 1;
				}

				else {
					for (; pin_day <= 28; pin_day++) { // 28일인 달
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



			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // 글자 색 다시 회색으로 변경


			// 다음 달 날짜 출력
			next_day = 1;
			reader1 = 0;
			reader2 = 0;
			next_day_oneweek = 0;

			switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				next_day_oneweek += 3;//(이번 달 - 28)만큼 더하기;
				break;
			case 2:
				if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
					next_day_oneweek++;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				next_day_oneweek += 2;
				break;
			}

			//다음 달 날짜가 특정 위치에서 멈추게 하는 함수
			for (i = oneweek + next_day_oneweek; i < 15; i++) {
				printf("\t%2d", next_day);
				next_day++;
				reader1++;
				if (i == 7) {
					switch (month) {
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12:
						if (reader1 < 5)
							reader2 = 1;
						break;
					case 4:
					case 6:
					case 9:
					case 11:
						if (reader1 < 6)
							reader2 = 1;
						break;
					case 2:
						if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) { // 윤년
							if (reader1 < 7)
								reader2 = 1;
						}
						else
							if (reader1 < 8)
								reader2 = 1;
					}
					if (reader2 == 1)
						printf("\n\n\n\n");
					else
						break;
				}
			}
		}


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //글자 색 다시 흰색으로 변경
		;

		q = _getch(); // q에 문자를 입력 받음

		// 'd'나 'D'를 누르면 다음달 달력으로 변경
		if (q == 'd' || q == 'D') {
			switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				oneweek += 3;//(이번 달 - 28)만큼 더하기;
				break;
			case 2:
				if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
					oneweek++;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				oneweek += 2;
				break;
			}
			month++;
			if (month == 13) {
				month = 1;
				year++;
			}


			COORD pos = { 0 , 0 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			//system("cls");
		}

		// 'a'나 'A'를 누르면 저번달 달력으로 변경
		else if (q == 'a' || q == 'A') {
			month--;
			if (month < 1) {
				month += 12;
				year--;
			}
			switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				oneweek -= 3;//(저번 달 - 28)만큼 빼기;
				break;
			case 2:
				if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
					oneweek--;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				oneweek -= 2;
				break;
				//oneweek는 날짜를 요일에 맞춰 출력하기 위한 함수이고 달력 출력이 끝났을 때 그 달에 1일의 요일에 위치해 있는데,
				//그려먼 저번 달에 관점에서 보면 다음 달의 1일, 즉 마지막 날의 다음 요일 위치에 oneweek가 위치해 있으므로,
				//저번 달 - 28을 하면 저번 달의 1일의 위치로 oneweek가 간다.
			}

			if (oneweek <= 0)
				oneweek += 7;



			COORD pos = { 0 , 0 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			//system("cls");
		}

		//'w'나 'W'를 누르면 년도가 증가
		if (q == 'w' || q == 'W') {
			year++;
			oneweek++;
			if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && month > 2 || (year % 400 == 1 || (year % 100 != 1 && year % 4 == 1)) && month < 3)
				oneweek++;

			if (oneweek < 1)
				oneweek += 7;
			if (oneweek > 7)
				oneweek -= 7;

			COORD pos = { 0 , 0 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			//system("cls");
		}

		//'s'나 'S'를 누르면 년도가 증가
		if (q == 's' || q == 'S') {
			oneweek--;
			if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && month > 2 || (year % 400 == 1 || (year % 100 != 1 && year % 4 == 1)) && month < 3)
				oneweek--;
			year--;

			if (oneweek < 1)
				oneweek += 7;
			COORD pos = { 0 , 0 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			//system("cls");
		}

		// c를 눌렀을때 add_Schedule함수 실행( Creaate Schdeule ) 
		if (q == 'c' || q == 'C')
		{
			add_Schedule();
		}

		// 지정한 키 제외하고 다른 키를 누르면 응답 안하게 설정
		else {
			printf("");
		}
	}
}

int main()
{
	CursorView();
	system("mode con cols=115 lines=50");
	draw_start_Calendar(); //달력의 첫화면 출력
	draw_Calendar(); //달력출력
}
