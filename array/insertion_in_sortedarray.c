#include <stdio.h>
#include <conio.h>
int main()
{
    int array[10], size;
    printf("Enter size of array:");
    scanf("%d", &size);
    if (size < 10)
    {
        for (int i = 0; i < size; i++)
        {
            printf("Enter element:");
            scanf("%d", &array[i]);
        }
        int index, element;
        printf("Enter index where you want to insert element in array :");
        scanf("%d", &index);
        if (index >= 0 && index <= size)
        {
            printf("Enter element:");
            scanf("%d", &element);
            for (int i = size - 1; i >= index; i--)
            {
                array[i + 1] = array[i];
            }
            array[index] = element;
            size++;
            printf("Now size of array is:%d\n", size);
            printf("Now array elements are:\n");
            for (int i = 0; i < size; i++)
            {
                printf("%d\n", array[i]);
            }
        }
        else
        {
            printf("Index out of bound");
        }
    }
    else
    {
        printf("Index out of bound");
    }
}