#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int indexOfMin, temp;
    printf("Running Selection sort...\n");
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13

    int A[] = {3, 5, 2, 13, 12};
    int n = 5;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;
}
// ✅ Advantages of Selection Sort:

// Simple and Easy to Implement – The algorithm is straightforward and requires fewer lines of code.
// In-Place Sorting – Requires O(1) extra space, making it memory efficient.
// Performs Well on Small Data Sets – Works fine for small arrays where advanced algorithms might be unnecessary.
// Fewer Swaps than Bubble Sort – Unlike Bubble Sort, which swaps in every iteration, Selection Sort only swaps once per pass, reducing the number of swaps significantly.
// Consistently O(n²) Time Complexity – Unlike Insertion Sort, which can be O(n) in the best case, Selection Sort remains consistently O(n²) regardless of initial ordering.

// ❌ Disadvantages of Selection Sort:

// Inefficient for Large Data Sets – Has a worst-case and average-case time complexity of O(n²), making it impractical for large datasets.
// Not Adaptive – Unlike Insertion Sort, Selection Sort does not take advantage of already sorted elements to speed up execution.
// Not Stable – It may change the relative order of equal elements, making it unsuitable for scenarios where stability is required.
// More Comparisons than Swaps – Even though it minimizes swaps, it performs O(n²) comparisons, which can slow down execution.
// Slower than Insertion Sort for Nearly Sorted Data – Insertion Sort performs O(n) in the best case, whereas Selection Sort still takes O(n²)..
