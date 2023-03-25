#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 201

typedef struct {
	int coef; //���
	int expon; //����
} polynomial;


void poly_mul(polynomial* a, polynomial* b, polynomial* c) { //�� ���׽� ���� �Լ�
	int i, j, k;
	polynomial d[MAX_TERMS] = { 0 };

	for (i = 0; i < MAX_TERMS; i++) {
		c[i].coef = 0; //����ü ��� ��� ��� ���� -> �ڿ� '.' �ֱ�
		c[i].expon = 0;
		d[i].coef = 0;
		d[i].expon = 0;
	}

	for (i = 0; i < MAX_TERMS; i++) {
		for (j = 0; j < MAX_TERMS; j++) {
			k = a[i].expon + b[j].expon;
			d[k].coef += a[i].coef * b[j].coef; //���� expon�̸� ���ϱ�
			d[k].expon = k;
		}
	}
	for (i = 0; i < MAX_TERMS; i++) {
		c[i].coef = d[i].coef;
		c[i].expon = d[i].expon;
	}
}


int main() {
	polynomial a[MAX_TERMS] = { 0 }, b[MAX_TERMS] = { 0 }, c[MAX_TERMS] = { 0 }; //ù°�� , ��°��, �����
	int m, n, i;

	printf("ù ��° ���׽� �� �� �Է��ϼ��� : ");
	scanf_s("%d", &m);
	printf("ù ��° ���׽�\n");
	for (i = 0; i < m; i++) {
		printf("��� : ");
		scanf_s("%d", &a[i].coef);
		printf("���� : ");
		scanf_s("%d", &a[i].expon);
	}

	printf("�� ��° ���׽� �� �� �Է��ϼ��� : ");
	scanf_s("%d", &n);
	printf("�� ��° ���׽�\n");
	for (i = 0; i < n; i++) {
		printf("��� : ");
		scanf_s("%d", &b[i].coef);
		printf("���� : ");
		scanf_s("%d", &b[i].expon);
	}
	poly_mul(a, b, c);

	printf("�� ���׽��� �� : ");
	int count = 0;
	for (i = m + n - 2; i >= 0; i--) {
		if (c[i].coef != 0 && c[i].expon != 0) {
			if (count > 0) printf(" + "); // ù ���� �ƴ� ��� '+' ���
			printf("%dx^%d", c[i].coef, c[i].expon);
			count++;
		}
		else if (c[i].expon == 0) {
			if (count > 0) printf(" + "); // ù ���� �ƴ� ��� '+' ���
			printf("%d", c[i].coef);
			count++;
		}
	}
	printf("\n");

	return 0;

}