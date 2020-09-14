/*
 * Disciplina - ST067 - Complexidade de Algoritmos
 * Alunos - Matheus Percario Bruder
 *
 * Faculdade de Tecnologia da Unicamp
 */
 
 
#include <stdio.h>

// -------------------------------------------------------------------------------------------
// 		MAIN
// -------------------------------------------------------------------------------------------
void main() { 
    int v_desejado, resto, i, m, a, b, soma_parcial, moeda_selecionada;

	printf("==============================\n");
	printf("      PROBLEMA DO TROCO       \n");
	printf("==============================\n");
	
	printf("-> Valor de troco: R$"); 
    scanf("%d", &v_desejado); 
    
    printf("-> Quantidade de tipos de moedas: ");
    scanf("%d", &m);
    
    printf("\n\n");
    
    
    // Declarando Struct
    typedef struct money {
    	int valor;
    	int quant;
    	int usadas;
	} Dinheiro;
    
    Dinheiro moedas[m];
    Dinheiro aux;
    
    
	// Inicializando
	for(i = 0; i < m; i++) {
	    moedas[i].valor = 0;
	    moedas[i].quant = 0;
	    moedas[i].usadas = 0;
	}
    
    // Preenchendo struct
    for (i = 0; i < m; i++) { 
		printf("Valor da moeda: "); 
		scanf("%d", &moedas[i].valor); 
		
		printf("Quantidade de moeda: "); 
		scanf("%d", &moedas[i].quant); 
	} 
	
	
	// Ordenar struct
	for(a = 0; a < m; a++) {
        for(b = a; b < m; b++) {
            if(moedas[a].valor > moedas[b].valor) {
                aux = moedas[a];
                moedas[a] = moedas[b];
                moedas[b] = aux;
            }
        }
	}

	
	/*
	// Visualizar DEPOIS da ordenação
	for(i = 0; i < m; i++) {
	    printf("Moeda[%d].valor = %d\n", i, moedas[i].valor);
	    printf("Moeda[%d].quant = %d\n", i, moedas[i].quant);
	    printf("Moeda[%d].usadas = %d\n", i, moedas[i].usadas);
	}
	*/
	
	

	resto = v_desejado;
	moeda_selecionada = m - 1; // começa pela moeda de maior valor 
	while((resto != 0) && (moeda_selecionada >= 0)) { 
		if((resto >= moedas[moeda_selecionada].valor) && (moedas[moeda_selecionada].usadas < moedas[moeda_selecionada].quant) && (moedas[moeda_selecionada].quant > 0)) { 
			moedas[moeda_selecionada].usadas++;
			resto = resto - moedas[moeda_selecionada].valor;
		}
		else {	
			moeda_selecionada--;
		}	
	} 
	
	
	if(resto != 0){
		
		printf("\n\nOps... Nao foi possivel calcular a solucao otima!\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("    SOLUCAO OTIMA PARCIAL\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		
		
		// Totalizar a solução "otima parcial"
		soma_parcial = 0;
		for(i = 0; i < m; i++) {
			soma_parcial += moedas[i].usadas * moedas[i].valor;
		}
		printf("\nTroco Esperado: R$%d\n", v_desejado);
		printf("Troco Obtido:   R$%d\n", soma_parcial);
	}
	
	
	
	printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("      RELACAO DE NOTAS\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Valor Moeda | Usadas | Restante\n");
	for(i = 0; i < m; i++) {
		printf("    %d           %d        %d\n", moedas[i].valor, moedas[i].usadas, moedas[i].quant - moedas[i].usadas);
	}
}
