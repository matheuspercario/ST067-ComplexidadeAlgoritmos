/*
 * Disciplina - ST067 - Complexidade de Algoritmos
 * Alunos - Matheus Percario Bruder
 *
 * Faculdade de Tecnologia da Unicamp
 */
 
 #include <stdio.h>
 
 /* Vetor global */
 int computed_fibs[100];
 
 
 /* Prototipos */
 int fib(int n);
 int fib_memo(int n);
 
 
// -------------------------------------------------------------------------------------------
// 		MAIN
// -------------------------------------------------------------------------------------------
int main(void) {
	unsigned long int num;
	printf("-----------------------------\n");
	printf("  FIBONACCI MEMOIZATION\n");
	printf("-----------------------------\n");
	printf("Digite um numero: ");
	scanf("%d", &num);
	printf("\n\n");
	printf("Fibonnaci de %d = %d\n", num, fib(num));
	
	return 0;
}

// -------------------------------------------------------------------------------------------
// 		FUNCOES
// -------------------------------------------------------------------------------------------

 int fib(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return fib_memo(n - 1) + fib_memo(n - 2);
	}
}


 int fib_memo(int n) {
	if(!computed_fibs[n]) {
		computed_fibs[n] = fib(n);
	}
	return computed_fibs[n];
}
