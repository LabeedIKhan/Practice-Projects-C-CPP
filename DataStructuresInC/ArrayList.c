
#include <stdio.h>
#include <stdlib.h>


typedef struct {

    int* array;

    size_t length;

    size_t size;

}ArrayList;

void CreateArray(ArrayList* arr)
{
    arr->array = malloc(10 * sizeof(int));
    arr->length = 10;
    arr->size = 0;
}

void AddElements(ArrayList* arr, int val)
{
    if (arr->size == arr->length)
    {
        arr->length += 10;
        arr->array = realloc(arr->array, arr->length * sizeof(int));
    }
    arr->array[arr->size++] = val;
}

void RemoveValueAtIndex(ArrayList* arr, int index)
{
    if (index <= arr->size)
    {
        int* temparr = malloc(arr->length * sizeof(int));

        int missing = 0;

        for (int i = 0; i < arr->length; i++)
        {
            if (i == index)
            {
                missing++;
            }
            temparr[i] = arr->array[i + missing];
        }

        free(arr->array);
        arr->array = NULL;
        arr->array = temparr;
        arr->size--;
    }
    else
    {
        printf("Index Out of Bound \n");
    }
}

void AddAtIndex(ArrayList* arr, int index, int val)
{
    if (index <= arr->size)
    {
        int* temparr = malloc((arr->length +1) * sizeof(int));

        int missing = 0;

        for (int i = 0; i < arr->length +1 ; i++)
        {
            if (i == index)
            {
                missing = -1;
                temparr[i] = val;
                i++;
            }
            temparr[i] = arr->array[i + missing];
        }

        free(arr->array);
        arr->array = NULL;
        arr->array = temparr;
        arr->size++;
    }
    else
    {
        if (index == arr->size + 1)
        {
            AddElements(arr, val);
        }
        else
        {
            printf("Index Out of Bound \n");
        }
    }
}

int GetValue(ArrayList * arr,int index)
{
    if (index > arr->size)
    {
        return 0;
    }
    else
    {
        return arr->array[index];
    }
}

void DeleteArray(ArrayList* arr)
{
    free(arr->array);
    arr->array = NULL;
    arr->size = 0;
    arr->length = 0;
}

int main()
{
    ArrayList arr;

    CreateArray(&arr);

    for (int i = 0; i < 50; i++)
    {
        AddElements(&arr, i);
    }

    for (int i = 0; i < 50; i++)
    {
        printf("%d\n", i);
    }

    printf("\nSize is %d\n", arr.size);

    RemoveValueAtIndex(&arr, 49);

    printf("\nSize is %d\n", arr.size);

    AddAtIndex(&arr, 5, 50);

    AddAtIndex(&arr, 51, 51);

    RemoveValueAtIndex(&arr, 53);

    AddAtIndex(&arr, 52, 52);

    printf("\nSize is %d\n", arr.size);

    for (int i = 0; i < arr.size; i++)
    {
        printf("%d\n", GetValue(&arr, i));
    }
    DeleteArray(&arr);
}

