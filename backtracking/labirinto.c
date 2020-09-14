#include<stdio.h>
#include <windows.h>
#define MAX 10

int M[MAX][MAX] = {88,88,88,88,88,88,88,88,88,88,
                   88,00,00,00,00,00,88,00,00,88,
                   88,00,88,88,00,00,88,00,00,88,
                   88,00,88,00,00,00,00,00,00,88,
                   88,00,88,00,00,00,88,00,00,88,
                   88,00,00,00,00,88,88,88,88,88,
                   88,00,00,00,00,88,00,00,00,88,
                   88,00,00,88,88,88,88,00,00,88,
                   88,00,00,00,00,00,88,00,00,88,
                   88,88,88,88,00,88,88,88,88,88 };

void imprimeLabirinto(int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
                if (M[i][j] == 88) printf(" XX");
                if (M[i][j] == 00) printf(" %02d", M[i][j]);
                if ((M[i][j] > 0)&&(M[i][j] != 88)) printf(" %02d", M[i][j]);
        }
        printf("\n\n");
    }
    //Sleep(500);
    system("pause");
    system("cls");
}

void obtemLabirinto(int *n, int *m, int *Li, int *Ci, int *Lf, int *Cf)
{
    int i, j, d;
    //printf("Dimens�es: Linha :");
    //scanf("%d",&n); /* dimensoes do labirinto */
    //printf("Dimens�es: Coluna :");
    //scanf("%d",&m); /* dimensoes do labirinto */

    *n = MAX;
    *m = MAX;
    //printf("Coordenada Inicial: Linha :);
    //scanf("%d",&Li); /* coordenadas da posicao inicial */
    //printf("Coordenada Inicial: Coluna :);
    //scanf("%d",&Ci); /* coordenadas da posicao inicial */

    *Li = 2;
    *Ci = 2;

    //printf("Coordenada Final: Linha :);
    //scanf("%d",&Lf); /* coordenadas da posicao inicial */
    //printf("Coordenada Final: Coluna :);
    //scanf("%d",&Cf); /* coordenadas da posicao inicial */

    *Lf = 10;  // lembre de n�o colocar uma parede nesta localiza��o
    *Cf = 5;

}
int labirinto(int deltaL[], int deltaC[], int Li, int Ci, int Lf, int Cf)
{
    int L, C, k, passos;
    if ((Li == Lf) && (Ci == Cf)) return M[Li][Ci];
    /* testa todos os movimentos a partir da posicao atual */
    for (k = 0; k < 4; k++)
    {
        L = Li + deltaL[k];
        C = Ci + deltaC[k];

        /* verifica se o movimento � valido e gera uma solucao factivel */
        if (M[L][C] == 0)
        {
            M[L][C] = M[Li][Ci] + 1;    // incrementa um passo
            imprimeLabirinto(MAX, MAX);
            passos = labirinto(deltaL, deltaC, L, C, Lf, Cf);
            if (passos > 0) return passos;
        }
    }
    return 0;
}
int main()
{
    int resposta, n, m, Li, Ci, Lf, Cf;
    /* define os movimentos validos no labirinto */
    int deltaL[4] = { 0, +1, 0, -1};
    int deltaC[4] = {+1, 0, -1, 0};

    /* obtem as informacoes do labirinto */
    obtemLabirinto(&n, &m, &Li, &Ci, &Lf, &Cf);
    M[Li - 1][Ci - 1] = 1;  /* define a posicao inicial no tabuleiro */

    /* tenta encontrar um caminho no labirinto */
    resposta = labirinto(deltaL, deltaC, Li - 1, Ci - 1, Lf - 1, Cf - 1);
    if (resposta == 0)
        printf("Nao existe solucao.\n");
    else
    {
        printf("\n\nExiste uma solucao em %d passos.\n\n\n", resposta);
        imprimeLabirinto(n, m);
    }
    return 0;
}

