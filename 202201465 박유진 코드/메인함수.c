/* 202201465 ������ ��ǻ�� ���α׷��� ���� �ڷγ� ���� ���α׷� �ۼ��ϱ�
���� �޴����� ����� �ϴ� ������ ��ȣ�� �޴´�. (1�� ������ Ȯ���� ��, 2�� �� Ȯ���� ��, 3�� �Ÿ��α� ����, 4�� ����)
���� ���� �ٸ� ��ȣ�� �Է��Ѵٸ� �ٽ� �Է¹޴´�.
1���� �����Ѵٸ� ���ϴ� ����(����, �λ�, ����, �뱸, ���, ����)�� �ϳ� �����Ͽ� �� ������ Ȯ���� ���� ������ ���Ͽ� ������ �˷��ش�.
���� ���� �ٸ� ��ȣ�� �Է��Ѵٸ� �ٽ� �Է¹޴´�. 
2���� �����Ѵٸ� ������ �� Ȯ���� ���� �˷��ش�.
3���� �����Ѵٸ� ���ϴ� �Ÿ��α�(1�ܰ�, 2�ܰ�, 3�ܰ�, 4�ܰ�, �����ڷγ�)�� ���� ������ �˷��ش�.
���� ���� �ٸ� ��ȣ�� �Է��Ѵٸ� �ٽ� �Է¹޴´�.
4���� �����Ѵٸ� �����Ѵ�.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "covidregion.h"
int menu, menu1, menu3; //�޴��� ���� ù��° ���ù޴� ������ ��ȣ�� �����ϴ� ����, �޴�1�� 1������ ������ �����Ҷ��� ��ȣ�� �����ϴ� ����, �޴�3�� 3������ �Ÿ��α⸦ �����Ҷ� �����ϴ� ����
int region_seoul6[30] = { 1000, 1250, 1300, 1400, 1500, 1350, 1200, 1000, 900, 920, 850, 920}; //������ 6�� �Ѵ޵��� 1�Ϻ��� ���ʷ� Ȯ���� �� ���� (���糯¥ 6/12 ����)
int region_busan6[30] = { 900, 750, 500, 600, 750, 800, 950, 150, 300, 600, 750 ,800}; //�λ��� 6�� �Ѵ޵��� Ȯ���ڼ� ���ʷ� ����
int region_jeju6[30] = { 250, 300, 500, 600, 750, 200, 460, 290, 600, 500, 700, 650 }; //���ֵ��� 6�� �Ѵ޵��� Ȯ���ڼ� ���ʷ� ����
int region_daegu6[30] = { 460, 490, 520, 600, 520, 600, 530, 470, 400, 380, 360 ,280}; //�뱸�� 6�� �Ѵ޵��� Ȯ���ڼ� ���ʷ� ����
int region_gyeonggi6[30] = { 1200, 1150, 1320, 1280, 1190, 1210, 1400, 1560, 1450, 1600, 1640 ,1500}; //��⵵�� 6�� �Ѵ޵��� Ȯ���ڼ� ���ʷ� ����
int region_gangwon6[30] = { 1000, 950, 920, 1200, 1100, 1200, 1050, 1200, 950, 890, 990, 1100 }; //�������� 6�� �Ѵ޵��� Ȯ���ڼ� ���ʷ� ���� 
struct distance { //�Ÿ��α��� ������ ���� �����ϴ� ����ü
	char name[30]; //�Ÿ��α� ��Ī
	char condition[250]; //�Ÿ��α� ����
	char content[250]; //�Ÿ��α� ����
	char now[50]; //�Ÿ��α��� ���� ���� ����
};
int main() {
	struct distance lv1 = { "������ �������� ����","���� 500�� �̸�/������ 250�� �̸�","����/����/���� ������ ���� �ü��� ���κ� �濪 ��Ģ �ؼ�","����ȵ�"}; //�Ÿ��α� 1�ܰ�
	struct distance lv2 = { "���� ����","���� 500�� �̻�/ ������ 250�� �̻�","�̿��ο� ����","����ȵ�" }; //�Ÿ��α� 2�ܰ�
	struct distance lv3 = { "�ǿ� ����","���� 1000�� �̻�/ ������ 500��  �̻�","���� ���� ����","����ȵ�" }; //�Ÿ��α� 3�ܰ�
	struct distance lv4 = { "������","���� 2000�� �̻�/ ������ 1000�� �̻�","���� ����/������ �ӹ�����","����ȵ�" }; //�Ÿ��α� 4�ܰ�
	int (*pf)(int, int); //�Լ��� ����ų �Լ������� ����
	pf = day_diff; 
	while (1) { //4���� �����ϱ� �������� ��� �ݺ���
	start1:
		menu_select();
		scanf("%d", &menu);
		if (menu == 1) {
			while (1) { //7���� �����Ͽ� �޴��� ���ư��� �������� ��� �ݺ���
				menu_select1();
				scanf("%d", &menu1);
				if (menu1 == 1) {
					printf("������ ���� Ȯ���ڴ� %d�� �Դϴ�.\n", region_seoul6[11]);
					if (day_diff(region_seoul6[10], region_seoul6[11]) < 0) {
						printf("�������� %d�� �����߽��ϴ�.\n", -(day_diff(region_seoul6[10], region_seoul6[11])));
					}
					else {
						printf("�������� %d�� �����߽��ϴ�.\n", day_diff(region_seoul6[10], region_seoul6[11]));
					}
				}
				else if (menu1 == 2) {
					printf("�λ��� ���� Ȯ���ڴ� %d�� �Դϴ�.\n", region_busan6[11]);
					if (day_diff(region_busan6[10], region_busan6[11]) < 0) {
						printf("�������� %d�� �����߽��ϴ�.\n", -(day_diff(region_busan6[10], region_busan6[11])));
					}
					else {
						printf("�������� %d�� �����߽��ϴ�.\n", day_diff(region_busan6[10], region_busan6[11]));
					}
				}
				else if (menu1 == 3) {
					printf("���ֵ��� ���� Ȯ���ڴ� %d�� �Դϴ�.\n", region_jeju6[11]);
					if (day_diff(region_jeju6[10], region_jeju6[11]) < 0) {
						printf("�������� %d�� �����߽��ϴ�.\n", -(day_diff(region_jeju6[10], region_jeju6[11])));
					}
					else {
						printf("�������� %d�� �����߽��ϴ�.\n", day_diff(region_jeju6[10], region_jeju6[11]));
					}
				}
				else if (menu1 == 4) {
					printf("�뱸�� ���� Ȯ���ڴ� %d�� �Դϴ�.\n", region_daegu6[11]);
					if (day_diff(region_daegu6[10], region_daegu6[11]) < 0) {
						printf("�������� %d�� �����߽��ϴ�.\n", -(day_diff(region_daegu6[10], region_daegu6[11])));
					}
					else {
						printf("�������� %d�� �����߽��ϴ�.\n", day_diff(region_daegu6[10], region_daegu6[11]));
					}
				}
				else if (menu1 == 5) {
					printf("��⵵�� ���� Ȯ���ڴ� %d�� �Դϴ�.\n", region_gyeonggi6[11]);
					if (day_diff(region_gyeonggi6[10], region_gyeonggi6[11]) < 0) {
						printf("�������� %d�� �����߽��ϴ�.\n", -(day_diff(region_gyeonggi6[10], region_gyeonggi6[11])));
					}
					else {
						printf("�������� %d�� �����߽��ϴ�.\n", day_diff(region_gyeonggi6[10], region_gyeonggi6[11]));
					}
				}
				else if (menu1 == 6) {
					printf("�������� ���� Ȯ���ڴ� %d�� �Դϴ�.\n", region_gangwon6[11]);
					if (day_diff(region_gangwon6[10], region_gangwon6[11]) < 0) {
						printf("�������� %d�� �����߽��ϴ�.\n", -(day_diff(region_gangwon6[10], region_gangwon6[11])));
					}
					else {
						printf("�������� %d�� �����߽��ϴ�.\n", day_diff(region_gangwon6[10], region_gangwon6[11]));
					}
				}
				else if (menu1 == 7) {
					printf("�ٽ� �޴�ȭ������ ���ư��ϴ�\n\n");
					goto start1; //�޴��� ���ư�
				}
				else {
					printf("��ȣ�� �ٽ� �Է����ּ���.\n"); //Ʋ�� ��ȣ �Է� �� �ٽ� ��ȣ�� �Է¹���
				}
			}
		}
		else if (menu == 2) {
			printf("������ �� Ȯ���� ���� %d�� �Դϴ�.\n", region_sum(region_seoul6[11], region_busan6[11], region_jeju6[11], region_daegu6[11], region_gyeonggi6[11], region_gangwon6[11]));
			if (pf(region_sum(region_seoul6[10], region_busan6[10], region_jeju6[10], region_daegu6[10], region_gyeonggi6[10], region_gangwon6[10]), region_sum(region_seoul6[11], region_busan6[11], region_jeju6[11], region_daegu6[11], region_gyeonggi6[11], region_gangwon6[11])) < 0) {
				printf("�������� %d�� �����߽��ϴ�.\n", -(pf(region_sum(region_seoul6[10], region_busan6[10], region_jeju6[10], region_daegu6[10], region_gyeonggi6[10], region_gangwon6[10]), region_sum(region_seoul6[11], region_busan6[11], region_jeju6[11], region_daegu6[11], region_gyeonggi6[11], region_gangwon6[11]))));
				printf("�ٽ� �޴�ȭ������ ���ư��ϴ�.\n\n");
				goto start1;
			}
			else
				printf("�������� %d�� �����߽��ϴ�.\n", pf(region_sum(region_seoul6[9], region_busan6[9], region_jeju6[9], region_daegu6[9], region_gyeonggi6[9], region_gangwon6[9]), region_sum(region_seoul6[10], region_busan6[10], region_jeju6[10], region_daegu6[10], region_gyeonggi6[10], region_gangwon6[10])));
			printf("�ٽ� �޴�ȭ������ ���ư��ϴ�\n\n"); //�Լ������� ���
			goto start1;
		}
		else if (menu == 3) {
			while (1) { //6�� �Է��ϱ� ������ �ݺ�
				menu_select3();
				scanf("%d", &menu3);
				if (menu3 == 1) {
					printf("�̸� : %s\n���� : %s\n���� : %s\n���� : %s\n",lv1.name,lv1.condition,lv1.content,lv1.now); //����ü ���
				}
				else if (menu3 == 2) {
					printf("�̸� : %s\n���� : %s\n���� : %s\n���� : %s\n", lv2.name, lv2.condition, lv2.content, lv2.now);
				}
				else if (menu3 == 3) {
					printf("�̸� : %s\n���� : %s\n���� : %s\n���� : %s\n", lv3.name, lv3.condition, lv3.content, lv3.now);
				}
				else if (menu3 == 4) {
					printf("�̸� : %s\n���� : %s\n���� : %s\n���� : %s\n", lv4.name, lv4.condition, lv4.content, lv4.now);
				}
				else if (menu3 == 5) {
					FILE* fp; //���� ����� ���
					int c;

					fp = fopen("withcovid19.txt", "rt");

					while ((c = fgetc(fp)) != EOF) {
						putchar(c);
					}

					fclose(fp);

				}
				else if (menu3 == 6) {
					printf("�ٽ� �޴�ȭ������ ���ư��ϴ�.\n\n");
					goto start1;
				}
				else {
					printf("\n�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���. \n");
				}
			}
		}
		else if (menu == 4) {
			printf("���α׷��� �����մϴ�.");
			break;
		}
		else {
		printf("\n�߸��� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���. \n");
}
	}
	return 0;
}