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
		cout << "				����(���� ��������)					" << endl;
		cout << "1.����������." << endl;
		cout << "2.������������." << endl;
		cout << "3.�����(?)." << endl;
		cout << "4.�����." << endl;	
		cin >> choice;
		switch (choice) {
		case 1:{
			system("cls");
			cout << "������� ����� ��� ����������:" << endl;
			cin >> text;
			cout << "������� ���� ����������:" << endl;
			cin >> keyEncrypt;
			int* F = new int[text.size()];  // ������ ������ ����� text
			int* G = new int[keyEncrypt.size()];  // ������ ������ ����� key

			for (int k1 = 0; k1 < text.size(); k1++) {
				if (j1 >= keyEncrypt.size()) // ���� j ������ ��  key.size, �� ���� ������ ���������� �������
					j1 = 0;
				for (int n1 = 0; n1 < 26; n1++) {
					if (text[k1] == A[n1]) { // ����������� ������ ����� text � �������� �
						F[k1] = n1;
					}
					if (keyEncrypt[j1] == A[n1]) { // ����������� ������ ����� key � �������� �
						G[k1] = n1;
					}
				}
				j1++; // ������� �� ��������� ����� key
			}
			//����������
			int e1 = 0;
			for (int u1 = 0; u1 < text.size(); u1++) {

				e1 = ((F[u1] + G[u1]) % 26);
				text[u1] = A[e1];
			}

			cout << "������������� ���������: " << text << endl;
	
			_getch();
			continue;
		}
		case 2: {
			system("cls");
			cout << "������� ������������� �����:" << endl;
			cin >> DecryptedText;
			cout << "������� ���� ����������:" << endl;
			cin >> keyDecrypt;
			int* Decrypt = new int[DecryptedText.size()];  // ������ ������ ����� text
			int* KeyDecryptArr = new int[keyDecrypt.size()];  // ������ ������ ����� key

			for (int k2 = 0; k2 < DecryptedText.size(); k2++) {
				if (j2 >= keyDecrypt.size()) // ���� j ������ ��  key.size, �� ���� ������ ���������� �������
					j2 = 0;
				for (int n2 = 0; n2 < 26; n2++) {
					if (DecryptedText[k2] == A[n2]) { // ����������� ������ ����� text � �������� �
						Decrypt[k2] = n2;
					}
					if (keyDecrypt[j2] == A[n2]) { // ����������� ������ ����� key � �������� �
						KeyDecryptArr[k2] = n2;
					}
				}
				j2++; // ������� �� ��������� ����� key
			}
			//����������
			int e2;
			e2 = 0;
			for (int u2 = 0; u2 < DecryptedText.size(); u2++) {

				e2 = ((Decrypt[u2] - KeyDecryptArr[u2]) % 26);
				if (e2 < 0) {
					e2 += 26;
				}
				DecryptedText[u2] = A[e2];
			}
			cout << "�������������� ���������: " << DecryptedText << endl;
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
