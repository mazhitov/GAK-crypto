#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int mas[100], c;
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

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
void output(int**A, int n, int m);
void func2(int**A, int**B, int**C, int n, int m);

void perms(int **P,int **K,int **C,int k, int m,int n)
{
	if (k == m) {
		//printf("%d:\t", ++c); 
		int p = 0;
		for (int i = 0; i < 1; i++) {
			cout << "==========================================";
			cout << endl;
			for (int banan = 0; banan < m; banan++) {
				printf("%d", mas[banan]);
				cout << "-";
			}
			if (p == 0) {
				
				cout << "Kлюч дешифрования, а это матрица ключа:\t\n";
				input(K, m, mas);
				PrintMatr(K, m);
				func2(P, K, C, n, m);
				cout << "P:\t\n";
				output(C, n, m);
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
				printf("\n");
				p = 1;
				
			}
		}
	}
	else {
		for (int i = 1; i <= m; i++) {
			int f = 0;
			for (int j = 0; j < k; j++)
				if (mas[j] == i) f = 1;
			if (f) continue;
			mas[k] = i;
			perms(P,K,C,k + 1, m,n);
		}
	}
}

void inputP(int **P, int n, int m, int *F, int j) {


	for (int d = 0; d < n*m; d++) {
		for (int i = 0; i < n; i++) {
			for (int t = 0; t < m; t++) {
				if ((d == j) || (d > j)) {
					P[i][t] = 25;
					d++;
				}
				else {
					P[i][t] = F[d++];
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
int main()
{
	setlocale(LC_ALL, "");
	int **P, **K, **C, *key,*choose; int sizekey;
	string text;
	int n = 0, m = 0;
	
	int j = 0;
	int k;
	c = 0;

	

	cout << "Введите зашифрованный текст:" << endl;

	cin >> text;

	int*F = new int[text.size()];
	//int*deKey = new int[sizekey];
	for (int k = 0; k < text.size(); k++) {
		for (int n = 0; n < 26; n++) {
			if (text[k] == alpha[n]) {
				F[k] = n;
				j++;
			}
		}
	}
chose:
	choose = new int[j];
	cout << "Массив делителей : ";
	for (int start = 1; start <= j; start++) {
		if (j%start == 0) {
			choose[start] = start;
		}
		else {
			choose[start] = 0;
		}
	}
	for (int start = 1; start <= j; start++) {
		if (choose[start] != 0) {
			cout << choose[start] << " ";
		}
	}
	int delitel = 1;
	cout << "Введите делитель : ";
	cin >> delitel;

	
			n = j / delitel;
			m = delitel;
			
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
			cout << "\nС:\t\n";
			output(P, n, m);
			perms(P, K, C, 0, m, n);

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
	cout << endl;
	goto chose;
	system("pause");
	return 0;
}

