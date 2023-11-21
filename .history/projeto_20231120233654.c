#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int valor;
} Registrador;

typedef struct {
    char opcode[10];
    char rs[5];
    char rt[5];
    char rd[5];
    char shamt[5];
    char funct[10];
} Instrucao;

void IF_stage(Registrador *PC, Instrucao *instrucao);
void ID_stage(Instrucao *instrucao, Registrador *registradores);
void EX_stage(Instrucao *instrucao, Registrador *registradores);
void MEM_stage(Instrucao *instrucao, Registrador *registradores);
void WB_stage(Instrucao *instrucao, Registrador *registradores);
void lerInstrucao(Instrucao *instrucao);
void exibirFormatoInstrucao(Instrucao *instrucao);
void atualizarPC(Registrador *PC);
int main() {
    // Inicializar registradores, memória, etc.

    Instrucao instrucao;
    Registrador PC;

    // Loop principal
    while (1) {
        // Ler instrução
        lerInstrucao(&instrucao);

        // Exibir formato da instrução
        exibirFormatoInstrucao(&instrucao);

        // Executar etapas do processador
        IF_stage(&PC, &instrucao);
        ID_stage(&instrucao, registradores);
        EX_stage(&instrucao, registradores);
        MEM_stage(&instrucao, registradores);
        WB_stage(&instrucao, registradores);

        // Atualizar PC
        atualizarPC(&PC);
    }

    return 0;
}

