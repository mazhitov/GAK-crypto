#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	int x = 0;
	int choice;
	string DecryptedText;
	string text;
	string	keyEncrypt;
	string  keyDecrypt;
	string A = "abcdefghijklmnopqrstvuwxyz";
	int j1 = 0;
	int j2 = 0;
	while (x == 0) {
		system("cls");
		cout << "	МЕНЮ(Афинный Шифр)					" << endl;
		cout << "===================================================\n";
		cout << "1.Шифрование." << endl;
		cout << "2.Дешифрование." << endl;
		cout << "3.Атака грубой силой." << endl;
		cout << "4.Атака по образцу." << endl;
		cout << "5.Выход." << endl;
		cout << "===================================================\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			string text1;
			int keyA1, keyM1;
			string A1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int j1 = 0;
			cout << "Введите текст для шифрования :" << endl;
			cin >> text1;
			cout << "Введите Аддитивный ключ для шифрования" << endl;
			cin >> keyA1;
			cout << "Введите мультипликативный шифр ключ для шифрования" << endl;
			cin >> keyM1;
			int* F1 = new int[text1.size()];

			for (int k1 = 0; k1 < text1.size(); k1++) {
				for (int n1 = 0; n1 < 26; n1++) {
					if (text1[k1] == A1[n1]) {
						F1[k1] = n1;
					}

				}
			}
			int e1 = 0;
			for (int u1 = 0; u1 < text1.size(); u1++) {

				e1 = (((F1[u1] * keyM1) + keyA1) % 26);
				text1[u1] = A1[e1];
			}
			cout << "Зашифрованный текст: " << text1 << endl;
			delete[] F1;
			_getch();
			continue;
		}
		case 2: {
			system("cls");
			string text2;
			int keyA2, keyM2;
			string A2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int j2 = 0, ka = 0, km = 0;
			cout << "Введите зашифрованный текст:" << endl;
			cin >> text2;
			cout << "Введите Аддитивный ключ для шифрования" << endl;
			cin >> keyA2;
		l1:cout << "Введите мультипликативный шифр ключ для шифрования" << endl;
			cin >> keyM2;
			for (int i = 1; i < 26; i++) {
				if (((keyM2*i) % 26) == 1) {
					km = i;
					j2 = 1;
				}
			}
			if (j2 == 0) {
				goto l1;
			}
			ka = 26 - keyA2;
			int* F2 = new int[text2.size()];

			for (int k2 = 0; k2 < text2.size(); k2++) {
				for (int n2 = 0; n2 < 26; n2++) {
					if (text2[k2] == A2[n2]) {
						F2[k2] = n2;
					}

				}
			}
			int e2 = 0;
			for (int u2 = 0; u2 < text2.size(); u2++) {

				e2 = (((F2[u2] + ka)* km) % 26);
				text2[u2] = A2[e2];
			}
			cout << "Расшифрованный текст : " << text2 << endl;
			delete[] F2;
			_getch();
			system("cls");
			continue;
		}
		case 3: {

			string text31;
			string A31 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int j31 = 0;
			cout << "Введите зашифрованный текст :" << endl;
			cin >> text31;
			cout << endl;
			int* F31 = new int[text31.size()];

			for (int k31 = 0; k31 < text31.size(); k31++) {
				for (int n31 = 0; n31 < 26; n31++) {
					if (text31[k31] == A31[n31]) {
						F31[k31] = n31;
					}
				}
			}
			for (int t31 = 0; t31 < 26; t31++) {
				for (int l31 = 0; l31 < 26; l31++) {
					int e31 = 0;
					for (int u31 = 0; u31 < text31.size(); u31++) {
						e31 = (((F31[u31] + t31)*l31) % 26);
						text31[u31] = A31[e31];
					}
					cout << "Расшифровка:\n " << text31 << "\nс ключом Ka^-1=" << t31 << "  c ключом Km^-1= " << l31 << endl;
					cout << "_____________________________________________________________________" << endl;
				}
			}
			//delete[] F31;	

			_getch();
			system("cls");
			continue;
		}
		case 4: {
			string text, obr_org, obr_cipher;
			string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int j = 0;
			cout << "Введите образец оригинального текста:" << endl;
			cin >> obr_org;
			cout << "Введите образец зашифрованнного текста:" << endl;
			cin >> obr_cipher;
			int* F = new int[text.size()];
			int* org = new int[obr_org.size()];
			int* cipher = new int[obr_cipher.size()];
			int** res = new int*[2];
			for (int i = 0; i < 2; i++) {
				res[i] = new int[2];
			}
			for (int i = 0; i < obr_org.size(); i++) {
				for (int n = 0; n < 26; n++) {
					if (obr_org[i] == A[n]) {
						org[i] = n;
					}

				}
			}
			for (int j = 0; j < obr_cipher.size(); j++) {
				for (int n = 0; n < 26; n++) {
					if (obr_cipher[j] == A[n]) {
						cipher[j] = n;
					}
				}
			}

			for (int i = 0; i < 2; i++) {
				res[0][0] = org[0];
				res[1][0] = org[1];
				res[i][1] = 1;

			}
			int det1 = 0; int detOtr1 = 0;
			det1 = (org[0] - org[1]);
			if (det1 < 0) {
				det1 += 26;
			}
			bool tmp = false;
			for (int i = 1; i <= 26; i++) {
				if (((det1*i) % 26) == 1) {
					detOtr1 = i;
					cout << "Обратная матрица существует\n" << endl;
					tmp = true;
				}
			}
			if (tmp == false) {
				cout << "Невозможно расшифровать, потому что не существует обратной матрицы для иcходного текста\n";
				system("pause");
				return 0;
			}

			cout << endl;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					if (((i + j) % 2) == 1) {
						res[i][j] = -res[i][j];
					}
				}
			}
			cout << endl;
			int a11 = 0, a21 = 0, a12 = 0, a22 = 0;
			a11 = res[0][0];
			a12 = res[0][1];
			a21 = res[1][0];
			a22 = res[1][1];
			res[0][0] = a22;
			res[0][1] = a21;
			res[1][0] = a12;
			res[1][1] = a11;

			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					res[i][j] = (res[i][j] * detOtr1) % 26;
					if (res[i][j] < 0) {
						res[i][j] += 26;
					}
				}
			}
			int km = 0, ka = 0;
			km = (res[0][0] * cipher[0] + res[0][1] * cipher[1]) % 26;
			ka = (res[1][0] * cipher[0] + res[1][1] * cipher[1]) % 26;
			cout << "Мультипликативный ключ  для шифрования : " << km << endl;
			cout << "Аддитивный ключ для шифрования : " << ka << endl;
			int KaOtr = 0, KmOtr = 0;
			for (int i = 1; i <= 26; i++) {
				if (((km*i) % 26) == 1) {
					KmOtr = i;
				}
			}
			KaOtr = 26 - ka;
			cout << "\nИнверсия мультипликативного ключа  для дешифрования : " << KmOtr << endl;
			cout << "Инверсия аддитивного ключа для дешифрования : " << KaOtr << endl << endl;
			cout << "Введите зашифрованный текст:" << endl;
			cin >> text;
			for (int k = 0; k < text.size(); k++) {
				for (int n = 0; n < 26; n++) {
					if (text[k] == A[n]) {
						F[k] = n;
					}
				}
			}



			int e = 0;
			for (int u = 0; u < text.size(); u++) {

				e = (((F[u] + KaOtr)* KmOtr) % 26);
				text[u] = A[e];
			}
			cout << "\nРасшифрованный текст: " << text << endl << endl;

			_getch();
			system("cls");
			/*delete[] F;
			delete[] org;
			delete[] cipher;
			for (int i = 0; i < 2; i++)
				delete res[i];
			delete[] res;*/
			continue;
		}

		case 5: {
			system("cls");
			_getch();
			x = 1;
			break;
		}
		}

	}

	system("pause");
	return 0;
}
