#ifndef GENERATOR_H
#define GENERATOR_H


#include <fstream>
#include <string>

using namespace std;

template <class var> 
var* generuj(unsigned rozmiar, int min, int max)
{
	var* tablica = new var[rozmiar];

	if (tablica == nullptr)
	{
		return nullptr;
	}

	for (unsigned q=0; q < rozmiar; ++q)
	{
		tablica[q] = min + rand() % (max - min) +1;
	}

	return tablica;
}


void zapis(int* tablica, int rozmiar) // zapisywanie tablicy do pliku
{
	fstream plik;
	string sciezka = to_string(rozmiar) + ".txt"; // towrzenie pliku .txt o nazwie rownej rozmiarowi
	plik.open(sciezka, fstream::out | fstream::app);

	for (int i = 0; i < rozmiar; i++)
	{
		plik << tablica[i] << " ";
	}
	plik << endl;
	plik.close();
}
#endif 
