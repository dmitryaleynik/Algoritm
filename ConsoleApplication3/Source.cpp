


#include  <iostream>
#include <queue>
#include <fstream>
#include <algorithm>
#include <list>
#include <stack>
using namespace std;
ifstream fin("in.txt");
ofstream fout("Text.txt");

const int MAX = 1000;
int n, m;
int k;
int a[MAX][MAX];
bool was[MAX][MAX];
point predok[MAX][MAX];

int col = 0;



struct point {
	int x;
	int y;
	int kol;
	point(int a = 0, int b = 0, int c = 0) : x(a), y(b), kol(c) {
	}
	bool operator ==(const point &p) {
		return ((p.x == x) && (p.y == y));
	}

	point operator+(const int i) {
		return point(x, y, kol + i);

	}

};





typedef stack<point> POINTSTACK;
typedef std::priority_queue<point> POINTQUEUE;





point up(point p) {
	if ((p.x > 1))
		return point(p.x - 1, p.y);
	return point();
}

point down(point p) {
	if ((p.x < n))
		return point(p.x + 1, p.y);
	return point();
}
point left(point p) {
	if ((p.y > 1))
		return point(p.x, p.y - 1);
	return point();
}
point right(point p) {
	if ((p.y < m))
		return point(p.x, p.y + 1);
	return point();
}

void printStack(point p) {
	POINTSTACK s;
	s.push(p);
	fout << p.kol << endl;
	while ((p.x != 0) && (p.y != 0)) {
		p = predok[p.x][p.y];
		s.push(p);
	}

	s.pop();
	while (!s.empty()) {
		p = s.top();
		s.pop();
		fout << p.x << ' ' << p.y << endl;
	}

}


bool proverka(point p) {
	if (was[p.x][p.y]) return false;
	was[p.x][p.y] = true; return true;
}

int main(int argc, char* argv[])

{


	fin >> n;
	fin >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			fin >> a[i][j];

	fin >> k;

	int x1, y1, x2, y2;
	fin >> x1 >> y1 >> x2 >> y2;


	POINTQUEUE q;
	const point nullPoint;


	if (proverka(point(x1, y1, 0)))
		q.push(point(x1, y1, 0));


	while (!q.empty()) {

		point p = q.top();
		q.pop();
		if ((p.x == x2) && (p.y == y2)) {
			printStack(p);
			return 0;
		}


		point tmp;
		tmp = p;
		if (!((tmp = up(tmp)) == nullPoint)) {
			if (proverka(tmp)) {
				q.push(tmp + (abs(-a[tmp.x][tmp.y] + a[p.x][p.y]) + p.kol + k));
				predok[tmp.x][tmp.y] = p;
			}

		}

		tmp = p;
		if (!((tmp = down(tmp)) == nullPoint)) {
			if (proverka(tmp)) {
				q.push(tmp + (abs(-a[tmp.x][tmp.y] + a[p.x][p.y]) + p.kol + k));
				predok[tmp.x][tmp.y] = p;
			}

		}

		tmp = p;
		if (!((tmp = left(tmp)) == nullPoint)) {
			if (proverka(tmp)) {
				q.push(tmp + (abs(-a[tmp.x][tmp.y] + a[p.x][p.y]) + p.kol + k));
				predok[tmp.x][tmp.y] = p;
			}
		}

		tmp = p;
		if (!((tmp = right(tmp)) == nullPoint)) {
			if (proverka(tmp)) {
				q.push(tmp + (abs(-a[tmp.x][tmp.y] + a[p.x][p.y]) + p.kol + k));
				predok[tmp.x][tmp.y] = p;
			}
		}

	}




	fout << "No";
	return 0;
}