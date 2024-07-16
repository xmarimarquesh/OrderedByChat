// Merge Sort é um algoritmo de ordenação baseado na técnica de divisão e conquista. Ele divide a lista em duas metades, 
// ordena cada metade recursivamente e, em seguida, mescla as duas metades ordenadas para formar a lista final ordenada. 
// Primeiro, o array é dividido até que cada sublista contenha um único elemento. Depois, as sublistas são combinadas de 
// volta em pares, garantindo que cada combinação resultante esteja ordenada. Esse processo de combinação continua até 
// que toda a lista esteja ordenada. O Merge Sort é eficiente, com um tempo de execução de O(n log n) no pior caso, e é 
// estável, mas requer espaço adicional para armazenar os arrays temporários.

#include <stdio.h>
#include <stdlib.h>

// Função para mesclar duas sublistas ordenadas
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criar arrays temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copiar dados para arrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclar os arrays temporários de volta ao array original
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Liberar a memória alocada
    free(L);
    free(R);
}

// Função para realizar o Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ordenar a primeira e a segunda metade
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mesclar as duas metades ordenadas
        merge(arr, l, m, r);
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

    mergeSort(arr, 0, n - 1);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
