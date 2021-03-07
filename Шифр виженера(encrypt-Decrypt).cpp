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
	string	D = "";
	string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int j1 = 0;
    int j2 = 0;
	while (x == 0) {
		system("cls");
		cout << "				МЕНЮ(Шифр Виженера)					" << endl;
		cout << "1.Шифрование." << endl;
		cout << "2.Дешифрование." << endl;
		cout << "3.Атака(?)." << endl;
		cout << "4.Выход." << endl;	
		cin >> choice;
		switch (choice) {
		case 1:{
			system("cls");
			cout << "Введите текст для шифрования:" << endl;
			cin >> text;
			cout << "Введите ключ шифрования:" << endl;
			cin >> keyEncrypt;
			int* F = new int[text.size()];  // запись номера буквы text
			int* G = new int[keyEncrypt.size()];  // запись номера буквы key

			for (int k1 = 0; k1 < text.size(); k1++) {
				if (j1 >= keyEncrypt.size()) // если j дойдет до  key.size, то ключ начнет повторение сначала
					j1 = 0;
				for (int n1 = 0; n1 < 26; n1++) {
					if (text[k1] == A[n1]) { // определение номера буквы text в алфавите А
						F[k1] = n1;
					}
					if (keyEncrypt[j1] == A[n1]) { // определение номера буквы key в алфавите А
						G[k1] = n1;
					}
				}
				j1++; // переход на следующую буквы key
			}
			//шифрование
			int e1 = 0;
			for (int u1 = 0; u1 < text.size(); u1++) {

				e1 = ((F[u1] + G[u1]) % 26);
				text[u1] = A[e1];
			}

			cout << "Зашифрованное сообщение: " << text << endl;
	
			_getch();
			continue;
		}
		case 2: {
			system("cls");
			cout << "Введите зашифрованный текст:" << endl;
			cin >> DecryptedText;
			cout << "Введите ключ шифрования:" << endl;
			cin >> keyDecrypt;
			int* Decrypt = new int[DecryptedText.size()];  // запись номера буквы text
			int* KeyDecryptArr = new int[keyDecrypt.size()];  // запись номера буквы key

			for (int k2 = 0; k2 < DecryptedText.size(); k2++) {
				if (j2 >= keyDecrypt.size()) // если j дойдет до  key.size, то ключ начнет повторение сначала
					j2 = 0;
				for (int n2 = 0; n2 < 26; n2++) {
					if (DecryptedText[k2] == A[n2]) { // определение номера буквы text в алфавите А
						Decrypt[k2] = n2;
					}
					if (keyDecrypt[j2] == A[n2]) { // определение номера буквы key в алфавите А
						KeyDecryptArr[k2] = n2;
					}
				}
				j2++; // переход на следующую буквы key
			}
			//шифрование
			int e2;
			e2 = 0;
			for (int u2 = 0; u2 < DecryptedText.size(); u2++) {

				e2 = ((Decrypt[u2] - KeyDecryptArr[u2]) % 26);
				if (e2 < 0) {
					e2 += 26;
				}
				DecryptedText[u2] = A[e2];
			}
			cout << "Расшифрованное сообщение: " << DecryptedText << endl;
			_getch();
			system("cls");
			continue;
		}
		case 3: {
			system("cls");
			_getch();
			continue;
		}
		case 4: {
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
