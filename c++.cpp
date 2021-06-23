#include<stdio.h>
int& add(int& a, int& b) {
	a = a + b;
	return a;
}
int add2(int& a, int& b) {
	a = a + b;
	return a;
}
int add3(int uu, int a = 9) {//形参在函数传递的时候自能传递到后面
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
	printf("%p", a);
	return 0;
}
void main() {
	/*int *pi,(*po)[8],*pl;
	po = new int[3][8];
	pl = new int[3];
	pi = new int;
	*pi = 2;
	delete[] pi;
	printf("%d",*pi);*/

	/*int i;
	int& j = i;
	int& u = i;
	u = 0;
	printf("%d\n", i);
	u = 1;
	printf("%d\n", i);
	printf("%p %p %p\n", &i,&u,&j);
	printf("%p%p %p\n", i, u, j);
	int q = 9;
	int w = 8;
	int& e = add(q, w);
	int r = add2(q, w);
	e = 88;
	printf("%d,%d,%d", q, w, r);
	printf("%d,%d,%d\n", q, w, e);
	add3(e);*/
	int a = 11;
	int b = 0;
	try
	{
		if (b == 0) {
			throw "s";
		}
		else {
			throw 1;
		}
		printf("%d", a / b);
	}
	catch (char s) {
		//错误处理
		printf("a");
	}
	catch (char* y) {
		printf("c");
	}
	catch (int i) {
		printf("b");
	}
	catch (...) {
		printf("d");
	}
	max(8);
	max("t");
}