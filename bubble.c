// O Bubble Sort é um algoritmo de ordenação simples que funciona repetidamente passando por uma lista e comparando pares de elementos adjacentes. 
// Se um par de elementos estiver na ordem errada (o primeiro maior que o segundo em uma ordenação crescente), eles são trocados. Cada passagem 
// coloca o maior elemento da parte não ordenada no final da lista, e o processo continua até que uma passagem completa seja feita sem trocas, 
// indicando que a lista está ordenada. Apesar de sua simplicidade, o Bubble Sort não é eficiente para grandes listas devido ao seu alto custo 
// computacional, sendo mais adequado para conjuntos de dados pequenos.

#include <stdio.h>

// Função para realizar o Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        // A cada iteração, o maior elemento "bolha" para o final do array
        for (j = 0; j < n-i-1; j++) {
            // Comparar o elemento atual com o próximo
            if (arr[j] > arr[j+1]) {
                // Trocar os elementos se estiverem na ordem errada
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}

