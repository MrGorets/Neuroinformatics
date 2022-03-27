#include <iostream>

using namespace std;

class Neiron {
private:
	int W[9] = { 3,7,6,4,1,1,8,2,6 };
	int numberAll[3] = {3,0,6};
	int number = 0;
	int form[10][9] = { {1,1,1,0,0,1,0,1,1},
			{0,0,1,1,0,0,0,1,0},
			{0,1,1,0,0,0,1,0,1},
			{0,1,0,1,1,0,1,0,0},
			{1,0,1,0,1,0,0,1,0},
			{1,1,0,0,1,0,0,1,1},
			{0,0,0,1,1,1,0,1,1},
			{0,1,0,1,0,1,0,0,0},
			{1,1,1,0,1,1,0,1,1},
			{1,1,1,0,1,0,1,0,0} };
	int row = 10, col = 9, limit;

public:
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
	void start() {
		cout << endl << "Введите пороговое значение: ";
		cin >> limit;
	}
	void paragon() {
		for (int counterAll = 0; counterAll < 3; counterAll++) {
			cout << endl << "Число: " << numberAll[counterAll];			
			int check = numberAll[counterAll];
			//check = SetRange(check);
			//cout << endl << "ДИапозон: " << check;
			int weight = 0;
			for (int counter = 0; counter < col; counter++) {
				if (form[check][counter] == 1) {
					weight = weight + W[counter];
				}
			}
			cout << endl << "вес: " << weight;
			if (check == number) {
				if (weight < limit) {
					SetUp(check);
				}
				if (weight >= limit) {
					//cout << endl << "Распозналось число!";
				}
			}
			else {
				if (weight > limit) {
					SetDown(check);
				}
			}
			Output();
		}
	}
	void Output() {
		
		cout << endl << "Вектор: ";
		for (int counter = 0; counter < col; counter++) {
			cout << W[counter] << " ";
		}
	}
};


int main() {
	setlocale(LC_ALL, "rus");
	Neiron exp;
	exp.start();
	exp.paragon();
	system("pause");
	return 0;
}
