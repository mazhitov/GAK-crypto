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
	cout << "������� ������������� �����:" << endl;
	cin >> DecryptedText;
	cout << "������� ���� ����������:" << endl;
	cin >> key;
	int* Decrypt = new int[DecryptedText.size()];  // ������ ������ ����� text
	int* G = new int[key.size()];  // ������ ������ ����� key

	for (int k = 0; k < DecryptedText.size(); k++) {
		if (j >= key.size()) // ���� j ������ ��  key.size, �� ���� ������ ���������� �������
			j = 0;
		for (int n = 0; n < 26; n++) {
			if (DecryptedText[k] == A[n]) { // ����������� ������ ����� text � �������� �
				Decrypt[k] = n;
			}
			if (key[j] == A[n]) { // ����������� ������ ����� key � �������� �
				G[k] = n;
			}
		}
		j++; // ������� �� ��������� ����� key
	}
	//����������
	int e = 0;
	for (int u = 0; u < DecryptedText.size(); u++) {

		e = ((Decrypt[u] - G[u]) % 26);
		if (e < 0) {
			e += 26;
		}
		
			DecryptedText[u] = A[e];
	}
	cout << "�������������� ���������: " << DecryptedText << endl;
	system("pause");
}