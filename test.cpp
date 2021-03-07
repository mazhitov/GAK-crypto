#include<iostream>
using namespace std;

int n, m[100], c;
void perms(int k)
{
	if (k == n) {
		printf("%d:\t", ++c);
		for (int i = 0; i < n; i++)
			printf("%d", m[i]);
		printf("\n");
	}
	else
		for (int i = 1; i <= n; i++) {
			int f = 0;
			for (int j = 0; j < k; j++)
				if (m[j] == i) f = 1;
			if (f) continue;
			m[k] = i;
			perms(k + 1);
		}
}
int main(int argc, char* argv[])
{
	int k;
	printf("Input n (not so big :)) : ");
	cin >> k;
	n = k;
	c = 0; perms(0);
	system("pause");
	return 0;
}