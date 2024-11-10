import matplotlib.pyplot as plt

# Tamanhos dos vetores
tamanhos = [1000, 10000, 50000, 100000]

# Tempos de execução dos algoritmos (exemplo de valores)
selection_sort_times = [0.1, 1.2, 15.4, 100.3]
insertion_sort_times = [0.2, 2.1, 23.5, 180.5]
bubble_sort_times = [0.3, 3.4, 40.7, 350.2]
merge_sort_times = [0.01, 0.05, 0.4, 1.9]
quick_sort_times = [0.02, 0.07, 0.3, 1.3]
heap_sort_times = [0.03, 0.1, 0.5, 2.2]

# Plotando o gráfico
plt.figure(figsize=(10, 6))
plt.plot(tamanhos, selection_sort_times, label='Selection Sort', marker='o')
plt.plot(tamanhos, insertion_sort_times, label='Insertion Sort', marker='o')
plt.plot(tamanhos, bubble_sort_times, label='Bubble Sort', marker='o')
plt.plot(tamanhos, merge_sort_times, label='Merge Sort', marker='o')
plt.plot(tamanhos, quick_sort_times, label='Quick Sort', marker='o')
plt.plot(tamanhos, heap_sort_times, label='Heap Sort', marker='o')

# Configurações do gráfico
plt.xlabel('Tamanho do Vetor')
plt.ylabel('Tempo de Execução (s)')
plt.title('Comparação de Algoritmos de Ordenação')
plt.legend()
plt.grid(True)
plt.yscale('log')  # Escala logarítmica para facilitar a visualização das diferenças

# Mostrando o gráfico
plt.show()