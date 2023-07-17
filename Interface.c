#include <stdio.h> //comunicação com o usuário 
#include <stdlib.h> //alocação de espaço em memória 
#include <locale.h> //alocações de texto por região
#include <string.h> // deixa criar strings
#include <time.h>
////#include <dirent.h> // abre os arquivos

/*int File_set()
{
    
}*/

int registro()
{
    setlocale (LC_ALL, "Portuguese");

    system("cls"); //Limpa a tela

    char arquivo[40];
    char cpf[14];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    //! Conjunto do while
    char ans[1];
    char ans2[1] = "N";
    int result = 1;

    printf("###Registro de nomes###\n\n\n");

    while(result == 1)
    {
        printf("\n>Digite o cpf\n\n");
        printf("CPF:");
        scanf("%s", cpf);

        strcpy(arquivo, cpf); //Copia o valor das strings

        //! Abrindo a pasta _________
        FILE *file; //cria o arquivo principal
        file =  fopen(arquivo,"w"); //abre o arquivo,  w = write, escrever no arquivo e criar um novo
        fprintf(file,"CPF:"); //* coloca um - entre as informações
        fprintf(file,cpf); //salva o valor
        fclose(file); //fecha o arquivo
        //! Pasta fechada_______

        /*
        ////file = fopen(arquivo,"a") 
        ////fprint(file,"—");
        ////fclose(file);
        */

        printf("\n\n>Digite o Nome\n\n");
        printf("Nome:");
        scanf("%s", nome);
        
        //!Abrindo a pasta _________
        file = fopen(arquivo,"a"); //* a = quer atualizar a informação e não abrir um novo
        fprintf(file,"\nNome:");
        fprintf(file, nome);
        fclose(file);
        //! Pasta fechada_______

        printf("\n\n>Digite o Sobrenome\n\n");
        printf("S.Nome:");
        scanf("%s", sobrenome);
        
        //! Abrindo a pasta _________
        file = fopen(arquivo,"a");
        fprintf(file,"\nSobrenome:");
        fprintf(file, sobrenome);   
        fclose(file);
        //! Pasta fechada_______

        printf("\n\n>Digite o Cargo\n\n");
        printf("Cargo:");
        scanf("%s", cargo);
        
        //! Abrindo a pasta _________
        file = fopen(arquivo,"a");
        fprintf(file,"\nCargo:");
        fprintf(file, cargo);
        fclose(file);
        //! Pasta fechada_______

        printf("\n\nSair?\n\n");
        printf("S/N:");
        scanf("%s", ans);
        result = strcmp(ans2, ans);
        printf("____________");

    }
    printf("\n");
    system("exit");
}

int consulta()
{
    setlocale (LC_ALL, "Portuguese");

    system("cls"); 

    int num = 1;
    char cpf[14];
    char conteudo[200];
    char ans[1];
    char ans2[1] = "N";
    int result = 1;

    printf("###Consulta de nomes###\n\n\n");
    printf(">Qual CPF deseja consultar?\n");

    while(result == 1)
    {
        printf("\nCPF:");
        scanf("%s", cpf);

        FILE *file;
        file = fopen(cpf, "r");// r = read, sempe colocar lembrete quando abrir um arquivo -> //!arquivo aberto!
        
        if(file != NULL)
        {
            printf("\n\nInfo do usuário:\n\n");
        

            while(fgets(conteudo, 200, file) != NULL)
            {
                printf("\t");
                printf("%d", num);
                printf("# ");
                printf("%s", conteudo);
                ////printf("\n\nInformações do usuário:");
                num++;
            }

        }else{ printf("\nNão encontrado.\n");}

        fclose(file); //! tem que lembrar de fechar o arquivo *facepalm* :(
        printf("\n\nSair?\n");
        printf("S/N:");
        scanf("%s", ans);
        result = strcmp(ans2, ans);
        printf("____________");
    }
    printf("\n");
    system("exit");
}

int deletar()
{
    setlocale (LC_ALL, "Portuguese");
    
    system("cls"); 

    char cpf[14];
    ////int redo = 1;
    char ans[1];
    char ans2[1] = "N";
    ////int result -strcmp(ans, "S");
    int result = 1;

    printf("###Remoção de nomes###\n\n\n");
    printf(">Qual CPF deseja deletar?\n\n");

    while(result == 1)
    {
        printf("\nNome:");
        scanf("%s", cpf);
        remove(cpf);

        printf("\n\nSair?\n\n");
        printf("S/N:");
        scanf("%s", ans);
        result = strcmp(ans2, ans);
        printf("____________");
    }
    
    printf("\n");
    system("exit");

}

int main()
{
    int opc = 0;

        setlocale (LC_ALL, "Portuguese");
        system("cls"); 
        printf("\n### Cartório da EBAC ###\n\n"); printf("Escolha a opçãoo desejada do menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n");
        printf(":");

        scanf("%d", &opc); //Salva o que foi escrito em 'opc'

        switch (opc)
        {
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
            printf("Obrigado por usar o sistema!");
            return 0;
            break;

            default:
                printf("Escolha inexistente");
                system("exit"); 
            break;
        }
}
