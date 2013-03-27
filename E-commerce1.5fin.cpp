#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAX_USUARIOS 100
#define MAX_PRODUTOS 50
#define TAM_NOME_MAX 60
#define MAX_LINHA 256
#define MAX_DIGITOS 10
#define MAX_CARRRINHO 20
#define DIAS_UTEIS 7
#define MAX_COMPRAS_SUSP 50
typedef struct
{
        int codigo;
        char nome[TAM_NOME_MAX];
        char categoria[TAM_NOME_MAX];
}USUARIO;

typedef struct
{
        USUARIO cadastro[MAX_USUARIOS];
        int totalUsuarios;
}CADASTRO;

typedef struct
{
        int codigo;
        char descricao[TAM_NOME_MAX];
        int altura;
        int largura;
        int profundidade;
        float preco;
        int estoque;
        char cor[TAM_NOME_MAX];
}ELETRO;

typedef struct
{
        int codigo;
        char descricao[TAM_NOME_MAX];
        char tamanho[TAM_NOME_MAX];
        float preco;
        int estoque;
        char cor[TAM_NOME_MAX];
        char genero[TAM_NOME_MAX];
}VESTUARIO;

typedef struct
{
        ELETRO eletronico[MAX_CARRRINHO];
        VESTUARIO vestuario[MAX_CARRRINHO];
        int itensEletro;
        int itensVestuario;
}CARRINHO;

typedef struct
{
        int valorTotal;
        int quantidadeEletronico;
        int quantidadeVestuario;
}VENDA;

//funcao tela inicial, chamada pela
int telaInicial()
{
     char resposta;
     textcolor(YELLOW);
     int opcaoValida;
     printf("\n         MM                                    ");
     printf("\n        MMM  MM    MM       nc     @Mo         ");
     printf("\n       MMM   MM    MM      bMM.    MMMM        ");
     printf("\n      MM#    MM    MM     cMMMM    MMMMM,      ");
     printf("\n     MME     MM    MM    .MM MMM   MM  MMM     ");
     printf("\n    MM7      MM    MM    MM   MMi  MM   MMM    ");
     printf("\n   MMQ       MM    MM   MM.    MM  MM     MMM  ");
     printf("\n   ;MMM      MMMMMMMM  MMv     MMM MM   ,MMMM  ");
     printf("\n     MMM     MMMMMMMM .MM       MM MM MMMMM    ");
     printf("\n      MMM.   MM    MM  MMM     @MM MMMMMv      ");
     printf("\n        MMM  MM    MM   MM    QMM  MMM         ");
     printf("\n        MMM  MM    MM   .MM  tMM   MM          ");
     printf("\n      .MMz   MM    MM    MM8 MM    MM          ");
     printf("\n     IMM.    MM    MM     MMMM     MM          ");
     printf("\n    MMM      MM    MM     IMM      MM          ");
     printf("\n   MMM       MM    MM      ;       #M          ");
     printf("\n   MM                                          ");
     textcolor(WHITE);
     printf("\n================================================================");
     printf("\nSeja bem vindo. O que voce deseja fazer?");
     textcolor(LIGHTGREEN);printf("\nL");textcolor(WHITE);printf("ogin");
     textcolor(LIGHTGREEN);printf("\nC");textcolor(WHITE);printf("riar nova conta");
     textcolor(LIGHTGREEN);printf("\nI");textcolor(WHITE);printf("nformacoes");
     textcolor(LIGHTGREEN);printf("\nS");textcolor(WHITE);printf("air");
     printf("\n================================================================\n");
     fflush(stdin);
     do
     {
        textcolor(LIGHTGREEN);
        fflush(stdin);
        scanf("%c", &resposta);
        resposta = toupper(resposta);
        textcolor(WHITE);
        switch(resposta)
        {
            case 'L':
            {    opcaoValida = 1;
                 break;
            }
            case 'C':
            {    opcaoValida = 2;
                 break;
            }
            case 'I':
            {    opcaoValida = 3;
                 break;
            }
            case 'S':
            {    opcaoValida = 4;
                 break;
            }
            default:
            {
               textcolor(LIGHTRED);
               printf("Opcao Invalida. Por favor digite uma opcao valida: ");
               textcolor(WHITE);
               opcaoValida = 0;
            }
        }
     }while(opcaoValida == 0);
     return(opcaoValida);
}

//MOSTRA AS INFORMACOES DO PROGRAMA
void showInfo()
{
    system("cls");
    textcolor(YELLOW);
    printf("\nINFORMACOES DO PROGRAMA:");
    textcolor(WHITE);
    printf("\n================================================================");
    printf("\nPrograma desenvolvido pelos alunos Geferson Hess Junior, Gabriel");
    printf("\nAlmeida e Augusto Ferreira para a disciplina de Tecnicas de Construcao");
    printf("\nde Programas. O programa gera um arquivo chamado report.txt que");
    printf("\ncontrola as vendas e suas respectivas datas e necessita dos arquivos");
    printf("\neletro.txt, vestuario.txt e usuarios.txt para controlar os esto-");
    printf("\nques e os cadastros.");
    printf("\n================================================================");
    fflush(stdin);
    getch();
}
//FIM DA FUNCAO QUE MOSTRA AS INFORMACOES DO PROGRAMA

//INICIO DA FUNÇÃO PARA CRIAR NOVO USUARIO
void novoUsuario()
{
     FILE *arq;
     USUARIO novoUsuario;
     int totalUsuarios, i;
     bool validaNome, validaCategoria;
     char leituraLinha[MAX_LINHA], categoria;
     system("cls");
     arq = fopen("usuarios.txt", "r");
     if(!arq)
     {
             printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
             getch();
             exit(1);
     }
     totalUsuarios = 0;
     while(!feof(arq))
     {
        fgets(leituraLinha, MAX_LINHA, arq);
        if(leituraLinha[0] != '\n')
           totalUsuarios++;
     }
     fclose(arq);
     if(totalUsuarios < MAX_USUARIOS)
     {
         novoUsuario.codigo = totalUsuarios+1;
         textcolor(YELLOW);
         printf("\nCADASTRO DE NOVO USUARIO");
         textcolor(WHITE);
         printf("\n=============================================================");
         printf("\nSeu cadastro: ");
         textcolor(LIGHTGREEN);
         printf("%d", totalUsuarios+1);
         textcolor(WHITE);
         printf("\nInforme o seu nome: ");
         do
         {
             validaNome = false;
             fflush(stdin);
             textcolor(LIGHTGREEN);
             gets(novoUsuario.nome);
             if(strlen(novoUsuario.nome) >= 3)
             {
                 for(i = 0; i < strlen(novoUsuario.nome); i++)
                 {
                     if(novoUsuario.nome[i] == ',')
                     {
                         textcolor(LIGHTRED);
                         printf("Nome informado invalido. Por favor, nao insira virgulas no nome.\n");
                         textcolor(WHITE);
                         validaNome = true;
                     }
                 }
             }
             else
             {
                 textcolor(LIGHTRED);
                 if(strlen(novoUsuario.nome) == 0)
                     printf("Por favor, insira um nome valido.\n");
                 else
                     printf("Seu nome deve conter pelo menos 3 letras.\n");
                 textcolor(WHITE);
                 validaNome = true;
             }
         }while(validaNome);
         textcolor(WHITE);
         printf("Informe sua categoria. (C para cliente ou G para gerente): ");
         validaCategoria = true;
         do
         {
             fflush(stdin);
             textcolor(LIGHTGREEN);
             scanf("%c", &categoria);
             categoria = toupper(categoria);
             switch(categoria)
             {
                case 'C':
                {
                     strcpy(novoUsuario.categoria, "cliente");
                     validaCategoria = false;
                     break;
                }
                case 'G':
                {
                     strcpy(novoUsuario.categoria, "gerente");
                     validaCategoria = false;
                     break;
                }
                default:
                {
                     textcolor(LIGHTRED);
                     printf("Caractere informado invalido! Informe um caractere valido:");
                     break;
                }
             }
          }while(validaCategoria);
          arq = fopen("usuarios.txt", "a");
          if(!arq)
          {
              printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
              getch();
              exit(1);
          }
          fprintf(arq,"%c%d%c%s%c%s", '\n', novoUsuario.codigo, ',', novoUsuario.nome, ',', novoUsuario.categoria);
          fclose(arq);
          textcolor(YELLOW);
          printf("\nCadastro criado com sucesso!");
          getch();
          textcolor(WHITE);
     }
     else
     {
         textcolor(LIGHTRED);
         printf("Numero maximo de usuarios atingido!");
         fclose(arq);
         textcolor(WHITE);
         getch();
     }
}
//FIM DA FUNÇÃO PARA CRIAR NOVO USUARIO

