// O Insertion Sort é um algoritmo de ordenação que constrói a lista ordenada uma peça de cada vez, inserindo elementos na posição correta. 
// O processo começa com o segundo elemento da lista e o compara com os elementos anteriores, deslocando-os para a direita se necessário para 
// abrir espaço para a inserção. O elemento é então inserido na posição correta, mantendo a ordem dos elementos anteriores. Esse processo é 
// repetido para cada elemento subsequente da lista até que toda a lista esteja ordenada. O Insertion Sort é eficiente para listas pequenas 
// ou quase ordenadas, mas pode ser lento para grandes listas devido ao seu custo computacional elevado no pior caso.

#include <stdio.h>

// Função para realizar o Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Mover os elementos de arr[0..i-1] que são maiores que key
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}

