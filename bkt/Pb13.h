#include <iostream>
#include <fstream>

using namespace std;

class Pb13
{
public:
	int n, x[11]{}, lMax = 0, l[11]{}, ct = 0;
	string v[11]{}, res[11]{};

	void copyMax(int size) {
		ct = size;
		for (int i = 0; i < size; i++)
			res[i] = v[x[i + 1]];
	}
	void back(int k, int s) {
		for (int i = x[k - 1] + 1; i <= n && s + l[i] > lMax; i++)
			if (v[i][0] > v[x[k - 1]][l[x[k - 1]] - 1]) {
				x[k] = i;
				if (s + l[i] > lMax) {
					lMax = s + l[i];
					copyMax(k);
				}
				if(k < n) back(k + 1, s + l[i]);
			}
	}
	void solve() {
		ifstream fin("fin.txt");
		fin >> n;
		v[0] = "@";
		l[0] = 1;
		for (int i = 1; i <= n; i++)
			fin >> v[i], l[i] = v[i].length();
		back(1, 0);
		for (int i = 0; i <= ct; i++)
			cout << res[i];
	}
};

