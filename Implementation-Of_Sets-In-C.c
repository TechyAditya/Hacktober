#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct set
{
    int *members; // array used in set
    int length;   // length of the array
} set;

set *init()
{
    set *new_set = (set *)malloc(sizeof(set));
    new_set->length = 0;
    new_set->members = (int *)malloc(sizeof(int));
    return new_set;
}

void insert(set *a, int member)
{
    bool in_set = false; // to check if a element is already presnt in the set.
    for (int i = 0; i < a->length; i++)
    {
        if (member == a->members[i])
            in_set = true; // if element found in set.
    }
    if (!in_set) // for unique elements.
    {
        a->members = (int *)realloc(a->members, sizeof(int) * (a->length + 1));
        a->members[a->length] = member;
        a->length++;
    }
}

bool isEmpty(set *a)
{
    return (a->length == 0);
}

void display(set *a)
{
    for (int i = 0; i < a->length; i++)
        printf("%d ", a->members[i]);
}

set *uninon(set *a, set *b)
{
    set *c = init();

    for (int i = 0; i < a->length; i++)
        insert(c, a->members[i]);

    for (int i = 0; i < b->length; i++)
        insert(c, b->members[i]);
    return c;
}

set *intersection(set *a, set *b)
{
    set *c = init();

    for (int i = 0; i < a->length; i++)
    {
        for (int j = 0; j < b->length; j++)
        {
            if (a->members[i] == b->members[j])
                insert(c, a->members[i]);
        }
    }
    return c;
}

set *difference(set *a, set *b)
{
    set *c = init();
    for (int i = 0; i < a->length; i++)
    {
        bool in_set = false;
        for (int j = 0; j < b->length; j++)
        {
            if (a->members[i] == b->members[j])
                in_set = true;
        }
        if (!in_set)
            insert(c, a->members[i]);
    }
    return c;
}

int main()
{
    set *a = init();
    insert(a, 5);
    insert(a, 10);
    insert(a, 15);
    insert(a, 20);
    insert(a, 20);
    insert(a, 25);

    if (isEmpty(a))
        printf("Set a is empty\n");
    else
        printf("Set a is not epmty\n");

    set *b = init();
    insert(b, 20);
    insert(b, 25);
    insert(b, 30);
    insert(b, 35);
    printf("Set elements of A are:\n");
    display(a);
    printf("\nSet elements of B are:\n");
    display(b);

    printf("\nUnion: \n");
    set *c = uninon(a, b);
    display(c);

    printf("\nIntersection: \n");
    set *d = intersection(a, b);
    display(d);

    printf("\nDifference (A-B): \n");
    set *e = difference(a, b);
    display(e);
    printf("\nDifference (B-A): \n");
    set *f = difference(b, a);
    display(f);
    return 0;
}
