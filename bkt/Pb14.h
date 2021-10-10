#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class Pb14
{
public:
	int n, m, x[11]{}, l[11]{}, p[11]{}, lMax = 0, ct = 0;
	string v[11]{}, rez[11]{};
	int a[30][30]{};

	
	void copyMax(int size) {
		ct = size;
		for (int i = 1; i <= size; i++)
			rez[i] = v[x[i]];
	}
	void back(int k, int auxL, int fMax) {
		for (int i = 1; i <= n && auxL + l[i] > lMax; i++) 
			if(!p[i]) {
				/*cout << maxChr << " & " << fMax << endl;*/
				p[i] = 1;
				x[k] = i;
				if (auxL + l[i] > lMax) {
					lMax = auxL + l[i];
					copyMax(k);
				}
				if (k < n) back(k + 1, auxL + l[i], fMax);
				p[i] = 0;
			}
	}
	void solve() {
		v[0] = "";
		ifstream fin("fin.txt");
		fin >> n >> m;
		string aux = "";
		int ct = 0;
		char c;
		while (fin >> c) {
			if (c == ',') {
				v[++ct] = aux;
				l[ct] = aux.length();
				aux = "";
			}
			else
				aux += c;
			if (c != ',')
				a[int(c - 96)][ct+1]++;
		}
		back(1, 0, 0);
		for (int i = 1; i <= ct; i++)
			cout << rez[i];
	}
};

