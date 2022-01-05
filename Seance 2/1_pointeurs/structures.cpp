#include <iostream>
#include <string>
#include "structures.hpp"

using namespace std;

void listeChainee()
{
    List *list = initList();
    addFirst(list, 10);
    printList(list);
    addFirst(list, 7);
    addFirst(list, 3);
    printList(list);
    removeFirst(list);
    //addLast(list, 5);
    //addLast(list, 6);
    printList(list);
    removeFirst(list);
    //removeId(list, 5);
    printList(list);
    //removeLast(list);
    printList(list);
    removeFirst(list);
    printList(list);
}

List *initList()
{
    List *list = new List;
    list->first = NULL;

    return list;
}


void addFirst(List *list, int id)
{
    if (list != NULL)
    {
        Element *element = new Element;
        element->next = list->first;
        element->id = id;
        list->first = element;
    }
}

void removeFirst(List *list)
{
    if (list != NULL && list->first != NULL)
    {
        Element *toDelete = list->first;
        list->first = list->first->next;
        delete toDelete;
    }
}

void printList(List *list)
{
    if(list != NULL)
    {
        Element *e = list->first;
        cout << "List -> ";
        while (e != NULL)
        {
            cout << e->id << " -> ";
            e = e->next;
        }
        cout << "NULL" << endl;
    }
}