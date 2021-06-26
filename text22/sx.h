#pragma once
class C {
private:
	int t=777;
public:
	int year;
	int month;
	int day;
	void Y(char x);
	int setC(int y, int m) {
		this->year = y;
		this->month = m;
		this->day = 6;
	}
	static int e;
	friend int add2(int& a, int& b, C z);
	C(int y,int s) {
		
		printf("%d", y);
	}
	C() {
		e++;
		printf("%d\n",e);
	}
	C(int y) {
		
		year = 1;
		month = 0;
		day = 8;
		printf("%d",y);
	}
  inline int hy() const {
		printf("%d", t);
		return t;
	}
  void sets(int e) {
	  this->e = e;
  }
  void static pe(int e) {
	  printf("%d", e);
  }
};
