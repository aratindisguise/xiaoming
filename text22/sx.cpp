#include<stdio.h>
#include"sx.h"

int& add(int& a, int& b) {
	a=a + b;
	return a;
}
int add2(int& a, int& b,C z) {
	printf("%d",z.t);
	a = a + b;
	return a;
}
int add3(int uu,int a = 9) {//形参在函数传递的时候自能传递到后面
	printf("%d", a + uu);
	return 0;
}

//int max(int a, int len) {
//	return 0;
//}int max(int a,int b, int c) {
//	return 0;
//}int max(int array[], int len) {
//	return 0;
/*}*/template <typename S> S max(S a) {
	printf("%d", a);
		return 0;
	}
void C::Y(char x) {
	printf("%c",x);
}
int C::e  = 0;
void main() {
	/*int *pi,(*po)[8],*pl;
	po = new int[3][8];
	pl = new int[3];
	pi = new int;
	*pi = 2;
	delete[] pi;
	printf("%d",*pi);*/
	const C u(1);
	C y[5] = {C(2,6)};
	C t[6] = {C(1)};
	y[3].sets(2);
	y[4].sets(40);
	C::pe(2);
	printf("%d", C::e);
	printf("\n%x\n%x\n%x", &C::e,&y[5].e,&t[2].e);
	//u.hy();
	///*int i;
	//int& j = i;
	//int& u = i;
	//u = 0;
	//printf("%d\n", i);
	//u = 1;
	//printf("%d\n", i);
	//printf("%p %p %p\n", &i,&u,&j);
	//printf("%p%p %p\n", i, u, j);
	//int q = 9;
	//int w = 8;
	//int& e = add(q, w);
	//int r = add2(q, w);
	//e = 88;
	//printf("%d,%d,%d", q, w, r);
	//printf("%d,%d,%d\n", q, w, e);
	//add3(e);*/
	//int a = 11;
	//int b = 0;
	//try
	//{
	//	if (b == 0) {
	//		throw "s";
	//	}
	//	else {
	//		throw 1;
	//	}
	//	printf("%d", a / b);
	//}
	//catch (char s) {
	//	//错误处理
	//	printf("a");
	//}
	//catch (char* y) {
	//	printf("c");
	//}
	//catch (int i) {
	//	printf("b");
	//}
	//catch (...) {
	//	printf("d");
	//}
	//max(8);
	//max("t");
}