#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int data[][3] = {
	{ 1, 1, 2 }, { 1, 1, 3 }, { 1, 2, 3 }, { 1, 2, 4 },
	{ 2, 5, 7 }, { 2, 2, 2 },
	{ 3, 8, 1 }, { 3, 8, 9 },
};

// �ṩһ������ؼ�����������ӣ�������Ϊ����

#define MAXN 100

class Triple {
private:
	// ��һ����Ա����������ζ�Ҫ˽�У����ܶ����ѣ���������
	int m_iRank;
	int m_iLevel;
	int m_Count;

public:
	// ������������Ĭ�Ϲ��캯����private��������Ϊpublic
	Triple() {}
	// ����������������(virtual deconstruction)��ϰ�ߣ������ڴ�й©
	virtual ~Triple() {}
	// ���ġ����캯���ĳ�ʼ���б� ���� ֱ�Ӹ�ֵ
	Triple(int rank, int level, int count) : m_iRank(rank), m_iLevel(level), m_Count(count) {}
	// ���塿����С�ںţ������ⲿ�����ʱȣ�ʵ�����ⲿҲ�޷�����˽�г�Ա��
	bool operator < (const Triple& t) const {
		if (m_iRank != t.m_iRank)          		  // 1. ����Ʒ��
			return m_iRank > t.m_iRank;
		if (m_iLevel != t.m_iLevel)               // 2. ���ŵȼ�
			return m_iLevel > t.m_iLevel;
		return m_Count < t.m_Count;               // 3. ���������
	}
	void Print() {
		printf("rank = %d, level = %d, count = %d\n", m_iRank, m_iLevel, m_Count);
	}
};

void sampleSortOfVecor(int size, int data[][3]) {
	vector <Triple> kTriples;
	// ������Ԥ�����д�С������ reserve Ԥ����ռ䣬����vector�ڴ��ط������������
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
	// ���ߡ�Ԥ������С��������Ͻ磬�Ҳ��ᳬ����ջ��С����ô��Ҫ�� vector ֱ��������Ч�ʸ���
	Triple kTriples[MAXN];
	// ���ˡ��Ͻ��ݴ�
	size = size > MAXN ? MAXN : size;
	// ���š�ѭ�����������ܹ��ó��������ó��� �� ��Ҫ�� .size() )
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


