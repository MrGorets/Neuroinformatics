#include <iostream>

using namespace std;

class Neiron {
private:
	int W[9] = { 9,7,6,4,1,9,8,2,6 };
	int form[10][9] = { {1,1,0,1,0,1,0,1,1},
			{0,0,1,1,0,0,0,1,0},
			{0,1,0,1,0,0,1,0,1},
			{0,1,1,0,1,0,1,0,0},
			{1,0,0,1,1,0,0,1,0},
			{1,1,0,0,1,0,0,1,1},
			{0,0,1,0,1,1,0,1,1},
			{0,1,1,0,0,1,0,0,0},
			{1,1,0,1,1,1,0,1,1},
			{1,1,0,1,1,0,1,0,0} };
	int row = 10, col = 9, number, limit;
	int matrix[100][100] = { {0} };

public:
	int ErrorCounter = 1;
	Neiron(int w[9], int NUM, int lim) {
		for (int counter = 0; counter < 9; counter++) {
			W[counter] = w[counter];
		}
		limit = lim;
		number = NUM;
	}
	Neiron() {}
	int SetRange(int count) {//вычисление диапозона
		int Range = 0, tmp = count;
		tmp--;
		Range = tmp / 10;
		return Range;
	}

	void SetUp(int count) {//награждение
		for (int counter = 0; counter < 9; counter++) {
			if (form[count][counter] == 1) {
				W[counter]++;
			}
		}
	}

	void SetDown(int count) {//наказание
		for (int counter = 0; counter < 9; counter++) {
			if (form[count][counter] == 1) {
				W[counter]--;
			}
		}
	}
	void paragon() {
		ErrorCounter = 0;
		for (int counter = 0; counter < 100; counter++) {//обучение
			int check = rand() % 99;
			check = SetRange(check);
			int weight = 0;
			for (int counter = 0; counter < col; counter++) {
				if (form[check][counter] == 1) {
					weight = weight + W[counter];
				}
			}
			if (check == number) {
				if (weight < limit) {
					ErrorCounter++;
					SetUp(check);
				}
				if (weight >= limit) {
				}
			}
			else {
				if (weight > limit) {
					ErrorCounter++;
					SetDown(check);
				}
			}
		}
		cout << endl << "Ошибок: " << ErrorCounter;
	}
	void Output() {
		cout << endl << "Итоговый вектор: ";
		for (int counter = 0; counter < col; counter++) {
			cout << W[counter] << " ";
		}
	}
};


int main() {
	setlocale(LC_ALL, "rus");
	int matrixV[10][9] = {
		{8,2,4,4,9,3,15,7,4},
		{3,4,0,6,10,9,1,2,0},
		{3,4,0,6,10,14,5,14,3},
		{8,11,5,2,14,10,0,2,7},
		{15,4,2,3,5,9,11,15,1},
		{0,12,1,12,3,6,1,5,6},
		{2,14,2,14,10,0,2,7,10},
		{0,2,7,4,2,3,5,9,6},
		{5,3,10,5,4,1,13,9,11},
		{1,2,7,3,4,3,5,5,6} }, limit;
	Neiron exp[10] = {};
	cout << endl << "Введите пороговое значение (от 20 до 30): ";
	cin >> limit;
	for (int counter = 0; counter < 10; counter++) {
		cout << endl << "____________________________________________________________" << endl
			<< "Распознование числа: " << counter << endl;
		cout << endl << "Начальный вектор: ";
		for (int counter1 = 0; counter1 < 9; counter1++) {
			cout << matrixV[counter][counter1] << " ";
		}
		exp[counter] = Neiron(matrixV[counter], counter, limit);
		int prag = 0;
		while (exp[counter].ErrorCounter != 0) {			
			cout << endl << "Прогон №:" << prag;
			exp[counter].paragon();
			prag++;
		}
		
		exp[counter].Output();
	}
	system("pause");
	return 0;
}