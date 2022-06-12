/* 202201465 박유진 컴퓨터 프로그래밍 과제 코로나 관련 프로그램 작성하기
먼저 메뉴에서 얻고자 하는 정보의 번호를 받는다. (1번 지역별 확진자 수, 2번 총 확진자 수, 3번 거리두기 정보, 4번 종료)
보기 외의 다른 번호를 입력한다면 다시 입력받는다.
1번을 선택한다면 원하는 지역(서울, 부산, 제주, 대구, 경기, 강원)을 하나 선택하여 그 지역의 확진자 수와 어제와 비교하여 증감을 알려준다.
보기 외의 다른 번호를 입력한다면 다시 입력받는다. 
2번을 선택한다면 오늘의 총 확진자 수를 알려준다.
3번을 선택한다면 원하는 거리두기(1단계, 2단계, 3단계, 4단계, 위드코로나)에 대한 정보를 알려준다.
보기 외의 다른 번호를 입력한다면 다시 입력받는다.
4번을 선택한다면 종료한다.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "covidregion.h"
int menu, menu1, menu3; //메뉴는 가장 첫번째 선택받는 보기의 번호를 저장하는 변수, 메뉴1은 1번에서 지역을 선택할때의 번호를 저장하는 변수, 메뉴3은 3번에서 거리두기를 선택할때 저장하는 변수
int region_seoul6[30] = { 1000, 1250, 1300, 1400, 1500, 1350, 1200, 1000, 900, 920, 850, 920}; //서울의 6월 한달동안 1일부터 차례로 확진자 수 나열 (현재날짜 6/12 기준)
int region_busan6[30] = { 900, 750, 500, 600, 750, 800, 950, 150, 300, 600, 750 ,800}; //부산의 6월 한달동안 확진자수 차례로 나열
int region_jeju6[30] = { 250, 300, 500, 600, 750, 200, 460, 290, 600, 500, 700, 650 }; //제주도의 6월 한달동안 확진자수 차례로 나열
int region_daegu6[30] = { 460, 490, 520, 600, 520, 600, 530, 470, 400, 380, 360 ,280}; //대구의 6월 한달동안 확진자수 차례로 나열
int region_gyeonggi6[30] = { 1200, 1150, 1320, 1280, 1190, 1210, 1400, 1560, 1450, 1600, 1640 ,1500}; //경기도의 6월 한달동안 확진자수 차례로 나열
int region_gangwon6[30] = { 1000, 950, 920, 1200, 1100, 1200, 1050, 1200, 950, 890, 990, 1100 }; //강원도의 6월 한달동안 확진자수 차례로 나열 
struct distance { //거리두기의 정보를 따로 저장하는 구조체
	char name[30]; //거리두기 명칭
	char condition[250]; //거리두기 조건
	char content[250]; //거리두기 내용
	char now[50]; //거리두기의 현재 적용 상태
};
int main() {
	struct distance lv1 = { "지속적 억제상태 유지","전국 500명 미만/수도권 250명 미만","밀집/밀폐/밀접 방지를 위한 시설별 개인별 방역 수칙 준수","적용안됨"}; //거리두기 1단계
	struct distance lv2 = { "지역 유행","전국 500명 이상/ 수도권 250명 이상","이용인원 제한","적용안됨" }; //거리두기 2단계
	struct distance lv3 = { "권역 유행","전국 1000명 이상/ 수도권 500명  이상","사적 모임 금지","적용안됨" }; //거리두기 3단계
	struct distance lv4 = { "대유행","전국 2000명 이상/ 수도권 1000명 이상","외출 금지/집에서 머무르기","적용안됨" }; //거리두기 4단계
	int (*pf)(int, int); //함수를 가르킬 함수포인터 선언
	pf = day_diff; 
	while (1) { //4번을 선택하기 전까지는 계속 반복함
	start1:
		menu_select();
		scanf("%d", &menu);
		if (menu == 1) {
			while (1) { //7번을 선택하여 메뉴로 돌아가기 전까지는 계속 반복함
				menu_select1();
				scanf("%d", &menu1);
				if (menu1 == 1) {
					printf("서울의 오늘 확진자는 %d명 입니다.\n", region_seoul6[11]);
					if (day_diff(region_seoul6[10], region_seoul6[11]) < 0) {
						printf("어제보다 %d명 감소했습니다.\n", -(day_diff(region_seoul6[10], region_seoul6[11])));
					}
					else {
						printf("어제보다 %d명 증가했습니다.\n", day_diff(region_seoul6[10], region_seoul6[11]));
					}
				}
				else if (menu1 == 2) {
					printf("부산의 오늘 확진자는 %d명 입니다.\n", region_busan6[11]);
					if (day_diff(region_busan6[10], region_busan6[11]) < 0) {
						printf("어제보다 %d명 감소했습니다.\n", -(day_diff(region_busan6[10], region_busan6[11])));
					}
					else {
						printf("어제보다 %d명 증가했습니다.\n", day_diff(region_busan6[10], region_busan6[11]));
					}
				}
				else if (menu1 == 3) {
					printf("제주도의 오늘 확진자는 %d명 입니다.\n", region_jeju6[11]);
					if (day_diff(region_jeju6[10], region_jeju6[11]) < 0) {
						printf("어제보다 %d명 감소했습니다.\n", -(day_diff(region_jeju6[10], region_jeju6[11])));
					}
					else {
						printf("어제보다 %d명 증가했습니다.\n", day_diff(region_jeju6[10], region_jeju6[11]));
					}
				}
				else if (menu1 == 4) {
					printf("대구의 오늘 확진자는 %d명 입니다.\n", region_daegu6[11]);
					if (day_diff(region_daegu6[10], region_daegu6[11]) < 0) {
						printf("어제보다 %d명 감소했습니다.\n", -(day_diff(region_daegu6[10], region_daegu6[11])));
					}
					else {
						printf("어제보다 %d명 증가했습니다.\n", day_diff(region_daegu6[10], region_daegu6[11]));
					}
				}
				else if (menu1 == 5) {
					printf("경기도의 오늘 확진자는 %d명 입니다.\n", region_gyeonggi6[11]);
					if (day_diff(region_gyeonggi6[10], region_gyeonggi6[11]) < 0) {
						printf("어제보다 %d명 감소했습니다.\n", -(day_diff(region_gyeonggi6[10], region_gyeonggi6[11])));
					}
					else {
						printf("어제보다 %d명 증가했습니다.\n", day_diff(region_gyeonggi6[10], region_gyeonggi6[11]));
					}
				}
				else if (menu1 == 6) {
					printf("강원도의 오늘 확진자는 %d명 입니다.\n", region_gangwon6[11]);
					if (day_diff(region_gangwon6[10], region_gangwon6[11]) < 0) {
						printf("어제보다 %d명 감소했습니다.\n", -(day_diff(region_gangwon6[10], region_gangwon6[11])));
					}
					else {
						printf("어제보다 %d명 증가했습니다.\n", day_diff(region_gangwon6[10], region_gangwon6[11]));
					}
				}
				else if (menu1 == 7) {
					printf("다시 메뉴화면으로 돌아갑니다\n\n");
					goto start1; //메뉴로 돌아감
				}
				else {
					printf("번호를 다시 입력해주세요.\n"); //틀린 번호 입력 시 다시 번호를 입력받음
				}
			}
		}
		else if (menu == 2) {
			printf("오늘의 총 확진자 수는 %d명 입니다.\n", region_sum(region_seoul6[11], region_busan6[11], region_jeju6[11], region_daegu6[11], region_gyeonggi6[11], region_gangwon6[11]));
			if (pf(region_sum(region_seoul6[10], region_busan6[10], region_jeju6[10], region_daegu6[10], region_gyeonggi6[10], region_gangwon6[10]), region_sum(region_seoul6[11], region_busan6[11], region_jeju6[11], region_daegu6[11], region_gyeonggi6[11], region_gangwon6[11])) < 0) {
				printf("어제보다 %d명 감소했습니다.\n", -(pf(region_sum(region_seoul6[10], region_busan6[10], region_jeju6[10], region_daegu6[10], region_gyeonggi6[10], region_gangwon6[10]), region_sum(region_seoul6[11], region_busan6[11], region_jeju6[11], region_daegu6[11], region_gyeonggi6[11], region_gangwon6[11]))));
				printf("다시 메뉴화면으로 돌아갑니다.\n\n");
				goto start1;
			}
			else
				printf("어제보다 %d명 증가했습니다.\n", pf(region_sum(region_seoul6[9], region_busan6[9], region_jeju6[9], region_daegu6[9], region_gyeonggi6[9], region_gangwon6[9]), region_sum(region_seoul6[10], region_busan6[10], region_jeju6[10], region_daegu6[10], region_gyeonggi6[10], region_gangwon6[10])));
			printf("다시 메뉴화면으로 돌아갑니다\n\n"); //함수포인터 사용
			goto start1;
		}
		else if (menu == 3) {
			while (1) { //6번 입력하기 전까지 반복
				menu_select3();
				scanf("%d", &menu3);
				if (menu3 == 1) {
					printf("이름 : %s\n조건 : %s\n내용 : %s\n현재 : %s\n",lv1.name,lv1.condition,lv1.content,lv1.now); //구조체 사용
				}
				else if (menu3 == 2) {
					printf("이름 : %s\n조건 : %s\n내용 : %s\n현재 : %s\n", lv2.name, lv2.condition, lv2.content, lv2.now);
				}
				else if (menu3 == 3) {
					printf("이름 : %s\n조건 : %s\n내용 : %s\n현재 : %s\n", lv3.name, lv3.condition, lv3.content, lv3.now);
				}
				else if (menu3 == 4) {
					printf("이름 : %s\n조건 : %s\n내용 : %s\n현재 : %s\n", lv4.name, lv4.condition, lv4.content, lv4.now);
				}
				else if (menu3 == 5) {
					FILE* fp; //파일 입출력 사용
					int c;

					fp = fopen("withcovid19.txt", "rt");

					while ((c = fgetc(fp)) != EOF) {
						putchar(c);
					}

					fclose(fp);

				}
				else if (menu3 == 6) {
					printf("다시 메뉴화면으로 돌아갑니다.\n\n");
					goto start1;
				}
				else {
					printf("\n잘못된 번호를 입력하셨습니다. 다시 입력해주세요. \n");
				}
			}
		}
		else if (menu == 4) {
			printf("프로그램을 종료합니다.");
			break;
		}
		else {
		printf("\n잘못된 번호를 입력하셨습니다. 다시 입력해주세요. \n");
}
	}
	return 0;
}