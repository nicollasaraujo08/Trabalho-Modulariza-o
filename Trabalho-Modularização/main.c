#include <stdio.h>
#include <string.h>

void cadastrar(int codigo[5], char nome[5][15], int *total) {
    int cod, i;
    if (*total >= 5) {
        printf("\nCadastro cheio!\n");
        return;
    }
    printf("\nDigite o codigo: ");
    scanf("%d", &cod);
    for (i = 0; i < *total; i++) {
        if (codigo[i] == cod) {
            printf("\nCodigo ja cadastrado!\n");
            return;
        }
    }
    codigo[*total] = cod;
    printf("Digite o nome: ");
    scanf("%14s", nome[*total]);
    (*total)++;
    printf("\nCadastro realizado com sucesso!\n");
}

void consultar(int codigo[5], char nome[5][15], int total) {
    int cod, i, achou = 0;
    printf("\nDigite o codigo para consultar: ");
    scanf("%d", &cod);
    for (i = 0; i < total; i++) {
        if (codigo[i] == cod) {
            printf("\nCodigo: %d\nNome: %s\n", codigo[i], nome[i]);
            achou = 1;
        }
    }
    if (achou == 0) {
        printf("\nRegistro nao encontrado!\n");
    }
}

void listar(int codigo[5], char nome[5][15], int total) {
    int i;
    if (total == 0) {
        printf("\nNenhum registro cadastrado.\n");
        return;
    }
    printf("\n--- LISTA DE REGISTROS ---");
    for (i = 0; i < total; i++) {
        printf("\nCodigo: %d | Nome: %s", codigo[i], nome[i]);
    }
    printf("\n");
}

void alterar(int codigo[5], char nome[5][15], int total) {
    int cod, i, achou = 0;
    printf("\nDigite o codigo para alterar: ");
    scanf("%d", &cod);
    for (i = 0; i < total; i++) {
        if (codigo[i] == cod) {
            printf("Nome atual: %s\nDigite o novo nome: ", nome[i]);
            scanf("%14s", nome[i]);
            printf("\nRegistro alterado com sucesso!\n");
            achou = 1;
        }
    }
    if (achou == 0) {
        printf("\nRegistro nao encontrado!\n");
    }
}

void excluir(int codigo[5], char nome[5][15], int *total) {
    int cod, i, j, achou = 0;
    printf("\nDigite o codigo para excluir: ");
    scanf("%d", &cod);
    for (i = 0; i < *total; i++) {
        if (codigo[i] == cod) {
            for (j = i; j < *total - 1; j++) {
                codigo[j] = codigo[j + 1];
                strcpy(nome[j], nome[j + 1]);
            }
            (*total)--;
            achou = 1;
            printf("\nRegistro excluido com sucesso!\n");
            break;
        }
    }
    if (achou == 0) {
        printf("\nRegistro nao encontrado!\n");
    }
}

int main(void) {
    int codigo[5];
    char nome[5][15];
    int total = 0;
    int opcao;

    do {
        printf("\n\n===== MENU =====");
        printf("\n1 - Cadastrar");
        printf("\n2 - Consultar");
        printf("\n3 - Listar");
        printf("\n4 - Alterar");
        printf("\n5 - Excluir");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar(codigo, nome, &total);
                break;
            case 2:
                consultar(codigo, nome, total);
                break;
            case 3:
                listar(codigo, nome, total);
                break;
            case 4:
                alterar(codigo, nome, total);
                break;
            case 5:
                excluir(codigo, nome, &total);
                break;
            case 0:
                printf("\nEncerrando...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}