#pragma once
class Point {
private :
    int x;
	int y;
	int length;

public : 

	Point(int x, int y, int length) {
		this->x = x;
		this->y = y;
		this->length = length;


	}
	Point (){}
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
	bool operator==( Point & right) {
		return this->x == right.getX() && this->y == right.getY();
	}
	void  operator= ( Point & right) {
		this->x = right.getX();
		this->y = right.getY();
		this->length = right.getLength();
	}

	
	


};



