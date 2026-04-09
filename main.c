#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Dados
{
    char nome[50];
    long int rg;
    struct Dados *prox;
} Dados;

typedef struct
{
    Dados *dados;
    int tamanho;
    int capacidade;
} ListaSeq;

void inserirInicio(Dados** inicio, Dados** fim, char nome[], long int rg, int *c, int* m);
void inserirFim(Dados** inicio, Dados** fim, char nome[], long int rg, int *c, int *m, int mostrar);
void inserirN(Dados** inicio, Dados** fim, char nome[], long int rg, int pos, int* c, int* m);

void removeIni(Dados** inicio, Dados** fim, int *c, int *m);
void removeFim(Dados** inicio, Dados** fim, int *c, int *m);
void removerN(Dados** inicio, Dados** fim, int *c, int *m, int pos);

void carregarArquivoENC(Dados** inicio, Dados** fim, int op);
void mostrarListaENC(Dados *inicio);
void menuENC(Dados** inicio, Dados** fim);
void procuraRG(Dados *inicio, long int rg, int *c, int *m);
void salvarListaENC(Dados *inicio, char nomeArquivo[]);
void carregarArquivoSalvoENC(Dados **inicio, Dados **fim, char nomeArquivo[]);
void liberarListaENC(Dados **inicio, Dados **fim);

///////////////////////////////////////////////////////////

void inserirINIS(ListaSeq *lista, char nome[], long int rg, int *c, int *m);
void inserirFIMS(ListaSeq *lista, char nome[], long int rg, int *c, int *m);
void inserirNS(ListaSeq *lista, char nome[], long int rg, int pos, int *c, int *m);

void removeINIS(ListaSeq *lista, int *c, int *m);
void removeFIMS(ListaSeq *lista, int *c, int *m);
void removeNS(ListaSeq *lista, int pos, int *c, int *m);

void carregarArquivoSEQ(ListaSeq *lista, int op);
void mostrarListaSEQ(ListaSeq *lista);
void menuSEQ(ListaSeq *lista);
void procuraRGS(ListaSeq *lista, long int rg, int *c, int *m);
void salvarListaSEQ(ListaSeq *lista, char nomeArquivo[]);
void carregarArquivoSalvoSEQ(ListaSeq *lista, char nomeArquivo[]);
void liberarListaSEQ(ListaSeq *lista);



