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
	cout << "������� ����� AC1" << endl;
	cin >> a;
	cout << "������� ����� AC2" << endl;
	cin >> b;
	cout << "������� ����� BC1" << endl;
	cin >> c;
	cout << "������� ����� BC2" << endl;
	cin >> d;
	cout << "��������������� �������" << endl;
	n = a - c;
	float l = b - d;
	float k = a + c;
	m = d + b;
	cout << n << "*x2+" << l << "x5 +" << -0.5 * (n * k + m * l) << endl;
	cout << " �������� ��������������� �������" << endl;
	cout << "x5 = ( " << n << "*x2 +" << -0.5 * (n * k + m * l) << " ) / " << 0 - l << endl;
	system("pause");
	return 0;
}