void inserirProdutoCarrinho(int cadastro)
{
     FILE *arq, *arq2;
     ELETRO eletronico;
     VESTUARIO vestuario;
     CARRINHO carrinho;
     char cadastroEmChar[MAX_DIGITOS], leituraLinha[MAX_LINHA], salvaLinha[MAX_PRODUTOS][MAX_LINHA];
     int codigoProduto, quantidadeProduto, contaLinha = 0, i, comparaCodigo;
     bool encontrouProduto, carrinhoCheio;

     system("cls");
     textcolor(YELLOW);
     printf("\nINSERIR NOVO ITEM NO CARRINHO DE COMPRAS");
     textcolor(WHITE);
     printf("\n==========================================================================");
     printf("\nDigite o codigo do produto que voce quer adicionar ao seu carrinho: ");
     do
     {
             textcolor(LIGHTGREEN);
             scanf("%d", &codigoProduto);
             textcolor(WHITE);
             printf("Digite a quantidade do produto que voce quer adicionar ao seu carrinho: ");
             do
             {
                 textcolor(LIGHTGREEN);
                 scanf("%d", &quantidadeProduto);
                 if(quantidadeProduto <= 0 || quantidadeProduto > MAX_CARRRINHO)
                 {
                     textcolor(LIGHTRED);printf("Quantidade invalida. Informe uma quantidade entre 1 e %d itens: ", MAX_CARRRINHO);
                 }
             }while(quantidadeProduto <= 0 || quantidadeProduto > MAX_CARRRINHO);
             textcolor(WHITE);
             //abre o arquivo de eletrodomesticos para procurar o codigo
//-----------------------------------------------PROCURA CODIGO/MOSTRA DADOS PRODUTO--------------------------------------------------------------------------------
             arq = fopen("eletro.txt", "r+");
             if(!arq)
             {
                 textcolor(LIGHTRED);
                 printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                 textcolor(WHITE);
                 getch();
                 exit(1);
             }
             while((!feof(arq)) && (!encontrouProduto))
             {
                 fgets(leituraLinha, sizeof(leituraLinha), arq);
                 comparaCodigo = atoi(strtok(leituraLinha, ","));
                 if(codigoProduto == comparaCodigo)
                 {
                      encontrouProduto = true;
                      eletronico.codigo = codigoProduto;
                      strcpy(eletronico.descricao, strtok(NULL, ","));
                      eletronico.altura = atoi(strtok(NULL, ","));
                      eletronico.largura = atoi(strtok(NULL, ","));
                      eletronico.profundidade = atoi(strtok(NULL, ","));
                      eletronico.preco = atof(strtok(NULL, ","));
                      eletronico.estoque = atoi(strtok(NULL, ","));
                      strcpy(eletronico.cor, strtok(NULL, "\n"));
                      textcolor(LIGHTGREEN);printf("\nProduto a ser adicionado: \n");textcolor(WHITE);
                      printf("%s   Altura: %d cm    Largura: %d cm" , eletronico.descricao, eletronico.altura, eletronico.largura);
                      printf("\nEstoque: %d   Profundidade: %d cm    Preco: %.2f    Cor: %s", eletronico.estoque, eletronico.profundidade, eletronico.preco, eletronico.cor);
                      printf("\n==========================================================================");
                      fflush(stdin);
                      getch();
                 }
             }
             fclose(arq);
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------SALVA CARRINHO(ADICIONA ITENS)/VENDO SE HÁ ESPAÇO-------------------------------------------
             if(encontrouProduto)
             {
                      if(quantidadeProduto <= eletronico.estoque)
                      {
                               //abre o arquivo de carrinho para salvar
                                carrinhoCheio = false;
                                itoa(cadastro, cadastroEmChar, 10); //converte o codigo para char
                                arq = fopen(cadastroEmChar, "rb");
                                if(!arq)
                                {
                                       arq = fopen(cadastroEmChar, "wb");
                                }
                                if(fread(&carrinho, sizeof(CARRINHO), 1, arq) == 1)
                                {
                                          if(carrinho.itensEletro+quantidadeProduto <= MAX_CARRRINHO)
                                          {
                                               for(i = carrinho.itensEletro; i < (carrinho.itensEletro+quantidadeProduto); i++)
                                               {
                                                    carrinho.eletronico[i] = eletronico;
                                               }
                                               carrinho.itensEletro += quantidadeProduto;
                                          }
                                          else
                                          {
                                              textcolor(LIGHTRED);printf("\nSeu carrinho de eletrodomesticos ja esta cheio.");
                                              textcolor(WHITE);fflush(stdin);getch();
                                              carrinhoCheio = true;
                                          }
                                }
                                else
                                {
                                    carrinho.itensEletro = 0;
                                    if(carrinho.itensEletro+quantidadeProduto <= MAX_CARRRINHO)
                                    {
                                           for(i = carrinho.itensEletro; i < (carrinho.itensEletro+quantidadeProduto); i++)
                                           {
                                                carrinho.eletronico[i] = eletronico;
                                           }
                                           carrinho.itensEletro += quantidadeProduto;
                                    }
                                    else
                                    {
                                        textcolor(LIGHTRED);printf("\nSeu carrinho de eletrodomesticos ja esta cheio.");
                                        textcolor(WHITE);fflush(stdin);getch();
                                        carrinhoCheio = true;
                                    }
                                }
                                fclose(arq);
                                if(!carrinhoCheio)  //ha espaco no carrinho
                                {
                                    arq = fopen(cadastroEmChar, "wb");
                                    if(!arq)
                                    {
                                            textcolor(LIGHTRED);
                                            printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            getch();
                                            exit(1);
                                    }
                                    if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq) == 1)
                                    {
                                           textcolor(YELLOW);printf("\nOs itens foram adicionados ao carrinho com sucesso.");
                                           fflush(stdin);getch();textcolor(WHITE);
                                    }
                                    else
                                    {
                                        textcolor(LIGHTRED);printf("\nHouve um problema ao adicionar os itens ao carrinho.");
                                        fflush(stdin);getch();textcolor(WHITE);
                                    }
                                    fclose(arq);
//------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------ATUALIZANDO ESTOQUE---------------------------------------------
                                    //edita o estoque
                                    arq = fopen("eletro.txt", "r+");
                                    if(!arq)
                                    {
                                            textcolor(LIGHTRED);
                                            printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            getch();
                                            exit(1);
                                    }
                                    contaLinha = 0;
                                    while(!feof(arq))
                                    {
                                        fgets(salvaLinha[contaLinha], sizeof(salvaLinha[contaLinha]), arq);
                                        contaLinha++;
                                    }
                                    fclose(arq);
                                    remove("eletro.txt");

                                    arq = fopen("eletro.txt", "w");
                                    if(!arq)
                                    {
                                            textcolor(LIGHTRED);
                                            printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            getch();
                                            exit(1);
                                    }
                                    eletronico.estoque = eletronico.estoque-quantidadeProduto;
                                    for(i = 0; i < contaLinha; i++)
                                    {
                                        strcpy(leituraLinha, salvaLinha[i]);
                                        comparaCodigo = atoi(strtok(leituraLinha, ","));
                                        if(comparaCodigo != codigoProduto)
                                        {
                                           fputs(salvaLinha[i], arq);
                                        }
                                        else
                                        {
                                            fseek(arq, 0*sizeof(char), SEEK_END);
                                            fprintf(arq,"%d%c%s%c%d%c%d%c%d%c%.2f%c%d%c%s%c", eletronico.codigo, ',', eletronico.descricao, ',', eletronico.altura, ',', eletronico.largura, ',', eletronico.profundidade, ',', eletronico.preco, ',', eletronico.estoque, ',', eletronico.cor, '\n');
                                        }
                                    }
                                    fclose(arq);

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
                               }
                      }
                      else
                      {
                          textcolor(LIGHTRED);
                          printf("\nDesculpe. Nao ha itens em estoque suficientes para efetuar a compra.");
                          textcolor(WHITE);fflush(stdin);getch();
                      }
             }
             else //caso nao tenha achado nos eletrodomesticos, procura no vestuario
             {
//----------------------------------------PROCURA CODIGO/MOSTRA DADOS DO PROTUDO / VESTUARIO------------------------------------------------------------------------
                     arq = fopen("vestuario.txt", "r+");
                     if(!arq)
                     {
                         textcolor(LIGHTRED);
                         printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                         textcolor(WHITE);
                         getch();
                         exit(1);
                     }
                     while((!feof(arq)) && (!encontrouProduto))
                     {
                         fgets(leituraLinha, sizeof(leituraLinha), arq);
                         comparaCodigo = atoi(strtok(leituraLinha, ","));
                         if(codigoProduto == comparaCodigo)
                         {
                              encontrouProduto = true;
                              vestuario.codigo = codigoProduto;
                              strcpy(vestuario.descricao, strtok(NULL, ","));
                              strcpy(vestuario.tamanho, strtok(NULL, ","));
                              vestuario.preco = atof(strtok(NULL, ","));
                              vestuario.estoque = atoi(strtok(NULL, ","));
                              strcpy(vestuario.cor, strtok(NULL, ","));
                              strcpy(vestuario.genero, strtok(NULL, "\n"));
                              textcolor(LIGHTGREEN);printf("\nProduto a ser adicionado: \n");
                              textcolor(WHITE);
                              printf("%s    Tamanho: %s    Preco: %.2f" , vestuario.descricao, vestuario.tamanho, vestuario.preco);
                              printf("\nEstoque: %d    Cor: %s    Genero: %s", vestuario.estoque, vestuario.cor, vestuario.genero);
                              printf("\n==========================================================================");
                              fflush(stdin);getch();
                         }
                     }
                     fclose(arq);

//-------------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------SALVA PRODUTOS NO CARRINHO/VE SE TEM ESPAÇO----------------------------------------------
                     //confere se achou nos vestuarios
                     if(encontrouProduto)
                     {
                              if(quantidadeProduto <= vestuario.estoque)
                              {
                                        carrinhoCheio = false;
                                        itoa(cadastro, cadastroEmChar, 10); //converte o codigo para char
                                        arq = fopen(cadastroEmChar, "rb");
                                        if(!arq)
                                        {
                                               arq = fopen(cadastroEmChar, "wb");
                                        }
                                        if(fread(&carrinho, sizeof(CARRINHO), 1, arq) == 1)
                                        {
                                                  if(carrinho.itensVestuario+quantidadeProduto <= MAX_CARRRINHO)
                                                  {
                                                       for(i = carrinho.itensVestuario; i < (carrinho.itensVestuario+quantidadeProduto); i++)
                                                       {
                                                            carrinho.vestuario[i] = vestuario;//insere produto no carrinho
                                                       }
                                                       carrinho.itensVestuario += quantidadeProduto;
                                                  }
                                                  else
                                                  {
                                                      textcolor(LIGHTRED);printf("\nSeu carrinho de vestuario ja esta cheio.");
                                                      textcolor(WHITE);fflush(stdin);getch();
                                                      carrinhoCheio = 1;
                                                  }
                                        }
                                        else
                                        {
                                            carrinho.itensVestuario = 0;
                                            if(carrinho.itensVestuario+quantidadeProduto <= MAX_CARRRINHO)
                                            {
                                                   for(i = carrinho.itensVestuario; i < (carrinho.itensVestuario+quantidadeProduto); i++)
                                                   {
                                                        carrinho.vestuario[i] = vestuario;
                                                   }
                                                   carrinho.itensVestuario += quantidadeProduto;
                                            }
                                            else
                                            {
                                                textcolor(LIGHTRED);printf("\nSeu carrinho de vestuario ja esta cheio.");
                                                textcolor(WHITE);fflush(stdin);getch();
                                                carrinhoCheio = 1;
                                            }
                                        }
                                        fclose(arq);
                                        if(!carrinhoCheio)  //ha espaco no carrinho
                                        {
                                            arq = fopen(cadastroEmChar, "wb");
                                            if(!arq)
                                            {
                                                    textcolor(LIGHTRED);
                                                    printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                                    getch();
                                                    exit(1);
                                            }
                                            if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq) == 1)
                                            {
                                                 textcolor(YELLOW);printf("\nOs itens foram adicionados ao carrinho com sucesso.");
                                                 fflush(stdin);getch();textcolor(WHITE);
                                            }
                                            else
                                            {
                                                 textcolor(LIGHTRED);printf("\nHouve um problema ao adicionar os itens ao carrinho.");
                                                 fflush(stdin);getch();textcolor(WHITE);
                                            }
                                            fclose(arq);
//------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------ATUALIZA O ESTOQUE---------------------------------------------------------
                                            //edita o estoque
                                            arq = fopen("vestuario.txt", "r+");
                                            if(!arq)
                                            {
                                                    textcolor(LIGHTRED);
                                                    printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                                    getch();
                                                    exit(1);
                                            }
                                            contaLinha = 0;
                                            while(!feof(arq))
                                            {
                                                fgets(salvaLinha[contaLinha], sizeof(salvaLinha[contaLinha]), arq);
                                                contaLinha++;
                                            }
                                            fclose(arq);
                                            remove("vestuario.txt");

                                            arq = fopen("vestuario.txt", "w");
                                            if(!arq)
                                            {
                                                    textcolor(LIGHTRED);
                                                    printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                                    getch();
                                                    exit(1);
                                            }
                                            vestuario.estoque = vestuario.estoque-quantidadeProduto;
                                            for(i = 0; i < contaLinha; i++)
                                            {
                                                strcpy(leituraLinha, salvaLinha[i]);
                                                comparaCodigo = atoi(strtok(leituraLinha, ","));
                                                if(comparaCodigo != codigoProduto)
                                                {
                                                   fputs(salvaLinha[i], arq);
                                                }
                                                else
                                                {
                                                    fseek(arq, 0*sizeof(char), SEEK_END);
                                                    fprintf(arq,"%d%c%s%c%s%c%.2f%c%d%c%s%c%s%c", vestuario.codigo, ',', vestuario.descricao, ',', vestuario.tamanho, ',', vestuario.preco, ',', vestuario.estoque, ',', vestuario.cor, ',', vestuario.genero, '\n');
                                                }
                                            }
                                            fclose(arq);
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
                                    }
                              }
                              else
                              {
                                  textcolor(LIGHTRED);
                                  printf("\nDesculpe. Nao ha itens em estoque suficientes para efetuar a compra.");
                                  textcolor(WHITE);fflush(stdin);getch();
                              }
                     }
             }
             if(!encontrouProduto)
             {
                 textcolor(LIGHTRED);printf("Codigo buscado nao encontrado, por favor digite um codigo valido.");
             }
     }while(!encontrouProduto);
}

