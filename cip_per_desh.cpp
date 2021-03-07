#include<iostream>
#include<ctime>
#include<string>
#include<cmath>
using namespace std;

void PrintMatr(int **mas, int m) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void input(int **K, int m, int *key) {
	for (int l = 0; l < m; l++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if ((key[l] - 1) == j) {
					K[j][i] = 1;

				}
				else {
					K[j][i] = 0;

				}
			}
			l++;
		}
	}
}
void inputP(int **P, int n, int m, int *F, int j) {


	for (int d = 0; d < n*m; d++) {
		for (int i = 0; i < n; i++) {
			for (int t = 0; t < m; t++) {
				if ((d == j) || (d > j)) {
					P[i][t] = 25; /*inputP(P, n, m, 25);*/
					d++;
				}
				else {
					P[i][t] = F[d++];/*inputP(P, n, m, F[d]);*/
				}
			}
		}
	}
}


void output(int**A, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
}
void func2(int**A, int**B, int**C, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			C[i][k] = 0;
			for (int j = 0; j < m; j++) {
				C[i][k] = (C[i][k] + A[i][j] * B[j][k]) % 26;
				if (C[i][k] < 0) {
					C[i][k] += 26;
				}
			}
		}
	}
}
void del(int**A, int n) {
	for (int i = 0; i < n; i++)
		delete A[i];
	delete[] A;

}
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "");
	int **P, **K, **C, *key; double sizekey;

	string text;
	double n = 0, m = 0;
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	double j = 0;
	cout << "Введите размер ключа\n";
	cin >> sizekey;
	key = new int[sizekey];
	cout << "Введите ключ\n";
	for (int start = 0; start < sizekey; start++) {
		cin >> key[start];

	}

	cout << "Введите зашифрованный текст:" << endl;
	cin >> text;

	int*F = new int[text.size()];
	int*deKey = new int[sizekey];
	for (int k = 0; k < text.size(); k++) {
		for (int n = 0; n < 26; n++) {
			if (text[k] == alpha[n]) {
				F[k] = n;
				j++;
			}

		}
	}
	double j1 = 0;
	j1 = j / sizekey;
	m = sizekey;
	n = ceil(j1);
	P = new int*[n];
	for (int i = 0; i < n; i++) {
		P[i] = new int[m];
	}
	K = new int*[m];
	for (int i = 0; i < m; i++) {
		K[i] = new int[m];
	}
	C = new int*[n];
	for (int i = 0; i < n; i++) {
		C[i] = new int[m];
	}


	// создание ключевой матрицы
	for (int q = 0; q < m; q++) {
		int s = 0;
		s = key[q] - 1;
		deKey[s] = q + 1;
	}

	cout << "Ваш ключ дешифрования\n";
	for (int i = 0; i < m; i++) {
		cout << deKey[i] << "  ";
	}

	inputP(P, n, m, F, j);
	cout << "\nС:\t\n";

	output(P, n, m);
	cout << "K:\t\n";
	input(K, m, deKey);
	PrintMatr(K, m);
	func2(P, K, C, n, m);
	cout << "P:\t\n";
	output(C, n, m);
	cout << endl;
	cout << "Ваш зашифрованный текст:\n";
	for (int l = 0; l < n; l++) {
		for (int s = 0; s < m; s++) {
			for (int n = 0; n < 26; n++) {
				if (C[l][s] == n) {
					cout << alpha[n];

				}

			}
		}
	}
	cout << endl;
	del(P, n);
	del(K, m);
	del(C, n);
	system("pause");
	return 0;

}

