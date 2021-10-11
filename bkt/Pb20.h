#include <fstream>
#include <iostream>

using namespace std;

class Pb20
{
public:
	int n, x[11]{};

	void afis() {
		for (int i = 1; i <= n; i++)
			(x[i]) ? cout << ")" : cout << "(";
		cout << '\n';
	}
	void back(int k, int des, int inc) {
		for (int i = 0; i <= 1; i++) {
			if (i == 0 && des <= n / 2) {
				x[k] = 0;
				back(k + 1, des + 1, inc);
			}
			else if (i == 1 && inc < des) {
				x[k] = 1;
				if (k == n)
					afis();
				else back(k + 1, des, inc + 1);
			}
		}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n;
		back(1, 0, 0);
	}
};

