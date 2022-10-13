#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string.h> 
#include <string> 
#include <clocale> 
#include <windows.h>

using namespace std;
string name(" ");
string secondplayer(" ");
bool win(false);
int turn(1);
bool FF(0), AIDoFirstTurn(0);

void fullfield(int** n, int k, int p) {
	int count(0);
	for (int i = 1; i < k; i++) {
		for (int j = 1; j < p; j++) {
			if (n[i][j] != 2)
				count += 1;
		}
	}
	if (count == 400) FF = 1;
}

void ciout(int** n, int k, int p) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < p; j++) {
			if ((i == 0) && (j == 0)) {
				cout << ' ' << ' ';
			}
			if ((i == 0) && (j != 0)) {
				cout << j % 10 << ' ';
			}
			if ((i != 0) && (j == 0)) {
				cout << i % 10 << ' ';
			}
			if ((n[i][j] == 2) && (i != 0) && (j != 0)) {
				cout << '_' << '|';
			}
			if ((n[i][j] == 0) && (i != 0) && (j != 0)) {
				cout << '0' << '|';
			}
			if ((n[i][j] == 1) && (i != 0) && (j != 0)) {
				cout << 'X' << '|';
			}
		}
		cout << endl;
	}
	cout << endl;

}
void AIfirstturn(int** n, int k, int p) {
	if (turn == 1) {
		n[10][10] = 0;
		turn += 1;
		AIDoFirstTurn = true;
		ciout(n, k, p);
	}
}

