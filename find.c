#include<stdio.h>

int binary_search(int a[], int size, int target)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    return -1;
    }
}
void insertionsort(int a[], int size)
{
    int i , j , k;
    for (i = 1; i < size; i++)
    {
        k = a[i];
        for (j = i; a[j-1] > k && j > 0; j--)
        {
            a[j] = a[j-1];
        }
        a[j] = k; 
    }
}
int aaj_ka_naya_binary_search(int a[], int size, int target, int low, int high)
{
    if (low <= high)
    {
        int mid = (high + low) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if(a[mid] < target)
        {
            return aaj_ka_naya_binary_search(a, size, target, mid + 1, high);
        }
        else
        {
            return aaj_ka_naya_binary_search(a, size, target, low, mid - 1);
        }
    }
    return -1;
}

int main()
{
    int index, total = 10, i;
    int b[] = {3, 7, -1, 6, 5, 9, 8, 5, 2, 0} ; 
    insertionsort(b, 10);
    printf("array after sorting : ");
    for(i = 0 ; i < 10 ; i ++)
    {
        printf("%d " ,b[i]);   
    }
    // index = binary_search(b, 10, -1);
    // printf("\nvalue found at index %d\n", index);
    for (i = 0; i < 10; i++)
    {
        index = binary_search(b, 10, total - b[i]);
        if (index != -1 && index < i)
        {
            printf("\nthe pair is (%d, %d) at index %d and %d", b[index], b[i], index, i);
        }
    }
    printf("\n");
}