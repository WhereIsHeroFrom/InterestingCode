#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <string>

#include <windows.h>
using namespace std;

#define MAXN 1000000
int a[MAXN];
bool hashtbl[MAXN * 5];
map<string, bool> maphash;
unordered_map<string, bool> umaphash;

void init() {
	int i;
	for (i = 0; i < MAXN; ++i) {
		a[i] = 5 * i;
	}
}

void init2() {
	int i;
	memset(hashtbl, 0, sizeof(hashtbl));
	for (i = 0; i < MAXN; ++i) {
		hashtbl[5 * i] = 1;
	}
}

void init3() {
	maphash.clear();
	char c[100];
	for (int i = 0; i < MAXN; ++i) {
		//itoa(i * 5, c, 10);
		maphash[c] = 1;
	}
}

void init4() {
	umaphash.clear();
	char c[100];
	for (int i = 0; i < MAXN; ++i) {
		//itoa(i * 5, c, 10);
		umaphash[c] = 1;
	}
}

bool find(int target) {
	for (int i = 0; i < MAXN; ++i) {
		if (target == a[i]) {
			return true;
		}
	}
	return false;
}

bool find2(int target) {
	return hashtbl[target];
}

bool find3(char *c) {
	return maphash.find(c) != maphash.end();
}
bool find4(char *c) {
	return umaphash.find(c) != umaphash.end();
}


int countBy() {
	int cnt = 0, m = 100000;
	while (m--) {
		if (find4("2252552")) {
			++cnt;
		}
	}
	return cnt;
}

#define MAXP 30
#define MAXN 1000000

int doCount() {
	int s = 0, cnt = MAXN;
	int pow2[MAXP] = { 1 };
	for (int i = 1; i < MAXP; ++i) {
		pow2[i] = pow2[i - 1] * 2;
	}
	while (cnt--) {
		for (int i = 0; i < MAXP; ++i) {
			//s += rand() / pow2[i];
			//s += (rand() % pow2[i]);
			s = s * 2;
			s += s * 2;
		}
	}
	return s;
}

int doCount2() {
	int s = 0, cnt = MAXN;
	int pow2[MAXP] = { 1 };
	for (int i = 1; i < MAXP; ++i) {
		pow2[i] = pow2[i - 1] * 2;
	}
	while (cnt--) {
		for (int i = 0; i < MAXP; ++i) {
			//s += rand() >> i;
			//s += (rand() & (pow2[i] - 1));
			s = s + s;
			s += s + s;
		}
	}
	return s;
}


#define MOD 10000007
int val[MAXN];

void initSumMod() {
	for (int i = 0; i < MAXN; ++i) {
		val[i] = rand();
	}
}

int doSumMod() {
	int s = 0;
	for (int i = 0; i < MAXN; ++i) {
		s = (s + val[i]) % MOD;
	}
	return s;
}

int doSumMod2() {
	int s = 0;
	for (int i = 0; i < MAXN; ++i) {
		s += val[i];
		if (s >= MOD) s %= MOD;
	}
	return s;
}


#define MAX(a,b) ((a)>(b)?(a):(b))

template <class T>
T Max(T a, T b){
	return a > b ? a : b;
}

int For() {
	int s = 0;
	for (int i = 0; i*i < MAXN; ++i) {
		for (int j = 0; j*j < MAXN; ++j) {
			for (int k = 0; k*k < MAXN; ++k) {
				// TODO
			}
		}
	}
	return s;
}

int For2() {
	int s = 0;
	int v = sqrt(MAXN + 1e-8);

	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			for (int k = 0; k < v; ++k) {
				// TODO
			}
		}
	}
	return s;
}

#define MAXA 10
int bin[MAXA] = { 1, 2, 4, 6, 8, 9, 11, 88, 520, 1314 };
int BinarySearch(int val) {
	int l = 0, r = MAXA - 1;
	int m, ans = -1;
	while (l <= r) {
		m = (l + r) >> 1;
		if (bin[m] > val) {
			ans = bin[m];
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return ans;
}

#define MAXDC 100

void DataCollect1() {
	int stk[MAXDC], top = 0;
	for (int i = 0; i < MAXDC; ++i) {
		stk[top++] = i;
	}
}

void DataCollect2() {
	vector <int> v;
	for (int i = 0; i < MAXDC; ++i) {
		v.push_back(i);
	}
}

void DataCollect3() {
	vector <int> v;
	v.reserve(MAXDC);
	for (int i = 0; i < MAXDC; ++i) {
		v.push_back(i);
	}
}


void DataCollectAll(int type) {
	int m = 100000;
	while (m--) {
		switch (type) {
		case 0:
			DataCollect1();
			break;
		case 1:
			DataCollect2();
			break;
		case 2:
			DataCollect3();
			break;
		}
	}
}

const int MAXPI = 100000000;

double CalcCircle() {
	double s = 0;
	for (int i = 0; i < MAXPI; ++i) {
		s += acos(-1.0) * i * i;
	}
	return s;
}

double CalcCircle2() {
	double s = 0;
	const double PI = 3.1415927;
	for (int i = 0; i < MAXPI; ++i) {
		s += PI * i * i;
	}
	return s;
}

class Base {
	int c;
	int b[10000];
public:
	void go() {
		++c;
	}
};

class Inher : public Base {
	int a[10000];
};

const int MAXT = 10000000;

void StaticCast_Test() {
	Inher *p = new Inher();
	for (int i = 0; i < MAXT; ++i){
		Base *pkBase = static_cast<Base*>(p);
	}
}

void Dynamic_Test() {
	Inher *p = new Inher();
	for (int i = 0; i < MAXT; ++i){
		Base *pkBase = dynamic_cast<Base*>(p);
	}
}

long long fib(unsigned int n) {
	if (n <= 1) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}

int lowbit(int x) {
	return x & -x;
}

int getlowbit(int x) {
	int c = 0;
	while (x % 2 == 0) {
		c++;
		x /= 2;
	}
	return (1 << c);
}

int main() {
	printf("%d %d\n", lowbit(12352), getlowbit(12352));
	/*init();
	init2();
	init3();
	init4();


	int t = GetTickCount();
	countBy();
	printf("%d ms\n", GetTickCount() - t);*/
	//initSumMod();
	/*for (int i = -1; i <= 100; ++i) {
	printf("%d > %d\n", BinarySearch(i), i );
	}
	*/

	int t = GetTickCount();
	fib(40);
	printf("%d ms\n", GetTickCount() - t);

	t = GetTickCount();
	Dynamic_Test();
	printf("%d ms\n", GetTickCount() - t);

	return 0;
}