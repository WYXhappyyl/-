#include<stdio.h>
#include<iostream>
using namespace std;
int Page_Reference[100];
int Page_number;
int Memory[3];

//�ҳ��ʱ�䲻��ʹ�õ�ҳ
int Findlongest(int x) {
	int zero = 0, one = 0, two = 0;
	int max;
	for (int i = x + 1; i < Page_number; i++) {
		if (Memory[0] == Page_Reference[i])
			break;
		if (Memory[0] != Page_Reference[i])
			zero++;
	}
	for (int i = x + 1; i < Page_number; i++) {
		if (Memory[1] == Page_Reference[i])
			break;
		if (Memory[1] != Page_Reference[i])
			one++;
	}
	for (int i = x + 1; i < Page_number; i++) {
		if (Memory[2] == Page_Reference[i])
			break;
		if (Memory[2] != Page_Reference[i])
			two++;
	}
	if (zero > one)
		max = zero;
	else max = one;
	if (max < two)
		max = two;
	if (max == zero)
		return 0;
	if (max == one)
		return 1;
	if (max == two)
		return 2;
}
void OPT() {
	int mistake = 3;                        //��ʼ��������3
	int Fram, j;
	Memory[0] = Page_Reference[0];
	Memory[1] = Page_Reference[1];
	Memory[2] = Page_Reference[2];
	for (int i = 3; i < Page_number; i++) {
		for (j = 0; j < 3; j++) {
			if (Page_Reference[i] == Memory[j])
				break;
		}
		if (j == 3) {
			Fram = Findlongest(i);
			int temp = Memory[Fram];
			Memory[Fram] = Page_Reference[i];
			mistake++;
			printf("ҳ��%d �û�ҳ��%d  �������%d\n", Page_Reference[i], temp, mistake);
		}
	}
	cout << "ȱҳ������" << mistake << endl;
	float str;
	str = (float)mistake / Page_number;
	cout << "ȱҳ��=" << str * 100 << "%" << endl;
}

void FIFO() {
	int mistake = 3;
	int Fram = 0;
	int j;
	Memory[0] = Page_Reference[0];
	Memory[1] = Page_Reference[1];
	Memory[2] = Page_Reference[2];
	for (int i = 3; i < Page_number; i++) {
		for (j = 0; j < 3; j++) {
			if (Page_Reference[i] == Memory[j])
				break;
		}
		if (j == 3) {
			int temp = Memory[Fram];
			Memory[Fram] = Page_Reference[i];
			Fram++;
			if (Fram == 4)
				Fram = 0;
			mistake++;
			printf("ҳ��%d �û�ҳ��%d  �������%d\n", Page_Reference[i], temp, mistake);
		}

	}
	cout << "ȱҳ������" << mistake << endl;
	float str;
	str = (float)mistake / Page_number;
	cout << "ȱҳ��=" << str * 100 << "%" << endl;
}

//���ʱ��δ��ʹ�õ�ҳ��
int FindPast(int x) {
	int zero = 0, one = 0, two = 0;
	int max;
	for (int i = x; i >= 0; i--) {
		if (Memory[0] == Page_Reference[i])
			break;
		if (Memory[0] != Page_Reference[i])
			zero++;
	}
	for (int i = x; i >= 0; i--) {
		if (Memory[1] == Page_Reference[i])
			break;
		if (Memory[1] != Page_Reference[i])
			one++;
	}
	for (int i = x; i >= 0; i--) {
		if (Memory[2] == Page_Reference[i])
			break;
		if (Memory[2] != Page_Reference[i])
			two++;
	}
	if (zero > one)
		max = zero;
	else max = one;
	if (max < two)
		max = two;
	if (max = zero)
		return 0;
	if (max = one)
		return 1;
	if (max = two)
		return 2;
}
void LRU() {
	int mistake = 3;                        //��ʼ��������3
	int Fram, j;
	Memory[0] = Page_Reference[0];
	Memory[1] = Page_Reference[1];
	Memory[2] = Page_Reference[2];
	for (int i = 3; i < Page_number; i++) {
		for (j = 0; j < 3; j++) {
			if (Page_Reference[i] == Memory[j])
				break;
		}
		if (j == 3) {
			Fram = FindPast(i - 1);
			int temp = Memory[Fram];
			Memory[Fram] = Page_Reference[i];
			mistake++;
			printf("ҳ��%d �û�ҳ��%d  �������%d\n", Page_Reference[i], temp, mistake);
		}

	}
	cout << "ȱҳ������" << mistake << endl;
	float str;
	str = (float)mistake / Page_number;
	cout << "ȱҳ��=" << str * 100 << "%" << endl;
}

int main() {

	cin >> Page_number;               //������
	for (int i = 0; i < Page_number; i++) {
		Page_Reference[i] = rand() % 10;
		printf("%d ", Page_Reference[i]);
	}
	cout << endl;
	cout << "****************OPT�㷨****************" << endl;
	OPT();
	cout << "****************FIFO�㷨****************" << endl;
	FIFO();
	cout << "****************LRU�㷨****************" << endl;
	LRU();

}