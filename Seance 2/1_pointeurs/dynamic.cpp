#include <iostream>

using namespace std;

void dynamic()
{
    int *pt(0);     // Un pointeur (initialisé à 0)
    pt = new int;   // Allocation de la mémoire 
    *pt = 5;        // Initialisation de la variable
    cout << "La valeur est" << *pt << endl;
    delete pt;      // Libération de la mémoire
    pt = 0;         // Remise du pointeur à 0
}

void tabDynamic()
{
    int taille(4);
    int *tab(0);
    tab = new int[taille];

    for (int i = 0; i < taille; i++)
    {
        tab[i] = i*2;
    }

    for (int i = 0; i < taille; i++)
    {
        cout << tab[i] << endl;
    }

    delete[] tab;
    tab = 0;
}