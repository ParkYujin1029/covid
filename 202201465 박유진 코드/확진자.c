/* 
region_sum함수는 그 날 지역에 나온 모든 확진자수의 합을 구하는 함수이다.
day_diff함수는 두 날 사이의 확진자 수의 증감 수치를 나타내는 함수이다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "covidregion.h"


int region_sum(int seoul, int busan, int jeju, int daegu, int gyeonggi, int gangwon) {
	return (seoul + busan + jeju + daegu + gyeonggi + gangwon);
}
int day_diff(int day1, int day2) {
	return (day2 - day1);
}