/*	

	Name: ExplicandoBuble.cpp
	Author: Miguel fernandes Santos 
	Date: 10/06/22 12:18
	Description: Explicando buble
	
*/

// Includes:
# include <stdio.h> // biblioteca basica do C
# include <string.h> // biblioteca para utilizar função para vetor de char
# include <stdlib.h>  // biblioteca de funções gesrais
# include <locale.h> //necessário para usar setlocale

// inicio do main:
int main(){

	// declaração de um vetor de inteiro com 3 valores:
	int Numeros[] = {5, 10, 3};
	
	
	// Laço para exibir os numeros:
        printf("Array desordenado:\n");
	for(int i = 0; i < sizeof(Numeros) / sizeof(int); i++){
		
		printf("| %d |", Numeros[i]);
		
	} // fim do laço:
	
	// O Buble Sort é uma forma de organizar um vetor em ordem crescente ou
	// descrecente.
	
	// Durante a explicação iremos exibir diversas vezes o valor do array:
	
	
	// --------------------------------------------------------------------//
	
	
	// Ordem dos numeros atualmente: 5, 10, 3
	
	// O buble sorte tem como objetivo fazer diversas comparações para que um
	// determinado valor seja movido para o fim ou inicio do vetor.
	
	// No exemplo a seguir tentaremos fazer com que os numeros fiquem em ordem
	// crescente:
	
	// Objetivo: 3, 5, 10
	
	// --------------------------------------------------------------------//
	
	
	// O buble utiliza de 2 laços de repetiçoes para realizar a ordenação.
	
	// O primeiro laço serve para percorrer o array do fim ate o indice 1:
	for(int i = (sizeof(Numeros) / sizeof(int))  - 1; i > 0; i--){
		
		//OBS: Caso nao entenda o SizeOf Verificar o arquivo com a sua explicação:
		
		// Explicação parametro 1: Pega o tamanho do vetor e subtrai
		// 1, apos isso guarda na variavel i
		// Explicação parametro 2: Enquanto i ser maior que 0
		// Explicação parametro 3: decremento da variavel i
		
		// Valores de i durante o laço:
		/*
		
			i = 2 <- primeira vez que o laço se inicia || Dentro da condição
			i = 1 <- segunda vez que o laço se inicia || Dentro da condição
			i = 0 <- Terceira vez que o laço se inicia || Fora da condição
		
		*/
		
		
		// Segundo laço para percorrer os valores do 0 ate a variavel i:
		for(int x = 0; x < i; x++){
			
			// Explicação parametro 1: declara X que se inicia em 0:
			// Explicação parametro 2: Enquanto x ser menor que i:
			// Explicação parametro 3: incremento do x:
			
			// Valores de X enquanto i = 2:
			/*
			
				x = 0 <- primeira vez que o laço se inicia || Dentro da condição
				Ordem dos numeros atualmente ao fim: 5, 10, 3
				
				x = 1 <- segunda vez que o laço se inicia || Dentro da condição
				Ordem dos numeros atualmente ao fim: 5, 3, 10
				
				x = 2 <- Terceira vez que o laço se inicia || Fora da condição
				
			*/	
			
			
			// -----------------------------------------------------------//

			
			// Valores de X enquanto i = 1:
			/*
			
				x = 0 <- primeira vez que o laço se inicia || Dentro da condição
				Ordem dos numeros atualmente ao fim: 3, 5, 10
				
				x = 1 <- segunda vez que o laço se inicia || Fora da condição
				
			*/
			

			// -----------------------------------------------------------//


			// Valores de X enquanto i = 0:
			/*
			
				x = 0 <- primeira vez que o laço se inicia || Fora da condição
				
			*/		
			
			
			// -----------------------------------------------------------//


			// Verifica se a posição X do vetor de numeros é maior que
			// a proxima posição do vetor:
			if(Numeros[x] > Numeros[x + 1]){
				
				// Declara uma variavel para auxiliar na troca de valores:
				// Variavel recebe a posição x do vetor de numeros:
				int aux = Numeros[x];
				
				// Posição x do vetor de numeros recebe o valor da proxima
				// posição:
				Numeros[x] = Numeros[x + 1];
				
				// a proxima posição recebe a variavel aux:
				Numeros[x + 1] = aux;
				
			}// fim do if
			
		}
		
	}
	
	
	// Laço para exibir os numeros:
        printf("\n\nArray ordenado:\n");
	for(int i = 0; i < sizeof(Numeros) / sizeof(int); i++){
		
		printf("| %d |", Numeros[i]);
		
	} // fim do laço:
	
}
