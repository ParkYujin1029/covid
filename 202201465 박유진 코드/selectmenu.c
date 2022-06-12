/*menu_select함수는 초기 메뉴를 나타내는 함수이다.
menu_select1함수는 1번을 선택했을 때의 메뉴를 나타내는 함수이다.
menu_select3함수는 3번을 선택했을 때의 메뉴를 나타내는 함수이다.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "covidregion.h"

void menu_select() {
	printf("==========메뉴==========\n");
	printf("= 1. 지역별 확진자 수  =\n");
	printf("= 2. 오늘 총 확진자 수 =\n");
	printf("= 3. 거리두기 정보     =\n");
	printf("= 4. 프로그램 종료     =\n");
	printf("========================\n");
	printf("숫자를 입력하시오 : ");
}
void menu_select1() {
	printf("\n==========지역==========\n");
	printf("=       1. 서울        =\n");
	printf("=       2. 부산        =\n");
	printf("=       3. 제주        =\n");
	printf("=       4. 대구        =\n");
	printf("=       5. 경기        =\n");
	printf("=       6. 강원        =\n");
	printf("=       7. 메뉴        =\n");
	printf("========================\n");
	printf("지역번호를 입력하시오 : ");
}
void menu_select3() {
	printf("\n==========거리두기==========\n");
	printf("=    1. 거리두기 1단계     =\n");
	printf("=    2. 거리두기 2단계     =\n");
	printf("=    3. 거리두기 3단계     =\n");
	printf("=    4. 거리두기 4단계     =\n");
	printf("=    5. 위드 코로나        =\n");
	printf("=    6. 메뉴               =\n");
	printf("============================\n");
	printf("숫자를 입력하시오 : ");
}