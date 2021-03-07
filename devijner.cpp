#include <iostream>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "");
	int x = 0;
	int choice;
	string DecryptedText;
	string text;
	string	key;
	string	D = "";
	string A = "abcdefghijklmnopqrstvuwxyz";
	int j = 0;
	cout << "Введите зашифрованный текст:" << endl;
	cin >> DecryptedText;
	cout << "Введите ключ шифрования:" << endl;
	cin >> key;
	int* Decrypt = new int[DecryptedText.size()];  // запись номера буквы text
	int* G = new int[key.size()];  // запись номера буквы key

	for (int k = 0; k < DecryptedText.size(); k++) {
		if (j >= key.size()) // если j дойдет до  key.size, то ключ начнет повторение сначала
			j = 0;
		for (int n = 0; n < 26; n++) {
			if (DecryptedText[k] == A[n]) { // определение номера буквы text в алфавите А
				Decrypt[k] = n;
			}
			if (key[j] == A[n]) { // определение номера буквы key в алфавите А
				G[k] = n;
			}
		}
		j++; // переход на следующую буквы key
	}
	//шифрование
	int e = 0;
	for (int u = 0; u < DecryptedText.size(); u++) {

		e = ((Decrypt[u] - G[u]) % 26);
		if (e < 0) {
			e += 26;
		}
		
			DecryptedText[u] = A[e];
	}
	cout << "Расшифрованное сообщение: " << DecryptedText << endl;
	system("pause");
}