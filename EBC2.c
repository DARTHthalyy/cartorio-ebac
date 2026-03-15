#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Função para registrar usuários
int registro() {
    char cpf[40], nome[40], sobrenome[40], cargo[40];

    printf("### TELA DE REGISTRO ###\n\n");
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

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

    fprintf(file, "CPF: %s | Nome: %s | Sobrenome: %s | Cargo: %s", cpf, nome, sobrenome, cargo);
    fclose(file);

    printf("\nUsuário cadastrado com sucesso!\n");
    return 0;
}

// Função para consultar usuários
int consulta() {
    char cpf[40];
    char conteudo[200];

    printf("### TELA DE CONSULTA ###\n\n");
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("\n[ERRO] CPF não localizado no sistema.\n");
        return 1;
    }

    printf("\nInformações encontradas:\n");
    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
    }
    printf("\n");
    fclose(file);
    return 0;
}

// Função para deletar usuários
int deletar() {
    char cpf[40];
    printf("### TELA DE EXCLUSÃO ###\n\n");
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("\nUsuário deletado com sucesso!\n");
    } else {
        printf("\n[ERRO] Usuário não encontrado ou arquivo em uso.\n");
    }
    return 0;
}

int main() {
    int opcao = 0;
    int continuar = 1;

    setlocale(LC_ALL, "Portuguese");

    while (continuar == 1) {
        system("cls"); // Limpa a tela para mostrar o menu sempre limpo
        printf("### Cartório do Thaly ###\n\n");
        printf("1 - Registrar nomes\n");
        printf("2 - Consultar nomes\n");
        printf("3 - Deletar nomes\n");
        printf("4 - Sair do sistema\n\n");
        printf("Opção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada inválida! Use apenas números.\n");
            while (getchar() != '\n'); // Limpa buffer para evitar loop infinito
            system("pause");
            continue;
        }

        system("cls"); // Limpa o menu para mostrar a tela da função escolhida

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
                continuar = 0;
                printf("Encerrando o sistema... Até logo!\n");
                break;
            default:
                printf("Opção indisponível. Tente novamente.\n");
                break;
        }
        
        // Se o usuário não escolheu sair, pausa para ele ler o resultado antes de voltar ao menu
        if (continuar) {
            printf("\n------------------------------------\n");
            printf("Pressione qualquer tecla para VOLTAR AO MENU.");
            system("pause > nul"); 
        }
    }

    return 0;
}

