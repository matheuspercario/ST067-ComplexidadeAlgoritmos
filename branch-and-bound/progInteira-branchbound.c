#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <time.h>

#define TEMP 300
#define TEMP2 100

// VARIAVEIS GLOBAIS
int x1, x2;
int max_parcial=0;



// ===================================
int f_objetivo () // maximizar esta funcao
{
	int result;
	result = 6*x1 + 5*x2;
	if (result < max_parcial){
		return max_parcial;
	}
	else{
		return result;
	}
}

// ===================================
int f_restricao1() // funcao restricao 1
{
	int r1;
	r1 = 15*x1 + 7*x2;
	if (r1 > 49) { // limitante superior
		return 1; // nao obedece restricao
	}	
	else {
		return 0;
	}
}

// ===================================
int f_restricao2() // funcao restricao 2
{
	int r2;
	r2 = 2*x1 + 4*x2;
	if (r2 > 17) { // limitante inferior
		return 1; // nao obedece restricao
	}	
	else {
		return 0;
	}
}


// MAIN ===============================
int main(void)
{
	clock_t Ticks[2];

	int resp, x1_parcial, x2_parcial;
	
	// ponto de inicializacao
	Ticks[0] = clock();
	
	for(x1 = 1; x1 <= 6; x1++){
		for(x2 = 1; x2 <= 6; x2++){
			printf("x1 = [%d]\nx2 = [%d]\n\n", x1, x2);
			
			resp = f_restricao1();
			if(resp==1){
				Sleep(TEMP);
				printf("Restricao 1 nao atendida!\n");
				Sleep(TEMP);
				system("cls");
				break;
			}
			else{
				resp = f_restricao2();
				if(resp==1){
					Sleep(TEMP);
					printf("Restricao 2 nao atendida!\n");
					Sleep(TEMP);
					system("cls");
					break;
				}
				else{
					resp = f_objetivo();
					x1_parcial = x1;
					x2_parcial = x2;
					max_parcial = resp;
					printf("PARCIAL=%d\n\n", max_parcial);
				}
			}
			Sleep(TEMP2);
			system("cls");
		}	
	}
	
	// ponto de finalizacao
	Ticks[1] = clock();
	
	printf("============================\n");
	printf("  WITH - Branch and Bound\n");
	printf("============================\n");
	printf("x1 = [%d]\nx2 = [%d]\n\n", x1_parcial, x2_parcial);
	printf("============================\n\n");
	printf("SOLUCAO = %d\n", max_parcial);
	
	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("DURACAO = %.1f seg.", Tempo/1000);
    getchar();
    
	system("pause");
}
