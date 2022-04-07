#include <stdio.h>
#include <string.h>

int main(){

    printf("Sistema de reservas de materiais\n");

    // ler logins e senhas do arquivo de configuracao
    FILE *cadastro = fopen("cadastro.txt", "r");
    char logins[100][100];
    char senhas[100][100];

    int num_cadastros = 0;
    char login[100];
    char senha[100];
    while (fscanf(cadastro, "%s %s", login, senha) > 0){
        strcpy(logins[num_cadastros], login);
        strcpy(senhas[num_cadastros], senha);
        num_cadastros++;
    }
    fclose(cadastro);
    printf("Carregados %d cadastros do banco de dados.\n", num_cadastros);

    // pedir login e senha do usuario

    int logado = 0;

    while(logado == 0){
        printf("Digite o seu usuario: ");
        scanf("%s%*c", login);
        printf("Digite a sua senha: ");
        scanf("%s%*c", senha);

    // procurar nos cadastros


    for (int i = 0; i < num_cadastros; i++){
        if (strcmp(login, logins[i]) == 0 && (strcmp(senha, senhas[i])) == 0){
            logado = 1;
        }
    }

    if (logado == 1){
        printf("Login bem sucedido.\n");
    } else {
        printf("Usuario ou senha incorretos.\n");

    }
}

    // Solicitante

    FILE *solicitantes = fopen("solicitantes.txt", "a");

    char nome[200];
    printf("Identificacao do solicitante:.\n ");
    fgets(nome, 199, solicitantes);

    char material[20];
    printf("Material para ser emprestado: ");
    fgets(material, 19, stdin);

    char sala[20];
    printf("Sala: ");
    fgets(sala, 19, stdin);

    char emprestimo[200];
    printf("Data do emprestimo: ");
    fgets(emprestimo, 199, stdin);

    char horario[100];
    printf("Horario pretendido: ");
    fgets(horario, 99, stdin);

    char devolucao[100];
    printf("Data da devolucao: ");
    fgets(devolucao, 99, stdin);

    // salvando dados dos solicitantes
   fclose(solicitantes);


    printf("Atendimento registrado no banco de dados.\n");
    return 0;
}
