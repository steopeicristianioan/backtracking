#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Intervale
{
public:
	int n, x[11]{};
	struct Interval {
		double a, b;
		bool NotIntersect(Interval i) {
			return i.a > b || i.b < a;
		}
	} v[11];

	void afis(int p) {
		for (int i = 1; i < p; i++)
			cout << "(" << v[x[i]].a << "," << v[x[i]].b << "), ";
		cout << "(" << v[x[p]].a << "," << v[x[p]].b << ")";
		cout << "\n";
	}
	void back(int k) {
		for (int i = x[k - 1] + 1; i <= n; i++)
			if (v[i].NotIntersect(v[x[k - 1]])) {
				x[k] = i;
				afis(k);
				back(k + 1);
			}
	}
	void read() {
		ifstream fin("fin.txt");
		fin >> n;
		int ct = 0, total = 0;
		double a, b;
		while (ct != n) {
			fin >> a >> b;
			v[++ct].a = a;
			v[ct].b = b;
		}
	}
	void solve() {
		read();
		back(1);
	}
};

