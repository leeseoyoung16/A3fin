#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 201

typedef struct {
	int coef; //계수
	int expon; //지수
} polynomial;


void poly_mul(polynomial* a, polynomial* b, polynomial* c) { //두 다항식 곱셈 함수
	int i, j, k;
	polynomial d[MAX_TERMS] = { 0 };

	for (i = 0; i < MAX_TERMS; i++) {
		c[i].coef = 0; //구조체 멤버 사용 방법 변수 -> 뒤에 '.' 넣기
		c[i].expon = 0;
		d[i].coef = 0;
		d[i].expon = 0;
	}

	for (i = 0; i < MAX_TERMS; i++) {
		for (j = 0; j < MAX_TERMS; j++) {
			k = a[i].expon + b[j].expon;
			d[k].coef += a[i].coef * b[j].coef; //같은 expon이면 더하기
			d[k].expon = k;
		}
	}
	for (i = 0; i < MAX_TERMS; i++) {
		c[i].coef = d[i].coef;
		c[i].expon = d[i].expon;
	}
}


int main() {
	polynomial a[MAX_TERMS] = { 0 }, b[MAX_TERMS] = { 0 }, c[MAX_TERMS] = { 0 }; //첫째항 , 둘째항, 결과항
	int m, n, i;

	printf("첫 번째 다항식 항 수 입력하세요 : ");
	scanf_s("%d", &m);
	printf("첫 번째 다항식\n");
	for (i = 0; i < m; i++) {
		printf("계수 : ");
		scanf_s("%d", &a[i].coef);
		printf("지수 : ");
		scanf_s("%d", &a[i].expon);
	}

	printf("두 번째 다항식 항 수 입력하세요 : ");
	scanf_s("%d", &n);
	printf("두 번째 다항식\n");
	for (i = 0; i < n; i++) {
		printf("계수 : ");
		scanf_s("%d", &b[i].coef);
		printf("지수 : ");
		scanf_s("%d", &b[i].expon);
	}
	poly_mul(a, b, c);

	printf("두 다항식의 곱 : ");
	int count = 0;
	for (i = m + n - 2; i >= 0; i--) {
		if (c[i].coef != 0 && c[i].expon != 0) {
			if (count > 0) printf(" + "); // 첫 항이 아닌 경우 '+' 출력
			printf("%dx^%d", c[i].coef, c[i].expon);
			count++;
		}
		else if (c[i].expon == 0) {
			if (count > 0) printf(" + "); // 첫 항이 아닌 경우 '+' 출력
			printf("%d", c[i].coef);
			count++;
		}
	}
	printf("\n");

	return 0;

}