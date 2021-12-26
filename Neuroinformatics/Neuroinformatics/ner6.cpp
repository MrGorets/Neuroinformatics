#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Merger {
private:
    float Points[45][6] = {
        {1,1},{1,3},{1,6},{2,3},{2,4},{2,6},{3,2},{3,5},{3,7},{4,1},
        {4,3},{4,5},{5,2},{5,4},{6,6},{8,1},{8,4},{9,2},{9,4},{9,5},
        {10,1},{10,3},{10,4},{11,2},{11,3},{11,5},{11,7},{12,1},{12,2},{12,4},
        {6,15},{7,11},{7,14},{8,13},{8,15},{9,12},{9,13},{10,11},{10,15},{11,12},
        {11,13},{11,14},{12,10},{12,12},{12,15} };
    float MIN = 999;
    float Thorndijk[100] = {};
    int ThorndijkCounter = 0;
public:
    int CountClaster = 1;
    int PAROGIBANI = 4;
    Merger() {};
    float Rage(float X1, float Y1, float X2, float Y2) {
        return sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
    }
    void Start() {
        for (int counterA = 0; counterA < 45; counterA++) {
            if (Points[counterA][2] == 0) {
                for (int counterB = 0; counterB < 45; counterB++) {
                    if (Points[counterB][2] == 0) {// не проверять точки которые уже в кластерах
                        if ((Points[counterB][0] != Points[counterA][0]) || (Points[counterB][1] != Points[counterA][1])) {// анти одинаковые точки
                            float temp = Rage(Points[counterA][0], Points[counterA][1], Points[counterB][0], Points[counterB][1]);
                            if (temp < MIN) {
                                MIN = temp;
                            }
                        }
                    }
                }
                if ((Points[counterA][2] == 0) && (MIN < PAROGIBANI)) {
                    Sliyaniye(counterA, CountClaster, 0, 1);
                    CountClaster++;
                }
                else {
                    Points[counterA][2] = CountClaster;
                    Points[counterA][3] = Points[counterA][0];
                    Points[counterA][4] = Points[counterA][1];
                    CountClaster++;

                }
            }
        }
        cout << endl << "Кластеров: " << CountClaster - 1;
    }
    void Sliyaniye(int A, int Claster, int X, int Y) {
        Points[A][2] = Claster;
        Thorndijk[ThorndijkCounter] = MIN;
        ThorndijkCounter-=-1;
        int СountEqualRage = 0;
        float PositionX = 0, PositionY = 0;
        for (int counterA = 0; counterA < 45; counterA++) {//ClasresIndication 
            float temp = Rage(Points[A][X], Points[A][Y], Points[counterA][X], Points[counterA][Y]);
            if (temp == MIN) {
                if (Points[counterA][2] == 0) {
                    Points[counterA][2] = Claster;
                    СountEqualRage++;
                }
            }
        }
        for (int counterA = 0; counterA < 45; counterA++) {//PositionCorrection
            if (Points[counterA][2] == Claster) {
                PositionX = PositionX + Points[counterA][X];
                PositionY = PositionY + Points[counterA][Y];
            }
        }
        for (int counterA = 0; counterA < 45; counterA++) {//PositionSet 10 2
            if (Points[counterA][2] == Claster) {
                Points[counterA][3] = PositionX / (СountEqualRage + 1);
                Points[counterA][4] = PositionY / (СountEqualRage + 1);
            }
        }
        MIN = 999;
    }
    void SliyaniyeClasters() {
        CountClaster = 100;
        for (int counterA = 0; counterA < 45; counterA++) {
            if (Points[counterA][5] == 0) {
                for (int counterB = 0; counterB < 45; counterB++) {
                    if (Points[counterB][5] == 0) {
                        if ((Points[counterB][2] != Points[counterA][2])) {//не сверять одинаковые кластеры
                            if ((Points[counterB][0] != Points[counterA][0]) || (Points[counterB][1] != Points[counterA][1])) {// анти одинаковые точки
                                float temp = Rage(Points[counterA][3], Points[counterA][4], Points[counterB][3], Points[counterB][4]);
                                if (temp < MIN) {
                                    MIN = temp;
                                }
                            }
                        }
                    }
                }
                if (MIN < PAROGIBANI) {
                    Sliyaniye1(counterA, CountClaster, 3, 4);
                    CountClaster++;
                }
                else {
                    int skip = Points[counterA][2];
                    for (int counterA = 0; counterA < 45; counterA++) {
                        if (Points[counterA][2] == skip) {
                            Points[counterA][5] = CountClaster;
                        }
                    }
                    CountClaster++;
                }

            }
        }
        Normal();
    }
    void Sliyaniye1(int A, int Claster, int X, int Y) {
        Points[A][5] = Claster;
        Thorndijk[ThorndijkCounter] = MIN;
        ThorndijkCounter -= -1;
        float PositionX = 0, PositionY = 0;
        for (int counterA = 0; counterA < 45; counterA++) {//ClasresIndication 
            float temp = Rage(Points[A][X], Points[A][Y], Points[counterA][X], Points[counterA][Y]);
            if (temp == MIN) {
                if (Points[counterA][5] == 0) {
                    Points[counterA][5] = Claster;
                    PositionX = (Points[A][3] + Points[counterA][3]) / 2;
                    PositionY = (Points[A][4] + Points[counterA][4]) / 2;
                    int temp1 = Points[A][2];
                    for (int counter = 0; counter < 45; counter++) {
                        if (Points[counter][2] == temp1) {
                            Points[counter][5] = Claster;
                        }
                    }
                }
            }
        }
        for (int counterA = 0; counterA < 45; counterA++) {//PositionSet
            if (Points[counterA][5] == Claster) {
                Points[counterA][3] = PositionX;
                Points[counterA][4] = PositionY;
            }
        }
        MIN = 999;
    }
    void Normal() {
        int numberClaster = 100;
        int tempCountClaster = CountClaster = 1;
        for (int counterA = 0; counterA < 45; counterA++) {
            for (int counterB = 0; counterB < 45; counterB++) {
                if (Points[counterB][5] == numberClaster) {
                    Points[counterB][5] = 0;
                    Points[counterB][2] = tempCountClaster;
                    CountClaster = tempCountClaster;
                }
            }
            numberClaster++;
            tempCountClaster++;
        }
        cout << endl << "Кластеров: " << CountClaster;
    }
    void Ouput(int Clasters) {
        CountClaster = 1;
        for (int counterA = 0; counterA < Clasters; counterA++) {
            cout << endl << "Кластер: " << counterA + 1 << endl;
            for (int counterB = 0; counterB < 45; counterB++) {
                if (Points[counterB][2] == CountClaster) {
                    cout << endl << " (" << Points[counterB][0] << ", " << Points[counterB][1] << ")";
                }
            }
            CountClaster++;
        }
        for (int counter = 0; counter < ThorndijkCounter; counter++){
            for (int counter1 = 0; counter1 < ThorndijkCounter; counter1++){
                if (Thorndijk[counter] < Thorndijk[counter1]){
                    swap(Thorndijk[counter], Thorndijk[counter1]);
                }
            }
        }
        cout << endl << "Кривая Торндейка: ";
        for (int counter = 0; counter < ThorndijkCounter; counter++)
        {
            cout << Thorndijk[counter] << " ";
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int Clasters = 3;
    cout << endl << "На сколько кластеров разбить? ";
    cin >> Clasters;
    Merger example;
    example.Start();
    while (Clasters != example.CountClaster) {
        example.SliyaniyeClasters();
        example.PAROGIBANI++;
    }
    example.Ouput(Clasters);
    system("pause");
    return 0;
}