/*	

	Name: ExplicandoBuscaSequencial.cpp
	Author: Miguel fernandes Santos 
	Date: 11/06/22 13:57
	Description: Explicando Busca sequencial
	
*/

// Includes:
# include <stdio.h> // biblioteca basica do C
# include <string.h> // biblioteca para utilizar função para vetor de char
# include <stdlib.h>  // biblioteca de funções gesrais
# include <locale.h> //necessário para usar setlocale


// ------------------------------------------------------------------------//


// inicio do main:
int main(){
	
	// Adiciona a acentuação brasileira:
	setlocale(LC_ALL, "Portuguese");
	
	// array:
	int MeuArray[] = {35, 17, 92, 8, -5, 40, 23, 71, 19, 27};
	
	// valor a procurar:
	int Valor = 0;
	
	// entrada do valor a procurar:
	printf("Digite o valor que deseja procurar: ");
	scanf("%d", &Valor);
	
	/*
	
		A busca sequencial é o tipo de busca mais simples, o objetivo dela é percorrer
		todo o array ate encontrar o valor procurado, quando encontrado ele sai do laço
		e retorna a posiçao ou algo equivalente necessario para sua situação.
	
	*/
	
	// percorrer o laço:
	for(int i = 0; i < sizeof(MeuArray) / sizeof(int); i++){

		// Verifica se o valor é igual:
		if(MeuArray[i] == Valor){
			
			// mostra que achou:
			printf("\nO %d foi encontrado no indice %d na posição %d\n\nPara isso foram realizados %d comparações.",Valor,i,i+1, i+1);
			
			// sai do laço:
			break;
			
		}else if(i == (sizeof(MeuArray) / sizeof(int)) - 1){ // verifica se esta na ultima posição:
			
			printf("Nao achou.\nforam realizados %d comparações.", sizeof(MeuArray) / sizeof(int)); // mostra que nao achou:
			
		}	 // fim do if
		
	}// fim do laço
	
}// fim do main
