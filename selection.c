// O Selection Sort é um algoritmo de ordenação que não usa a técnica de divisão e conquista. Em vez disso, ele ordena 
// a lista em uma única passagem através do array. O algoritmo percorre repetidamente a lista não ordenada, encontrando 
// o menor (ou maior, dependendo da ordem desejada) elemento e movendo-o para a posição correta na lista ordenada. 
// Ele tem uma complexidade de tempo O(n²) no pior e no melhor caso, o que o torna ineficiente para listas grandes. 
// No entanto, é simples de implementar e não requer espaço adicional significativo além do array de entrada.

#include <stdio.h>

// Função para realizar o Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex;

    // Um por um, move a fronteira da sublista não ordenada
    for (i = 0; i < n - 1; i++) {
        // Encontra o menor elemento na sublista não ordenada
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro elemento
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
