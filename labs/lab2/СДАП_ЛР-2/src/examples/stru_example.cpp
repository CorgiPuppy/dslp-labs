// Ознакомлен: Студент группы ЗОМ34-ПВШ261 Золотухин Андрей

// stru_example.cpp
// author: user
// C++ программа демонстрирует использование
// структуры данных struct, описывающая точку
// координатной плоскости
#include <iostream>
#include <cmath>

using namespace std;
// точка на плоскости
struct Point {
 double x, y; // x и  y координаты точки плоскости
};
// Некоторые функции декартовой геометрии на плоскости
// функция расстояния между двумя точками
double dist(Point pA, Point pB){
	return sqrt((pB.x - pA.x)*(pB.x - pA.x)+(pB.y - pA.y)*(pB.y - pA.y));
}
// Евклидова норма вектора из точки О(0,0) до точки (x,y)
double norm(Point A){
	return sqrt(A.x*A.x+A.y*A.y);
}
int main(){
	// тестирование структуры данных Point и функций на простом примере
	Point p1 = {1.0, 5.0};//координаты точки p1
	Point p2 = {2.5, 1.5};//координаты точки p2
	cout << " Point p1:  x = " << p1.x << ", y = " << p1.y <<endl;
	cout << " Point p2 (" << p2.x << ", " << p2.y <<")"<<endl;
	cout << " distance(p1,p2)= "<<dist(p1,p2)<< endl;
	cout << " norm(p1)="<<norm(p1)<<endl;// норма вектора (0,p1)
	cout<<endl;

	return 0;
}
