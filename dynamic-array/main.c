#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray
{
    int size;
    int capacity;
    int* dinarray;
} Dynarray;

Dynarray* init(Dynarray* d, int capacity);
int get(Dynarray* d, int i);
void set(Dynarray* d, int i, int n);
void pushback(Dynarray* d, int n);
void resize(Dynarray* d);

Dynarray*
init(Dynarray* d, int capacity)
{
    d->size = 0;
    d->capacity = capacity;
    d->dinarray = malloc(capacity * sizeof(int));
    return d;
}

int
get(Dynarray* d, int i)
{
    return d->dinarray[i];
}

/*
* BUG: this is bogus. Should set only itens that were pushed back.
*/
void
set(Dynarray* d, int i, int n)
{
    d->dinarray[i] = n;
}

void
pushback(Dynarray* d, int n)
{
    if(d->size == d->capacity)
    {
        resize(d);
    }
    d->dinarray[d->size] = n;
    d->size++;
}

// pop and return the element at the end of the array.
// Array must be non-empty.
int
popback(Dynarray* d)
{
    int popped = d->dinarray[d->size];
    d->dinarray[d->size] = 0;
    d->size--;
    return popped;
}

// double the capacity of the array.
void
resize(Dynarray* d)
{
    d->dinarray = realloc(d->dinarray, 2 * d->capacity);
    d->capacity *= 2;
}

// return the number of elements in the array
int
getSize(Dynarray* d)
{
    return d->size;
}

int
getCapacity(Dynarray* d)
{
    return d->capacity;
}

// TEST: TESTING!!!
int main()
{
    Dynarray d;
    init(&d, 3);

    printf("%s\n",
           getCapacity(&d) == 3? "V" : "F");
    
    pushback(&d, 1);
    pushback(&d, 10);
    pushback(&d, 20);
    
    printf("%s\n",
           get(&d,0) == 1? "V":"F");
    printf("%s\n",
           get(&d,1) == 10? "V":"F");
    printf("%s\n",
           getSize(&d) == 3? "V":"F");

    pushback(&d, 99);

    printf("%s\n",
           getCapacity(&d) == 6? "V":"F");
}
