// tab_primes2.cpp
// C++ программа для таблицы простых чисел
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

#include <iostream>
#include <iomanip>
#include <cmath>

// Модуль-функция генерации массива простых чисел меньших n
// функция возвращает количество простых чисел в массиве primes из n элементов
int gen_primes(int *primes, int n){
	int m, p, pk;
	int k=(int)sqrt(n+1);
 	int *buf =new int [n];
 	buf[0]=2;
	for (int i=1;i<n;i++){
		buf[i]=i+1;
	}
	p=0;
  	while(p<k){
		m=p+1;
		while(m<n) {
			if(buf[m]%buf[p] ==0)
	    		buf[m]=-1;
	     	m++;
    	}
    	pk=0;
		for (int i=0;i<n;i++){
			if (buf[i] !=-1) {
				primes[pk] = buf[i];
				pk++;
			}
		}
		for (int i=0;i<n;i++){
	  		if (i<pk)
	  			buf[i]=primes[i];
	  		else
	    		buf[i]=-1;
		}
		p++;
	}
	return pk;
}

int main() {
 	int nprimes, n;
 	std::cout << "n = ";
 	std::cin >> n;
 	std::cout << "Numbers: " << n << std::endl;
 	int *primes=new int [n];
 	nprimes=gen_primes(primes,n);
 	cout << " primes: "<< nprimes <<endl;
 	for (int i=0;i<nprimes;i++){
		if(i%9==0 && i != 0) cout << endl;
		cout << setw(4) << primes[i];
	}
    cout <<endl;
 return 0;
}
