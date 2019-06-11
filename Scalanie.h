#ifndef SCALANIE_H
#define SCALANIE_H

template <class var>
void scalanie(var* tab, int lewy, int srodek, int prawy)
{
	int i = lewy;
	int j = srodek + 1;
	int k = 0;
	var* tabpom = new var[prawy - lewy + 1];

	while (i <= srodek && j <= prawy)
	{
		if (tab[i] <= tab[j])
			tabpom[k++] = tab[i++];
		else
			tabpom[k++] = tab[j++];
	}

	while (i <= srodek)
		tabpom[k++] = tab[i++];

	while (j <= prawy)
		tabpom[k++] = tab[j++];

	for (k = 0, i = lewy; i <= prawy; ++i, ++k)
		tab[i] = tabpom[k];

	delete[]tabpom;
}

template <class var>
void sortowanie_przez_scalanie(var* tab, int lewy, int prawy)
{
	int srodek;

	if (lewy < prawy)
	{
		srodek = (lewy + prawy) /2;

		sortowanie_przez_scalanie(tab, lewy, srodek);
		sortowanie_przez_scalanie(tab, srodek + 1, prawy);
		scalanie(tab, lewy, srodek, prawy);
	}
}

#endif