#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int data[][3] = {
	{ 1, 1, 2 }, { 1, 1, 3 }, { 1, 2, 3 }, { 1, 2, 4 },
	{ 2, 5, 7 }, { 2, 2, 2 },
	{ 3, 8, 1 }, { 3, 8, 9 },
};

// 提供一个多个关键字排序的例子（以三个为例）

#define MAXN 100

class Triple {
private:
	// 【一】成员变量无论如何都要私有，不管多困难，绝不开放
	int m_iRank;
	int m_iLevel;
	int m_Count;

public:
	// 【二】单例的默认构造函数用private，否则定义为public
	Triple() {}
	// 【三】养成虚析构(virtual deconstruction)的习惯，避免内存泄漏
	virtual ~Triple() {}
	// 【四】构造函数的初始化列表 优于 直接赋值
	Triple(int rank, int level, int count) : m_iRank(rank), m_iLevel(level), m_Count(count) {}
	// 【五】重载小于号，避免外部进行攀比（实际上外部也无法调用私有成员）
	bool operator < (const Triple& t) const {
		if (m_iRank != t.m_iRank)          		  // 1. 先排品质
			return m_iRank > t.m_iRank;
		if (m_iLevel != t.m_iLevel)               // 2. 再排等级
			return m_iLevel > t.m_iLevel;
		return m_Count < t.m_Count;               // 3. 最后排数量
	}
	void Print() {
		printf("rank = %d, level = %d, count = %d\n", m_iRank, m_iLevel, m_Count);
	}
};

void sampleSortOfVecor(int size, int data[][3]) {
	vector <Triple> kTriples;
	// 【六】预估可行大小，利用 reserve 预分配空间，减少vector内存重分配带来的消耗
	kTriples.reserve(100);
	for (int i = 0; i < size; ++i) {
		kTriples.push_back(Triple(data[i][0], data[i][1], data[i][2]));
	}

	sort(kTriples.begin(), kTriples.end());
	for (int i = 0; i < size; ++i) {
		kTriples[i].Print();
	}
}

void sampleSortOfArray(int size, int data[][3]) {
	// 【七】预估最大大小，如果有上界，且不会超过堆栈大小，那么不要用 vector 直接上数组效率更高
	Triple kTriples[MAXN];
	// 【八】上界容错
	size = size > MAXN ? MAXN : size;
	// 【九】循环结束条件能够用常量尽量用常量 （ 不要用 .size() )
	for (int i = 0; i < size; ++i) {
		kTriples[i] = Triple(data[i][0], data[i][1], data[i][2]);
	}

	sort(kTriples, kTriples + size);
	for (int i = 0; i < size; ++i) {
		kTriples[i].Print();
	}
}

int main() {
	sampleSortOfVecor(8, data);
	sampleSortOfArray(8, data);
	return 0;
}


