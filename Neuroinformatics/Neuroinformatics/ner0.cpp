#include <iostream>

using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	float a = 0;
	float b = 0;
	float c = 0;
	float d = 0;
	float n = 0;
	float m = 0;
	cout << "Введите число AC1" << endl;
	cin >> a;
	cout << "Введите число AC2" << endl;
	cin >> b;
	cout << "Введите число BC1" << endl;
	cin >> c;
	cout << "Введите число BC2" << endl;
	cin >> d;
	cout << "Дискриминантная функция" << endl;
	n = a - c;
	float l = b - d;
	float k = a + c;
	m = d + b;
	cout << n << "*x2+" << l << "x5 +" << -0.5 * (n * k + m * l) << endl;
	cout << " Итоговая Дискриминантная функция" << endl;
	cout << "x5 = ( " << n << "*x2 +" << -0.5 * (n * k + m * l) << " ) / " << 0 - l << endl;
	system("pause");
	return 0;
}