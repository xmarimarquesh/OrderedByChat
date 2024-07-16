// O Quick Sort é um algoritmo de ordenação eficiente baseado na técnica de divisão e conquista. Ele seleciona um elemento como 
// pivô e reorganiza o array para que todos os elementos menores que o pivô fiquem à esquerda e os maiores fiquem à direita. 
// O algoritmo é aplicado recursivamente nas sublistas resultantes até que todo o array esteja ordenado. O Quick Sort tem um 
// tempo médio de execução de O(n log n), sendo muito eficiente para grandes conjuntos de dados, mas pode ter um desempenho 
// pior no pior caso, dependendo da escolha do pivô.

#include <stdio.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array e retornar o índice do pivô
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Seleciona o último elemento como pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j < high; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Coloca o pivô na posição correta
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Particiona o array
        int pi = partition(arr, low, high);

        // Ordena as sublistas
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, n - 1);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