//funcao usadas pela funcao pesquisa
void imprime_vest(VESTUARIO produtoVest)
{
    textcolor(WHITE);
    printf("\nCodigo: %d  Descricao: %s\n",produtoVest.codigo, produtoVest.descricao);
    printf("Tamanho: %s  Preco: %.2f  Estoque:  %d\n",produtoVest.tamanho, produtoVest.preco, produtoVest.estoque);
    printf("Cor: %s  Genero: %s\n",produtoVest.cor, produtoVest.genero);
    printf("\n================================================================");
}
//funcao usadas pela funcao pesquisa
void imprime_eletro(ELETRO produtoEletro)
{
     textcolor(WHITE);
     printf("\nCodigo: %d  Descricao: %s\n",produtoEletro.codigo, produtoEletro.descricao);
     printf("Altura: %d cm  Largura: %d cm  Profundidade:  %d cm\n",produtoEletro.altura, produtoEletro.largura, produtoEletro.profundidade);
     printf("Preco: %.2f Reais  Produtos em estoque: %d  Cor: %s\n",produtoEletro.preco, produtoEletro.estoque, produtoEletro.cor);
     printf("\n================================================================");
}

void pesquisar()
{
    FILE *arq;
    char letraEntradaUser;
    char leituraLinha[MAX_LINHA];
    ELETRO produtoEletro;
    VESTUARIO produtoVestuario;
    char *atributosProd;
    char leituraCor[TAM_NOME_MAX], leituraDescricao[TAM_NOME_MAX], leituraTamanho[TAM_NOME_MAX], leituraGenero[TAM_NOME_MAX];
    int codProdEncontrados[TAM_NOME_MAX];
    int i = 0;
    float precoMin;
    float precoMax;
    int totalEncontrados = 0;
    bool validaOpcao, maisUmaPesquisa;
    do
    {
            system("cls");
            textcolor(YELLOW);
            printf("\nPESQUISA:");
            textcolor(WHITE);
            printf("\n=================================================================");
            printf("\nO que voce deseja pesquisar?");
            textcolor(LIGHTGREEN);
            printf("\nE");textcolor(WHITE);printf("letronico           ");textcolor(LIGHTGREEN);printf("V");textcolor(WHITE);printf("estuario\n");
            validaOpcao = false;
            totalEncontrados = 0;
            do
            {
                textcolor(LIGHTGREEN);
                fflush(stdin);
                scanf("%c",&letraEntradaUser);
                letraEntradaUser = toupper(letraEntradaUser);
                if((letraEntradaUser == 'E') || (letraEntradaUser == 'V'))
                   validaOpcao = true;
                else
                {
                    textcolor(LIGHTRED);
                    printf("Opcao invalida. Por favor digite uma opcao valida: ");
                }
            }while(!validaOpcao);
            textcolor(WHITE);
            switch(letraEntradaUser)
            {
                case 'E':
                     arq = fopen("eletro.txt","r");
                     if(!arq)
                     {
                         textcolor(LIGHTRED);
                         puts("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                         getch();
                         exit(1);
                     }
                     printf("\n=================================================================");
                     printf("\nComo voce deseja pesquisar o produto?");
                     textcolor(LIGHTGREEN);printf("\nD");textcolor(WHITE);printf("escricao    ");textcolor(LIGHTGREEN);printf("C");textcolor(WHITE);printf("or");textcolor(LIGHTGREEN);printf("    P");textcolor(WHITE);printf("reco\n");
                     validaOpcao = false;
                     do
                     {
                        textcolor(LIGHTGREEN);
                        fflush(stdin);
                        scanf("%c",&letraEntradaUser);
                        letraEntradaUser = toupper(letraEntradaUser);
                        if((letraEntradaUser == 'D') || (letraEntradaUser == 'C') || (letraEntradaUser == 'P'))
                            validaOpcao = true;
                        else
                        {
                            textcolor(LIGHTRED);
                            printf("Opcao invalida. Por favor digite uma opcao valida: ");
                        }
                     }while(!validaOpcao);
                     textcolor(WHITE);
                     switch(letraEntradaUser)
                     {
                         case 'D':
                             printf("Informe a descricao buscada: ");
                             fflush(stdin);
                             textcolor(LIGHTGREEN);
                             gets(leituraDescricao);
                             strcpy(leituraDescricao,strlwr(leituraDescricao));
                             break;
                         case 'C':
                             printf("Informe a cor buscada: ");
                             fflush(stdin);
                             textcolor(LIGHTGREEN);
                             gets(leituraCor);
                             strcpy(leituraCor,strlwr(leituraCor));
                             break;
                         case 'P':
                             printf("Informe o preco minimo buscado: ");
                             textcolor(LIGHTGREEN);
                             scanf("%f",&precoMin);
                             textcolor(WHITE);
                             printf("Informe o preco maximo buscado: ");
                             textcolor(LIGHTGREEN);
                             scanf("%f",&precoMax);
                             break;
                     }
                     textcolor(WHITE);
                     while(!feof(arq))
                     {
                         atributosProd = fgets(leituraLinha,MAX_LINHA,arq);
                         if (atributosProd)
                         {

                             produtoEletro.codigo = atoi(strtok(leituraLinha,","));
                             strcpy(produtoEletro.descricao,(strtok(NULL,",")));
                             produtoEletro.altura = atoi(strtok(NULL,","));
                             produtoEletro.largura = atoi(strtok(NULL,","));
                             produtoEletro.profundidade = atoi(strtok(NULL,","));
                             produtoEletro.preco = atof(strtok(NULL,","));
                             produtoEletro.estoque = atoi(strtok(NULL,","));
                             strcpy(produtoEletro.cor,strtok(NULL,"\n"));

                             if(letraEntradaUser == 'D' && (strcmp(leituraDescricao,produtoEletro.descricao) == 0))
                             {
                                 imprime_eletro(produtoEletro);
                                 codProdEncontrados[i] = produtoEletro.codigo;
                                 i++;
                                 totalEncontrados++;
                             }
                             else
                                 if(letraEntradaUser == 'C' && (strcmp(leituraCor,produtoEletro.cor) == 0))
                                 {
                                     imprime_eletro(produtoEletro);
                                     codProdEncontrados[i] = produtoEletro.codigo;
                                     i++;
                                     totalEncontrados++;
                                 }
                                 else
                                     if(letraEntradaUser == 'P' && produtoEletro.preco <= precoMax && produtoEletro.preco >= precoMin)
                                     {
                                         imprime_eletro(produtoEletro);
                                         codProdEncontrados[i] = produtoEletro.codigo;
                                         i++;
                                         totalEncontrados++;
                                     }
                             }

                     }
                     if(totalEncontrados == 0)
                     {
                         textcolor(LIGHTRED);
                         printf("\nNenhum produto encontrado.");
                         fflush(stdin);getchar();
                         textcolor(WHITE);
                     }
                     else
                     {
                         printf("\nForam encontrados ");
                         textcolor(LIGHTGREEN);
                         printf("%d", totalEncontrados);
                         textcolor(WHITE);
                         printf(" produtos.");
                         fflush(stdin);getchar();
                     }fclose(arq);break;

                     case 'V':
                     arq = fopen("vestuario.txt","r");
                     if(arq == NULL)
                     {
                         textcolor(LIGHTRED);
                         printf("Houve um erro ao abrir o arquivo. O programa sera terminado.");
                         fflush(stdin);getch();
                         exit(1);
                     }
                     else
                         printf("\n=================================================================");
                         printf("\nComo voce deseja pesquisar o produto?");
                         textcolor(LIGHTGREEN);printf("\nD");textcolor(WHITE);printf("escricao    ");textcolor(LIGHTGREEN);printf("C");textcolor(WHITE);printf("or");textcolor(LIGHTGREEN);printf("    P");textcolor(WHITE);printf("reco");textcolor(LIGHTGREEN);
                         printf("\nG");textcolor(WHITE);printf("enero");textcolor(WHITE);textcolor(LIGHTGREEN);printf("       T");textcolor(WHITE);printf("amanho\n");
                         validaOpcao = false;
                         do
                         {
                             textcolor(LIGHTGREEN);fflush(stdin);scanf("%c",&letraEntradaUser);letraEntradaUser = toupper(letraEntradaUser);
                             if((letraEntradaUser == 'D') || (letraEntradaUser == 'C') || (letraEntradaUser == 'P') || (letraEntradaUser == 'T') || (letraEntradaUser == 'G'))
                                 validaOpcao = true;
                             else
                             {
                                  textcolor(LIGHTRED);
                                  printf("Opcao invalida. Por favor digite uma opcao valida: ");
                             }
                         }while(!validaOpcao);
                         textcolor(WHITE);
                         switch(letraEntradaUser)
                         {
                             case 'D':
                                  printf("Informe a descricao buscada: ");
                                  textcolor(LIGHTGREEN);fflush(stdin);gets(leituraDescricao);
                                  strcpy(leituraDescricao,strlwr(leituraDescricao));
                                  break;
                             case 'T':
                                  printf("Escolha o tamanho:\n(");
                                  textcolor(LIGHTGREEN);printf("PP");textcolor(WHITE);printf(" / ");textcolor(LIGHTGREEN);printf("P");
                                  textcolor(WHITE);printf(" / ");textcolor(LIGHTGREEN);printf("M");
                                  textcolor(WHITE);printf(" / ");textcolor(LIGHTGREEN);printf("G");
                                  textcolor(WHITE);printf(" / ");textcolor(LIGHTGREEN);printf("XG");
                                  textcolor(WHITE);printf(")\n");
                                  validaOpcao = false;
                                  do
                                  {
                                      textcolor(LIGHTGREEN);fflush(stdin);gets(leituraTamanho);
                                      strcpy(leituraTamanho,strupr(leituraTamanho));
                                      if((strcmp(leituraTamanho,"PP") == 0) || (strcmp(leituraTamanho,"P") == 0) || (strcmp(leituraTamanho,"M") == 0) ||
                                         (strcmp(leituraTamanho,"G") == 0) || (strcmp(leituraTamanho,"XG") == 0))
                                          validaOpcao = true;
                                      else
                                      {
                                           textcolor(LIGHTRED);
                                           printf("Opcao invalida. Por favor digite uma opcao valida: ");
                                      }
                                  }while(!validaOpcao);
                                  break;
                             case 'P':
                                   printf("Informe o preco minimo buscado: ");
                                   textcolor(LIGHTGREEN);scanf("%f",&precoMin);
                                   textcolor(WHITE);printf("Informe o preco maximo buscado.\n");
                                   textcolor(LIGHTGREEN);scanf("%f",&precoMax);fflush(stdin);
                                   break;
                             case 'C':
                                  printf("Informe a cor buscada: ");
                                  textcolor(LIGHTGREEN);fflush(stdin);scanf("%s",leituraCor);
                                  strcpy(leituraCor,strlwr(leituraCor));
                                  break;
                             case 'G':
                                  printf("Informe o genero (");textcolor(LIGHTGREEN);printf("masculino");textcolor(WHITE);printf(", ");
                                  textcolor(LIGHTGREEN);printf("feminino");textcolor(WHITE);printf(" ou ");textcolor(LIGHTGREEN);printf("unissex");
                                  textcolor(WHITE);printf("): ");
                                  validaOpcao = true;
                                  do
                                  {
                                      textcolor(LIGHTGREEN);fflush(stdin);gets(leituraGenero);
                                      strupr(leituraGenero);
                                      if((strcmp(leituraGenero,"MASCULINO") == 0) || (strcmp(leituraGenero,"FEMININO") == 0) || (strcmp(leituraGenero,"UNISSEX") == 0))
                                          validaOpcao = true;
                                      else
                                      {
                                           textcolor(LIGHTRED);
                                           printf("Opcao invalida. Por favor digite uma opcao valida: ");
                                      }
                                  }while(!validaOpcao);
                                  strcpy(leituraGenero,strlwr(leituraGenero));
                                  break;
                         }
                         while(!feof(arq))
                         {
                             atributosProd = fgets(leituraLinha,MAX_LINHA,arq);
                             if (atributosProd)
                             {
                                  produtoVestuario.codigo = atoi(strtok(leituraLinha,","));
                                  strcpy(produtoVestuario.descricao,(strtok(NULL,",")));
                                  strcpy(produtoVestuario.tamanho,(strtok(NULL,",")));
                                  produtoVestuario.preco = atof(strtok(NULL,","));
                                  produtoVestuario.estoque = atoi(strtok(NULL,","));
                                  strcpy(produtoVestuario.cor,(strtok(NULL,",")));
                                  strcpy(produtoVestuario.genero,(strtok(NULL,"\n")));

                                  if(strcmp(leituraDescricao,produtoVestuario.descricao) == 0 || strcmp(leituraTamanho,produtoVestuario.tamanho) == 0 ||
                                  strcmp(leituraCor,produtoVestuario.cor) == 0 || strcmp(leituraGenero,produtoVestuario.genero) == 0)
                                  {
                                     imprime_vest(produtoVestuario);
                                     codProdEncontrados[i] = produtoVestuario.codigo;
                                     i++;
                                     totalEncontrados++;
                                  }
                                  else
                                  if(letraEntradaUser == 'P' && produtoVestuario.preco <= precoMax && produtoVestuario.preco >= precoMin)
                                  {
                                     imprime_vest(produtoVestuario);
                                     codProdEncontrados[i] = produtoVestuario.codigo;
                                     i++;
                                     totalEncontrados++;
                                  }

                             }
                         }
                         if(totalEncontrados == 0)
                         {
                             textcolor(LIGHTRED);
                             printf("\nNenhum produto encontrado.");
                             fflush(stdin);getchar();
                         }
                         else
                         {
                                textcolor(WHITE);
                                printf("\nForam encontrados ");
                                textcolor(LIGHTGREEN);
                                printf("%d", totalEncontrados);
                                textcolor(WHITE);
                                printf(" produtos.");
                                fflush(stdin);getchar();
                         }
                         break;
            }
            textcolor(WHITE);printf("\nVoce deseja realizar mais uma pesquisa? (");
            textcolor(LIGHTGREEN);printf("S");textcolor(WHITE);printf(" ou ");textcolor(LIGHTGREEN);printf("N");textcolor(WHITE);printf(">");
            validaOpcao = false;
            do
            {
                textcolor(LIGHTGREEN);fflush(stdin);scanf("%c", &letraEntradaUser);
                letraEntradaUser = toupper(letraEntradaUser);
                if(letraEntradaUser == 'S')
                {
                     maisUmaPesquisa = true;
                     validaOpcao = true;
                }
                if(letraEntradaUser == 'N')
                {
                     maisUmaPesquisa = false;
                     validaOpcao = true;
                }
                if(!validaOpcao)
                {
                     textcolor(LIGHTRED);
                     printf("Opcao invalida. Por favor digite uma opcao valida: ");
                }
            }while(!validaOpcao);
    }while(maisUmaPesquisa);
}

//mostra todas as compras do carrinho
void vizualizacompras(int numCadastro)
{
     FILE *arq;
     CARRINHO compras;
     char cadastroChar[MAX_DIGITOS];
     int i;

     system("cls");
     itoa(numCadastro, cadastroChar, 10);
     textcolor(YELLOW);printf("\nSEU CARRINHO DE COMPRAS:");
     textcolor(WHITE);printf("\n=======================================================================");
     arq=fopen(cadastroChar, "rb");
     if(!arq)
     {
         printf("\nAinda nao ha itens no seu carrinho de compras.");
         fflush(stdin);getch();textcolor(WHITE);
     }
     else
     {
             if(fread(&compras, sizeof(CARRINHO), 1, arq) == 1)
             {
                 printf("\nVoce possui");textcolor(LIGHTGREEN);printf(" %d ", compras.itensEletro);textcolor(WHITE);
                 printf("eletrodomesticos e");textcolor(LIGHTGREEN);printf(" %d ", compras.itensVestuario);
                 textcolor(WHITE);printf("pecas de vestuario no seu carrinho.");
                 for(i = 0; i < compras.itensEletro; i++)
                 {
                     printf("\n===========================================================");
                     printf("\nCodigo do produto: %d", compras.eletronico[i].codigo);
                     printf("\nDescricao: %s", compras.eletronico[i].descricao);
                     printf("\nAltura: %d cm", compras.eletronico[i].altura);
                     printf("\nLargura: %d cm", compras.eletronico[i].largura);
                     printf("\nProfundidade: %d cm", compras.eletronico[i].profundidade);
                     printf("\nPreco: %.2f reais", compras.eletronico[i].preco);
                     printf("\nCor: %s", compras.eletronico[i].cor);
                 }
                 for(i = 0; i < compras.itensVestuario; i++)
                 {
                     printf("\n===========================================================");
                     printf("\nCodigo do produto: %d", compras.vestuario[i].codigo);
                     printf("\nDescricao: %s", compras.vestuario[i].descricao);
                     printf("\nTamanho: %s", compras.vestuario[i].tamanho);
                     printf("\nPreco: %.2f reais", compras.vestuario[i].preco);
                     printf("\nCor: %s", compras.vestuario[i].cor);
                     printf("\nGenero: %s", compras.vestuario[i].genero);
                 }
             }
             fclose(arq);
             fflush(stdin);getch();
     }
}
//fim da funcao que mostra as compras

//funcao cancela a compra e repoe o estoqueitem a item
void cancelaTodasCompras(int numCadastro)
{
     FILE *arq, *arqtxt;
     char cadastroEmChar[MAX_DIGITOS], salvaLinha[MAX_PRODUTOS][MAX_LINHA], copiaLinha[MAX_LINHA];
     int i, j, k, contaLinha, comparaCodigo, codCompra;
     ELETRO eletronico;
     VESTUARIO vestuario;
     CARRINHO carrinho;

     system("cls");
     textcolor(YELLOW);printf("\nCANCELAR TODAS AS COMPRAS:");
     textcolor(WHITE);printf("\n=======================================================================");
     itoa(numCadastro, cadastroEmChar, 10);
     arq = fopen(cadastroEmChar, "rb");
     if(!arq)
     {
             printf("\nNao ha itens em seu carrinho para serem excluidos.");
             fflush(stdin);getch();textcolor(WHITE);
     }
     else
     {
         if(fread(&carrinho, sizeof(CARRINHO), 1, arq) == 1)
         {
             for(i = 0; i < carrinho.itensEletro; i++)
             {
                         arqtxt = fopen("eletro.txt", "r");
                         if(!arqtxt)
                         {
                             textcolor(LIGHTRED);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             textcolor(WHITE);
                             getch();
                             exit(1);
                         }
                         contaLinha = 0;
                         while(!feof(arqtxt))
                         {
                              fgets(salvaLinha[contaLinha], sizeof(salvaLinha[contaLinha]), arqtxt);
                              contaLinha++;
                         }
                         fclose(arqtxt);
                         remove("eletro.txt");

                         arqtxt = fopen("eletro.txt", "w");
                         if(!arqtxt)
                         {
                             textcolor(LIGHTRED);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             textcolor(WHITE);
                             getch();
                             exit(1);
                         }
                         for(j = 0; j < contaLinha; j++)
                         {
                                  strcpy(copiaLinha, salvaLinha[j]);
                                  codCompra = atoi(strtok(copiaLinha, ","));
                                  if(codCompra == carrinho.eletronico[i].codigo)
                                  {
                                        eletronico.codigo = atoi(strtok(salvaLinha[j], ","));;
                                        strcpy(eletronico.descricao, strtok(NULL, ","));
                                        eletronico.altura = atoi(strtok(NULL, ","));
                                        eletronico.largura = atoi(strtok(NULL, ","));
                                        eletronico.profundidade = atoi(strtok(NULL, ","));
                                        eletronico.preco = atof(strtok(NULL, ","));
                                        eletronico.estoque = atoi(strtok(NULL, ","))+1;
                                        strcpy(eletronico.cor, strtok(NULL, "\n"));
                                        fseek(arq, 0*sizeof(char), SEEK_END);
                                        fprintf(arqtxt,"%d%c%s%c%d%c%d%c%d%c%.2f%c%d%c%s%c", eletronico.codigo, ',', eletronico.descricao, ',', eletronico.altura, ',', eletronico.largura, ',', eletronico.profundidade, ',', eletronico.preco, ',', eletronico.estoque, ',', eletronico.cor, '\n');
                                  }
                                  else
                                      fputs(salvaLinha[j], arqtxt);
                         }
                         fclose(arqtxt);
             }
             //repoe o estoque dos vestuarios
             for(i = 0; i < carrinho.itensVestuario; i++)
             {
                         arqtxt = fopen("vestuario.txt", "r");
                         if(!arqtxt)
                         {
                             textcolor(LIGHTRED);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             textcolor(WHITE);
                             getch();
                             exit(1);
                         }
                         contaLinha = 0;
                         while(!feof(arqtxt))
                         {
                              fgets(salvaLinha[contaLinha], sizeof(salvaLinha[contaLinha]), arqtxt);
                              contaLinha++;
                         }
                         fclose(arqtxt);
                         remove("vestuario.txt");

                         arqtxt = fopen("vestuario.txt", "w");
                         if(!arqtxt)
                         {
                             textcolor(LIGHTRED);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             textcolor(WHITE);
                             getch();
                             exit(1);
                         }
                         for(j = 0; j < contaLinha; j++)
                         {
                                  strcpy(copiaLinha, salvaLinha[j]);
                                  codCompra = atoi(strtok(copiaLinha, ","));
                                  if(codCompra == carrinho.vestuario[i].codigo)
                                  {
                                        vestuario.codigo = atoi(strtok(salvaLinha[j], ","));;
                                        strcpy(vestuario.descricao, strtok(NULL, ","));
                                        strcpy(vestuario.tamanho, strtok(NULL, ","));
                                        vestuario.preco = atof(strtok(NULL, ","));
                                        vestuario.estoque = atoi(strtok(NULL, ","))+1;
                                        strcpy(vestuario.cor, strtok(NULL, ","));
                                        strcpy(vestuario.genero, strtok(NULL, "\n"));
                                        fseek(arq, 0*sizeof(char), SEEK_END);
                                        fprintf(arqtxt,"%d%c%s%c%s%c%.2f%c%d%c%s%c%s%c", vestuario.codigo, ',', vestuario.descricao, ',', vestuario.tamanho, ',', vestuario.preco, ',', vestuario.estoque, ',', vestuario.cor, ',', vestuario.genero, '\n');
                                  }
                                  else
                                      fputs(salvaLinha[j], arqtxt);
                         }
                         fclose(arqtxt);
             }
         }
         fclose(arq);
         remove(cadastroEmChar);
         textcolor(YELLOW);printf("\nSeu carrinho foi esvaziado!");textcolor(WHITE);fflush(stdin);getch();
     }
}
//fim da funcao de cancelamento de pedido

void excluiUmProduto(int numCadastro)
{

     FILE *arq, *arqtxt;
     int codigoExclui, i, j, contaLinha, codProduto;
     char cadastroEmChar[MAX_DIGITOS], salvaLinha[MAX_PRODUTOS][MAX_LINHA], copiaLinha[MAX_LINHA];
     char opcaoExcluir;
     bool achouProduto, opcaoValida, excluiMaisUmItem;
     ELETRO eletronico;
     VESTUARIO vestuario;
     CARRINHO carrinho;

     do
     {
             achouProduto = false;
             system("cls");
             textcolor(YELLOW);printf("\nEXCLUIR ITEM DO CARRINHO");
             textcolor(WHITE);printf("\n==================================================================");
             itoa(numCadastro, cadastroEmChar, 10);
             arq = fopen(cadastroEmChar, "rb");
             if(!arq)
             {
                     textcolor(WHITE);printf("\nNao ha itens em seu carrinho para serem excluidos.");
                     fflush(stdin);getch();textcolor(WHITE);
                     excluiMaisUmItem = false;
             }
             else
             {
                 printf("\nInforme o codigo do produto que voce quer excluir do seu carrinho: ");
                 textcolor(LIGHTGREEN);scanf("%d", &codigoExclui);textcolor(WHITE);
                 if(fread(&carrinho, sizeof(CARRINHO), 1, arq) == 1)
                 {
                       fclose(arq);
                       for(i = 0; i < carrinho.itensEletro; i++)
                       {
                                if(codigoExclui == carrinho.eletronico[i].codigo && achouProduto == false)
                                {
                                    arq = fopen(cadastroEmChar, "wb");
                                    if(!arq)
                                    {
                                            textcolor(LIGHTRED);printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            fflush(stdin);getch();exit(1);
                                    }
                                    achouProduto = true;
                                    carrinho.eletronico[i] = carrinho.eletronico[carrinho.itensEletro-1];
                                    carrinho.itensEletro = carrinho.itensEletro-1;
                                    if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq) == 1)
                                    {
                                        textcolor(YELLOW);printf("Uma unidade do produto de codigo");
                                        textcolor(LIGHTGREEN);printf(" %d ", codigoExclui);
                                        textcolor(YELLOW);printf("foi excluido de seu carrinho.");
                                        fflush(stdin);getch();
                                    }
                                    fclose(arq);
                                    if(carrinho.itensEletro == 0 && carrinho.itensVestuario == 0)
                                        remove(cadastroEmChar);
                                    //repoe o estoque dos eletrodomesticos
                                    arqtxt = fopen("eletro.txt", "r");
                                     if(!arqtxt)
                                     {
                                             textcolor(LIGHTRED);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                     }
                                     contaLinha = 0;
                                     while(!feof(arqtxt))
                                     {
                                          fgets(salvaLinha[contaLinha], sizeof(salvaLinha[contaLinha]), arqtxt);
                                          contaLinha++;
                                     }
                                     fclose(arqtxt);
                                     remove("eletro.txt");

                                     arqtxt = fopen("eletro.txt", "w");
                                     if(!arqtxt)
                                     {
                                             textcolor(LIGHTRED);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                     }
                                     for(j = 0; j < contaLinha; j++)
                                     {
                                              strcpy(copiaLinha, salvaLinha[j]);
                                              codProduto = atoi(strtok(copiaLinha, ","));
                                              if(codProduto == codigoExclui)
                                              {
                                                    eletronico.codigo = atoi(strtok(salvaLinha[j], ","));;
                                                    strcpy(eletronico.descricao, strtok(NULL, ","));
                                                    eletronico.altura = atoi(strtok(NULL, ","));
                                                    eletronico.largura = atoi(strtok(NULL, ","));
                                                    eletronico.profundidade = atoi(strtok(NULL, ","));
                                                    eletronico.preco = atof(strtok(NULL, ","));
                                                    eletronico.estoque = atoi(strtok(NULL, ","))+1;
                                                    strcpy(eletronico.cor, strtok(NULL, "\n"));
                                                    fseek(arq, 0*sizeof(char), SEEK_END);
                                                    fprintf(arqtxt,"%d%c%s%c%d%c%d%c%d%c%.2f%c%d%c%s%c", eletronico.codigo, ',', eletronico.descricao, ',', eletronico.altura, ',', eletronico.largura, ',', eletronico.profundidade, ',', eletronico.preco, ',', eletronico.estoque, ',', eletronico.cor, '\n');
                                              }
                                              else
                                                  fputs(salvaLinha[j], arqtxt);
                                     }
                                     fclose(arqtxt);
                                }
                       }
                       if(achouProduto == false)
                       {
                             for(i = 0; i < carrinho.itensVestuario; i++)
                             {
                                    if(codigoExclui == carrinho.vestuario[i].codigo && achouProduto == false)
                                    {
                                        arq = fopen(cadastroEmChar, "wb");
                                        if(!arq)
                                        {
                                            textcolor(LIGHTRED);printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            fflush(stdin);getch();exit(1);
                                        }
                                        achouProduto = true;
                                        carrinho.vestuario[i] = carrinho.vestuario[carrinho.itensVestuario-1];
                                        carrinho.itensVestuario = carrinho.itensVestuario-1;
                                        if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq) == 1)
                                        {
                                            textcolor(YELLOW);printf("Uma unidade do produto de codigo");
                                            textcolor(LIGHTGREEN);printf(" %d ", codigoExclui);
                                            textcolor(YELLOW);printf("foi excluido de seu carrinho.");
                                            fflush(stdin);getch();
                                        }
                                        fclose(arq);

                                        if(carrinho.itensEletro == 0 && carrinho.itensVestuario == 0)
                                             remove(cadastroEmChar);
                                        //repoe o estoque
                                         arqtxt = fopen("vestuario.txt", "r");
                                         if(!arqtxt)
                                         {
                                             textcolor(LIGHTRED);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                         }
                                         contaLinha = 0;
                                         while(!feof(arqtxt))
                                         {
                                              fgets(salvaLinha[contaLinha], sizeof(salvaLinha[contaLinha]), arqtxt);
                                              contaLinha++;
                                         }
                                         fclose(arqtxt);
                                         remove("vestuario.txt");

                                         arqtxt = fopen("vestuario.txt", "w");
                                         if(!arqtxt)
                                         {
                                             textcolor(LIGHTRED);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                         }
                                         for(j = 0; j < contaLinha; j++)
                                         {
                                                  strcpy(copiaLinha, salvaLinha[j]);
                                                  codProduto = atoi(strtok(copiaLinha, ","));
                                                  if(codigoExclui == codProduto)
                                                  {
                                                        vestuario.codigo = atoi(strtok(salvaLinha[j], ","));;
                                                        strcpy(vestuario.descricao, strtok(NULL, ","));
                                                        strcpy(vestuario.tamanho, strtok(NULL, ","));
                                                        vestuario.preco = atof(strtok(NULL, ","));
                                                        vestuario.estoque = atoi(strtok(NULL, ","))+1;
                                                        strcpy(vestuario.cor, strtok(NULL, ","));
                                                        strcpy(vestuario.genero, strtok(NULL, "\n"));
                                                        fseek(arq, 0*sizeof(char), SEEK_END);
                                                        fprintf(arqtxt,"%d%c%s%c%s%c%.2f%c%d%c%s%c%s%c", vestuario.codigo, ',', vestuario.descricao, ',', vestuario.tamanho, ',', vestuario.preco, ',', vestuario.estoque, ',', vestuario.cor, ',', vestuario.genero, '\n');
                                                  }
                                                  else
                                                      fputs(salvaLinha[j], arqtxt);
                                         }
                                         fclose(arqtxt);
                                    }
                             }
                       }
                       if(achouProduto == false)
                       {
                           textcolor(LIGHTRED);printf("Nao foi encontrado nenhum item com esse codigo em seu carrinho.");
                       }
                 }
                 else
                 {
                     textcolor(LIGHTRED);printf("Houve um problema ao abrir seu carrinho.");
                     fflush(stdin);getch();
                     fclose(arq);
                 }
                    textcolor(WHITE);printf("\nVoce deseja excluir mais um item do seu carrinho? (");
                    textcolor(LIGHTGREEN);printf("S");textcolor(WHITE);printf(" ou ");textcolor(LIGHTGREEN);printf("N");textcolor(WHITE);printf(">");
                    opcaoValida = false;
                    do
                    {
                        textcolor(LIGHTGREEN);fflush(stdin);scanf("%c", &opcaoExcluir);
                        opcaoExcluir = toupper(opcaoExcluir);
                        if(opcaoExcluir == 'S')
                        {
                             excluiMaisUmItem = true;
                             opcaoValida = true;
                        }
                        if(opcaoExcluir == 'N')
                        {
                             excluiMaisUmItem = false;
                             opcaoValida = true;
                        }
                        if(opcaoValida == false)
                        {
                             textcolor(LIGHTRED);
                             printf("Opcao invalida. Por favor digite uma opcao valida: ");
                        }
                    }while(opcaoValida == false);
             }
     }while(excluiMaisUmItem);
}

