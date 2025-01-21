#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Livro
{
  char editora[40];
  char nome[40];
  char isbn[40];
  float preco;
  int score;
};

typedef struct Livro tLivro, *pLivro;

pLivro livro_aloc(int qtde);
void livro_ler(pLivro livros, int qtde);
void livro_exibe(pLivro livros, int qtde);
void livro_desaloca(pLivro livros);

int main()
{
  int qtde;
  scanf("%d", &qtde);
  getchar();
  
  if(qtde <= 0)
  {
    printf("Sem livros\n");
    exit(1);
  }

  pLivro livros = livro_aloc(qtde);
  livro_ler(livros, qtde);
  livro_exibe(livros, qtde);
  livro_desaloca(livros);


  return 0;
}

pLivro livro_aloc(int qtde)
{
  pLivro qtd =(pLivro)malloc(sizeof(tLivro)*qtde);
  
  return qtd;
}

void livro_ler(pLivro livros, int qtde)
{
  for(int i = 0; i < qtde; i++)
  {
    fgets(livros[i].nome, sizeof(livros[i].nome), stdin);
    livros[i].nome[strcspn(livros[i].nome, "\n")] = '\0';
    fgets(livros[i].isbn, sizeof(livros[i].isbn), stdin);
    livros[i].isbn[strcspn(livros[i].isbn, "\n")] = '\0';
    scanf("%f", &livros[i].preco);
    while (getchar() != '\n');
    scanf("%d", &livros[i].score);
    while (getchar() != '\n');
    fgets(livros[i].editora, sizeof(livros[i].editora), stdin);
    livros[i].editora[strcspn(livros[i].editora, "\n")] = '\0';
  }
}

void livro_exibe(pLivro livros, int qtde)
{
  for(int i = 0; i < qtde; i++)
  {
    if(i != 0){printf("\n");}
    printf("Livro %d:\n", i+1);
    printf("Nome: %s\n", livros[i].nome);
    printf("ISBN: %s\n", livros[i].isbn);
    printf("Preço: R$ %.2lf\n", livros[i].preco);
    printf("Score: %d\n", livros[i].score);
    printf("Editora: %s\n", livros[i].editora);
  }
}
void livro_desaloca(pLivro livros)
{
  free(livros);
}