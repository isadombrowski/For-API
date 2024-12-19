#include <stdio.h>
#include <ctype.h>  // Para a função isalpha

int valid_f(char c) {
    // Função que valida se o caractere é alfanumérico
    return isalpha(c);
}

int main() {
    char achar;
    int length = 0;
    int valid_id = 1;

    printf("Identificador: ");
    achar = fgetc(stdin);  // Leitura do primeiro caractere

    if (valid_f(achar)) {
        length = 1;  // Se o primeiro caractere for válido, o comprimento é 1
    }

    achar = fgetc(stdin);  // Lê o próximo caractere

    while (achar != '\n' && achar != EOF) {
        if (!(valid_f(achar))) {
            valid_id = 0;  // Se um caractere inválido for encontrado
        }
        length++;  // Contagem do comprimento
        achar = fgetc(stdin);  // Continua lendo os caracteres
    }

    // Verifica se o identificador é válido
    if (valid_id && length >= 1 && length < 6) {
        printf("Válido\n");
    } else {
        printf("Inválido\n");
    }

    return 0;
}
