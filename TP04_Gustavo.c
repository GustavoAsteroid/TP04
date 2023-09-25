#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void removeTags(FILE *entrada, FILE *saida) {
    int dentroDaTag = 0;
    char caractere;

    while ((caractere = fgetc(entrada)) != EOF) {
        if (caractere == '<') {
            dentroDaTag = 1;
        } else if (caractere == '>') {
            dentroDaTag = 0;
        } else if (!dentroDaTag) {
            fputc(caractere, saida);
        }
    }
}

int main() {
    setlocale(LC_ALL, "");

    FILE *entrada;
    FILE *saida;

    entrada = fopen("index.html", "r");
    saida = fopen("remocao.html", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    removeTags(entrada, saida);

    fclose(entrada);
    fclose(saida);

    printf("As tags foram removidas e o arquivo remocao.html foi gerado com sucesso.\n");

    return 0;
}

