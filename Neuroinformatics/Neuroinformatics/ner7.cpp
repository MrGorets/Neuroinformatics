#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Merger {
private:
    float Points[42][6] = {
        {1,1},{1,3},{1,6},{2,3},{2,6},{3,2},{3,5},{3,7},{4,1},
        {4,3},{4,5},{5,2},{5,4},{6,6},{8,1},{8,4},{9,2},{9,4},{9,5},
        {10,1},{10,3},{10,4},{11,3},{11,5},{11,7},{12,1},{12,2},{12,4},
        {6,15},{7,11},{7,14},{8,13},{8,15},{9,12},{10,11},{10,15},{11,12},
        {9,13},{11,14},{12,10},{12,12},{12,15} };
    float MIN = 999;
    float MainClasters[3][6] = {
        {2,4,1},
        {11,2,2},
        {11,13,3}
    };//öåíòğû êëàñòåğîâ
public:
    int CountClaster = 1;
    int PAROG = 6;
    Merger() {};
    float Rage(float X1, float Y1, float X2, float Y2) {
        return sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
    }
    void Start() {
        while (CountClaster!=0) {
            for (int counterA = 0; counterA < 3; counterA++) {


                for (int counterB = 0; counterB < 42; counterB++) {
                    if (Points[counterB][2] == 0) {// íå ïğîâåğÿòü òî÷êè êîòîğûå óæå â êëàñòåğàõ

                        float temp = Rage(MainClasters[counterA][0], MainClasters[counterA][1], Points[counterB][0], Points[counterB][1]);
                        if (temp < MIN) {
                            MIN = temp;
                        }

                    }
                }
                if ((MIN < PAROG)) {
                    Sliyaniye(counterA, counterA+1);
                }

            } 
            CountClaster = 0;
            for (int counter = 0; counter < 42; counter++) {
                if (Points[counter][2] == 0) {
                    CountClaster++;
                }
            }
            cout << endl << "Îäèíî÷íûõ êëàñòåğîâ: " << CountClaster;
        }        
    }
    void Sliyaniye(int A, int Claster) {
        int ÑountEqualRage = 0;
        float PositionX=0, PositionY=0;
        for (int counterA = 0; counterA < 42; counterA++) {//ClasresIndication 
            float temp = Rage(MainClasters[A][0], MainClasters[A][1], Points[counterA][0], Points[counterA][1]);
            if (temp == MIN) {
                if (Points[counterA][2] == 0) {
                    Points[counterA][2] = Claster;
                    ÑountEqualRage++;
                }
            }
        }    
        for (int counterA = 0; counterA < 42; counterA++) {//PositionCorrection
            if (Points[counterA][2] == Claster) {
                PositionX = PositionX + Points[counterA][0];
                PositionY = PositionY + Points[counterA][1];
            }
        }
        for (int counterA = 0; counterA < 42; counterA++) {//PositionSet 10 2
            if (Points[counterA][2] == Claster) {
                Points[counterA][3] = PositionX / (ÑountEqualRage + 1);
                Points[counterA][4] = PositionY / (ÑountEqualRage + 1);
            }
        }
        MainClasters[A][3] = PositionX / (ÑountEqualRage + 1);
        MainClasters[A][4] = PositionY / (ÑountEqualRage + 1);
        MIN = 999;
    }
    
    void Ouput(int Clasters) {
        CountClaster = 1;
        for (int counterA = 0; counterA < Clasters; counterA++) {
            cout << endl << endl << "Êëàñòåğ: " << counterA+1 << endl;
            cout << "Öåíòğ: (" << MainClasters[counterA][0] << ", " << MainClasters[counterA][1] << ")";
            for (int counterB = 0; counterB < 42; counterB++) {
                if (Points[counterB][2] == CountClaster) {
                   cout << endl << " (" << Points[counterB][0] <<", "<< Points[counterB][1]<<")";
                }
            }
            CountClaster++;
        }
    }
};

int main() {
	setlocale(LC_ALL, "rus");    
    Merger example;
    example.Start();   
    example.Ouput(3);
	system("pause");
	return 0;
}