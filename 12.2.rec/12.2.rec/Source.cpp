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

int sum(Elem*& first, Elem*& last, Elem* tmp, int& result)
{
    if (tmp != NULL)
    {
        if (tmp->info >= 0)
            result += tmp->info;
        return sum(first, last, tmp = tmp->link, result);
    }
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


void Create(Elem*& first, Elem*& last, int i)
{
    if (i <= 10) {
        enqueue(first, last, i);
        Create(first, last, i + 1);
    }
}

void DeleteEnum(Elem*& first, Elem*& last)
{
    while (first != NULL)
        dequeue(first, last);
}

void PrintEnum(Elem*& first, Elem*& last, Elem* tmp)
{
    if (tmp != NULL) {
        cout << tmp->info << " ";
        return PrintEnum(first, last, tmp = tmp->link);
    }
    else
        cout << endl;
}

int main()
{
    Elem* first = NULL,
        * last = NULL;

    Create(first, last, -10);
    PrintEnum(first, last, first);

    int res = 0;
    sum(first, last, first, res);
    cout << " Sum = " << res << endl;

    DeleteEnum(first, last);
    return 0;
}