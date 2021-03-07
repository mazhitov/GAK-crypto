#include<iostream>
#include<ctime>
#include<string>
using namespace std;
void Get_Matr(int **matr, int n, int **temp_matr, int indRow, int indCol)
{
	int ki = 0;
	for (int i = 0; i < n; i++) {
		if (i != indRow) {
			for (int j = 0, kj = 0; j < n; j++) {
				if (j != indCol) {
					temp_matr[ki][kj] = matr[i][j];
					kj++;
				}
			}
			ki++;
		}
	}
}
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

//Функция транспонирования матрицы
template <typename T> void TransponMtx(T **matr, T **tMatr, int n) {//
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tMatr[j][i] = matr[i][j];
}

void input(int **K, int **obr_matr, int**tobr_matr, int m, int &q) {
	int d; int det = 0;
	d = Determinant(K, m);
	if ((d == 0) || (d % 2 == 0) || (d % 13 == 0)) {

		cout << "Матрица не имеет инверсию\n";
		q = 1;
	}
	else {
		for (int i = 1; i < 26; i++) {
			if (((i*d) % 26) == 1) {
				det = i;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				int n = m - 1;
				int **temp_matr = new int *[n];
				for (int k = 0; k < n; k++)
					temp_matr[k] = new int[n];
				Get_Matr(K, m, temp_matr, i, j);
				obr_matr[i][j] = pow(-1.0, i + j + 2) * Determinant(temp_matr, n)*det;
				obr_matr[i][j] %= 26;
				if (obr_matr[i][j] < 0) {
					obr_matr[i][j] += 26;
				}
				for (int i = 0; i < n; i++)
					delete[] temp_matr[i];
				delete[] temp_matr;
			}
		}

		TransponMtx(obr_matr, tobr_matr, m);
	}
}
void inputP(int **C, int n, int m, int *F, int j) {


	for (int d = 0; d < n*m; d++) {
		for (int i = 0; i < n; i++) {
			for (int t = 0; t < m; t++) {
				if ((d == j) || (d > j)) {
					C[i][t] = 25;
					d++;
				}
				else {
					C[i][t] = F[d++];
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
void func2(int**C, int**K, int**P, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			P[i][k] = 0;
			for (int j = 0; j < m; j++) {
				P[i][k] = (P[i][k] + C[i][j] * K[j][k]) % 26;
				if (P[i][k] < 0) {
					P[i][k] += 26;
				}
			}
		}
	}
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "");
	string textP, textC, text; int n = 0, m = 0, nC = 0, mC = 0, size = 0, n2 = 0, m2 = 0;
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int j = 0, jC = 0;
er1:
	cout << "Введите исходный текст:" << endl;
	cin >> textP;
	cout << "Введите зашифрованный текст:" << endl;
	cin >> textC;
	int*F = new int[textP.size()];
	int*G = new int[textC.size()];
	int*X = new int[text.size()];
	for (int k = 0; k < textP.size(); k++) {
		for (int n = 0; n < 26; n++) {
			if (textP[k] == alpha[n]) {
				F[k] = n;
				j++;
			}

		}
	}
	for (int k1 = 0; k1 < textC.size(); k1++) {
		for (int n = 0; n < 26; n++) {
			if (textC[k1] == alpha[n]) {
				G[k1] = n;
				jC++;
			}

		}
	}

	double y = 0, z = 0, j1 = 0, y1 = 0, z1 = 0, j1C = 0, y2 = 0, z2 = 0, j2 = 0;
	j1 = sqrt(j);
	j1C = sqrt(jC);

	y = floor((j1) * 100 + 0.5) / 100; //Создание матрицы P 
	y1 = floor((j1C) * 100 + 0.5) / 100; //Создание матрицы P 
	 //Создание матрицы P 
	z = round(y);
	z1 = round(y1);

	if ((y - z) > 0 && (y - z) < 0.5) {
		n = z;
		m = z + 1;
	}
	else {
		n = z;
		m = z;
	}


	if ((y1 - z1) > 0 && (y1 - z1) < 0.5) {
		nC = z1;
		mC = z1 + 1;
	}
	else {
		nC = z;
		mC = z;
	}
	if (nC == mC) {
		mC = nC;
	}
	else {
		cout << "Зашифрованный текст не является квадратной матрицей\n";
		goto er1;
	}

	int **P = new int*[n];
	int **t = new int*[n];
	int **Q = new int*[n];
	for (int i = 0; i < n; i++) {
		P[i] = new int[m];
		t[i] = new int[m];
		Q[i] = new int[m];
	}
	int **K = new int*[m];
	int **C = new int*[n];
	int **obr_matr = new int*[m];
	int **obr_matr2 = new int*[m];
	int **tobr_matr = new int*[m];
	int **tobr_matr2 = new int*[m];
	for (int i = 0; i < m; i++) {
		K[i] = new int[m];
		C[i] = new int[m];
		obr_matr[i] = new int[m];
		obr_matr2[i] = new int[m];
		tobr_matr[i] = new int[m];
		tobr_matr2[i] = new int[m];
	}

	inputP(P, n, m, F, j);
	cout << "P:\t\n";
	output(P, n, m);
	inputP(C, nC, mC, G, jC);
	cout << "С:\t\n";
	output(C, nC, mC);
	int q = 0;
	input(P, obr_matr, tobr_matr, m, q); // создание ключевой матрицы
	if (q == 1) {
		goto er1;
	}
	else {
		cout << "P^-1:\t\n";
		PrintMatr(tobr_matr, m);

		func2(tobr_matr, C, K, n, m);
		cout << "K:\t\n";
		output(K, n, m);
		cout << endl;
		cout << "Введите зашифрованный текст\n";
		cin >> text;
		for (int k = 0; k < text.size(); k++) {
			for (int n = 0; n < 26; n++) {
				if (text[k] == alpha[n]) {
					X[k] = n;
					size++;
				}

			}
		}
		j2 = sqrt(size);
		y2 = floor((j1C) * 100 + 0.5) / 100;
		z2 = round(y2);
		if ((y2 - z2) > 0 && (y2 - z2) < 0.5) {
			n2 = z2;
			m2 = z2 + 1; 
		}
		else {
			n2 = z2;
			m2 = z2;
		}
		inputP(t, n2, m2, X, size);
		cout << "P:\t\n";
		output(t, n2, m2);
		input(K, obr_matr2, tobr_matr2, m2, q); // создание ключевой матрицы
		if (q == 1) {
			goto er1;
		}
		cout << "K^-1:\t\n";
		PrintMatr(tobr_matr2, m2);

		func2(t, tobr_matr2, Q, n2, m2);

		cout << "Ваш расшифрованный текст:\n";
		for (int l = 0; l < n; l++) {
			for (int s = 0; s < m; s++) {
				for (int n = 0; n < 26; n++) {
					if (Q[l][s] == n) {
						cout << alpha[n];

					}

				}
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;

}

