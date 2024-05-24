#include<iostream>
#include<stdio.h>
#include <fstream>
#include <iomanip>
#include<cstring>
#include<math.h>
#define pi 3.14
using namespace std;

class Shape{
	protected:
		char name[15];
};


class D2Shape : public Shape{
	protected:
		int coordinat1x;
		int coordinat1y;
		int length;
};


class Circle : public D2Shape{
	private:
		float length_oloh();
		float square_oloh();
	public:
		void getdata();
		void print_data();
};

void Circle :: print_data(){
	cout <<"\nToirgiin tow tseg x: "<< coordinat1x<< ", " <<coordinat1y;
	cout <<"\nName: ";
	cout << name;
	cout <<"\nTaliin urt: ";
	cout <<length;
	cout <<"\nToirgiin urt: ";
	cout <<length_oloh();
	cout <<"\nToirgiin talbai: ";
	cout <<square_oloh();
}

void Circle :: getdata(){
	strcpy(name, "Toirog") ;
	cout << "\nToirgiin towiin x coordinat: ";
	cin >> coordinat1x;
	cout << "\nToirgiin towiin y coordinat: ";
	cin >> coordinat1y;
	cout << "\nToirgiin radius: ";
	cin >> length;
}

float Circle :: length_oloh(){
	return length*2*pi;
}

float Circle :: square_oloh(){
	return pi*pi*length;
}


class Square : public D2Shape{
	private:
		int coordinat2x;
		int coordinat2y;
		int coordinat3x;
		int coordinat3y;
		int coordinat4x;
		int coordinat4y;
		float length_oloh();
		float square_oloh();
	public:
		void getdata();
		void coordinat_oloh();
		void print_data();
};

void Square :: print_data(){
	cout <<"\nZvvn deed oroin coordinat: "<< coordinat1x<< ", " <<coordinat1y;
	cout <<"\nBaruun deed oroin coordinat: "<< coordinat2x<< ", " <<coordinat2y;
	cout <<"\nBaruun dood oroin coordinat: "<< coordinat3x<< ", " <<coordinat3y;
	cout <<"\nZvvn dood oroin coordinat: "<< coordinat4x<< ", " <<coordinat4y;

	cout <<"\nName: ";
	cout << name;
	cout <<"\nLength: ";
	cout <<length;
	cout <<"\nDorwoljinii urt: ";
	cout <<length_oloh();
	cout <<"\nDorwoljinii talbai: ";
	cout <<square_oloh();
}

void Square :: getdata(){
	strcpy(name, "Kvadrat") ;
	cout << "\nKvadratiin zuun deed oroin x coordinat: ";
	cin >> coordinat1x;
	cout << "\nKvadratiin zuun deed oroin y coordinat: ";
	cin >> coordinat1y;
	cout << "\nTaliin urt: ";
	cin >> length;
}

void Square :: coordinat_oloh(){
	//baruun deed
	coordinat2x = coordinat1x+length;
	coordinat2y = coordinat1y;
	//baruun dood
	coordinat3x = coordinat2x;
	coordinat3y = coordinat2y-length;
	//zvvn dood
	coordinat4x = coordinat3x-length;
	coordinat4y = coordinat3y;
}

float Square :: square_oloh(){
	return length*length;
}

float Square :: length_oloh(){
	return length*4;
}


class Triangle : public D2Shape{
	private:
		int coordinat2x;
		int coordinat2y;
		int coordinat3x;
		int coordinat3y;
		float heigth;
		float length_oloh();
		float square_oloh();
	public:
		void getdata();
		void coordinat_oloh();
		void print_data();
};

void Triangle :: getdata(){
	strcpy(name, "Gurwaljin") ;
	cout << "\nGurwaljinii deed oroin x coordinat: ";
	cin >> coordinat1x;
	cout << "\nGurwaljinii deed oroin y coordinat: ";
	cin >> coordinat1y;
	cout << "\nGurwaljinii Taliin urt: ";
	cin >> length;
}

float Triangle :: length_oloh(){
	return length*3;
}

float Triangle :: square_oloh(){
	heigth = sqrt((length*length)-(length/2*length/2));
	return ((length*heigth)/2);
}

void Triangle :: print_data(){
	cout <<"\nGurvaljnii deed oroin coordinat: "<< coordinat1x<< ", " <<coordinat1y;
	cout <<"\nGurvaljnii zvvn dood oroin coordinat: "<< coordinat2x<< ", " <<coordinat2y;
	cout <<"\nGurvaljnii baruun dood oroin coordinat: "<< coordinat3x<< ", " <<coordinat3y;
	cout <<"\nName: ";
	cout << name;
	cout <<"\nGurvaljnii taliin urt: ";
	cout <<length;
	cout <<"\nGurvaljnii taliin ondor: ";
	cout <<heigth;
	cout <<"\nGurwaljnii niit urt: ";
	cout <<length_oloh();
	cout <<"\nGurwaljnii talbai";
	cout <<square_oloh();
}

void Triangle :: coordinat_oloh(){
	coordinat2x = coordinat1x-length/2;
	coordinat2y = coordinat1y-heigth;
	coordinat3x = coordinat2x+length;
	coordinat3y = coordinat2y;
 }
 
 
int main(){
	Circle circle;
	Square square;
	Triangle triangle;
	
	circle.getdata();
	circle.print_data();
	
	square.getdata();
	square.coordinat_oloh();
	square.print_data();
	
	triangle.getdata();
	triangle.coordinat_oloh();
	triangle.print_data();
}
