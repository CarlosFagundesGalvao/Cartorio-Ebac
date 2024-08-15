#include <stdio.h>    // Biblioteca de comunica?ao com o usu?rio.
#include <stdlib.h>   // Biblioteca de aloca?ao de espa?o em mem?ria
#include <locale.h>   // Biblioteca de aloca?oes de texto por regiao(acentos e tals)
#include <string.h>   // Biblioteca responsavel pelas strings

int registro() // Função responsavel por cadastrar usuarios
{
    //Variáveis
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    // CPF

    printf("Digite o CPF a ser cadastrado:"); //coletando informaçoes do usuário
    scanf("%s", cpf); //%s refere-se a strings

    strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings 

    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e W = write
    fprintf(file,cpf); // Salva o valor da variavel
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    
    // NOME


    printf("Digite o nome a ser cadastrado:");
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);



     // SOBRENOME



    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);



     // CARGO
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);

    system("pause");





}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf, "r"); // r = read
    fclose(file);

    if(file == NULL)
    {
        printf("Este CPF n?o est? registrado! \n ");
    }

    while(fgets(conteudo, 200, file) != NULL);
    {
        printf("\nEssas s?o as informa??es do usu?rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");


}

    

int deletar()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");
    fclose(file);

    if(file == NULL)
    {
        printf("\nO usu?rio n?o se encontra no sistema!. \n\n");
        system("pause");
    }

    remove(cpf);

    if 
    (file != NULL)
    {
        printf("\nO usu?rio foi deletado com sucesso!.\n\n");
        system("pause");
    }





}

int main()
{
    int opcao=0; //Definindo v?riaveis
    int laco=1;
    
    for(laco=1;laco=1;)
{

    system("cls"); // Limpar a tela
    setlocale(LC_ALL, "Portuguese"); // Definindo l?nguagem


    printf("--- Cart?rio da EBAC --- \n\n"); // In?cio do programa
    printf("Escolha a op??o desejada no menu: \n\n");
    printf("\t 1 - Registrar nomes \n");
    printf("\t 2 - Consultar nomes \n");
    printf("\t 3 - Deletar nomes \n\n\n");
    printf("Op??o: "); // Fim do programa

    scanf("%d" , &opcao); // Armazenando a escolha do usu?rio

    system("cls");

    switch (opcao) // inicio da seleção do menu
    {
    case 1:
        registro(); // chamada de funções   
        break;
    
    case 2:
        consulta();
        break;

    case 3:
        deletar();
        break;

    default:   
        printf("Essa op??o n?o existe!\n");
        system("pause");
        break;
    }

}
}