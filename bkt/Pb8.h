#include <iostream>
#include <fstream>

using namespace std;

class Pb8
{
public:
	int n, sum, x[11]{}, v[10]{}, ct = 0;

	void getInput() {
		ifstream fin("fin.txt");
		fin >> n >> sum;
		int f[10]{};
		while (n) {
			f[n % 10]++;
			n /= 10;
		}
		for (int i = 0; i <= 9; i++)
			if (f[i])
				v[++ct] = i;
	}
	void afis(int size) {
		for (int i = 1; i <= size; i++)
			cout << v[x[i]] << " ";
		cout << '\n';
	}
	void back(int k, int s) {
		for (int i = x[k - 1] + 1; i <= ct && s + v[i] <= sum; i++) {
			x[k] = i;
			if (s + v[i] == sum)
				afis(k);
			back(k + 1, s + v[i]);
		}
	}
	void solve() {
		getInput();
		back(1, 0);
	}
};

