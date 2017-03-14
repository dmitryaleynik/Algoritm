#include <iostream>
#include <fstream>
#include <list>
#include  <vector>

using namespace std;

#pragma once
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






int main() {

	ifstream in("in.txt");
	ofstream out("out.txt");
	Point point(1, 2, 3);
	Point point3(1, 2, 4);
	
	int n, m;
	in >> n;
	
	in >> m;
	
	int curr;
	

	int ** board;
	 board = new  int * [n + 1];
	 for (int i = 0; i <= n; i++) {
		 board[i]  = new int[m + 1];
	 }




	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			in >> board[i][j];
			
		}
		
	}
	int startX, startY, finishX, finishY;
	in >> startX;
	in >> startY;
	in >> finishX;
	in >> finishY;
	Point start(startX, startY, 0);
	Point  goal(finishX, finishY, 0);
	bool ** visited;
	visited = new bool *[n + 1];
	for (int i = 1; i <= n; i++) {
		visited[i] = new bool[m + 1];
	}
	int  step[8][2] = { { 2, 1 }
		,{ 1, 2 }
		,{ -1, 2 }
		,{ 2, -1 }
		,{ -2, 1 }
		,{ 1, -2 }
		,{ -2, -1 }
	    ,{ -1, -2 } };
	int result;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visited[i][j] = false;
		}
	}
	
	vector<Point> vector;
	vector.push_back (start);
	bool  found = false;
	int x = 0; int y = 1;

	ex:
	while (x < y) {
		int s = vector[x].getLength();
		int j = x;
		
		while (j < vector.size() && vector[j].getLength() == s) {
			Point   current = vector[j];
			if (current==goal) {
				found = true;
				result = s;
				x = y;
				goto ex;
			}
			for (int i = 0; i < 8; i++) {
				int newX = current.getX() + step[i][0];
				int newY = current.getY() + step[i][1];
				if (newX>0 && newY>0 && newX<=n&& newY<=m && board[newX][newY] == 0) {
					if (visited[newX][newY] != true) {

						Point newPoint(newX, newY, s + 1);
						vector.push_back(newPoint);
						y++;
						visited[newX][newY] = true;
					}

				}
			}
			j++;
		}
		j = x;
		while (j < vector.size() && vector[j].getLength() == s) {
			Point   current = vector[j];
			for (int i = 0; i < 8; i++) {
				int newX = current.getX() + step[i][0];
				int newY = current.getY() + step[i][1];
				if (newX>0 && newY>0 && newX <= n&& newY <= m && board[newX][newY] == 1) {
					if (visited[newX][newY] != true) {

						Point newPoint(newX, newY, 2+s);
						vector.push_back(newPoint);
						y++;
						visited[newX][newY] = true;
					}

				}
				
			}
			j++;



		}
		x = j;

	}
	if (!found) {
		out << "No";
		
	}
	else
		out << result;



	out.close();


	




}