void fechaCompra(int cadastro)
{
     FILE *arq, *arqtxt;
     CARRINHO carrinho;
     int i;
     float valorDaCompra;
     char copiaData[MAX_LINHA], dia[MAX_DIGITOS], mes[MAX_DIGITOS], ano[MAX_DIGITOS];
     char cadastroEmChar[MAX_DIGITOS];

     system("cls");
     itoa(cadastro, cadastroEmChar, 10);
     textcolor(YELLOW);printf("\nFECHAR COMPRA");
     textcolor(WHITE);printf("\n==============================================================");
     strcpy(copiaData, __DATE__);
     strcpy(mes, strupr(strtok(copiaData, " ")));
     strcpy(dia, strtok(NULL, " "));
     strcpy(ano, strtok(NULL, "\n"));
     arq = fopen(cadastroEmChar, "rb");
     if(!arq)
     {
             textcolor(WHITE);printf("\nSeu carrinho ainda nao possui nenhum item para poder fechar a compra");
             fflush(stdin);getch();
     }
     else
     {
         if(fread(&carrinho, sizeof(CARRINHO), 1, arq) == 1)
         {
                    valorDaCompra = 0;
                    for(i = 0; i < carrinho.itensEletro; i++)
                    {
                             valorDaCompra += carrinho.eletronico[i].preco;
                    }
                    for(i = 0; i < carrinho.itensVestuario; i++)
                    {
                             valorDaCompra += carrinho.vestuario[i].preco;
                    }
                    arqtxt = fopen("report.txt", "a");
                    if(!arqtxt)
                    {
                          textcolor(LIGHTRED);printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                          fflush(stdin);getch();exit(1);
                    }
                    fprintf(arqtxt, "%c%s%c%s%c%s%c", '\n', dia, ',', mes, ',', ano, ',');
                    fprintf(arqtxt, "%d%c%d%c%.2f", carrinho.itensEletro, ',', carrinho.itensVestuario, ',', valorDaCompra);
                    fclose(arqtxt);
                    printf("\nData da compra: ");textcolor(LIGHTGREEN);printf("%s", dia);
                    textcolor(WHITE);printf("/");textcolor(LIGHTGREEN);printf("%s", mes);
                    textcolor(WHITE);printf("/");textcolor(LIGHTGREEN);printf("%s", ano);
                    textcolor(WHITE);printf("\nValor total da compra: ");textcolor(LIGHTGREEN);printf("%.2f.", valorDaCompra);
                    textcolor(WHITE);
                    if(carrinho.itensEletro != 0)
                    {
                           printf("\nEletrodomesticos comprados: ");textcolor(LIGHTGREEN);printf("%d", carrinho.itensEletro);
                    }
                    else
                          printf("\nNenhum eletrodomestico comprado.");
                    textcolor(WHITE);
                    if(carrinho.itensVestuario != 0)
                    {
                           printf("\nPecas de vestuario compradas: ");textcolor(LIGHTGREEN);printf("%d.", carrinho.itensVestuario);
                    }
                    else
                          printf("\nNenhuma peca de vestuario comprada.");
                    textcolor(YELLOW);printf("\nSua compra foi finalizada! \nVoce estara recebendo sua encomenda");
                    printf(" dentro de");textcolor(LIGHTGREEN);printf(" %d ", DIAS_UTEIS);textcolor(YELLOW);printf("dias uteis.");
                    fflush(stdin);getch();
         }
         else
         {
                     textcolor(LIGHTRED);
                     printf("\nHouve um erro ao abrir o seu carrinho.");
                     fflush(stdin);getch();
         }
         fclose(arq);
         remove(cadastroEmChar);
     }
}

