#include <stdio.h>   
#include <stdlib.h>   

// Inclui o arquivo de cabeçalho personalizado "ponto.h".
#include "ponto.h"     

int main() {
    // Declara um ponteiro para um arquivo.
    FILE *file;   
    // Declara variáveis para o número de vértices e um contador.      
    int numVertices, i; 
    // Declara um ponteiro para um array de pontos.
    Ponto *vertices;   
    // Inicializa a variável de área com zero. 
    float area = 0.0;   

    // Abre o arquivo de entrada chamado "vertices.txt" no modo de leitura ("r").
    file = fopen("vertices.txt", "r");
    
    // Verifica se o arquivo foi aberto com sucesso.
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        // Sai do programa com código de erro.
        return 1; 
    }

    // Lê o número de vértices do arquivo.
    fscanf(file, "%d", &numVertices);

    // Aloca dinamicamente memória para armazenar os vértices do polígono.
    vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));
    
    // Verifica se a alocação de memória foi bem-sucedida.
    if (vertices == NULL) {
        printf("Erro ao alocar memória.\n");
        // Fecha o arquivo antes de sair.
        fclose(file);
        // Sai do programa com código de erro. 
        return 1;     
    }

    // Lê as coordenadas dos vértices do arquivo.
    for (i = 0; i < numVertices; i++) {
        fscanf(file, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    // Calcula a área do polígono dividindo-o em triângulos.
    for (i = 1; i < numVertices - 1; i++) {
        area += calcularAreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }

    // Exibe a área calculada no formato especificado.
    printf("A area do poligono e %.2f\n", area);

    // Libera a memória alocada para os vértices e fecha o arquivo.
    free(vertices);

    // Fecha o arquivo
    fclose(file);

    // Sai do programa com sucesso.
    return 0; 
}
