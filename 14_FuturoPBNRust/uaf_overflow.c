// uaf_overflow.c
// Exemplos clássicos de vulnerabilidades espaciais e temporais em C
// Compile com: gcc -Wall -g uaf_overflow.c -o uaf_overflow
// Para detectar com AddressSanitizer: gcc -fsanitize=address -g uaf_overflow.c -o uaf_asan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int nivel_acesso; // 0 = usuario comum, 99 = admin
} Sessao;

// 1. Falha Espacial: Buffer Overflow (sobrenome invade a variável 'autorizado')
void vulnerabilidade_espacial(const char *entrada) {
    char buffer[8];
    int autorizado = 0;

    // PERIGO: strcpy não verifica o tamanho de 'buffer'!
    strcpy(buffer, entrada);

    printf("[Espacial] buffer = '%s' | autorizado = %d\n", buffer, autorizado);
}

// 2. Falha Temporal: Use-After-Free (ponteiro pendente lê memória realocada)
void vulnerabilidade_temporal(void) {
    Sessao *usuario = (Sessao *)malloc(sizeof(Sessao));
    usuario->id = 101;
    usuario->nivel_acesso = 0;

    // Libera a sessão do usuário comum, mas esquece de anular o ponteiro!
    free(usuario);

    // Outra parte do sistema aloca memória do mesmo tamanho (reaproveita o bloco!)
    Sessao *servico_admin = (Sessao *)malloc(sizeof(Sessao));
    servico_admin->id = 1;
    servico_admin->nivel_acesso = 99; // Privilégio máximo!

    // BUG GRAVE (Use-After-Free): ponteiro antigo 'usuario' ainda aponta para lá!
    printf("[Temporal] Lendo ponteiro liberado -> id: %d, nivel_acesso: %d\n",
           usuario->id, usuario->nivel_acesso);

    free(servico_admin);
}

int main(void) {
    printf("--- Demonstração de Falhas de Memória em C ---\n");
    vulnerabilidade_espacial("aluno");
    vulnerabilidade_temporal();
    return 0;
}

