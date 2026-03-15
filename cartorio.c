
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Função para registrar usuários
int registro() {
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    // Abre o arquivo uma única vez para escrita
    FILE *file = fopen(cpf, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    printf("Digite o nome: ");
    scanf("%s", nome);
    printf("Digite o sobrenome: ");
    scanf("%s", sobrenome);
    printf("Digite o cargo: ");
    scanf("%s", cargo);

    // Grava todos os dados formatados (estilo CSV)
    fprintf(file, "%s,%s,%s,%s", cpf, nome, sobrenome, cargo);
    fclose(file);

    printf("\nUsuário cadastrado com sucesso!\n");
    return 0;
}

// Função para consultar usuários
int consulta() {
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("CPF não localizado ou erro ao abrir arquivo.\n");
        return 1;
    }

    printf("\nInformações do usuário (CPF, Nome, Sobrenome, Cargo):");
    while (fgets(conteudo, 200, file) != NULL) {
        printf("\n%s", conteudo);
    }
    printf("\n\n");
    fclose(file);
    return 0;
}

// Função para deletar usuários
int deletar() {
    char cpf[40];
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    // Tenta deletar o arquivo
    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso!\n");
    } else {
        printf("Usuário não encontrado ou erro ao deletar.\n");
    }
    return 0;
}

int main() {
    int opcao = 0;
    int continuar = 1;

    setlocale(LC_ALL, "Portuguese");

    // Loop corrigido: usa a variável 'continuar' para controle
    while (continuar == 1) {
        system("cls");
        printf("### Cartório do Thaly ###\n\n");
        printf("1 - Registrar nomes\n");
        printf("2 - Consultar nomes\n");
        printf("3 - Deletar nomes\n");
        printf("4 - Sair do sistema\n\n");
        printf("Opção: ");

        // Verifica se a leitura do scanf foi bem-sucedida
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida!\n");
            fflush(stdin); // Limpa o buffer
            system("pause");
            continue;
        }

        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
                continuar = 0; // Encerra o loop
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção indisponível.\n");
                break;
        }
        
        if (continuar) system("pause");
    }

    return 0;
}
