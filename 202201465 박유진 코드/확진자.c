/* 
region_sum�Լ��� �� �� ������ ���� ��� Ȯ���ڼ��� ���� ���ϴ� �Լ��̴�.
day_diff�Լ��� �� �� ������ Ȯ���� ���� ���� ��ġ�� ��Ÿ���� �Լ��̴�.
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