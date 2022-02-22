// персональный шаблон C++
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int scoreplayer = 0, scoreComputer = 0;
bool yesOrno() {
	return rand() % 2;
}
void roll(bool comp = false) {
	int points = rand() % 6 + 1;//от 1 до 6 включительно
	if (points == 6) {
		if (!comp) {
			scoreplayer += points;
			cout << "Вам выпало 6.Хотите ли кинуть кубик еще раз?\n";
			cout << "Ответ--->";
			bool choise;
			cin >> choise;
			if (choise) {
				points = rand() % 6 + 1;
				if (points % 2)//нечетное число
					scoreplayer += points;
				cout << "Вам выпало " << points << " .\n";
				cout << "Игрок: " << scoreplayer << " .\n";
			}
			else {
				scoreplayer -= points;
				cout << "Вам выпало " << points << " .\n";
				cout << "Игрок: " << scoreplayer << " .\n";
			}


		}
		else
		{
			scoreComputer += points;
			if (yesOrno) {
				cout << "Компьютеру выпало 6.Он решил кинуть повторно.\n";
				points = rand() % 6 + 1;
				if (points % 2)
					scoreComputer += points;
				else
					scoreComputer -= points;
				cout << "Выпало " << points << ".\n";
				cout << "Компьютер: " << scoreComputer << ".\n";

			}
			else
			{
				cout << "Компьютеру выпало 6. Он решил не кидать повторно.\n";
			}

		}
	}
	else
		if (comp) {
			scoreComputer += points;
			cout << "Компьютеру выпало " << points << ".\n";
			cout << "Компьютер: " << scoreComputer << ".\n";
		}
		else {
			scoreplayer += points;
			cout << "Игроку выпало " << points << ".\n";
			cout << "Игрок: " << scoreplayer << ".\n";
		}

}

	

	

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int n;
	//for (int i = 0; i < 5; i++)
		//cout << yesOrno() << endl;


	cout << "Давай сыграем в кубики!\n";
	if (yesOrno() == true) {
		cout << "Начинает игрок\nИгрок бросает кубик-> ";
		roll();
	}
	else
		cout << "Начинает компьютер.\nКомпьютер бросает кубик-> ";
	do {
		if (scoreplayer < 50)
			roll(true);
		if (scoreComputer < 50)
			roll();

	} while (scoreplayer < 50 && scoreComputer < 50);
	if (scoreplayer >= 50)
		cout << "Вы победили!\n";
	else
		cout << "Победил компьютер!\n";
	


	return 0;
}