int contaComprasSuspensas()
{
     FILE *arq;
     int usersCadastrados, i, totalCarrinhosAbertos, carrinhosAbertos[MAX_USUARIOS];
     char cadastroEmChar[MAX_DIGITOS], leituraLinha[MAX_LINHA];

     arq = fopen("usuarios.txt", "r");
     if(!arq)
     {
             textcolor(LIGHTRED);printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
             fflush(stdin);getch();exit(1);
     }
     usersCadastrados = 0;
     while(!feof(arq))
     {
        fgets(leituraLinha, MAX_LINHA, arq);
        if(leituraLinha[0] != '\n')
           usersCadastrados++;
     }
     fclose(arq);
     //usersCadastrados verifica quantos usuarios ha cadastrados
     totalCarrinhosAbertos = 0;
     for(i = 1; i <= usersCadastrados; i++)
     {
              itoa(i, cadastroEmChar, 10);
              arq = fopen(cadastroEmChar, "rb");
              if(arq)
              {
                     carrinhosAbertos[totalCarrinhosAbertos] = i;
                     totalCarrinhosAbertos++;
                     fclose(arq);
              }
     }
     return(totalCarrinhosAbertos);
}

void menuCLIENTE(char nomeCliente[], int cadastroProd)
{
    FILE *arq;
    char leituraMenu, cadastroChar[MAX_DIGITOS];
    int opcaoValida = 0, comprasSuspensas;
    do
    {
            system("cls");
            textcolor(YELLOW);
            printf("\nCLIENTE: ");
            textcolor(LIGHTGREEN);
            printf("%s", nomeCliente);
            textcolor(WHITE);
            printf("\nData: %s Hora: %s",__DATE__,__TIME__);
            printf("\n=====================================================================");
            printf("\nSelecione a letra correspondente em verde para acessar a opcao.\n");
            textcolor(LIGHTGREEN);
            printf("\nT");textcolor(WHITE);printf("rocar Usuario (Suspende as compras que estiverem abertas e faz logout)");
            textcolor(LIGHTGREEN);printf("\nS");textcolor(WHITE);printf("air (Cancela suas compras e faz logout)");
            printf("\nC");textcolor(LIGHTGREEN);printf("o");textcolor(WHITE);printf("ncluir (Fecha as suas compras e faz logout)");
            textcolor(LIGHTGREEN);printf("\n\nP");textcolor(WHITE);printf("esquisar");
            textcolor(LIGHTGREEN);printf("                 I");textcolor(WHITE);printf("nserir");
            textcolor(LIGHTGREEN);printf("\nE");textcolor(WHITE);printf("xcluir um item");
            textcolor(LIGHTGREEN);printf("           V");textcolor(WHITE);printf("isualizar");
            textcolor(LIGHTGREEN);printf("\nF");textcolor(WHITE);printf("echar as compras");
            textcolor(LIGHTGREEN);printf("         C");textcolor(WHITE);printf("ancelar as compras");
            printf("\n==================================================================\n");
            do
            {
                textcolor(LIGHTGREEN);fflush(stdin);scanf("%c", &leituraMenu);
                leituraMenu = toupper(leituraMenu);
                textcolor(WHITE);
                switch(leituraMenu)
                {
                    case 'T':
                    {
                         itoa(cadastroProd, cadastroChar, 10);
                         arq = fopen(cadastroChar, "rb");
                         if(arq)                        //checa se o usuario tem compras para suspender
                         {
                             comprasSuspensas = contaComprasSuspensas();
                             if(comprasSuspensas < MAX_COMPRAS_SUSP)
                             {
                                   printf("\nSuas compras ficarao suspensas. Voce podera finaliza-las mais tarde.");
                                   fflush(stdin);getch();
                                   opcaoValida = 10;
                             }
                             else
                             {
                                 textcolor(LIGHTRED);printf("\nO numero maximo de compras suspensas simultaneas");
                                 printf("\nfoi atingido. Voce tera que fechar suas compras ou cancela-las.");
                                 textcolor(WHITE);
                                 opcaoValida = 1;
                             }
                             fclose(arq);
                         }
                         else
                             opcaoValida = 10;
                         break;
                    }
                    case 'S':
                    {
                         printf("\nSuas compras serao canceladas antes de voce fazer logout.");
                         fflush(stdin);getch();
                         cancelaTodasCompras(cadastroProd);
                         opcaoValida = 10;
                         break;
                    }
                    case 'O':
                    {
                         printf("\nSuas compras serao finalizadas antes de voce fazer logout.");
                         fflush(stdin);getch();
                         fechaCompra(cadastroProd);
                         opcaoValida = 10;
                         break;
                    }
                    case 'P':
                    {
                         pesquisar();
                         opcaoValida = 1;
                         break;
                    }
                    case 'I':
                    {
                         inserirProdutoCarrinho(cadastroProd);
                         opcaoValida = 1;
                         break;
                    }
                    case 'E':
                    {
                         excluiUmProduto(cadastroProd);
                         opcaoValida = 1;
                         break;
                    }
                    case 'V':
                    {
                         vizualizacompras(cadastroProd);
                         opcaoValida = 1;
                         break;
                    }
                    case 'F':
                    {
                         fechaCompra(cadastroProd);
                         opcaoValida = 1;
                         break;
                    }
                    case 'C':
                    {
                         cancelaTodasCompras(cadastroProd);
                         opcaoValida = 1;
                         break;
                    }
                    default:
                    {
                       textcolor(LIGHTRED);
                       printf("Opcao invalida. Por favor digite uma opcao valida: ");
                       opcaoValida = 0;
                    }
                }
             }while(opcaoValida == 0);
    }while(opcaoValida != 10);
}

