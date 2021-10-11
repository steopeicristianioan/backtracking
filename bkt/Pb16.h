#include <iostream>
#include <fstream>

using namespace std;

class Pb16
{
public:
	int n, v[11]{}, maxi = INT_MIN, mini = INT_MAX;
	int x[11]{}, a[11]{}, p[11]{}, ct = 0;

	void afis() {
		int aux = 0;
		for (int i = 1; i <= n; i++) {
			if (v[i] == mini || v[i] == maxi)
				cout << v[i] << " ";
			else cout << a[x[++aux]] << " ";
		}
		cout << '\n';
	}
	void back(int k) {
		for (int i = 1; i <= ct; i++)
			if (!p[i]) {
				p[i] = 1;
				x[k] = i;
				if (k == ct)
					afis();
				else if (k < ct) back(k + 1);
				p[i] = 0;
			}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n;
		for (int i = 1; i <= n; i++) {
			fin >> v[i];
			if (v[i] > maxi) maxi = v[i];
			if (v[i] < mini) mini = v[i];
		}
		for (int i = 1; i <= n; i++)
			if (v[i] != maxi && v[i] != mini)
				a[++ct] = v[i];
		back(1);
	}
};

