#ifndef SORTOWANIE_H
#define SORTOWANIE_H

#include "Scalanie.h"
#include "SzybkieSortowanie.h"
#include "Introspektywne.h"

#include <chrono>

template <class var> 
double sortuj(int metoda, var* tab, int rozmiar)
{
	auto begin = std::chrono::high_resolution_clock::now();

	switch (metoda)
	{
	case 0: 
		quick_sort(tab, 0, rozmiar-1);
		break; 
	case 1: 
		sortowanie_przez_scalanie(tab, 0, rozmiar - 1);
		break;
	case 2: 
		IntroSort(tab, rozmiar - 1);
		break; 
	}
	auto end = std::chrono::high_resolution_clock::now();

	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / 1000000.0;
}

#endif

