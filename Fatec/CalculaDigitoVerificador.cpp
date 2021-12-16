//####################################################
//                                                   #
//    NOME: Miguel Fernandes Santos.                 #
//    DATA: 04/11/2021                               #
//    PROJETO: Digito Verificador.                   #
//                                                   #
//####################################################

# include <stdio.h>
# include <locale.h>
# include <string.h>
# include <stdlib.h>  

int calcula_dv(char palavra[]);

main(){
	
	// Variaveis do MAIN:	
	char palavra[31];
	int digito;
	
	// Adiciona gramatica:
	setlocale(LC_ALL, "Portuguese");

	// Mostra os integrantes:
	printf("----- Integrantes -----\n\n");
	printf(" 1 - Gabriela da Silva Limeira.\n 2 - Miguel Fernandes Santos\n 3 - Rachel Arruda Lima.");
	printf("\n\n----- Integrantes -----");
	
	// Laço de repetição principal:
	do {
	
		// Entrada da string:
		printf("\n\nDigite Fim para sair do programa!!");
		printf("\nEntre com uma string com valores decimais (maximo 30 caracteres): ");
		fgets(palavra, 31, stdin);
		palavra[strlen(palavra) - 1] = '\0';
		strlwr(palavra);
		fflush(stdin);
		
		// Verifica se é necessario sair:
		if (strcmp(palavra,"fim") == 0){ 
	
		    printf("Saindo...\n\n");
	
		}else{ // Se não:
				
			// Chama a função para calcular digito verificador:	
			digito = calcula_dv(palavra);
			
			if(digito != -1){ // Verifica se no valor digitado pode ser calculado o DV:
			
				printf("DV calculado com sucesso: %s-%d.", palavra, digito);
			
			}else{ // Se não:
				
				printf("Atenção!!! Valor informado inválido");	
				
			}
			
		}
		
	} while (strcmp (palavra,"fim") != 0);
	
}

//####################################################
//                                                   #
//    FUNÇÃO: Calcular o Digito Verificador.         #
//    RETORNO: Inteiro. (int)                        #
//    PARAMETROS: String. (char)                     #
//    DATA: 03/11/2021                               #
//                                                   #
//####################################################

int calcula_dv (char palavra[]){
	
	// Variaveis locais da função:
	char aux[3] = {'\0','\0','\0'};
	int num, i, multiplicador, soma;
	
	// Soma começa com -1:
	soma = -1;
	
	// Multiplicador com 2:
	multiplicador = 2;
	
	// Laço para percorrer o vetor da string:
	for( i = strlen(palavra) - 1; i >= 0; i--){
		
		// Analisar se é um numero baseado na tabela ASCII:
		if(palavra[i] >= 48 && palavra[i] <= 57){
			
			// Se for igual a -1:
			if (soma == -1){
				
				soma = 0;
				
			}
			
			aux[0] = palavra[i]; // Auxiliar recebe a letra atual do laço:
			num = atoi(aux); // Converte para inteiro:
			soma = soma + (num * multiplicador); // Faz o calculo do numero atual:
			multiplicador = multiplicador + 1; // Incrementa 1 no multiplicador:
			
		}
		
		// Se o multiplicador é maior que 9:
		if (multiplicador > 9){
			
			// Multiplicador retorna a 2:
			multiplicador = 2;
			
		}
		
	}
	
	// Se foi digitado um numero:
	if (soma != -1){
		
		// Faz o calculo do digito verificador:
		soma = soma * 10;
		soma = soma - ((soma / 11) * 11);
		
		// Se o digito verificador ser 10 então ele volta a ser 0:
		if (soma == 10){
			
			soma = 0;
			
		}
	
	}
	
	return soma;
	
}
