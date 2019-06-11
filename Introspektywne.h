#ifndef INTROSPEKTYWNE_H
#define INTROSPEKTYWNE_H

#include "SzybkieSortowanie.h"
#define M_LN2 0.6931
/*
template <class var>
void wstawianie(var *tab, int n)
{
	int tmc, j;
	for (int i = 1; i < n; ++i)
	{
		tmc = tab[i]; 
		j = i - 1;

		while (j >= 0 && tab[j] > tmc)
		{
			tab[j + 1] = tab[j]; 
			--j;
		}
		tab[j + 1] = tmc;
	}
}

template <class var>
void kopiec(var tab[], int n, int i)
{

	int j = i;
	int lewy = i * 2 + 2;
	int prawy = i * 2 + 1; 

	if ((prawy < n) && (tab[j] < tab[prawy]))
	{
		j = prawy; 
	}
	if ((lewy < n) && (tab[j] < tab[lewy]))
	{
		j = lewy; 
	}

    if(j != i)
	{ 
       int tmc = tab[i];
       tab[i] = tab[j];
       tab[j] = tmc;
       kopiec(tab, n, j); 
    }
}


template <class var>
void kopcowanie(var tab[], int n)
{

	int i;
	int tmc; 
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		kopiec(tab, n, i);
	}

     for(i = n-1 ; i>=0 ; i--){ 

          tmc=tab[i];
          tab[i]=tab[0];
          tab[0]=tmc;

          kopiec(tab,i,0); 
     }
}



template <class var>
void IntroSort(var *Array, int N, int M)
{
	int i;
	if (M <= 0)
	{
		kopcowanie(Array, N);
		return;
	}
	i = szybkie(Array, 0, N - 1);
	if (i > 9)
		IntroSort(Array, i, M - 1);
	if (N - 1 - i > 9)
		IntroSort(Array + i + 1, N - 1 - i, M - 1);
}

template <class var>
void Hybrid_Introhyspective_Sort(var *Array, int N)
{
	IntroSort(Array, N, (int)floor(2 * log(N) / M_LN2));
	wstawianie(Array, N);
}
*/



void kopiec(int* tablica, int rozmiar_kopca, int indeks) {
	int lewy = (indeks + 1) * 2 - 1;
	int prawy = (indeks + 1) * 2;
	int max = 0;

	if (lewy < rozmiar_kopca && tablica[lewy] > tablica[indeks])
		max = lewy;
	else
		max = indeks;

	if (prawy < rozmiar_kopca && tablica[prawy] > tablica[max])
		max = prawy;

	if (max != indeks)
	{
		int pom = tablica[indeks];
		tablica[indeks] = tablica[max];
		tablica[max] = pom;

		kopiec(tablica, rozmiar_kopca, max);
	}
}

void kopcowanie(int* data, int count) {
	int heapSize = count;

	for (int p = (heapSize - 1) / 2; p >= 0; --p)
		kopiec(data, heapSize, p);

	for (int i = count - 1; i > 0; --i)
	{
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;

		--heapSize;
		kopiec(data, heapSize, 0);
	}
}

void wstawianie(int *tab, int rozmiar)
{
	int pom, j;
	for (int i = 1; i < rozmiar; i++)
	{
		//wstawienie elementu w odpowiednie miejsce
		pom = tab[i]; //ten element bêdzie wstawiony w odpowiednie miejsce
		j = i - 1;

		while (j >= 0 && tab[j] > pom)
		{
			tab[j + 1] = tab[j]; //przesuwanie elementów
			--j;
		}
		tab[j + 1] = pom; //wstawienie pom w odpowiednie miejsce
	}
}

void introsort_wybor(int* tablica, int N, int M)
{
	long i;
	if (M <= 0)
	{
		kopcowanie(tablica, N);
		return;
	}
	i = podzial(tablica, 0, N);
	if (i > 9)
		introsort_wybor(tablica, i, M - 1);
	if (N - 1 - i > 9)
		introsort_wybor(tablica + i + 1, N - 1 - i, M - 1);
}

void IntroSort(int* tablica, int N)
{
	introsort_wybor(tablica, N, (int)floor(2 * log(N) / M_LN2));
	wstawianie(tablica, N);
}

//void IntroSort(int* data, int count) 
//{
//	int partitionSize = podzial(data, 0, count - 1);
//
//	if (partitionSize < 16) 
//	{
//		wstawianie(data, count);
//	}
//	else if (partitionSize > (2 * log(count))) // wybor kopcowania
//	{
//		kopcowanie(data, count);
//	}
//	else
//	{
//		quick_sort(data, 0, count - 1); // wybor quicksorta
//	}
//}

#endif INTROSPEKTYWNE_H