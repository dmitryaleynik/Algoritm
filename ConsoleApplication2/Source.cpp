

#include  <iostream>
#include <queue>
#include <fstream>
#include <algorithm>
#include <list>
using namespace std;


class Point {
private:
	int x;
	int y;
	int length;

public:

	Point(int x, int y, int length) {
		this->x = x;
		this->y = y;
		this->length = length;


	}
	Point() {}
	bool step(int nX, int nY, int nSize, int mSize) {
		int newX = this->x + nX;
		int newY = this->y + nY;
		if (nSize < newX || mSize < newY || newX <= 0 || newY <= 0) {
			return false;
		}
		return true;
	}

	int getLength() { return length; }
	void setLength(int length) { this->length = length; }
	int getX() { return x; }
	int getY() { return y; }
	bool equal(Point right) {
		return  ((x == right.getX()) && (y == right.getY()));
	}
	bool operator==(Point & right) {
		return this->x == right.getX() && this->y == right.getY();
	}
	void  operator= (Point & right) {
		this->x = right.getX();
		this->y = right.getY();
		this->length = right.getLength();
	}





};


void quickSort(int l, int r,vector <Point> v)
{
	int x = v[l + (r - l) / 2].getLength();
	
	int i = l;
	int j = r;

	while (i <= j)
	{
		while (v[i].getLength() < x) i++;
		while (v[j].getLength() > x) j--;
		if (i <= j)
		{
			swap(v[i], v[j]);
			i++;
			j--;
		}
	}
	if (i<r)
		quickSort(i, r,v);

	if (l<j)
		quickSort(l, j,v);
}




int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");
	int n, m;
	in >> n;
	in >> m;
	int ** matrix;
	matrix = new int *[n + 1];
	for (int i = 0; i <= n; i++) {
		matrix[i] = new int[m + 1];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			in >> matrix[i][j];
		}
	}
	int ** routes;
	routes = new int *[n + 1];
	for (int i = 0; i <= n; i++) {
		routes[i] = new int[m + 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			routes[i][j] = 1000000000;
		}
	}
	int k;
	in >> k;

	int startX, startY, goalX, goalY;
	in >> startX;
	in >> startY;
	in >> goalX;
	in >> goalY;
	Point start(startX, startY, 0);
	Point goal(goalX, goalY, 0);
	routes[startX][startY] = 0;
	int step[4][2] = { { 1,0, },{ 0,-1 },{ -1,0 },{ 0,1 } };
	vector <Point> v;
	queue<Point> q;
	q.push(start);
	while (!q.empty()) {

		Point current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newX = current.getX() + step[i][0];
			int newY = current.getY() + step[i][1];
			if (newX >= 1 && newY >= 1 && newX <= n && newY <= m) {
				int newL = current.getLength() + k + abs(matrix[newX][newY] - matrix[current.getX()][current.getY()]);
				if (newL < routes[newX][newY]) {
					Point newPoint(newX, newY, newL);
					v.push_back(newPoint);
					routes[newX][newY] = newL;

		
				}
			}
		}
		quickSort(0, v.size() - 1, v);
		for (int i = 0; i < v.size(); i++) {
			q.push(v[i]);
		}
		

	}
	
	out << routes[goalX][goalY];
	out.close();
	system("pause");




}