//funções de relatorios de gerentes

void relatorioComprasEmAndamento()
{
     FILE *arq;
     int totalUsuarios, i, totalCarrinhosAbertos, carrinhosAbertos[MAX_USUARIOS], codigoProd;
     char cadastroChar[MAX_DIGITOS], leituraLinha[MAX_LINHA];

     system("cls");
     textcolor(YELLOW);printf("\nUSUARIOS COM CARRINHOS ABERTOS:");
     textcolor(WHITE);printf("\n===============================================================");
     arq=fopen("usuarios.txt", "r");
     if(!arq)
     {
             textcolor(LIGHTRED);printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
             fflush(stdin);getch();exit(1);
     }
     totalUsuarios = 0;
     while(!feof(arq))
     {
        fgets(leituraLinha, MAX_LINHA, arq);
        if(leituraLinha[0] != '\n')
           totalUsuarios++;
     }
     fclose(arq);
     //totalUsuarios verifica o total de usuários cadastrados.
     totalCarrinhosAbertos = 0;
     for(i = 1; i <= totalUsuarios; i++)
     {
              itoa(i, cadastroChar, 10);
              arq = fopen(cadastroChar, "rb");
              if(arq)
              {
                     carrinhosAbertos[totalCarrinhosAbertos] = i;
                     totalCarrinhosAbertos++;
                     fclose(arq);
              }
     }

     if(totalCarrinhosAbertos != 0)
     {
             printf("\nTotal de usuarios com carrinhos abertos: ");textcolor(LIGHTGREEN);printf("%d", totalCarrinhosAbertos);
             textcolor(WHITE);printf("\nUsuarios com carrinhos abertos:");
             arq = fopen("usuarios.txt", "r");
             if(!arq)
             {
                     textcolor(LIGHTRED);printf("\nHouve um problema ao abrir o arquivo, o programa será encerrado.");
                     fflush(stdin);getch();exit(1);
             }
             for(i = 0; i < totalCarrinhosAbertos; i++)
             {
                           rewind(arq);
                           while(!feof(arq))
                           {
                                fgets(leituraLinha, MAX_LINHA, arq);
                                codigoProd = atoi(strtok(leituraLinha, ","));
                                if(codigoProd == carrinhosAbertos[i])
                                {
                                     textcolor(WHITE);
                                     printf("\n===========================================");
                                     printf("\nCodigo: ");textcolor(LIGHTGREEN);printf("%d", codigoProd);
                                     textcolor(WHITE);
                                     printf("\nNome: ");textcolor(LIGHTGREEN);printf("%s", strtok(NULL, ","));
                                     textcolor(WHITE);
                                     printf("\nTipo: ");textcolor(LIGHTGREEN);printf("%s", strtok(NULL, "\n"));
                                }
                           }
             }
             fflush(stdin);getch();
     }
     else
     {
          printf("\nNao ha nenhum cliente com o carrinho de compras aberto.");
          fflush(stdin);getch();
     }
}