void computer(int** n, int k, int p) {
	int q = 0, aiturn = 0, a[400], five = 0, four = 0, three = 0, two = 0;
	for (int i = 1; i < k; i++) { //перевод двойного массива в одиночный
		for (int j = 1; j < p; j++) {
			a[q] = n[i][j];
			q++;
		}
	}

	//for victory
	for (int i = 0; i < 400; i++) {
		//checkup 3_1
		//build 5
		{
			//строка
			if ((a[i + 3] == 2) && (a[i] + a[i + 1] + a[i + 2] + a[i + 4] == 0) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
				a[i + 3] = 0; if (a[i + 3] == 0) { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
			//столбец 
			if ((a[i + 60] == 2) && (a[i] + a[i + 20] + a[i + 40] + a[i + 80] == 0) && (i >= 0) && (i <= 319)) {
				a[i + 60] = 0; if (a[i + 60] == 0) { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
			//гл.диагональ
			if ((a[i + 63] == 2) && (a[i] + a[i + 21] + a[i + 42] + a[i + 84] == 0) && (i >= 0) && (i <= 315)) {
				a[i + 63] = 0; if (a[i + 63] == 0) { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
			//побочная диагональ 
			if ((a[i + 57] == 2) && (a[i] + a[i + 19] + a[i + 38] + a[i + 76] == 0) && (i >= 0) && (i <= 342)) {
				a[i + 57] = 0; if (a[i + 57] == 0) { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
			if (aiturn == 1) break;
		}

		//checkup 1_3
		//build 5
		{
			//строка
			if ((a[i + 1] == 2) && (a[i] + a[i + 2] + a[i + 3] + a[i + 4] == 0) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
				a[i + 1] = 0; if (a[i + 1] == 0) { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
			//столбец 
			if ((a[i + 20] == 2) && (a[i] + a[i + 40] + a[i + 60] + a[i + 80] == 0) && (i >= 0) && (i <= 319)) {
				a[i + 20] = 0; if (a[i + 20] == 0) { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
			//гл.диагональ
			if ((a[i + 21] == 2) && (a[i] + a[i + 42] + a[i + 63] + a[i + 84] == 0) && (i >= 0) && (i <= 315)) {
				a[i + 21] = 0; { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
			//побочная диагональ 
			if ((a[i + 19] == 2) && (a[i] + a[i + 38] + a[i + 57] + a[i + 76] == 0) && (i >= 0) && (i <= 323)) {
				a[i + 19] = 0; if (a[i + 19] == 0) { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
		}

		//checkup 2_2
		//build 5
		{
			//строка
			if ((a[i + 2] == 2) && (a[i] + a[i + 1] + a[i + 3] + a[i + 4] == 0) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
				a[i + 2] = 0; if (a[i + 2] == 0) { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
			//столбец
			if ((a[i + 40] == 2) && (a[i] + a[i + 20] + a[i + 60] + a[i + 80] == 0) && (i >= 0) && (i <= 319)) {
				a[i + 40] = 0; if (a[i + 40] == 0) { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
			//гл.диагональ
			if ((a[i + 42] == 2) && (a[i] + a[i + 21] + a[i + 63] + a[i + 84] == 0) && (i >= 0) && (i <= 315)) {
				a[i + 42] = 0; if (a[i + 42] == 0) { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
			//побочная диагональ
			if ((a[i + 38] == 2) && (a[i] + a[i + 19] + a[i + 57] + a[i + 76] == 0) && (i >= 0) && (i <= 323)) {
				a[i + 38] = 0; if (a[i + 38] == 0) { aiturn = 1; five = 1; }
				if (aiturn == 1) break;
			}
		}

		//checkup 4
		//build 5
		{
			//строка
			if (((a[i + 4] == 2) || (a[i - 1] == 2)) && (a[i] + a[i + 1] + a[i + 2] + a[i + 3] == 0) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
				if (a[i + 4] == 2) {
					a[i + 4] = 0; if (a[i + 4] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 1] == 2) {
					a[i - 1] = 0; if (a[i - 1] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
			}
			//столбец 
			if (((a[i + 80] == 2) || (a[i - 20] == 2)) && (a[i] + a[i + 20] + a[i + 40] + a[i + 60] == 0) && (i >= 20) && (i <= 339)) {
				if (a[i + 80] == 2) {
					a[i + 80] = 0; if (a[i + 80] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 20] == 2) {
					a[i - 20] = 0; if (a[i - 20] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
			}
			//гл.диагональ
			if (((a[i + 84] == 2) || (a[i - 21] == 2)) && (a[i] + a[i + 21] + a[i + 42] + a[i + 63] == 0) && (i >= 21) && (i <= 336)) {
				if (a[i + 84] == 2) {
					a[i + 84] = 0; if (a[i + 84] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 21] == 2) {
					a[i - 21] = 0; if (a[i - 21] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
			}
			//побочная диагональ 
			if (((a[i + 76] == 2) || (a[i - 19] == 2)) && (a[i] + a[i + 19] + a[i + 38] + a[i + 57] == 0) && (i >= 19) && (i <= 323)) {
				if (a[i + 76] == 2) {
					a[i + 76] = 0; if (a[i + 76] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 19] == 2) {
					a[i - 19] = 0; if (a[i - 19] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				if (aiturn == 1) break;
			}
		}
		if (aiturn == 1) break;
	}
	//break player's victory
	if ((aiturn == 0) && (five == 0))
		for (int i = 0; i < 400; i++) {

			//checkup 3_1
			//interrupt player's victory
			{
				//строка
				if ((a[i + 3] == 2) && (a[i] + a[i + 1] + a[i + 2] + a[i + 4] == 4) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
					a[i + 3] = 0; if (a[i + 3] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				//столбец 
				if ((a[i + 60] == 2) && (a[i] + a[i + 20] + a[i + 40] + a[i + 80] == 4) && (i >= 0) && (i <= 319)) {
					a[i + 60] = 0; if (a[i + 60] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				//гл.диагональ
				if ((a[i + 63] == 2) && (a[i] + a[i + 21] + a[i + 42] + a[i + 84] == 4) && (i >= 0) && (i <= 315)) {
					a[i + 63] = 0; if (a[i + 63] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				//побочная диагональ 
				if ((a[i + 57] == 2) && (a[i] + a[i + 19] + a[i + 38] + a[i + 76] == 4) && (i >= 0) && (i <= 342)) {
					a[i + 57] = 0; if (a[i + 57] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				if (aiturn == 1) break;
			}

			//checkup 1_3
			//interrupt player's victory 
			{
				//строка
				if ((a[i + 1] == 2) && (a[i] + a[i + 2] + a[i + 3] + a[i + 4] == 4) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
					a[i + 1] = 0; if (a[i + 1] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				//столбец 
				if ((a[i + 20] == 2) && (a[i] + a[i + 40] + a[i + 60] + a[i + 80] == 4) && (i >= 0) && (i <= 319)) {
					a[i + 20] = 0; if (a[i + 20] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				//гл.диагональ
				if ((a[i + 21] == 2) && (a[i] + a[i + 42] + a[i + 63] + a[i + 84] == 4) && (i >= 0) && (i <= 315)) {
					a[i + 21] = 0; if (a[i + 21] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				//побочная диагональ 
				if ((a[i + 19] == 2) && (a[i] + a[i + 38] + a[i + 57] + a[i + 76] == 4) && (i >= 0) && (i <= 323)) {
					a[i + 19] = 0; if (a[i + 19] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				if (aiturn == 1) break;
			}

			//checkup 2_2
			//interrupt player's victory
			{
				//строка
				if ((a[i + 2] == 2) && (a[i] + a[i + 1] + a[i + 3] + a[i + 4] == 4) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
					a[i + 2] = 0; if (a[i + 2] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				//столбец
				if ((a[i + 40] == 2) && (a[i] + a[i + 20] + a[i + 60] + a[i + 80] == 4) && (i >= 0) && (i <= 319)) {
					a[i + 40] = 0; if (a[i + 40] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				//гл.диагональ
				if ((a[i + 42] == 2) && (a[i] + a[i + 21] + a[i + 63] + a[i + 84] == 4) && (i >= 0) && (i <= 315)) {
					a[i + 42] = 0; if (a[i + 42] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				//побочная диагональ
				if ((a[i + 38] == 2) && (a[i] + a[i + 19] + a[i + 57] + a[i + 76] == 4) && (i >= 0) && (i <= 323)) {
					a[i + 38] = 0; if (a[i + 38] == 0) { aiturn = 1; five = 1; }
					if (aiturn == 1) break;
				}
				if (aiturn == 1) break;
			}
			//checkup 4
						//interrupt player's victory, нужно перепроверить
			{
				//строка
				if (((a[i + 4] == 2) || (a[i - 1] == 2)) && (a[i] + a[i + 1] + a[i + 2] + a[i + 3] == 4) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
					if (a[i + 4] == 2) {
						a[i + 4] = 0; if (a[i + 4] == 0) { aiturn = 1; five = 1; }
						if (aiturn == 1) break;
					}
					if (a[i - 1] == 2) {
						a[i - 1] = 0; if (a[i - 1] == 0) { aiturn = 1; five = 1; }
						if (aiturn == 1) break;
					}
					if (aiturn == 1) break;
				}
				//столбец 
				if (((a[i + 80] == 2) || (a[i - 20] == 2)) && (a[i] + a[i + 20] + a[i + 40] + a[i + 60] == 4) && (i >= 20) && (i <= 339)) {
					if (a[i + 80] == 2) {
						a[i + 80] = 0; if (a[i + 80] == 0) { aiturn = 1; five = 1; }
						if (aiturn == 1) break;
					}
					if (a[i - 20] == 2) {
						a[i - 20] = 0; if (a[i - 20] == 0) { aiturn = 1; five = 1; }
						if (aiturn == 1) break;
					}
					if (aiturn == 1) break;
				}
				//гл.диагональ
				if (((a[i + 84] == 2) || (a[i - 21] == 2)) && (a[i] + a[i + 21] + a[i + 42] + a[i + 63] == 4) && (i >= 21) && (i <= 336)) {
					if (a[i + 84] == 2) {
						a[i + 84] = 0; if (a[i + 84] == 0) { aiturn = 1; five = 1; }
						if (aiturn == 1) break;
					}
					if (a[i - 21] == 2) {
						a[i - 21] = 0; if (a[i - 21] == 0) { aiturn = 1; five = 1; }
						if (aiturn == 1) break;
					}
					if (aiturn == 1) break;
				}
				//побочная диагональ 
				if (((a[i + 76] == 2) || (a[i - 19] == 2)) && (a[i] + a[i + 19] + a[i + 38] + a[i + 57] == 4) && (i >= 19) && (i <= 323)) {
					if (a[i + 76] == 2) {
						a[i + 76] = 0; if (a[i + 76] == 0) { aiturn = 1; five = 1; }
						if (aiturn == 1) break;
					}
					if (a[i - 19] == 2) {
						a[i - 19] = 0; if (a[i - 19] == 0) { aiturn = 1; five = 1; }
						if (aiturn == 1) break;
					}
					if (aiturn == 1) break;
				}
			}
			if (aiturn == 1) break;
		}

	//build4
	if ((aiturn == 0) && (four == 0))
		for (int i = 0; i < 400; i++) {
			//checkup 3
			//interrupt player's 4
			//строка
			if (((a[i + 3] == 2) || (a[i - 1] == 2)) && (a[i] + a[i + 1] + a[i + 2] == 3) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 18)) {
				if (a[i + 3] == 2) {
					a[i + 3] = 0; if (a[i + 3] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 1] == 2) {
					a[i - 1] = 0; if (a[i - 1] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
			}
			//столбец 
			if (((a[i + 60] == 2) || (a[i - 20] == 2)) && (a[i] + a[i + 20] + a[i + 40] == 3) && (i >= 20) && (i <= 339)) {
				if (a[i + 60] == 2) {
					a[i + 60] = 0; if (a[i + 60] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 20] == 2) {
					a[i - 20] = 0; if (a[i - 1] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
			}
			//гл.диагональ
			if (((a[i + 63] == 2) || (a[i - 21] == 2)) && (a[i] + a[i + 21] + a[i + 42] == 3) && (i >= 21) && (i <= 337)) {
				if (a[i + 63] == 2) {
					a[i + 63] = 0; if (a[i + 63] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 21] == 2) {
					a[i - 21] = 0; if (a[i - 21] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
			}
			//побочная диагональ 
			if (((a[i + 57] == 2) || (a[i - 19] == 2)) && (a[i] + a[i + 19] + a[i + 38] == 3) && (i >= 19) && (i <= 323)) {
				if (a[i + 57] == 2) {
					a[i + 57] = 0; if (a[i + 57] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 19] == 2) {
					a[i - 19] = 0; if (a[i - 19] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
				if (aiturn == 1) break;
			}

			//checkup 2_1
			//interrupt player's 4
				//строка
			if ((a[i + 2] == 2) && (a[i] + a[i + 1] + a[i + 3] == 3) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
				a[i + 2] = 0; if (a[i + 2] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			//столбец 
			if ((a[i + 40] == 2) && (a[i] + a[i + 20] + a[i + 60] == 3) && (i >= 0) && (i <= 339)) {
				a[i + 40] = 0; if (a[i + 40] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			//гл.диагональ
			if ((a[i + 42] == 2) && (a[i] + a[i + 21] + a[i + 63] == 3) && (i >= 0) && (i <= 336)) {
				a[i + 42] = 0; if (a[i + 42] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			//побочная диагональ 
			if ((a[i + 38] == 2) && (a[i] + a[i + 19] + a[i + 57] == 3) && (i >= 0) && (i <= 343)) {
				a[i + 38] = 0; if (a[i + 38] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			if (aiturn == 1) break;

			//checkup 1_2
			//interrupt player's 4
			//строка
			if ((a[i + 1] == 2) && (a[i] + a[i + 2] + a[i + 3] == 3) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
				a[i + 1] = 0; if (a[i + 1] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			//столбец 
			if ((a[i + 20] == 2) && (a[i] + a[i + 40] + a[i + 60] == 3) && (i >= 0) && (i <= 339)) {
				a[i + 20] = 0; if (a[i + 20] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			//гл.диагональ
			if ((a[i + 21] == 2) && (a[i] + a[i + 42] + a[i + 63] == 3) && (i >= 0) && (i <= 336)) {
				a[i + 21] = 0; if (a[i + 21] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			//побочная диагональ 
			if ((a[i + 19] == 2) && (a[i] + a[i + 38] + a[i + 57] == 3) && (i >= 0) && (i <= 343)) {
				a[i + 19] = 0; if (a[i + 19] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			if (aiturn == 1) break;
		}

	//break p's 4
	if ((aiturn == 0) && (four == 0))
		for (int i = 0; i < 400; i++) {
			//checkup 3
			//build 4
			//строка
			if (((a[i + 3] == 2) || (a[i - 1] == 2)) && (a[i] + a[i + 1] + a[i + 2] == 0) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 18)) {
				if (a[i + 3] == 2) {
					a[i + 3] = 0; if (a[i + 3] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 1] == 2) {
					a[i - 1] = 0; if (a[i - 1] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
			}
			//столбец 
			if (((a[i + 60] == 2) || (a[i - 20] == 2)) && (a[i] + a[i + 20] + a[i + 40] == 0) && (i >= 20) && (i <= 339)) {
				if (a[i + 60] == 2) {
					a[i + 60] = 0; if (a[i + 60] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 20] == 2) {
					a[i - 20] = 0; if (a[i - 1] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
			}
			//гл.диагональ
			if (((a[i + 63] == 2) || (a[i - 21] == 2)) && (a[i] + a[i + 21] + a[i + 42] == 0) && (i >= 21) && (i <= 337)) {
				if (a[i + 63] == 2) {
					a[i + 63] = 0; if (a[i + 63] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 21] == 2) {
					a[i - 21] = 0; if (a[i - 21] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
			}
			//побочная диагональ 
			if (((a[i + 57] == 2) || (a[i - 19] == 2)) && (a[i] + a[i + 19] + a[i + 38] == 0) && (i >= 19) && (i <= 323)) {
				if (a[i + 57] == 2) {
					a[i + 57] = 0; if (a[i + 57] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 19] == 2) {
					a[i - 19] = 0; if (a[i - 19] == 0) { aiturn = 1; four = 1; }
					if (aiturn == 1) break;
				}
				if (aiturn == 1) break;
			}
			//checkup 2_1
						//build 4
						//строка
			if ((a[i + 2] == 2) && (a[i] + a[i + 1] + a[i + 3] == 0) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
				a[i + 2] = 0; if (a[i + 2] == 0) { aiturn = 1; four = 1; }
			}
			//столбец 
			if ((a[i + 40] == 2) && (a[i] + a[i + 20] + a[i + 60] == 0) && (i >= 0) && (i <= 339)) {
				a[i + 40] = 0; if (a[i + 40] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			//гл.диагональ
			if ((a[i + 42] == 2) && (a[i] + a[i + 21] + a[i + 63] == 0) && (i >= 0) && (i <= 336)) {
				a[i + 42] = 0; if (a[i + 42] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			//побочная диагональ 
			if ((a[i + 38] == 2) && (a[i] + a[i + 19] + a[i + 57] == 0) && (i >= 0) && (i <= 343)) {
				a[i + 38] = 0; if (a[i + 38] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			if (aiturn == 1) break;

			//checkup 1_2
			//build 4
			//строка
			if ((a[i + 1] == 2) && (a[i] + a[i + 2] + a[i + 3] == 0) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
				a[i + 1] = 0; if (a[i + 1] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			//столбец 
			if ((a[i + 20] == 2) && (a[i] + a[i + 40] + a[i + 60] == 0) && (i >= 0) && (i <= 339)) {
				a[i + 20] = 0; if (a[i + 20] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			//гл.диагональ
			if ((a[i + 21] == 2) && (a[i] + a[i + 42] + a[i + 63] == 0) && (i >= 0) && (i <= 336)) {
				a[i + 21] = 0; if (a[i + 21] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			//побочная диагональ 
			if ((a[i + 19] == 2) && (a[i] + a[i + 38] + a[i + 57] == 0) && (i >= 0) && (i <= 343)) {
				a[i + 19] = 0; if (a[i + 19] == 0) { aiturn = 1; four = 1; }
				if (aiturn == 1) break;
			}
			if (aiturn == 1) break;
		}

	//build 3
	if ((aiturn == 0) && (four == 0))
		for (int i = 0; i < 400; i++) {
			//checkup 1_1
			//build 3 
				//строка
			if ((a[i + 1] == 2) && (a[i] + a[i + 2] == 0) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
				a[i + 1] = 0; if (a[i + 1] == 0) { aiturn = 1; three = 1; }
				if (aiturn == 1) break;
			}
			//столбец 
			if ((a[i + 20] == 2) && (a[i] + a[i + 40] == 0) && (i >= 0) && (i <= 339)) {
				a[i + 20] = 0; if (a[i + 20] == 0) { aiturn = 1; three = 1; }
				if (aiturn == 1) break;
			}
			//гл.диагональ
			if ((a[i + 21] == 2) && (a[i] + a[i + 42] == 0) && (i >= 0) && (i <= 336)) {
				a[i + 21] = 0; if (a[i + 21] == 0) { aiturn = 1; three = 1; }
				if (aiturn == 1) break;
			}
			//побочная диагональ 
			if ((a[i + 19] == 2) && (a[i] + a[i + 38] == 0) && (i >= 0) && (i <= 343)) {
				a[i + 19] = 0; if (a[i + 19] == 0) { aiturn = 1; three = 1; }
				if (aiturn == 1) break;
			}
			if (aiturn == 1) break;

			//checkup 2
			//build 3
			//строка
			if (((a[i + 2] == 2) || (a[i - 1] == 2)) && (a[i] + a[i + 1] == 0) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 18)) {
				if (a[i + 2] == 2) {
					a[i + 2] = 0; if (a[i + 2] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 1] == 2) {
					a[i - 1] = 0; if (a[i - 1] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
			}
			//столбец 
			if (((a[i + 40] == 2) || (a[i - 20] == 2)) && (a[i] + a[i + 20] == 0) && (i >= 20) && (i <= 339)) {
				if (a[i + 40] == 2) {
					a[i + 40] = 0; if (a[i + 40] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 20] == 2) {
					a[i - 20] = 0; if (a[i - 20] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
			}
			//гл.диагональ
			if (((a[i + 42] == 2) || (a[i - 21] == 2)) && (a[i] + a[i + 21] == 0) && (i >= 21) && (i <= 337)) {
				if (a[i + 42] == 2) {
					a[i + 42] = 0; if (a[i + 42] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 21] == 2) {
					a[i - 21] = 0; if (a[i - 21] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
			}
			//побочная диагональ 
			if (((a[i + 38] == 2) || (a[i - 19] == 2)) && (a[i] + a[i + 19] == 0) && (i >= 19) && (i <= 323)) {
				if (a[i + 38] == 2) {
					a[i + 38] = 0; if (a[i + 38] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 19] == 2) {
					a[i - 19] = 0; if (a[i - 19] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
				if (aiturn == 1) break;
			}
			if (aiturn == 1) break;
		}
	//break p's 3
	if ((aiturn == 0) && (four == 0))
		for (int i = 0; i < 400; i++) {
			//checkup 1_1
			//interrupt player's 3
			//строка
			if ((a[i + 1] == 2) && (a[i] + a[i + 2] == 2) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 16)) {
				a[i + 1] = 0; if (a[i + 1] == 0) { aiturn = 1; three = 1; }
				if (aiturn == 1) break;
			}
			//столбец 
			if ((a[i + 20] == 2) && (a[i] + a[i + 40] == 2) && (i >= 0) && (i <= 339)) {
				a[i + 20] = 0; if (a[i + 20] == 0) { aiturn = 1; three = 1; }
				if (aiturn == 1) break;
			}
			//гл.диагональ
			if ((a[i + 21] == 2) && (a[i] + a[i + 42] == 2) && (i >= 0) && (i <= 336)) {
				a[i + 21] = 0; if (a[i + 21] == 0) { aiturn = 1; three = 1; }
				if (aiturn == 1) break;
			}
			//побочная диагональ 
			if ((a[i + 19] == 2) && (a[i] + a[i + 38] == 2) && (i >= 0) && (i <= 343)) {
				a[i + 19] = 0; if (a[i + 19] == 0) { aiturn = 1; three = 1; }
				if (aiturn == 1) break;
			}
			if (aiturn == 1) break;

			//checkup 2
			//interrupt player's 3
			//строка
			if (((a[i + 2] == 2) || (a[i - 1] == 2)) && (a[i] + a[i + 1] == 2) && (i - 20 * ((i + 1) / 20 - 1) >= 0) && (i - 20 * ((i + 1) / 20 - 1) <= 18)) {
				if (a[i + 2] == 2) {
					a[i + 2] = 0; if (a[i + 2] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 1] == 2) {
					a[i - 1] = 0; if (a[i - 1] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
			}
			//столбец 
			if (((a[i + 40] == 2) || (a[i - 20] == 2)) && (a[i] + a[i + 20] == 2) && (i >= 20) && (i <= 339)) {
				if (a[i + 40] == 2) {
					a[i + 40] = 0; if (a[i + 40] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 20] == 2) {
					a[i - 20] = 0; if (a[i - 20] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
			}
			//гл.диагональ
			if (((a[i + 42] == 2) || (a[i - 21] == 2)) && (a[i] + a[i + 21] == 2) && (i >= 21) && (i <= 337)) {
				if (a[i + 42] == 2) {
					a[i + 42] = 0; if (a[i + 42] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 21] == 2) {
					a[i - 21] = 0; if (a[i - 21] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
			}
			//побочная диагональ 
			if (((a[i + 38] == 2) || (a[i - 19] == 2)) && (a[i] + a[i + 19] == 2) && (i >= 19) && (i <= 323)) {
				if (a[i + 38] == 2) {
					a[i + 38] = 0; if (a[i + 38] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
				if (a[i - 19] == 2) {
					a[i - 19] = 0; if (a[i - 19] == 0) { aiturn = 1; three = 1; }
					if (aiturn == 1) break;
				}
				if (aiturn == 1) break;
			}
			if (aiturn == 1) break;
		}

	//если все выше перечисленные не сделали ход, то сделать этот ход
	//2,3,4...n' ai turn

	if ((aiturn == 0) && (four == 0) && (three == 0)) for (int i = 0; i < 400; i++) {
		//2,3,4...n' ai turn
		if (aiturn == 0) {
			if ((a[i] == 1) && ((a[i + 21] == 2) || (a[i + 19] == 2) || (a[i - 21] == 2) || (a[i - 19] == 2))) {
				if (a[i + 21] == 2) {
					a[i + 21] = 0; if (a[i + 21] == 0) aiturn++;
					if (aiturn == 1) break;
				}
				if (a[i + 19] == 2) {
					a[i + 19] = 0; if (a[i + 19] == 0) aiturn++;
					if (aiturn == 1) break;
				}
				if (a[i - 21] == 2) {
					a[i - 21] = 0; if (a[i - 21] == 0) aiturn++;
					if (aiturn == 1) break;
				}
				if (a[i - 19] == 2) {
					a[i - 19] = 0; if (a[i - 19] == 2) aiturn++;
					if (aiturn == 1) break;
				}
				if (aiturn == 1) break;
			}
		}
		if (aiturn == 1) break;
	}

	for (int i = 1, q = 0; i < k; i++) { //обратный перевод из одиночного массива в двойной
		for (int j = 1; j < p; j++) {
			n[i][j] = a[q];
			q++;
		}
	}
	//честно говоря, я очень устал от этой программы
	ciout(n, k, p);
	turn++;
}
void wincheck(int** n, int k, int p) {
	int crosses(0), zeros(0);
	for (int i = 0; i < k; i++) { //горизонтальная проверка
		for (int j = 0; j < p; j++) {
			if (n[i][j] == 1) {
				crosses += 1;
				zeros = 0;
			}
			if (n[i][j] == 0) {
				crosses = 0;
				zeros += 1;
			}
			if (n[i][j] == 2) {
				crosses = 0;
				zeros = 0;
			}
			if (crosses == 5) {
				cout << "Поздравляю, ты победил компьютер\n" << "Лавры победителя и почёт\n";
				win = true;
			}
			if (zeros == 5) {
				cout << "К сожалению ты проиграл, но не переживай, в следующий раз получится победить!\n\n";
				win = true;
			}
			if (win == true) break;
		}
		if (win == true) break;
	}

	crosses = zeros = 0;

	for (int j = 0; j < p; j++) { //вертикальная проверка
		for (int i = 0; i < k; i++) {
			if (n[i][j] == 1) {
				crosses += 1;
				zeros = 0;
			}
			if (n[i][j] == 0) {
				crosses = 0;
				zeros += 1;
			}
			if (n[i][j] == 2) {
				crosses = 0;
				zeros = 0;
			}
			if (crosses == 5) {
				cout << "Поздравляю, ты победил компьютер\n" << "Лавры победителя и почёт\n";
				win = true;
			}
			if (zeros == 5) {
				cout << "К сожалению ты проиграл, но не переживай, в следующий раз получится победить!\n\n";
				win = true;
			}
			if (win == true) break;
		}
		if (win == true) break;
	}

	crosses = zeros = 0;

	for (int i = 0; i < k; i++) { //проверка по диагонали слева сверху направо вниз
		for (int j = 0; j < p - i; j++) {
			if (n[i + j][j] == 1) {
				crosses += 1;
				zeros = 0;
			}
			if (n[i + j][j] == 0) {
				crosses = 0;
				zeros += 1;
			}
			if (n[i + j][j] == 2) {
				crosses = 0;
				zeros = 0;
			}
			if (crosses == 5) {
				cout << "Поздравляю, ты победил компьютер\n" << "Лавры победителя и почёт\n";
				win = true;
			}
			if (zeros == 5) {
				cout << "К сожалению ты проиграл, но не переживай, в следующий раз получится победить!\n\n";
				win = true;
			}
			if (win == true) break;
		}
		if (win == true) break;

		for (int j = 0; j < p - i; j++) {
			if (n[j][i + j] == 1) {
				crosses += 1;
				zeros = 0;
			}
			if (n[j][i + j] == 0) {
				crosses = 0;
				zeros += 1;
			}
			if (n[j][i + j] == 2) {
				crosses = 0;
				zeros = 0;
			}
			if (crosses == 5) {
				cout << "Поздравляю, ты победил компьютер\n" << "Лавры победителя и почёт\n";
				win = true;
			}
			if (zeros == 5) {
				cout << "К сожалению ты проиграл, но не переживай, в следующий раз получится победить!\n\n";
				win = true;
			}
			if (win == true) break;
		}
	}

	crosses = zeros = 0;

	for (int i = 0; i < k; i++) { //проверка слева снизу направо вверх
		for (int j = 0; j < i + 1; j++) {
			if (n[i - j][j] == 1) {
				crosses += 1;
				zeros = 0;
			}
			if (n[i - j][j] == 0) {
				crosses = 0;
				zeros += 1;
			}
			if (n[i - j][j] == 2) {
				crosses = 0;
				zeros = 0;
			}
			if (crosses == 5) {
				cout << "Поздравляю, ты победил компьютер\n" << "Лавры победителя и почёт\n";
				win = true;
			}
			if (zeros == 5) {
				cout << "К сожалению ты проиграл, но не переживай, в следующий раз получится победить!\n\n";
				win = true;
			}
			if (win == true) break;
		}
		if (win == true) break;
	}

	for (int i = k - 1; i >= 0; i--) {
		for (int j = 0; j < i + 1; j++) {
			if (n[k - 1 - j][k - i - 1 + j] == 1) {
				crosses += 1;
				zeros = 0;
			}
			if (n[k - 1 - j][k - i - 1 + j] == 0) {
				crosses = 0;
				zeros += 1;
			}
			if (n[k - 1 - j][k - i - 1 + j] == 2) {
				crosses = 0;
				zeros = 0;
			}
			if (crosses == 5) {
				cout << "Поздравляю, ты победил компьютер\n" << "Лавры победителя и почёт\n";
				win = true;
			}
			if (zeros == 5) {
				cout << "К сожалению ты проиграл, но не переживай, в следующий раз получится победить!\n\n";
				win = true;
			}
			if (win == true) break;
		}
		if (win == true) break;
	}
}
void player(int** n, int k, int p) {
	setlocale(LC_ALL, "Rus");
	string ixx, jxx;
	cout << name << ", введите строку - ";
	getline(cin, ixx);
	cout << "И ещё будь добр, столбец - ";
	getline(cin, jxx);
	cout << endl;
	int ix = atoi(ixx.c_str()), jx = atoi(jxx.c_str());
	//проверка на неправильный ввод, так сказать, проверка на "дурака"
	while ((ix <= 0) || (ix > 20) || (jx <= 0) || (jx > 20)) {
		if ((ix <= 0) || (ix > 20)) {
			cout << "Кажется строчка за пределами поля.. Давай заново строчку - ";
			getline(cin, ixx);
			ix = atoi(ixx.c_str());
		}
		if ((jx <= 0) || (jx > 20)) {
			cout << "Блин, столбец неправильный. Введи пожалуйста ещё раз - ";
			getline(cin, jxx);
			jx = atoi(jxx.c_str());
		}
	}
	if ((n[ix][jx] == 1) || (n[ix][jx] == 0)) {
		cout << "Дружище, клетка занята. Давай в другую... Введи строчку - ";
		getline(cin, ixx);
		ix = atoi(ixx.c_str());
		cout << "И столбец - ";
		getline(cin, jxx);
		jx = atoi(jxx.c_str());
		cout << endl;
	}
	if (((ix > 0) && (jx > 0)) && ((ix <= 20) && (jx <= 20))) {
		cout << endl;
		n[ix][jx] = 1;
		ciout(n, k, p);
		cout << endl;
	}
	turn++;
}

void player2(int** n, int k, int p) {
	setlocale(LC_ALL, "Rus");
	string ioo, joo;
	cout << secondplayer << ", введите строку - ";
	getline(cin, ioo);
	cout << "И ещё будь добр, столбец - ";
	getline(cin, joo);
	cout << endl;
	int io = atoi(ioo.c_str()), jojo = atoi(joo.c_str());

	while ((io <= 0) || (io > 20) || (jojo <= 0) || (jojo > 20)) {
		if ((io <= 0) || (io > 20)) {
			cout << "Кажется строчка за пределами поля.. Давай заново строчку - ";
			getline(cin, ioo);
			io = atoi(ioo.c_str());
		}
		if ((jojo <= 0) || (jojo > 20)) {
			cout << "Блин, столбец неправильный. Введи пожалуйста ещё раз - ";
			getline(cin, joo);
			jojo = atoi(joo.c_str());
		}
	}
	if ((n[io][jojo] == 1) || (n[io][jojo] == 0)) {
		cout << "Дружище, клетка занята. Давай в другую... Введи строчку - ";
		getline(cin, ioo);
		io = atoi(ioo.c_str());
		cout << "И столбец - ";
		getline(cin, joo);
		jojo = atoi(joo.c_str());
		cout << endl;
	}
	if (((io > 0) && (jojo > 0)) && ((io <= 20) && (jojo <= 20))) {
		cout << endl;
		n[io][jojo] = 0;
		ciout(n, k, p);
		cout << endl;
	}
	turn++;
}
//я не знаю, будете ли вы читать до этого момента, но вы хороший человек 
int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int k, p, ** n, whoisfirst = rand();
	k = p = 21;
	n = new int* [k];
	bool playerschoice(0); //переменная для выбора между игрой игрок/компьютер, игрок/игрок

	cout << "Введите свое имя" << endl << ">";
	getline(cin, name);
	cout << "Отлично, " << name << ", давай играть\n"; /*"<< , но погоди, может ты хочешь сыграть с другом?" << endl << "Если так, то введи 1 или 0, где 1 - игра с другом, а 0 - игра с компьютером" << endl;*/
	if (playerschoice == 1) {
		cout << "И имя второго игрока.\n" << ">";
		cin >> secondplayer;
		cout << endl << "Отлично, а теперь давай играть." << endl;
	}
	system("pause");
	cout << endl;

	for (int i = 0; i <= k; i++) { //заполнение поля пустыми элементами
		n[i] = new int[p];
		for (int j = 0; j <= p; j++) {
			n[i][j] = 2;
		}
	}

	if (playerschoice == 0) {
		if (whoisfirst % 2 == 0) {
			while (win == 0) {
				if (turn == 1) {
					cout << "По воле случая ты начинаешь первый" << endl;
					cout << "Ход " << turn << endl << "Ход игрока" << endl << endl;
					ciout(n, k, p);
					cout << endl;
					player(n, k, p);
				}
				if (turn > 2) {
					cout << "Ход " << turn << endl << "Ход игрока" << endl;
					player(n, k, p);
					wincheck(n, k, p);
					if (win == 1) break;
				}
				cout << "Ход " << turn << endl << "Ход ИИ" << endl;
				computer(n, k, p);
				fullfield(n, k, p);
				wincheck(n, k, p);
				if (FF == 1) {
					cout << "Упс, поле заполнилось до конца, а победителя так и нет.." << endl << "В таком случае я объявляю ничью!" << endl;
					system("pause");
					exit(0);
				}
			}
		}
		else if (whoisfirst % 2 != 0) {
			while (win == 0) {
				if (turn == 1) {
					cout << "Ход " << turn << endl << "Ход ИИ" << endl;
					AIfirstturn(n, k, p);
				}
				if (turn > 2) {
					cout << "Ход " << turn << endl << "Ход ИИ" << endl;
					computer(n, k, p);
					wincheck(n, k, p);
					if (win == 1) break;
				}
				cout << "Ход " << turn << endl << "Ход игрока" << endl;
				player(n, k, p);
				fullfield(n, k, p);
				wincheck(n, k, p);
				if (FF == 1) {
					cout << "Упс, поле заполнилось до конца, а победителя так и нет.." << endl << "В таком случае я объявляю ничью!" << endl;
					system("pause");
					exit(0);
				}
			}
		}
	}
	else if (playerschoice == 1) {
		if (whoisfirst % 2 == 0) {
			while (win == 0) {
				cout << "Ход " << turn << endl << "Ход игрока" << " " << name << endl << endl;
				ciout(n, k, p);
				player(n, k, p);
				cout << "Ход " << turn << endl << "Ход игрока " << secondplayer << endl;
				ciout(n, k, p);
				player2(n, k, p);
				fullfield(n, k, p);
				wincheck(n, k, p);
				if (FF == 1) {
					cout << "Упс, поле заполнилось до конца, а победителя так и нет.." << endl << "В таком случае я объявляю ничью!" << endl;
					system("pause");
					exit(0);
				}
			}
		}
		else if (whoisfirst % 2 != 0) {
			while (win == 0) {
				cout << "Ход " << turn << endl << "Ход игрока " << secondplayer << endl;
				ciout(n, k, p);
				player2(n, k, p);
				cout << "Ход " << turn << endl << "Ход игрока " << name << endl;
				ciout(n, k, p);
				player(n, k, p);
				fullfield(n, k, p);
				wincheck(n, k, p);
				if (FF == 1) {
					cout << "Упс, поле заполнилось до конца, а победителя так и нет.." << endl << "В таком случае я объявляю ничью!" << endl;
					system("pause");
					exit(0);
				}
			}
		}
	}
	return 0;
}
