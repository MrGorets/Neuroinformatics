#include <iostream>

using namespace std;

int matrixV[10][9] = {
{8, 6, 1, 4, 1, 4, 7, 2, 6},
{8, 1, 7, 2, 5, 1, 4, 5, 2},
{7, 3, 4, 3, 6, 5, 1, 0, 3},
{4, 5, 2, 1, 8, 8, 3, 4, 7},
{5, 0, 4, 3, 5, 6, 7, 2, 5},
{4, 3, 3, 7, 2, 8, 5, 4, 3},
{3, 9, 7, 4, 7, 1, 6, 2, 9},
{5, 2, 7, 2, 1, 3, 1, 2, 5},
{1, 2, 5, 8, 6, 1, 4, 7, 2},
{5, 0, 8, 1, 2, 7, 7, 2, 1} };

class Neiron {
private:
	int form[10][9] = {
	{1, 1, 1, 0, 0, 1, 0, 1, 1},
	{0, 0, 1, 1, 0, 0, 0, 1, 0},
	{0, 1, 1, 0, 0, 0, 1, 0, 1},
	{0, 1, 0, 1, 1, 0, 1, 0, 0},
	{1, 0, 1, 0, 1, 0, 0, 1, 0},
	{1, 1, 0, 0, 1, 0, 0, 1, 1},
	{0, 0, 0, 1, 1, 1, 0, 1, 1},
	{0, 1, 0, 1, 0, 1, 0, 0, 0},
	{1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 0} };
	int MassWeight[10] = {};
public:
	Neiron() {}

	void SetUp(int count, int AAABBB) {//награждение
		for (int counter = 0; counter < 9; counter++) {
			if (form[AAABBB][counter] == 1) {
				matrixV[count][counter]++;
			}
		}
	}

	void SetDown(int count, int AAABBB) {//наказание
		for (int counter = 0; counter < 9; counter++) {
			if (form[AAABBB][counter] == 1) {
				matrixV[count][counter]--;
			}
		}
	}
	void paragon(int received) {
		for (int paragon = 0; paragon < 100; paragon++) {
			int weight = 0;
			int count = 0;
			int NAMBER1 = 0;
			for (int counter = 0; counter < 10; counter++) {
				for (int counterL = 0; counterL < 10; counterL++) {
					if (form[received][counterL] == 1) {
						weight = weight + matrixV[counter][counterL];
					}
				}
				MassWeight[count] = weight;
				count++;
				weight = 0;
			}
			int MAX = 0, NAMBER = 0;
			for (int counter = 0; counter < 10; counter++) {
				if (MassWeight[counter] > MAX) {
					MAX = MassWeight[counter];
					NAMBER = counter;
				}
			}
			if (received != NAMBER) {
				SetDown(NAMBER, received);
				cout << endl << "Апнута: " << received << " cтрока" << endl << "Опущена: " << NAMBER << " строка" << endl;
				SetUp(received, received);
			}
		}
		
	}
	void Output(){
		cout << endl << "Итоговая матрица: "<<endl;
		for (int counter = 0; counter < 10; counter++) {
			cout << counter<< ") ";
			for (int counter1 = 0; counter1 < 9; counter1++) {
				cout << matrixV[counter][counter1] << " ";
			}
			cout << endl;
		}
	}
};


int main() {
	setlocale(LC_ALL, "rus");
	Neiron exp[10] = {};
	for (int training = 0; training < 100; training++) {
		for (int counter = 0; counter < 10; counter -= -1) {
			exp[counter].paragon(counter);
		}
	}
	exp[0].Output();
	system("pause");
	return 0;
}