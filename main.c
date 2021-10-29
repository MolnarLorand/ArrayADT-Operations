#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr) {
    int i;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void Add(struct Array *arr, int x) {
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}


void Insert(struct Array *arr, int index, int x) {
    int i;
    if (index >= 0 && index <= arr->length) {
        for (i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index) {
    int i;
    int x;//to store the value we want to delete
    if (index >= 0 && index <= arr->length - 1) {
        x = arr->A[index]; //store the value in the variable x
        for (i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    return x;
}

void Swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key) {
    int i;
    for (i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {
            Swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array *arr, int key) {
    int l, mid, h;
    l = 0;
    h = arr->length - 1;
    while (l <= h) {
        mid = (l + h) / 2;
        if (key == arr->A[mid])
            return mid;
        else if (key < arr->A[mid])
            h = mid - 1;
        else
            h = mid + 1;
    }
    return -1;
}

int BinarySearchRecursive(int a[], int l, int h, int key) {
    int mid;
    if (l <= h) {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return BinarySearchRecursive(a, l, mid - 1, key);
        else
            return BinarySearchRecursive(a, mid + 1, h, key);
    }
    return -1;
}

int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int Max(struct Array arr) {
    int i;
    int max = arr.A[0];
    for (i = 1; i < arr.length; i++) {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr) {
    int i;
    int min = arr.A[0];
    for (i = 1; i < arr.size; i++) {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr) {
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++) {
        s += arr.A[i];
    }
    return i;
}

int Avg(struct Array arr) {
    return (float) Sum(arr) / arr.length;
}

int AvgCalculated(struct Array arr) {
    int i, s, total = 0;
    for (i = 0; i < arr.length; i++)
        total += arr.A[i];

    return total / arr.length;
}

void Reverse(struct Array *arr) {
    int *B;
    int i, j;

    B = (int *) malloc(arr->length * sizeof(int));
    for (i = arr->length, j = 0; i > 0; i--, j++) {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }
}

void Reverse2(struct Array *arr) {
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--) {
        Swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertInSort(struct Array *arr, int x) {
    int i = arr->length - 1;
    if (arr->length == arr->size) {
        return;
    }
    while (arr->A[i] > x && i >= 0) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int CheckIfIsSorted(struct Array arr) {
    int i;
    for (i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1])
            return 0;//0 if is false
    }
    return 1;//1 if is true
}

void Rearrange(struct Array *arr) {
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j) {
        while (arr->A[i] < 0)i++;
        while (arr->A[j] >= 0)j--;
        if (i < j) {
            Swap(&arr->A[i], &arr->A[j]);
        }
    }
}

struct Array *Merge(struct Array *arr1, struct Array *arr2) {
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while (i < arr1->length - 1 && j < arr2->length - 1) {//compare element from arr1&2 and then store them in arr3 !
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i];
        else
            arr3->A[k++] = arr2->A[j];
    }
    for (; i < arr1->length; i++)//copy the rest of the elements if there are some
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

struct Array *Union(struct Array *arr1, struct Array *arr2) {
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr2->A[j] < arr1->A[i]) {
            arr3->A[k++] = arr2->A[j++];
        } else {//if are equals then copy just one of them in third array
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2) {
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            i++;
        } else if (arr2->A[j] < arr1->A[i]) {
            j++;
        } else if (arr1->A[i] == arr2->A[j]) {//here both are equal
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2) {
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr2->A[j] < arr1->A[i]) {
            j++;
        } else {//equal
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];


    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main() {
    struct Array arr1;
    int ch;
    int x, index;
    printf("Enter size of Array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *) malloc(arr1.size * sizeof(int)); // create an array inside heap and asign to A
    arr1.length = 0;
    do {
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Add at the end\n");
        printf("6. Min\n");
        printf("7. Max\n");
        printf("8. Reverse\n");
        printf("9. Check if is sorted\n");
        printf("10. Display\n");
        printf("11. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter an element and index: ");
                scanf("%d%d", &x, &index);
                Insert(&arr1, index, x);
                break;

            case 2:
                printf("Enter the index where you want to delete: ");
                scanf("%d", &index);
                x = Delete(&arr1, index);
                printf("Teleted element is %d\n", x);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &x);
                index = LinearSearch(&arr1, x);
                printf("Element deleted at index %d", index);
                break;

            case 4:
                printf("Sum is %d", Sum(arr1));
                break;

            case 5:
                printf("Enter element to add at the end of the array: ");
                scanf("%d",&x);
                Add(&arr1,x);
                break;

            case 6:
                printf("The min element in the array is: %d",Min(arr1));
                break;

            case 7:
                printf("The max element in the array is: %d", Max(arr1));
                break;

            case 8:
                printf("Reverse the array");
                Reverse(&arr1);
                printf("\n");
                Display(arr1);
                break;

            case 9:
                printf("1 is true 0 is false: %d",CheckIfIsSorted(arr1));

                break;
//sss
            case 10:
                Display(arr1);

        }
    } while (ch < 11);

    return 0;
}
