/*	

	Name: ExplicandoPrintf.cpp
	Author: Miguel fernandes Santos 
	Date: 10/06/22 10:45
	Description: Explicando printf()
	
*/

// Includes:
# include <stdio.h> // biblioteca basica do C
# include <string.h> // biblioteca para utilizar função para vetor de char
# include <stdlib.h>  // biblioteca de funções gerais
# include <locale.h> // necessário para usar setlocale

int main(){
	
	// Esse arquivo tem como objetivo explicar o printf:
	
	// exibe uma informação no console:
	printf("Ira exibir isso no console.");
	
	
	// O printf tem como objetivo exibir um determinado valor no console
	// Entretanto ele possui diversas "ramificações" de certa forma,
	// como por exemplo
	
	// Exibe uma informação no console e substitui o %d por um numero:
	printf("Um valor inteiro: %d", 19);
	
	// O codigo acima teria como objetivo substituir o %d pelo numero 19
	// Quando a gente coloca dentro de um printf um % é como se estivessemos
	// falando para o C que aquele determinado espaço vai ser substituido
	// por um outro valor, que sera passado posteriormente.
	
	// Segue abaixo alguns exemplos mais usados de % dentro do printf:
	/*
	
		%c -> Pode ser substituido por um unico char
		%s -> pode ser substituido por um vetor de char
		%d -> pode ser substituido por um valor decimal
		%p -> pode ser substituido por um endereço de memoria
		
	*/	

}
