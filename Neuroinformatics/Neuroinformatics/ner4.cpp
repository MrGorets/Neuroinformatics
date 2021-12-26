#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Neiron {
private:
	int W[15] = { 9, 5, 6, 2, 1, 0, 8, 7, 6, 5, 3, 3, 3, 5, 1 };
	int form[10][15] = { 
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
	{0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
	{1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
	{1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
	{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
	{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
	{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}};
	int row = 10, col = 15, number, limit;
	int matrix[100][100] = { {0} };
	int TablNumber1 = 0, TablNumber2 = 0;
public:
	int ErrorCounter = 1;
	int SetRange(int count) {//вычисление диапозона
		int Range = 0, tmp = count;
		tmp--;
		Range = tmp / 10;
		return Range;
	}

	void SetUp(int count) {//награждение
		for (int counter = 0; counter < 15; counter++) {
			if (form[count][counter] == 1) {
				W[counter]++;
			}
		}
	}

	void SetDown(int count) {//наказание
		for (int counter = 0; counter < 15; counter++) {
			if (form[count][counter] == 1) {
				W[counter]--;
			}
		}
	}
	void start() {
		cout << endl << "Введите пороговое значение (от 20 до 30): ";
		cin >> limit;
		cout << endl << "Введите распозноваемое число: ";//3
		cin >> number;
		cout << endl << "Начальный вектор: ";
		Output();
	}
	int noise() {
		int Trabl = rand() % 9;
			if (form[number][Trabl]==1) {
				form[number][Trabl] = 0;
			}
			else {
				form[number][Trabl] = 1;
			}
			return  Trabl;
	}
	void ClearNoise(int TablNumber) {
		if (form[number][TablNumber] == 1) {
			form[number][TablNumber] = 0;
		}
		else {
			form[number][TablNumber] = 1;
		}
	}
	void paragon() {
		TablNumber1 = noise();
		TablNumber2 = noise();
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
			if ((TablNumber1 != 0)) {
				ClearNoise(TablNumber1);
				ClearNoise(TablNumber2);
				TablNumber1 = noise();
				TablNumber2 = noise();
			}
			if (check == number) {
				if (weight < limit) {
					SetUp(check);
					ErrorCounter++;
				}
				if (weight >= limit) {
					//cout << endl << "Распозналось число!";
				}
			}
			else {
				if (weight > limit) {
					SetDown(check);
					ErrorCounter++;
				}
			}
		}	
		cout << endl << "Конечный вектор: ";
		Output();
		cout << endl << "Ошибок: " << ErrorCounter;
	}
	void Output() {
		for (int counter = 0; counter < col; counter++) {
			cout << W[counter] << " ";
		}
	}
};


int main() {
	setlocale(LC_ALL, "rus");
	Neiron exp;
	srand(time(NULL));
	exp.start();
	int prag = 0;
	while (exp.ErrorCounter != 0) {
		cout << endl << "Прогон №:" << prag;
		exp.paragon();
		prag++;
	}
	system("pause");
	return 0;
}