#include <iostream>
#include <fstream>

using namespace std;

class Pb6
{
public:
    int n, x[11]{}, p[11]{};

    struct Elev {
        char nume[15] = "";
        double inaltime = 0;
    } v[11];
    bool cmp(Elev e1, Elev e2) {
        return e1.inaltime < e2.inaltime;
    }
    void getElevi() {
        ifstream fin("fin.txt");
        fin >> n;
        for (int i = 1; i <= n; i++)
            fin >> v[i].nume, fin >> v[i].inaltime;
    }
    void afis() {
        for (int i = 1; i <= n; i++)
            cout << v[x[i]].nume << " ";
        cout << "\n";
    }
    void back(int k) {
        for (int i = 1; i <= n; i++)
            if (!p[i] && v[i].inaltime >= v[x[k - 1]].inaltime) {
                p[i] = 1;
                x[k] = i;
                if (k == n)
                    afis();
                else back(k + 1);
                p[i] = 0;
            }
    }
    void solve() {
        getElevi();
        back(1);
    }
};

