#include <iostream>

using namespace std;

void pointers()
{
    int a = 3; // Une variable
    int *pt(0); // Un pointeur (initialisé à 0)
    pt = &a; // pt pointe vers a
    cout << "La valeur de a est" << *pt << endl;
}