void vendas()
{
     FILE *arq;
     char dia[MAX_DIGITOS], mes[MAX_DIGITOS], ano[MAX_DIGITOS], leituraArquivo[MAX_LINHA];
     char stringComparacao[MAX_LINHA];
     int confirmaData, vendasEletro = 0, vendasVestuario = 0;
     bool encontrouData = false;
     float totalVendas = 0;

     system("cls");
     textcolor(YELLOW);printf("\nVENDAS POR TIPO:");
     textcolor(WHITE);printf("\n======================================================");
     printf("\nInforme uma data. Ex (8, jul , 2010)");
     printf("\nDia: ");textcolor(LIGHTGREEN);fflush(stdin);gets(dia);
     textcolor(WHITE);printf("Mes: ");textcolor(LIGHTGREEN);fflush(stdin);gets(mes);strupr(mes);
     textcolor(WHITE);printf("Ano: ");textcolor(LIGHTGREEN);fflush(stdin);gets(ano);
     arq = fopen("report.txt", "r");
     if(arq)
     {
             while(!feof(arq))
             {
                 fgets(leituraArquivo, MAX_LINHA, arq);
                 if(leituraArquivo[0] != '\n')
                 {
                     confirmaData = 0;
                     strcpy(stringComparacao, strtok(leituraArquivo, ","));
                     if(strcmp(dia, stringComparacao) == 0)
                     {
                        confirmaData++;
                     }
                     strcpy(stringComparacao, strtok(NULL, ","));
                     if(strcmp(mes, stringComparacao) == 0)
                     {
                        confirmaData++;
                     }
                     strcpy(stringComparacao, strtok(NULL, ","));
                     if(strcmp(ano, stringComparacao) == 0)
                     {
                        confirmaData++;
                     }
                     if(confirmaData == 3)
                     {
                         vendasEletro += atoi(strtok(NULL, ","));
                         vendasVestuario += atoi(strtok(NULL, ","));
                         totalVendas += atof(strtok(NULL, "\n"));
                         encontrouData = true;
                     }
                 }
             }
             fclose(arq);
             if(encontrouData)
             {
                 textcolor(WHITE);printf("\nTotal de vendas no dia ");textcolor(LIGHTGREEN);printf("%s", dia);
                 textcolor(WHITE);printf("/");textcolor(LIGHTGREEN);printf("%s", mes);textcolor(LIGHTGREEN);printf("/");
                 textcolor(LIGHTGREEN);printf("%s", ano);textcolor(WHITE);printf(":");
                 printf("\nNumero de eletrodomesticos vendidos: ");textcolor(LIGHTGREEN);printf("%d", vendasEletro);
                 textcolor(WHITE);printf("\nNumero de pecas de vestuario vendidas: ");
                 textcolor(LIGHTGREEN);printf("%d", vendasVestuario);textcolor(WHITE);
                 printf("\nTotal de vendas: R$ ");textcolor(LIGHTGREEN);printf("%.2f", totalVendas);
                 fflush(stdin);getch();
             }
             else
             {
                 textcolor(LIGHTRED);printf("\nA data informada nao foi encontrada nos registros.");
                 fflush(stdin);getch();
             }
     }
     else
     {
         textcolor(LIGHTRED);printf("\nNenhuma venda foi efetuada ainda.");
         fflush(stdin);getch();
     }
}

