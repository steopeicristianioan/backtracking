#include <iostream>
#include <fstream>

using namespace std;

class Pb9
{
public:
	int n, p;
	int sup[10]{}, inf[10]{}, m[520]{};

	long long pow(int n) {
		if (n == 0)
			return 1;
		if (n % 2 == 1)
			return 2 * pow(n - 1);
		long long aux = pow(n / 2);
		return aux * aux;
	}
	void getInfSup() {
		inf[0] = 0;
		sup[0] = 2;
		for (int i = 1; i <= n; i++)
			inf[i] = (2 * inf[i - 1]) + 1, sup[i] = (2 * sup[i - 1]) - 1;
	}
	void getM() {
		m[0] = 0;
		m[1] = 1;
		int d = pow(n);
		for (int i = 2; i <= d; i++) {
			if (i % 2 == 0) m[i] = m[i / 2];
			else m[i] = 1 + m[i / 2];
		}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n >> p;
		getInfSup();
		getM();
		for (int i = inf[n - 1] + 1; i < sup[n]; i++)
			if (m[i] == p)
				cout << i << " ";
	}
};

