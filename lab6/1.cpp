#include<stdio.h>
#include<iostream>
#include<math.h>
#define size 2

class matrix{
	private:
		float m1[size][size];
	public:
		void set_matrix(matrix m2);
		matrix get_matrix();
		matrix();
		void scan_matrix();
		void showMatrix();
		matrix operator +(matrix m2); //
		matrix operator +(float m2);  //
		matrix operator *(matrix m2); //
		matrix operator -(matrix m2); //
		void operator =(matrix m2);   //
		void operator ++(void);		  //
		void operator --(void);       //
		void operator +=(matrix m2);  //
		void operator -=(matrix m2);  //
		void operator *=(matrix m2);  //
		matrix operator ->(void);     //horwvvleh
		
};

void matrix :: set_matrix(matrix m2){
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			m1[i][k] = m2.m1[i][k];
		}
	}
}

matrix matrix :: get_matrix(){
	matrix temp;
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			temp.m1[i][k] = m1[i][k];
		}
	}
	return temp;
}

matrix :: matrix(){
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			m1[i][k] = 0;
		}
	}
}

void matrix :: showMatrix(){
	printf("\n\n");
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			printf("%.1f  ", m1[i][k]);
			//cout << setw(8) << m1[i][k];
		}
		printf("\n");
	}
}

matrix matrix :: operator +(matrix mtr){
	matrix temp;
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			temp.m1[i][k] = m1[i][k] + mtr.m1[i][k];
		}
	}
	return temp;
}

void matrix ::  scan_matrix(){
	printf("\n");
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			printf("\n%d moriin %d element: ", i, k);
			scanf("%f", &m1[i][k]);
		}
	}
}

matrix matrix :: operator +(float m2){
	matrix temp;
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			temp.m1[i][k] = m1[i][k] + m2;
		}
	}
	return temp;
}

void matrix :: operator =(matrix m2){
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			m1[i][k] = m2.m1[i][k];
		}
	}
}

matrix matrix :: operator *(matrix mtr){
	matrix temp;
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			temp.m1[i][k] = m1[i][k] * mtr.m1[i][k];
		}
	}
	return temp;
}

matrix matrix :: operator -(matrix mtr){
	matrix temp;
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			temp.m1[i][k] = m1[i][k] - mtr.m1[i][k];
		}
	}
	return temp;
}

void matrix :: operator ++(void){
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			m1[i][k]++;
		}
	}
}

void matrix :: operator --(void){
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			m1[i][k]--;
		}
	}
}

void matrix :: operator +=(matrix m2){
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			m1[i][k] += m2.m1[i][k];
		}
	}
}

void matrix :: operator -=(matrix m2){
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			m1[i][k] -= m2.m1[i][k];
		}
	}
}

void matrix :: operator *=(matrix m2){
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			m1[i][k] *= m2.m1[i][k];
		}
	}
}

matrix matrix :: operator ->(void){
	matrix temp;
	for(int i=0; i<size; i++){
		for(int k=0; k<size; k++){
			temp.m1[i][k] = m1[k][i];
		}
	}
	return temp;
}

int main(){
	matrix mt;
	matrix mtr;
	matrix mtrx;
	mt.scan_matrix();
	mtr.scan_matrix();
//	mtr+=mt;
//	mtrx = mtr.operator +(mtr); 
//	float k= 3.4;
//	mtrx = mtr.operator +(k);
	mtrx= mtr.operator ->();
	mtr.showMatrix();
	
	mtrx.showMatrix();
	//int a=5, b=4; 
	//a+=b; //a bol 9 garna
	//a*=b; // a bol 1 garna
	//printf("%d", a);
}
