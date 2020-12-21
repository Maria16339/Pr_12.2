#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
        Elem* link;
        Info info;
};


void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; 
    tmp->info = value; 
    tmp->link = NULL; 
    if (last != NULL)
        last->link = tmp; 
    last = tmp; 
    if (first == NULL)
        first = tmp; 
}

int sum(Elem*& first)
{
    Elem* tmp = first;
    int result = 0;
    while (tmp != NULL)
    {
        if (tmp->info >= 0)
            result += tmp->info;
        tmp = tmp->link;
    }
    return result;
}

Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->link; 
    Info value = first->info; 
    delete first; 
    first = tmp; 
    if (first == NULL)
        last = NULL; 
    return value; 
}


void Create(Elem*& first, Elem*& last)
{
    for (int i = -10; i <= 10; i++)
    {
        enqueue(first, last, i);
    }
}

void DeleteEnum(Elem*& first, Elem*& last)
{
    while (first != NULL)
        dequeue(first, last);
}

void PrintEnum(Elem*& first, Elem*& last)
{
    Elem* tmp = first;
    while (tmp != NULL)
    {
        cout << tmp->info << " ";
        tmp = tmp->link;
    }
    cout << endl;
}

int main()
{
    Elem* first = NULL,
        * last = NULL;

    Create(first, last);
    PrintEnum(first, last);

    cout << " Sum = " << sum(first) << endl;

    DeleteEnum(first, last);
    return 0;
}