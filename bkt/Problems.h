#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("fin.txt");

///pb1
void getDiv(int n, int v[101]) {
	int ct = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			v[++ct] = i;
			if (i * i < n)
				v[++ct] = n / i;
		}
	}
	for (int i = 1; i <= ct; i++)
		cout << v[i] << " ";
}













