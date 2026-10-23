// Ознакомлен: Студент группы ЗОМ34-ПВШ261 Золотухин Андрей

// aray2D.cpp Программа C++ для иллюстрации двумерного массива.
// author: user
#include <iostream>
#include <string>
using namespace std;

int main(){
	// Определить 2D массив целых чисел (марицу 4х4)
	const int dim=4;
	int arr[dim][dim];
	/*
	 Oбъявили 2D-массив с 4 строками (row) и 4 столбцами (column),
	 после чего инициализировали массив значением (i+j) на каждой итерации цикла.
	 Затем печатаем 2D-массив, используя вложенный цикл, и в приведенном ниже
	 выводе мы видим, что имеется 4 строки и 4 столбца.
	*/
	cout <<" 2D array (matrix) " << dim <<"x" << dim<<":"<<endl;
	// Задать 2D массив, используя цикл for
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = i + j;
		}
	}

	// Вывести элементы 2D массив в виде таблицы (матрицы)
	 for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << " "  << arr[i][j] ;
		}
		cout << endl;
	}
	// вывод главной диагонали матрицы
	cout << " Elements of the main diagonal:" << endl;
	string s=" ";
	for (int i=0;i<dim;i++){
		cout <<s <<arr[i][i] <<endl;
		s+="  "; // добавить 2 символа пробела в строку s
	}
	// вывод побочной диагонали матрицы
	cout <<" Elements of secondary diagonal:"<<endl;
	int k=dim;
	string s1="       ";
	for (int j=0;j<dim;j++){
			cout << s1 << arr[j][k-1]<<endl;
			k--;
			s1.erase(1,2);//удалить 2 символа проболе из строки s1
	}
	int indxr=2; // индекс строки матрицы
	// вывод строки матрицы с индексом indxr
	cout <<" Vector-row of arr["<<indxr<<"][j] (j=0,1,2,3):"<<endl;
	for(int j=0;j<dim;j++)
		cout << " " <<arr[indxr][j];
	cout << endl;

	int indxc=1; //исндех столбца матрицы
	cout <<" Vector-column of arr[i]["<<indxc<<"] (i=0,1,2,3):"<<endl;
	for(int i=0;i<dim;i++)
		cout << " " <<arr[i][indxc]<<endl;
	cout << endl;
	return 0;
}
