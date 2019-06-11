#include <iostream>

#include "Generator.h"
#include "SzybkieSortowanie.h"
#include "Scalanie.h"
#include "Introspektywne.h"
#include "Sortowanie.h"

#define ROZMIAR 5
#define LICZBA_TABLIC 100


using namespace std; 

int main()
{

	int rozmiar_tablic[] = {10000, 50000, 100000, 500000, 1000000};
	double procent[] = {0, 0.25, 0.5, 0.75, 0.9, 0.95, 0.997 };
	fstream plik;
	string sciezka = "dane.txt"; // towrzenie pliku .txt o nazwie rownej rozmiarowi
	plik.open(sciezka, fstream::out | fstream::app);

	for (int nr_algorytmu = 0; nr_algorytmu < 3; ++nr_algorytmu)
	{

		//cout << "Algoytm: " << nr_algorytmu << endl << endl << endl << endl;
		plik << "Algorytm:" << nr_algorytmu << endl;
		//plik.close();
		for (int rozmiar = 0; rozmiar < 5; ++rozmiar)
		{
			plik << "Rozmiar: " << rozmiar_tablic[rozmiar] << endl;

			for (int p = 0; p < 7; ++p)
			{
				plik << "Procent: " << procent[p] << endl;

				double calka = 0;
				for (int t = 0; t < LICZBA_TABLIC; ++t)
				{
					int *wsk = generuj<int>(rozmiar_tablic[rozmiar], 0, 1000);
					sortuj(0, wsk, procent[p] * rozmiar_tablic[rozmiar]);
					calka += sortuj(nr_algorytmu, wsk, rozmiar_tablic[rozmiar]);
					delete[] wsk; 
				}

				calka /= LICZBA_TABLIC;

				plik << "Wynik: " << calka << " [ms]" << endl;


			}
				
		}
	}

	for (int nr_algorytmu = 0; nr_algorytmu < 3; ++nr_algorytmu)
	{
		plik << "Algorytm:" << nr_algorytmu << endl;
		for (int rozmiar = 0; rozmiar < 5; ++rozmiar)
		{
			plik << "Rozmiar: " << rozmiar_tablic[rozmiar] << endl;
			double calka = 0;
			for (int t = 0; t < LICZBA_TABLIC; ++t)
			{
				int *wsk = generuj<int>(rozmiar_tablic[rozmiar], 0, 1);
				for (int i = 0; i < rozmiar_tablic[rozmiar]; ++i)
				{
					wsk[i] = rozmiar_tablic[rozmiar] - i;
				}
				sortuj(nr_algorytmu, wsk, rozmiar_tablic[rozmiar]);
				calka += sortuj(nr_algorytmu, wsk, rozmiar_tablic[rozmiar]);
			}
			calka /= LICZBA_TABLIC;
			plik << "Wynik: " << calka << " [ms]" << endl;
		}
	}
	plik.close();
	system("pause");
}