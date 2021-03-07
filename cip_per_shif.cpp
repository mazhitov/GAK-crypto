#include<iostream>
#include<ctime>
#include<string>
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
// Получение матрицы без i-й строки и j-го столбца
void GetMatr(int **mas, int **p, int i, int j, int m) {
	int ki, kj, di, dj;
	di = 0;
	for (ki = 0; ki < m - 1; ki++) { // проверка индекса строки
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj < m - 1; kj++) { // проверка индекса столбца
			if (kj == j) dj = 1;
			p[ki][kj] = mas[ki + di][kj + dj];
		}
	}
}
// Рекурсивное вычисление определителя
int Determinant(int **mas, int m) {
	int i, j, d, k, n;
	int **p;
	p = new int*[m];
	for (i = 0; i < m; i++)
		p[i] = new int[m];
	j = 0; d = 0;
	k = 1;//(-1) в степени i
	n = m - 1;
	if (m < 1) cout << "Определитель вычислить невозможно!";
	if (m == 1) {
		d = (mas[0][0]) % 26;
		if (d < 0) {
			d += 26;
		}
		return(d);
	}
	if (m == 2) {
		d = (mas[0][0] * mas[1][1]) - (mas[1][0] * mas[0][1]) % 26;
		if (d < 0) {
			d += 26;
		}
		return(d);
	}
	if (m > 2) {
		for (i = 0; i < m; i++) {
			GetMatr(mas, p, i, 0, m);
			/*cout << mas[i][j] << endl;*/
			/*PrintMatr(p, n);*/
			d = (d + k * mas[i][0] * Determinant(p, n)) % 26;
			if (d < 0) {
				d += 26;
			}
			k = -k;
		}
	}
	return(d);
}
//ввод ключа
void input(int **K, int m) {
	int d;
label:
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			K[i][j] = rand() % 26;
			if (m - 1 == i && m - 1 == j) {
				d = Determinant(K, m);
				if ((d == 0) || (d % 2 == 0) || (d % 13 == 0)) {

					i = 0; j = 0;
					cout << "Матрица не имеет инверсию\n";
					goto label;
					/*K[i][j] = rand() % 26;*/
				}
				else {
					cout << "Матрица имеет инверсию, Ключ равен : \n";
					PrintMatr(K, m);
				}
			}

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
void inputkey(int **K, int m, int *key) {
	for (int d = 0; d < m; d++) {
		for (int i = 0; i < m; i++) {
			for (int t = 0; t < m; t++) {
				if ((key[d]-1) == t) {
					K[t][i] = 1;
				}
				else {
					K[t][i] = 0;
				}
			}
			d++;
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
	int **P, **K, **C;
	double keysize;
	string text; double n = 0, m = 0;
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	double j = 0;
	cout << "Введите текст: ";
	cin >> text;
	cout << "ВВедите размер ключа : ";
	cin >> keysize;
	cout << "Введите ключ : ";
	int *key = new int[keysize];
	for (int i = 0; i < keysize; i++) {
		cin >> key[i];
	}


	int*F = new int[text.size()];
	
	for (int k = 0; k < text.size(); k++) {
		for (int n = 0; n < 26; n++) {
			if (text[k] == alpha[n]) {
				F[k] = n;
				j++;
			}

		}
	}
	
	m = keysize;
	n = ceil(j / keysize);

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
	inputP(P, n, m, F, j);
	cout << "P:\t\n";
	output(P, n, m);
	/*input(K, m);*/ // создание ключевой матрицы
	/*for (int i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			cout << "mas[" << i << "][" << j << "]= ";
			cin >> K[i][j];
		}
	}*/
	cout << "K:\t\n";
	inputkey(K, m, key);
	PrintMatr(K, m);
	//ENEMYATTACKSTONIGHT
	func2(P, K, C, n, m);
	cout << "C:\t\n";
	output(C, n, m);
	cout << endl;
	for (int l = 0; l < n; l++) {
		for (int s = 0; s < m; s++) {
			for (int n = 0; n < 26; n++) {
				if (C[l][s] == n) {
					cout << alpha[n];

				}

			}
		}
	}

	del(P, n);
	del(K, m);
	del(C, n);


	
	system("pause");
	return 0;

}

