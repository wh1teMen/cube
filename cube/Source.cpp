// ������������ ������ C++
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int scoreplayer = 0, scoreComputer = 0;
bool yesOrno() {
	return rand() % 2;
}
void roll(bool comp = false) {
	int points = rand() % 6 + 1;//�� 1 �� 6 ������������
	if (points == 6) {
		if (!comp) {
			scoreplayer += points;
			cout << "��� ������ 6.������ �� ������ ����� ��� ���?\n";
			cout << "�����--->";
			bool choise;
			cin >> choise;
			if (choise) {
				points = rand() % 6 + 1;
				if (points % 2)//�������� �����
					scoreplayer += points;
				cout << "��� ������ " << points << " .\n";
				cout << "�����: " << scoreplayer << " .\n";
			}
			else {
				scoreplayer -= points;
				cout << "��� ������ " << points << " .\n";
				cout << "�����: " << scoreplayer << " .\n";
			}


		}
		else
		{
			scoreComputer += points;
			if (yesOrno) {
				cout << "���������� ������ 6.�� ����� ������ ��������.\n";
				points = rand() % 6 + 1;
				if (points % 2)
					scoreComputer += points;
				else
					scoreComputer -= points;
				cout << "������ " << points << ".\n";
				cout << "���������: " << scoreComputer << ".\n";

			}
			else
			{
				cout << "���������� ������ 6. �� ����� �� ������ ��������.\n";
			}

		}
	}
	else
		if (comp) {
			scoreComputer += points;
			cout << "���������� ������ " << points << ".\n";
			cout << "���������: " << scoreComputer << ".\n";
		}
		else {
			scoreplayer += points;
			cout << "������ ������ " << points << ".\n";
			cout << "�����: " << scoreplayer << ".\n";
		}

}

	

	

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int n;
	//for (int i = 0; i < 5; i++)
		//cout << yesOrno() << endl;


	cout << "����� ������� � ������!\n";
	if (yesOrno() == true) {
		cout << "�������� �����\n����� ������� �����-> ";
		roll();
	}
	else
		cout << "�������� ���������.\n��������� ������� �����-> ";
	do {
		if (scoreplayer < 50)
			roll(true);
		if (scoreComputer < 50)
			roll();

	} while (scoreplayer < 50 && scoreComputer < 50);
	if (scoreplayer >= 50)
		cout << "�� ��������!\n";
	else
		cout << "������� ���������!\n";
	


	return 0;
}