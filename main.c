#include <stdio.h>
int vez; //serve para identificar o número do jogador
//declaração de todas as funções -->
int menu(void);
void zeraTabuleiro(int tabuleiro[3][3]);
void exibeTabuleiro(int tabuleiro[3][3]);
void jogar(int tabuleiro[3][3]);
int Local(int tabuleiro[3][3], int linha, int coluna);
int Linha(int tabuleiro[3][3]);
int Coluna(int tabuleiro[3][3]);
int Diagonal(int tabuleiro[3][3]);
int Empate(int tabuleiro[3][3]);
int Termino(int tabuleiro[3][3], int vez);
void jogada(int tabuleiro[3][3]);
 
int main(void) {
  int tabuleiro[3][3],continuar;
  do {
    vez=1; //
    continuar = menu(); //chama a função menu, para saber a opção
    if(continuar == 1)
      jogar(tabuleiro);
 }
 while(continuar); //repete o jogo até que o comando break seja executado
  return 0;
}
 
int menu(void) { //menu principal do programa
  int opcao;
  printf("\n----------------\n");
  printf("\nJogo da Velha\n");
  printf("\nJogar(Digite 1)\n");
  printf("Sair(Digite 0)\n");
  printf("\n-----------------\n");
  printf("\nOpcão: ");
  scanf("%d", &opcao);
  switch(opcao){ //Ele executa a variável opção de acordo com o número colocado
    case 1:
    case 0:
      break;
    default: //No caso de não ocorrer nenhum dos cases
      printf("Opcao invalida. Tente de novo!\n");
  }
  return opcao;
}
 
 
void zeraTabuleiro(int tabuleiro[3][3]) { //zera todas as 9 posições da matriz (tabuleiro)
  int linha, coluna;
  for(linha = 0 ; linha < 3 ; linha++)
    for(coluna = 0 ; coluna < 3 ; coluna++)
        tabuleiro[linha][coluna] = 0;
}
 
void exibeTabuleiro(int tabuleiro[3][3]) { //essa função serve para trocar as informações da matriz(trocar o 0 por espaço em branco, o 1 por X e o -1 por O), além de esquematizar as colunas, transformando ela em um jogo da velha
  int linha, coluna;
    printf("\n");
  for(linha = 0 ; linha < 3 ; linha++) {
    for(coluna = 0 ; coluna < 3 ; coluna++) {
      if(tabuleiro[linha][coluna] == 0)
        printf("    ");
      else
        if(tabuleiro[linha][coluna] == 1)
          printf("  X ");
        else
          printf("  O ");
      if(coluna != (3-1))
                printf("|");
    }
  printf("\n");
  }
  printf("\n");
}
 
void jogar(int tabuleiro[3][3]) {
  zeraTabuleiro(tabuleiro);
  do {
    exibeTabuleiro(tabuleiro);
    jogada(tabuleiro); //Falar sobre a função jogada
  }
  while(Termino(tabuleiro, vez) != 1); //o procedimento jogar ocorre até que a função termino seja TRUE, ou seja até que o jogo termine
}
 
 
int Local(int tabuleiro[3][3], int linha, int coluna) { //verifica se o local onde o jogador escolheu é vazio ou se o número digitado é valido
  if(linha < 0 || linha > (3-1) || coluna < 0 || coluna > (3-1) ||      tabuleiro[linha][coluna] != 0)
    return 0;// enquanto for 0 o laço da função jogada não acontece
  else
    return 1;
}
 
int Linha(int tabuleiro[3][3]) { //essa função checa a soma de cada linha do tabuleiro, se alguma for 3 ou -3, é porque alguém ganhou.
  int linha, coluna,
    soma;
  for(linha = 0 ; linha < 3 ; linha++) {
    soma=0;
    for(coluna = 0 ; coluna < 3 ; coluna++)
      soma += tabuleiro[linha][coluna];
    if(soma==3 || soma == (-1)*3)
      return 1;
  }
  return 0;
}
 
int Coluna(int tabuleiro[3][3]) { //faz o mesmo da função Linha, mas checa as colunas em vez disso
  int linha, coluna,
    soma;
  for(coluna = 0 ; coluna < 3 ; coluna++) {
    soma=0;
    for(linha = 0 ; linha < 3 ; linha++)
      soma += tabuleiro[linha][coluna];
    if(soma==3 || soma == (-1)*3)
    return 1;
  }
  return 0;
}
 
int Diagonal(int tabuleiro[3][3]) { // essa função checa as duas diagonais de nosso tabuleiro, pra ver se a soma de uma delas é 3 ou -3
  int linha,diagonal_principal=0,diagonal_secundaria=0;
  for(linha = 0 ; linha < 3 ; linha++) {
    diagonal_principal += tabuleiro[linha][linha];
    diagonal_secundaria += tabuleiro[linha][3-linha-1];
  }
  if(diagonal_principal==3 || diagonal_principal==(-1)*3 ||
  diagonal_secundaria==3 || diagonal_secundaria==(-1)*3)
    return 1;
 
  return 0;
}
 
int Empate(int tabuleiro[3][3]) { //essa função checa se ainda existe o número 0 na matriz, caso não exista ele retorna o valor 1 para indicar que todas as casas estão preenchidas
  int linha, coluna;
  for(linha = 0 ; linha < 3 ; linha++)
    for(coluna = 0 ; coluna < 3 ; coluna++)
       if(tabuleiro[linha][coluna] == 0)
        return 0;
    return 1;
}
 
int Termino(int tabuleiro[3][3], int vez) { //caso qualquer das funções acima retornem 1, a função término também retorna 1, assim dando a vitória ao jogador da vez ou ocorre o empate
  if(Linha(tabuleiro)) {
    printf("\nJogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
    exibeTabuleiro(tabuleiro);
    return 1;
  }
  if(Coluna(tabuleiro)) {
    printf("\nJogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
    exibeTabuleiro(tabuleiro);
    return 1;
  }
  if(Diagonal(tabuleiro)) {
    printf("\nJogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
    exibeTabuleiro(tabuleiro);
    return 1;
  }
  if(Empate(tabuleiro)) {
    printf("\nJogo encerrado. Ocorreu um empate! !\n\n");
    exibeTabuleiro(tabuleiro);
    return 1;
  }
  return 0;
} //quando a função Termino retorna 1 voltamos a função principal e o programa recomeça
 
void jogada(int tabuleiro[3][3]) {
  int linha, coluna;
  vez++; //a cada jogada a variável 'vez' aumenta
  printf("\n--> Jogador %d \n", (vez % 2) + 1);
  do {
    printf("Linha: ");
    scanf("%d", &linha);
    linha--;
    printf("Coluna: ");
    scanf("%d", &coluna);
    coluna--;
    if(Local(tabuleiro, linha, coluna) == 0) //chama a função Local
      printf("Posicao ocupada ou inexistente, escolha outra.\n");
  } 
  while(Local(tabuleiro, linha, coluna) == 0);
  if(vez%2)//-> jogador 2
    tabuleiro[linha][coluna] = -1; //-1 aparece O
  else
    tabuleiro[linha][coluna] = 1; //1 aparece X
}