// Andressa Sampaio - 24006205
// Marcus Lopes - 24005440

#include <stdio.h>
#include <stdlib.h> // funções como rand e malloc
#include <time.h>// medir tempo de execução

// Selection Sort
void selection_sort(int arr[], int n) {
    // for para percorrer todo o array menos o último, já que o último já está no lugar certo
    for (int i = 0; i < n - 1; i++) {
        int menor = i; //define o primeiro elemento como o menor
        //for para achar o menor elemento
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[menor]) { //se achar um elemento menor, atualiza o menor elemento
                menor = j;
            }
        }
        // troca o elemento atual pelo menor e coloca ele na posição certa
        int temp = arr[menor];
        arr[menor] = arr[i];
        arr[i] = temp;
    }
}

//Insertion Sort
void insertion_sort(int arr[], int n) {
    // for para percorrer cada elemento, partindo do segundo elemento. O primeiro elemento já é considerado ordenado
    for (int i = 1; i < n; i++) {
        // Guarda o valor do elemento atual para colocar ele na posição certa
        int elemento_atual = arr[i];
        // j compara o elemento_atual com elementos anteriores
        int j = i - 1;
        // Enquanto o elemento for maior que o elemento_atual, move ele para frente
        while (j >= 0 && arr[j] > elemento_atual) {
            arr[j + 1] = arr[j];
            j--;
        }
        //coloca o elemento_atual na posição certa
        arr[j + 1] = elemento_atual;
    }
}

//Bubble Sort
void bubble_sort(int arr[], int n) {
    // for para percorrer cada elemento, menos o último
    for (int i = 0; i < n - 1; i++) {
        // for para comparar e mover o maior elemento que não está ordenado para o final
        for (int j = 0; j < n - i - 1; j++) {
            // Se o elemento atual for maior que o próximo
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos de posição
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2];

    // Copia os elementos do subarray esquerda para L[]
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    // Copia os elementos do subarray direita para R[]
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Inicializa os índices de L e R e do array principal
    int i = 0, j = 0, k = l;
    // Mescla os elementos de L[] e R[] de volta para o array arr[]
    while (i < n1 && j < n2) { // Enquanto tiver elementos nas duas arrays
        if (L[i] <= R[j]) { // Se o elemento atual de L[] for menor ou igual ao de R[]
            arr[k++] = L[i++]; // L[i] é copiado para arr[k], ambos são incrementados
        } else {
            arr[k++] = R[j++]; // Se R[j] for menor, R[j] é copiado para arr[k]
        }
    }
    // Copia os elementos que restarem de L[]
    while (i < n1) arr[k++] = L[i++];
    // Copia os elementos que restarem de R[]
    while (j < n2) arr[k++] = R[j++];
}

//Merge Sort
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Calcula o ponto médio do array
        merge_sort(arr, l, m); 
        merge_sort(arr, m + 1, r); 
        merge(arr, l, m, r); // Mescla as metades direita e esquerda
    }
}

// "wrapper" para chamar o Merge Sort
void merge_sort_wrapper(int arr[], int n) {
    merge_sort(arr, 0, n - 1);
}

// Função auxiliar - Quick Sort
int particionar(int arr[], int primeiro, int ultimo) {
    int elemento_central = arr[ultimo]; // Define o último elemento como elemento central
    int i = primeiro - 1; 

    // for para colocar os elementos menores que o elemento central para a esquerda
    for (int j = primeiro; j < ultimo; j++) {
        if (arr[j] < elemento_central) {
            i++; // Incrementa o índice do menor elemento
            // Troca os elementos arr[i] e arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Coloca o elemento central na sua posição certa
    int temp = arr[i + 1];
    arr[i + 1] = arr[ultimo];
    arr[ultimo] = temp;

    // Retorna o índice do elemento central, que está na sua posição certa
    return i + 1;
}

// Quick Sort
void quick_sort(int arr[], int primeiro, int ultimo) {
    if (primeiro < ultimo) {
        int pi = particionar(arr, primeiro, ultimo); 
        quick_sort(arr, primeiro, pi - 1); // Ordena a metade esquerda
        quick_sort(arr, pi + 1, ultimo); // Ordena a metade direita
    }
}

// função para chamar o Quick Sort
void quick_sort_wrapper(int arr[], int n) {
    quick_sort(arr, 0, n - 1);
}

// função para manter a propriedade da Heap em um nó
void heapify(int arr[], int n, int i) {
    int maior = i; // Define o nó atual como o maior
    int esquerda = 2 * i + 1; // Índice do filho à esquerda de i
    int direita = 2 * i + 2; // Índice do filho à direita de i

    // Verifica se o filho à esquerda existe e é maior que o nó atual
    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    // Verifica se o filho à direita existe e é maior que o nó atual ou o filho à esquerda
    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    // Se o maior não for mais o nó atual, faz a troca para manter a propriedade da heap
    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;
        
        heapify(arr, n, maior);
    }
}

// Heap Sort
void heap_sort(int arr[], int n) {
    // Constrói a heap max, organizando o array como uma heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai o maior elemento e o coloca no final do array, repetidamente
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

// medir o tempo de execução 
void medir_tempo(void (*sortFunction)(int[], int), int arr[], int n) {
    int* temp_array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp_array[i] = arr[i];
    }

    clock_t inicio = clock(); // Marca o tempo inicial
    sortFunction(temp_array, n);
    clock_t fim = clock(); // Marca o tempo final

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo em segundos
    printf("Tempo de execução: %.6f segundos\n", tempo);

    free(temp_array); // Libera a memória alocada para o array temporário
}

// Função principal: testes de performance
int main() {
    int tamanhos[] = {100, 1000, 10000, 50000, 100000}; // Tamanhos a serem testados
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]); // Calcula o número total de tamanhos disponíveis

    // Para cada tamanho de array, realiza os testes de performance
    for (int i = 0; i < numTamanhos; i++) { 
        int n = tamanhos[i]; 
        printf("Testando com %d elementos:\n", n); 

        int* arr = (int*)malloc(n * sizeof(int)); // A função malloc é usada para alocar memória dinamicamente

        for (int j = 0; j < n; j++) { 
            arr[j] = rand();
        }

        printf("Selection Sort: "); 
        medir_tempo(selection_sort, arr, n); 
        printf("Insertion Sort: ");
        medir_tempo(insertion_sort, arr, n); 
        printf("Bubble Sort: "); 
        medir_tempo(bubble_sort, arr, n); 
        printf("Merge Sort: ");
        medir_tempo(merge_sort_wrapper, arr, n); 
        printf("Quick Sort: "); 
        medir_tempo(quick_sort_wrapper, arr, n); 
        printf("Heap Sort: "); 
        medir_tempo(heap_sort, arr, n); 

        // Libera a memória alocada para o array após o uso, evitando vazamentos de memória
        free(arr); // Libera a memória alocada para o array
        printf("\n"); // Adiciona uma nova linha para melhor legibilidade na saída do console
    }

    return 0; //indica que o programa foi executado
}