void menuENC(Dados** inicio, Dados** fim)
{
    int op, pos;
    int c = 0, m = 0;
    char nome[50];
    long int rg;
    clock_t inicioT, fimT;
    double temp=0;

    printf("\nLista Encadeada\n");
    printf("1 - Inserir um no Inicio\n");
    printf("2 - Inserir um no Fim\n");
    printf("3 - Inserir um no N\n");
    printf("4 - Remover um no Inicio\n");
    printf("5 - Remover um no Fim\n");
    printf("6 - Remover um no N\n");
    printf("7 - Procura por RG\n");
    printf("8 - Salvar lista\n");
    printf("9 - Carregar o Arquivo salvo\n");

    scanf("%d", &op);

    if (op == 1)
    {
        printf("Digite o nome: ");
        scanf("%49s", nome);
        printf("Digite o RG: ");
        scanf("%ld", &rg);
        inicioT= clock();
        inserirInicio(inicio, fim, nome, rg, &c, &m);
        fimT= clock();
        temp= ((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;

    }
    else if (op == 2)
    {
        printf("Digite o nome: ");
        scanf("%49s", nome);
        printf("Digite o RG: ");
        scanf("%ld", &rg);
        inicioT= clock();
        inserirFim(inicio, fim, nome, rg, &c, &m, 1);
        fimT= clock();
        temp= ((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;
    }
    else if (op == 3)
    {
        printf("Digite o nome: ");
        scanf("%49s", nome);
        printf("Digite o RG: ");
        scanf("%ld", &rg);
        printf("Digite a posicao N: ");
        scanf("%d", &pos);
        inicioT= clock();
        inserirN(inicio, fim, nome, rg, pos, &c, &m);
        fimT= clock();
        temp= ((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;

    }
    else if(op == 4)
    {
        inicioT= clock();
        removeIni(inicio, fim, &c, &m);
        fimT= clock();
        temp= ((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;

    }
    else if(op == 5)
    {
        inicioT= clock();
        removeFim(inicio, fim, &c, &m);
        fimT= clock();
        temp= ((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;
    }
    else if(op == 6)
    {
        printf("Digite a posicao do N: ");
        scanf("%d", &pos);
        printf("\n");
        inicioT= clock();
        removerN(inicio, fim, &c, &m, pos);
        fimT= clock();
        temp=((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;
    }
    else if(op == 7)
    {
        printf("Digite o RG desejado: ");
        scanf("%ld", &rg);
        inicioT= clock();
        procuraRG(*inicio, rg, &c, &m);
        fimT= clock();
        temp= ((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;
    }
    else if(op == 8)
    {
        salvarListaENC(*inicio, "listaENC.txt");
    }
    else if(op == 9)
    {
        liberarListaENC(inicio, fim);
        carregarArquivoSalvoENC(inicio, fim, "listaENC.txt");
    }
    else
    {
        printf("Erro opcao Invalida\n");
        return;
    }

    printf("\nConteudo atual da lista:\n");
    mostrarListaENC(*inicio);
    printf("\nTempo: %.6f ms\n", temp);
    printf("C(n): %d operacoes\n", c);
    printf("M(n): %d movimentacoes\n", m);
}
void qualarqui(int *op)
{
    printf("Qual arquivo quer ler: \n");
    printf("1 - 10 pessoas\n");
    printf("2 - 50 pessoas\n");
    printf("3 - 100 pessoas\n");
    printf("4 - 1k pessoas\n");
    printf("5 - 10k pessoas\n");
    printf("6 - 1M pessoas\n");
    //printf("7 - 100M pessoas\n");
    scanf("%d", op);
}
void carregarArquivoENC(Dados** inicio, Dados** fim, int op)
{
    int c=0, m=0, lidos, ignorada=0;
    char linha[100];
    char nome[50];
    long int rg;
    FILE *arquivo = NULL;

    if(op == 1)
    {
        arquivo = fopen("NomeRG10.txt", "r");
    }
    else if(op == 2)
    {
        arquivo = fopen("NomeRG50.txt", "r");
    }
    else if(op == 3)
    {
        arquivo = fopen("NomeRG100.txt", "r");
    }
    else if(op == 4)
    {
        arquivo = fopen("NomeRG1K.txt", "r");
    }
    else if(op == 5)
    {
        arquivo = fopen("NomeRG10K.txt", "r");
    }
    else if(op == 6)
    {
        arquivo = fopen("NomeRG1M.txt", "r");
    }
   /* else if(op == 7)
    {
        arquivo = fopen("NomeRG100M.txt", "r");
    }*/
    else
    {
        printf("Erro, opcao invalida");
    }

    if (arquivo == NULL)
    {
        printf("Nao abriu o arquivo\n");
        return;
    }

    printf("Arquivo carregado com sucesso\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        lidos = sscanf(linha, " %49[^,],%ld", nome, &rg);

        if (lidos == 2)
        {
            inserirFim(inicio, fim, nome, rg, &c, &m, 0);
        }
        else
        {
            ignorada++;
        }
    }

    fclose(arquivo);
    printf("Linhas ignoradas: %d\n", ignorada);
}
void inserirInicio(Dados** inicio, Dados** fim, char nome[], long int rg, int* c, int* m)
{
    Dados *novo = (Dados *)malloc(sizeof(Dados));
    *c=0;
    *m=0;
    (*c)++;
    if (novo == NULL)
    {
        printf("Erro ao alocar\n");
        return;
    }

    strcpy(novo->nome, nome);
    (*m)++;

    novo->rg = rg;
    (*m)++;

    novo->prox = *inicio;
    (*m)++;

    *inicio = novo;
    (*m)++;

    (*c)++;
    if (*fim == NULL)
    {
        *fim = novo;
        (*m)++;
    }

    printf("Inserido no inicio com sucesso\n");
    printf("Posicao: 1\n");
}

void inserirFim(Dados** inicio, Dados** fim, char nome[], long int rg, int *c, int *m, int mostrar)
{
    Dados *novo, *aux;
    novo = (Dados *)malloc(sizeof(Dados));
    aux= *inicio;
    int pos=0;
    *c=0;
    *m=0;
    (*c)++;
    if (novo == NULL)
    {
        printf("Erro ao alocar\n");
        return;
    }
    strcpy(novo->nome, nome);
    (*m)++;

    novo->rg = rg;
    (*m)++;

    novo->prox = NULL;
    (*m)++;

    (*c)++;
    if (*inicio == NULL)
    {
        *inicio = novo;
        (*m)++;
        *fim = novo;
        (*m)++;
        pos=1;
    }
    else
    {
        (*fim)->prox = novo;
        (*m)++;
        *fim = novo;
        (*m)++;
        if(mostrar)
        {
            while(aux!=NULL)
            {
                aux=aux->prox;
                pos++;
            }
            pos++;
        }
    }
    if(mostrar)
    {
        printf("Inserido: %s RG: %ld\n", novo->nome, novo->rg);
        printf("Posicao: %d\n", pos);
    }
}
void inserirN(Dados** inicio, Dados** fim, char nome[], long int rg, int pos, int *c, int *m)
{
    Dados *novo, *aux;
    *c=0;
    *m=0;

    int i;

    (*c)++;
    if (pos < 1)
    {
        printf("Posicao invalida\n");
        return;
    }

    (*c)++;
    if (pos == 1)
    {
        inserirInicio(inicio, fim, nome, rg, c, m);
        return;
    }

    novo = (Dados *)malloc(sizeof(Dados));
    (*c)++;

    if (novo == NULL)
    {
        printf("Erro ao alocar\n");
        return;
    }

    strcpy(novo->nome, nome);
    (*m)++;

    novo->rg = rg;
    (*m)++;

    novo->prox = NULL;
    (*m)++;

    aux = *inicio;
    (*m)++;

    for (i = 1; i < pos - 1 && aux != NULL; i++)
    {
        (*c)++;
        aux = aux->prox;
        (*m)++;
    }
    (*c)++;
    if (aux == NULL)
    {
        printf("Posicao invalida\n");
        free(novo);
        return;
    }

    novo->prox = aux->prox;
    (*m)++;
    aux->prox = novo;
    (*m)++;

    (*c)++;
    if (novo->prox == NULL)
    {
        *fim = novo;
        (*m)++;
    }

    printf("Inserido: %s RG: %ld\n", novo->nome, novo->rg);
    printf("Posicao: %d\n", pos);
}
void removeIni(Dados** inicio, Dados** fim, int *c, int *m)
{
    Dados* temp;
    *c=0;
    *m=0;

    (*c)++;
    if(*inicio == NULL)
    {
        printf("Lista esta vazia\n");
        return;
    }
    temp=*inicio;
    (*m)++;
    printf("\n");
    printf("Removido: %s RG: %ld\n", temp->nome, temp->rg);
    printf("Posicao: 1\n");
    *inicio=(*inicio)->prox;
    (*m)++;
    (*c)++;
    if(*inicio == NULL)
    {
        *fim=NULL;
        (*m)++;
    }
    free(temp);
}
void removeFim(Dados** inicio, Dados** fim, int *c, int *m)
{
    Dados *aux, *anterior;
    int pos=1;
    *c=0;
    *m=0;

    (*c)++;
    if(*inicio == NULL)
    {
        printf("Lista esta vazia\n");
        return;
    }
    aux=*inicio;
    (*m)++;
    anterior=NULL;
    (*m)++;
    (*c)++;
    if(*inicio == *fim)
    {
        printf("Removido: %s RG: %ld\n", aux->nome, aux->rg);
        printf("Posicao: 1\n");
        free(aux);
        *inicio=NULL;
        (*m)++;
        *fim=NULL;
        (*m)++;
        return;
    }
    while(aux->prox != NULL)
    {
        (*c)++;
        anterior=aux;
        (*m)++;
        aux =aux->prox;
        (*m)++;
        pos++;
    }
    (*c)++;
    printf("\n");
    printf("Removido: %s RG: %ld\n", aux->nome, aux->rg);
    printf("Posicao: %d\n", pos);
    anterior->prox=NULL;
    (*m)++;
    *fim=anterior;
    (*m)++;
    free(aux);

}
void removerN(Dados** inicio, Dados** fim, int *c, int *m, int pos)
{
    Dados *aux, *anterior;
    int i;
    *c=0;
    *m=0;

    (*c)++;
    if(*inicio == NULL)
    {
        printf("Lista vazia\n");
        return;
    }
    (*c)++;
    if(pos < 1)
    {
        printf("Posicao escolhida eh invalida\n");
        return;
    }
    (*c)++;
    if(pos == 1)
    {
        removeIni(inicio, fim, c, m);
        return;
    }
    aux=*inicio;
    (*m)++;
    anterior=NULL;
    (*m)++;
    for(i=1; i<pos && aux!=NULL; i++)
    {
        (*c)++;
        anterior=aux;
        (*m)++;
        aux=aux->prox;
        (*m)++;
    }
    (*c)++;
    if(aux == NULL)
    {
        printf("Posicao invalida\n");
        return;
    }
    printf("\n");
    printf("Removido: %s RG: %ld\n", aux->nome, aux->rg);
    printf("Posicao: %d\n", pos);
    anterior->prox=aux->prox;
    (*m)++;
    (*c)++;
    if(aux == *fim)
    {
        *fim=anterior;
        (*m)++;
    }
    free(aux);
}

void procuraRG(Dados *inicio, long int rg, int *c, int *m)
{
    Dados *aux;
    int pos=1;
    aux=inicio;
    *c=0;
    *m=0;

    (*c)++;
    if(aux == NULL)
    {
        printf("Lista vazia\n");
        return;
    }
    while(aux != NULL)
    {
        (*c)++;
        (*c)++;
        if(aux->rg == rg)
        {
            printf("\n");
            printf("Posição na lista %d\n", pos);
            printf("Nome: %s RG: %ld\n", aux->nome, aux->rg);
            return;
        }
        aux=aux->prox;
        (*m)++;
        pos++;
        (*m)++;
    }
    printf("Nao foi encontrado o RG\n");
}

void mostrarListaENC(Dados *inicio)
{
    Dados *aux = inicio;

    if (aux == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    while (aux != NULL)
    {
        printf("Nome: %s  RG: %ld\n", aux->nome, aux->rg);
        aux = aux->prox;
    }
}
void salvarListaENC(Dados *inicio, char nomeArquivo[])
{
    FILE *arquivo;
    Dados *aux = inicio;

    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    while (aux != NULL)
    {
        fprintf(arquivo, "%s,%ld\n", aux->nome, aux->rg);
        aux = aux->prox;
    }

    fclose(arquivo);

    printf("Lista encadeada salva com sucesso\n");
}
void carregarArquivoSalvoENC(Dados **inicio, Dados **fim, char nomeArquivo[])
{
    FILE *arquivo;
    char linha[100];
    char nome[50];
    long int rg;
    int c = 0, m = 0, lidos, ignorada=0;

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        lidos = sscanf(linha, " %49[^,],%ld", nome, &rg);

        if (lidos == 2)
        {
            inserirFim(inicio, fim, nome, rg, &c, &m, 0);
        }
        else
        {
            ignorada++;
        }
    }

    fclose(arquivo);
    printf("Linhas ignoradas: %d\n", ignorada);

    printf("Lista encadeada carregada com sucesso\n");
}
void liberarListaENC(Dados **inicio, Dados **fim)
{
    Dados *aux;
    Dados *temp;

    aux = *inicio;

    while (aux != NULL)
    {
        temp = aux;
        aux = aux->prox;
        free(temp);
    }

    *inicio = NULL;
    *fim = NULL;
}

/////////////////Completo Lista Encadeada//////////////////
///////////////////////////////////////////////////////////


void mostrarListaSEQ(ListaSeq *lista)
{
    int i;

    if (lista->tamanho == 0)
    {
        printf("Lista sequencial vazia.\n");
        return;
    }

    for (i = 0; i < lista->tamanho; i++)
    {
        printf("Nome: %s  RG: %ld\n", lista->dados[i].nome, lista->dados[i].rg);
    }
}

void carregarArquivoSEQ(ListaSeq *lista, int op)
{
    char linha[100];
    char nome[50];
    long int rg;
    int lidos, ignorada=0;
    Dados *novo;
    FILE *arquivo = NULL;

    lista->capacidade=10000;
    lista->tamanho=0;

    lista->dados=(Dados*)malloc(lista->capacidade*sizeof(Dados));

    if(lista->dados == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return;
    }

    if(op == 1)
    {
        arquivo = fopen("NomeRG10.txt", "r");
    }
    else if(op == 2)
    {
        arquivo = fopen("NomeRG50.txt", "r");
    }
    else if(op == 3)
    {
        arquivo = fopen("NomeRG100.txt", "r");
    }
    else if(op == 4)
    {
        arquivo = fopen("NomeRG1K.txt", "r");
    }
    else if(op == 5)
    {
        arquivo = fopen("NomeRG10K.txt", "r");
    }
    else if(op == 6)
    {
        arquivo = fopen("NomeRG1M.txt", "r");
    }
   /* else if(op == 7)
    {
        arquivo = fopen("NomeRG100M.txt", "r");
    }*/
    else
    {
        printf("Erro, opcao invalida");
    }
    if(arquivo == NULL)
    {
        printf("Nao abriu o arquivo\n");
        free(lista->dados);
        lista->dados = NULL;
        lista->tamanho = 0;
        lista->capacidade = 0;
        return;
    }

    printf("Arquivo carregado com sucesso\n");

    while(fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        lidos = sscanf(linha, " %49[^,],%ld", nome, &rg);

        if(lidos == 2)
        {
            if(lista->tamanho == lista->capacidade)
            {
                lista->capacidade *= 2;
                novo = (Dados*)realloc(lista->dados, lista->capacidade * sizeof(Dados));
                if(novo == NULL)
                {
                    printf("Erro ao realocar\n");
                    fclose(arquivo);
                    return;
                }
                lista->dados = novo;
            }
            strcpy(lista->dados[lista->tamanho].nome, nome);
            lista->dados[lista->tamanho].rg = rg;
            lista->dados[lista->tamanho].prox = NULL;
            lista->tamanho++;
        }
        else
        {
            ignorada++;
        }
    }
    fclose(arquivo);
    printf("Linhas ignoradas: %d\n", ignorada);
}

void menuSEQ(ListaSeq *lista)
{
    int op, pos;
    int c = 0, m = 0;
    char nome[50];
    long int rg;
    clock_t inicioT, fimT;
    double temp=0;
    printf("\n");
    printf("1 - Inserir um no Inicio\n");
    printf("2 - Inserir um no Fim\n");
    printf("3 - Inserir um no N\n");
    printf("4 - Remover um no Inicio\n");
    printf("5 - Remover um no Fim\n");
    printf("6 - Remover um no N\n");
    printf("7 - Procura por RG\n");
    printf("8 - Salvar arquivo\n");
    printf("9 - Carregar o Arquivo salvo\n");

    scanf("%d", &op);

    if(op == 1)
    {
        printf("Digite o nome: ");
        scanf("%49s", nome);
        printf("Digite o RG: ");
        scanf("%ld", &rg);
        inicioT= clock();
        inserirINIS(lista, nome, rg, &c, &m);
        fimT= clock();
        temp=((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;
    }
    else if(op == 2)
    {
        printf("Digite o nome: ");
        scanf("%49s", nome);
        printf("Digite o RG: ");
        scanf("%ld", &rg);
        inicioT= clock();
        inserirFIMS(lista, nome, rg, &c, &m);
        fimT= clock();
        temp=((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;
    }
    else if(op == 3)
    {
        printf("Digite o nome: ");
        scanf("%49s", nome);
        printf("Digite o RG: ");
        scanf("%ld", &rg);
        printf("Digite a posicao: ");
        scanf("%d", &pos);
        inicioT= clock();
        inserirNS(lista, nome, rg, pos, &c, &m);
        fimT= clock();
        temp=((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;
    }
    else if(op == 4)
    {
        inicioT= clock();
        removeINIS(lista, &c, &m);
        fimT= clock();
        temp=((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;
    }
    else if(op == 5)
    {
        inicioT= clock();
        removeFIMS(lista, &c, &m);
        fimT= clock();
        temp=((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;
    }
    else if(op == 6)
    {
        printf("Digite a posicao: ");
        scanf("%d", &pos);
        inicioT= clock();
        removeNS(lista, pos, &c, &m);
        fimT= clock();
        temp=((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;
    }
    else if(op == 7)
    {
        printf("Digite o RG: ");
        scanf("%ld", &rg);
        inicioT= clock();
        procuraRGS(lista, rg, &c, &m);
        fimT=clock();
        temp=((double)(fimT - inicioT)/CLOCKS_PER_SEC) *1000;
    }
    else if(op == 8)
    {
        m=0;
        c=0;
        temp=0;
        salvarListaSEQ(lista, "listaSEQ.txt");
    }
    else if(op == 9)
    {
        m=0;
        c=0;
        temp=0;
        liberarListaSEQ(lista);
        carregarArquivoSalvoSEQ(lista, "listaSEQ.txt");
    }
    else
    {
        printf("Opcao invalida\n");
        return;
    }
    printf("\nConteudo atual da lista:\n");
    mostrarListaSEQ(lista);
    printf("\nTempo: %.6f ms\n", temp);
    printf("C(n): %d operacoes\n", c);
    printf("M(n): %d movimentacoes\n", m);
}

void inserirINIS(ListaSeq *lista, char nome[], long int rg, int *c, int *m)
{
    int i;
    Dados *novo;
    *c=0;
    *m=0;

    (*c)++;
    if(lista->tamanho == lista->capacidade)
    {
        lista->capacidade *=2;
        (*m)++;
        novo= realloc(lista->dados, lista->capacidade * sizeof(Dados));
        (*c)++;

        if(novo == NULL)
        {
            printf("Erro ao realocar memoria\n");
            return;
        }

        lista->dados = novo;
        (*m)++;
    }
    for(i=lista->tamanho; i>0; i--)
    {
        (*c)++;
        lista->dados[i]=lista->dados[i-1];
        (*m)++;
    }
    strcpy(lista->dados[0].nome, nome);
    (*m)++;
    lista->dados[0].rg=rg;
    (*m)++;
    lista->tamanho++;
    (*m)++;

    printf("Inserido: %s RG: %ld\n", lista->dados[0].nome, lista->dados[0].rg);
    printf("Posicao: 1\n");
}

void inserirFIMS(ListaSeq *lista, char nome[], long int rg, int *c, int *m)
{
    Dados *novo;
    *c=0;
    *m=0;

    (*c)++;
    if(lista->tamanho == lista->capacidade)
    {
        lista->capacidade *=2;
        (*m)++;
        novo= realloc(lista->dados, lista->capacidade * sizeof(Dados));
        (*c)++;

        if(novo == NULL)
        {
            printf("Erro ao realocar memoria\n");
            return;
        }

        lista->dados = novo;
        (*m)++;
    }
    strcpy(lista->dados[lista->tamanho].nome, nome);
    (*m)++;
    lista->dados[lista->tamanho].rg= rg;
    (*m)++;
    lista->tamanho++;
    (*m)++;

    printf("Inserido: %s RG: %ld\n", lista->dados[lista->tamanho-1].nome, lista->dados[lista->tamanho-1].rg);
    printf("Posicao: %d\n", lista->tamanho);
}

void inserirNS(ListaSeq *lista, char nome[], long int rg, int pos, int *c, int *m)
{
    int i;
    Dados *novo;
    *c=0;
    *m=0;

    (*c)++;
    (*c)++;
    if(pos<1 || pos>lista->tamanho+1)
    {
        printf("Posicao Invalida\n");
        return;
    }
    (*c)++;
    if(lista->tamanho == lista->capacidade)
    {
        lista->capacidade *=2;
        (*m)++;
        novo= realloc(lista->dados, lista->capacidade * sizeof(Dados));
        (*c)++;

        if(novo == NULL)
        {
            printf("Erro ao realocar memoria\n");
            return;
        }

        lista->dados = novo;
        (*m)++;
    }
    for(i=lista->tamanho; i>=pos; i--)
    {
        (*c)++;
        lista->dados[i]=lista->dados[i-1];
        (*m)++;
    }
    strcpy(lista->dados[pos-1].nome, nome);
    (*m)++;
    lista->dados[pos-1].rg= rg;
    (*m)++;
    lista->tamanho++;
    (*m)++;

    printf("Inserido: %s RG: %ld\n", lista->dados[pos - 1].nome, lista->dados[pos - 1].rg);
    printf("Posicao: %d\n", pos);
}

void removeINIS(ListaSeq *lista, int *c, int *m)
{
    int i;
    *c=0;
    *m=0;

    (*c)++;
    if(lista->tamanho == 0)
    {
        printf("Lista vazia\n");
        return;
    }
    printf("\n");
    printf("Removido: %s RG: %ld\n", lista->dados[0].nome, lista->dados[0].rg);
    printf("Posicao: 1\n");
    for(i=0; i<lista->tamanho-1; i++)
    {
        (*c)++;
        lista->dados[i]=lista->dados[i+1];
        (*m)++;
    }
    lista->tamanho--;
    (*m)++;

}

void removeFIMS(ListaSeq *lista, int *c, int *m)
{
    *c=0;
    *m=0;

    (*c)++;
    if(lista->tamanho == 0)
    {
        printf("Lista vazia\n");
        return;
    }
    printf("\n");
    printf("Removido: %s RG: %ld\n", lista->dados[lista->tamanho-1].nome, lista->dados[lista->tamanho-1].rg);
    printf("Posicao: %d\n", lista->tamanho);
    lista->tamanho--;
    (*m)++;
}

void removeNS(ListaSeq *lista, int pos, int *c, int *m)
{
    int i;
    char nomeRemovido[50];
    long int rgRemovido;

    *c = 0;
    *m = 0;

    (*c)++;
    if (lista->tamanho == 0)
    {
        printf("Lista vazia\n");
        return;
    }
    (*c)++;
    (*c)++;
    if (pos < 1 || pos > lista->tamanho)
    {
        printf("Posicao invalida\n");
        return;
    }

    strcpy(nomeRemovido, lista->dados[pos - 1].nome);
    (*m)++;
    rgRemovido = lista->dados[pos - 1].rg;
    (*m)++;

    printf("Removido: %s RG: %ld\n", nomeRemovido, rgRemovido);
    printf("Posicao: %d\n", pos);

    for (i = pos - 1; i < lista->tamanho - 1; i++)
    {
        (*c)++;
        lista->dados[i] = lista->dados[i + 1];
        (*m)++;
    }

    lista->tamanho--;
    (*m)++;
}

void procuraRGS(ListaSeq *lista, long int rg, int *c, int *m)
{
    int i;
    *c = 0;
    *m = 0;

    (*c)++;
    if (lista->tamanho == 0)
    {
        printf("Lista vazia\n");
        return;
    }

    for (i = 0; i < lista->tamanho; i++)
    {
        (*c)++;
        if (lista->dados[i].rg == rg)
        {
            printf("\nPosicao na lista %d\n", i + 1);
            printf("Nome: %s RG: %ld\n",lista->dados[i].nome, lista->dados[i].rg);
            return;
        }
    }

    printf("Nao foi encontrado o RG\n");
}

void salvarListaSEQ(ListaSeq *lista, char nomeArquivo[])
{
    FILE *arquivo;
    int i;

    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    for (i = 0; i < lista->tamanho; i++)
    {
        fprintf(arquivo, "%s,%ld\n",lista->dados[i].nome, lista->dados[i].rg);
    }

    fclose(arquivo);

    printf("Lista sequencial salva com sucesso\n");
}

void carregarArquivoSalvoSEQ(ListaSeq *lista, char nomeArquivo[])
{
    FILE *arquivo;
    char linha[100];
    char nome[50];
    long int rg;
    int lidos, ignorada=0;
    Dados *novo;

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    lista->capacidade = 10;
    lista->tamanho = 0;
    lista->dados = (Dados*) malloc(lista->capacidade * sizeof(Dados));

    if (lista->dados == NULL)
    {
        printf("Erro ao alocar memoria\n");
        fclose(arquivo);
        return;
    }

    while(fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        lidos = sscanf(linha, " %49[^,],%ld", nome, &rg);

        if(lidos == 2)
        {
            if(lista->tamanho == lista->capacidade)
            {
                lista->capacidade *= 2;
                novo = (Dados*)realloc(lista->dados, lista->capacidade * sizeof(Dados));
                if(novo == NULL)
                {
                    printf("Erro ao realocar\n");
                    fclose(arquivo);
                    return;
                }
                lista->dados = novo;
            }
            strcpy(lista->dados[lista->tamanho].nome, nome);
            lista->dados[lista->tamanho].rg = rg;
            lista->dados[lista->tamanho].prox = NULL;
            lista->tamanho++;
        }
        else
        {
            ignorada++;
        }
    }
    fclose(arquivo);
    printf("Linhas ignoradas: %d\n", ignorada);
    printf("Lista sequencial carregada com sucesso\n");
}
void liberarListaSEQ(ListaSeq *lista)
{
    if (lista->dados != NULL)
    {
        free(lista->dados);
    }
    lista->dados = NULL;
    lista->tamanho = 0;
    lista->capacidade = 0;
}

int main()
{
    int opcoes, op, tipoInicial, achou = 1, aux=0, op2;
    Dados *inicio = NULL;
    Dados *fim = NULL;

    ListaSeq lista;
    lista.dados = NULL;
    lista.tamanho = 0;
    lista.capacidade = 0;

    qualarqui(&op);

    printf("\nQual lista deseja mostrar primeiro?\n");
    printf("1 - Lista Encadeada\n");
    printf("2 - Lista Sequencial\n");
    printf("3 - Encerrar Programa\n");
    scanf("%d", &tipoInicial);

    if (tipoInicial == 1)
    {
        printf("\nLista Encadeada inicial:\n");
       // mostrarListaENC(inicio);
    }
    else if (tipoInicial == 2)
    {
        printf("\nLista Sequencial inicial:\n");
        //mostrarListaSEQ(&lista);
    }
    else if(tipoInicial == 3)
    {
        printf("Programa Encerrado\n");
        return 1;
    }
    else
    {
        printf("Opcao Invalida\n");
        return 1;
    }
    carregarArquivoSEQ(&lista, op);
    carregarArquivoENC(&inicio, &fim, op);
    opcoes=tipoInicial;
    while (achou != 0)
    {
        if(aux == 1)
        {
            printf("\nQual opcao:\n");
            printf("1 - Lista Encadeada\n");
            printf("2 - Lista Sequencial\n");
            printf("3 - Encerrar Programa\n");
            printf("4 - Carregar arquivo salvo\n");
            scanf("%d", &opcoes);
        }

        if (opcoes == 1)
        {

            menuENC(&inicio, &fim);
        }
        else if (opcoes == 2)
        {
            printf("Lista Sequencial\n");
            menuSEQ(&lista);
        }
        else if (opcoes == 3)
        {
            printf("Programa Encerrado\n");
            achou = 0;
        }
        else if(opcoes == 4)
        {
            printf("1 - Encadeada\n2 - Sequencial\n");
            scanf("%d", &op2);
            if(op2 == 1)
            {
                liberarListaENC(&inicio, &fim);
                carregarArquivoSalvoENC(&inicio, &fim, "listaENC.txt");
            }
            else if(op2 == 2)
            {
                liberarListaSEQ(&lista);
                carregarArquivoSalvoSEQ(&lista, "listaSEQ.txt");
            }
        }
        else
        {
            printf("Opcao invalida\n");
        }
        aux=1;
    }

    liberarListaENC(&inicio, &fim);
    liberarListaSEQ(&lista);
    return 0;
}