void verificaEstoque()
{
     FILE *arq;
     char leituraArquivo[MAX_LINHA];

     //imprime eletro
     system("cls");
     textcolor(YELLOW);printf("\nESTOQUE:");
     textcolor(WHITE);printf("\n===============================================================");
     arq=fopen("eletro.txt", "r");
     textcolor(YELLOW);printf("\nEletrodomesticos:");
     while(!feof(arq))
     {
         fgets(leituraArquivo, sizeof(leituraArquivo), arq);
         textcolor(WHITE);printf("\n====================================================");
         printf("\nCodigo do produto: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(leituraArquivo,","));
         textcolor(WHITE);printf("\nDescricao do produto: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,","));textcolor(WHITE);
         textcolor(WHITE);printf("\nAltura: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,","));textcolor(WHITE);printf(" cm");
         textcolor(WHITE);printf("\nLargura: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,","));textcolor(WHITE);printf(" cm");
         textcolor(WHITE);printf("\nProfundidade: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,","));textcolor(WHITE);printf(" cm");
         textcolor(WHITE);printf("\nPreco:");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,","));textcolor(WHITE);printf(" reais");
         textcolor(YELLOW);printf("\nEstoque: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,","));textcolor(WHITE);printf(" unidades");
         textcolor(WHITE);printf("\nCor do produto: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,"\n"));
     }
     fclose(arq);
     fflush(stdin);getch();
     //imprime vestuario
     system("cls");
     textcolor(YELLOW);printf("\nESTOQUE:");
     textcolor(WHITE);printf("\n===============================================================");
     arq=fopen("vestuario.txt", "r");
     textcolor(YELLOW);printf("\nVestuario:");
     while(!feof(arq))
     {
         fgets(leituraArquivo, sizeof(leituraArquivo), arq);
         textcolor(WHITE);printf("\n====================================================");
         printf("\nCodigo do produto: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(leituraArquivo,","));
         textcolor(WHITE);printf("\nDescricao do produto: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,","));
         textcolor(WHITE);printf("\nTamanho: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,","));
         textcolor(WHITE);printf("\nPreco:");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,","));textcolor(WHITE);printf(" reais");
         textcolor(YELLOW);printf("\nEstoque: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,","));textcolor(WHITE);printf(" unidades");
         textcolor(WHITE);printf("\nCor do produto: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,","));
         textcolor(WHITE);printf("\nGenero: ");
         textcolor(LIGHTGREEN);printf("%s", strtok(NULL,"\n"));
     }
     fclose(arq);
     fflush(stdin);getch();
}

void clientesCadastrados()
{
      FILE *arq;
      char leituraArquivo[MAX_LINHA];

      system("cls");
      textcolor(YELLOW);printf("\nCLIENTES CADASTRADOS:");
      textcolor(WHITE);printf("\n=======================================================");
      arq=fopen("usuarios.txt", "r");
      if(!arq)
      {
             textcolor(LIGHTRED);printf("\nHouve um problema ao abrir o arquivo, o programa será encerrado.");
             fflush(stdin);getch();exit(1);
      }
      while(!feof(arq))
      {
          fgets(leituraArquivo, sizeof(leituraArquivo), arq);
          printf("\n===========================================");
          printf("\nCodigo: ");textcolor(LIGHTGREEN);printf("%s", strtok(leituraArquivo, ","));
          textcolor(WHITE);
          printf("\nNome: ");textcolor(LIGHTGREEN);printf("%s", strtok(NULL, ","));
          textcolor(WHITE);
          printf("\nTipo: ");textcolor(LIGHTGREEN);printf("%s", strtok(NULL, "\n"));
          textcolor(WHITE);printf("\n===========================================");
      }
      fflush(stdin);getch();
}

void menuGERENTE(char nomeGerente[])
{
    char respostaMenu;               //resposta caracter informada pelo usuario
    int validaMenu = 0;           //resposta devolvida pela funcao

    do
    {
        system("cls");
        textcolor(YELLOW);printf("\nGERENTE: ");
        textcolor(LIGHTGREEN);printf(" %s", nomeGerente);
        textcolor(WHITE);printf("\nData: %s Hora: %s",__DATE__,__TIME__);
        printf("\n====================================================================");
        printf("\nSelecione a letra correspondente em verde para acessar a opcao.\n");
        textcolor(LIGHTGREEN);printf("\nT");textcolor(WHITE);printf("rocar Usuario");
        textcolor(LIGHTGREEN);printf("\n\nP");textcolor(WHITE);printf("esquisar");
        printf("\n\nRelatorios:");
        textcolor(LIGHTGREEN);
        printf("\nC");textcolor(WHITE);printf("ompras em Andamento");
        textcolor(LIGHTGREEN);printf("\nV");textcolor(WHITE);printf("endas");
        textcolor(LIGHTGREEN);printf("\nE");textcolor(WHITE);printf("stoque");
        printf("\nC");textcolor(LIGHTGREEN);printf("l");textcolor(WHITE);printf("lientes Cadastrados");
        printf("\n==================================================================\n");
        do
        {
            textcolor(LIGHTGREEN);
            fflush(stdin);
            scanf("%c", &respostaMenu);
            respostaMenu = toupper(respostaMenu);
            textcolor(WHITE);
            switch(respostaMenu)
            {
                case 'T':
                {    validaMenu = 10;
                     break;
                }
                case 'P':
                {
                     pesquisar();
                     validaMenu = 1;
                     break;
                }
                case 'C':
                {
                     relatorioComprasEmAndamento();
                     validaMenu = 1;
                     break;
                }
                case 'V':
                {
                     vendas();
                     validaMenu = 1;
                     break;
                }
                case 'E':
                {
                     verificaEstoque();
                     validaMenu = 1;
                     break;
                }
                case 'L':
                {
                     clientesCadastrados();
                     validaMenu = 1;
                     break;
                }
                default:
                {
                   textcolor(LIGHTRED);
                   printf("Opcao invalida. Por favor digite uma opcao valida: ");
                   validaMenu = 0;
                }
            }
         }while(validaMenu == 0);
    }while(validaMenu != 10);
}

//INICIO DA TELA DE LOGIN
void telaLogin()
{
    FILE *arq;
    int codCadastro, i, comparaCadastro, testaGerente;
    bool achouCadastro = false;
    char leituraArquivo[MAX_LINHA], tipoCliente[TAM_NOME_MAX], nome[TAM_NOME_MAX];
    system("cls");
    textcolor(YELLOW);
    printf("\nLOGIN");
    textcolor(WHITE);
    printf("\n=================================================================");
    printf("\nInforme seu numero de cadastro: ");
    do
    {
            textcolor(LIGHTGREEN);
            scanf("%d", &codCadastro);
            textcolor(WHITE);
            arq = fopen("usuarios.txt", "r");
            if(!arq)
            {
                    textcolor(LIGHTRED);
                    printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
                    textcolor(WHITE);
                    getch();
                    exit(1);
            }
            while(!feof(arq) && achouCadastro == false)
            {
                 fgets(leituraArquivo, sizeof(leituraArquivo), arq);
                 comparaCadastro = atoi(strtok(leituraArquivo, ","));
                 if(codCadastro == comparaCadastro)
                 {
                     strcpy(nome, strtok(NULL, ","));
                     strcpy(tipoCliente, (strtok(NULL, "\n")));
                     achouCadastro = true;
                 }
            }
            fclose(arq);
            if(achouCadastro == true)
            {
                testaGerente = strcmp("gerente", tipoCliente);
                if(testaGerente == 0)
                   menuGERENTE(nome);
                else
                   menuCLIENTE(nome, codCadastro);
            }
            else
            {
                textcolor(LIGHTRED);
                printf("Usuario nao encontrado. Informe outro cadastro: ");
                textcolor(YELLOW);
                getch();
            }
    }while(achouCadastro == false);
}
//FIM DA TELA DE LOGIN

int main()
{
    FILE *arq;
    int leituraOpcao;
    textcolor(WHITE);

    //cria o arquivo usuarios.txt caso ele nao existir
    arq = fopen("usuarios.txt", "a");
    if(!arq)
    {
            textcolor(LIGHTRED);
            printf("\nErro ao criar arquivo! O programa sera finalizado.");
            textcolor(WHITE);
            getch();
            exit(1);
    }
    fclose(arq);

    //cria o arquivo vestuario.txt caso ele nao existir
    arq = fopen("vestuario.txt", "a");
    if(!arq)
    {
            textcolor(LIGHTRED);
            printf("\nErro ao criar arquivo! O programa sera finalizado.");
            textcolor(WHITE);
            getch();
            exit(1);
    }
    fclose(arq);

    //cria o arquivo eletro.txt caso ele nao exitir
    arq = fopen("eletro.txt", "a");
    if(!arq)
    {
            textcolor(LIGHTRED);
            printf("\nErro ao criar arquivo! O programa sera finalizado.");
            textcolor(WHITE);
            getch();
            exit(1);
    }
    fclose(arq);

    do
         {
             system("cls");
             leituraOpcao = telaInicial();
             switch(leituraOpcao)
             {
                case 1:
                {
                     telaLogin();
                     break;
                }
                case 2:
                {
                     novoUsuario();
                     break;
                }
                case 3:
                {    showInfo();
                     break;
                }
             }
    }while(leituraOpcao != 4);
    system("cls");
    textcolor(LIGHTRED);
    printf("\n                           tMMM0.                        ");
    printf("\n                         1MMMM                           ");
    printf("\n                        :MMMM   :$                       ");
    printf("\n                       .EMMMM  cMM                       ");
    printf("\n                      M  MMMM# ;MMM.                     ");
    printf("\n                     8Mn :MMMMM YMMM                     ");
    printf("\n                     .MM@ .;MMMM MMM                     ");
    printf("\n                       #MMM$ MM0 MMt                     ");
    printf("\n                           ,:YW.#Q                       ");
    printf("\n                    i6WMMM@B@M@MM@$M#0c.                 ");
    printf("\n                        ,:;BUWSQ;,,.                     ");
    printf("\n                           1 c S                         ");
    textcolor(LIGHTBLUE);
    printf("\n                                                         ");
    printf("\n      MM    MM  MMMMMMM  MMMMMMM      MMMMMMM   MMMMMM    ");
    printf("\n      MM    MM  MM       MM   MMM    MM    MM  MMM  MMM   ");
    printf("\n      MM    MM  MM       MM    MM   MM         MMM        ");
    printf("\n      MM    MM  MMMMMM   MMMMMMM   MM   MMMMM  MMMMMM    ");
    printf("\n      MM    MM  MM       MM   MM    MM     MM       MMM   ");
    printf("\n      MMMMMMMM  MM       MM    MM    MM    MM  MMM  MMM     ");
    printf("\n       MMMMM    MM       MW     MM    MMMMMMM   MMMMM     ");
    fflush(stdin);
    getch();
    return(0);
}
