/*	

	Name: ExplicandoChar.cpp
	Author: Miguel fernandes Santos 
	Date: 10/06/22 10:23
	Description: Explicando Char
	
*/

// Includes:
# include <stdio.h> // biblioteca basica do C
# include <string.h> // biblioteca para utilizar função para vetor de char
# include <stdlib.h>  // biblioteca de funções gerais
# include <locale.h> //necessário para usar setlocale

// função principal do programa em C:
int main(){
	
	// Quantidade de bits que um char ocupa: 1 bit
	
	// Declaração de uma variavel do tipo char:
	char Letra;
	
	// Obs: Variaveis do tipo char servem basicamente para guardar
	// um unico caractere, como por exemplo 'a'.
	
	
	// -----------------------------------------------------------------//
	
	
	// Adiciona um unico char na variavel Letra:
	Letra = 'a';
	
	// Quando estamos atribuindo um unico caractere utilizamos das aspas
	// simples para realizar a atribuição
	
	
	// -----------------------------------------------------------------//
	
	
	// Mostrando o codigo ascii da letra:
	printf("Ascii da letra %c: %d\n\n",Letra, Letra);
	
	// Todo caractere possui um codigo anscii para o computador o identificar
	// no C é possivel retornar esse codigo fazendo um cast de Char
	// para inteiro.
	// O %d signfica que aquele espaço sera substituido por um numero,
	// como ao final passamos um char o C faz a conversão para o codigo
	// Ascii da letra.

	
	// -----------------------------------------------------------------//


	// declaração de um vetor de char:
	char Palavra[10];
	
	// Na linguagem C não existe string igual diversas outras linguagens
	// no lugar é utilizado os vetores de char, como um char guarda uma
	// letra, os vetores de char tem como objetivo guardar um conjunto
	// de char.
	
	
	// -----------------------------------------------------------------//
	
	
	// Adicionando valores em char:
	printf("Digite algo para o exemplo: ");
	gets(Palavra);
	
	// Gets é uma função que vem pronta dentro de algumas bibliotecas do C
	// Ela tem como objetivo ler o que é digitado pelo usuario e adicionar
	// na variavel em questão.
	// Parametro: Vetor de char
	
	// -----------------------------------------------------------------// 	
	
	
	// Mostra no console o valor da variavel palavra:
	printf("\n\nO que foi digitado: %s", Palavra);
	
	// Quando a gente quer exibir um vetor de char é utilizado dentro do
	// printf "%S" que basicamente é uma forma de dizer que aquele espaço
	// sera substituido por um vetor de string
	
	
	// -----------------------------------------------------------------// 	
	
	
	// Mostrando a quantide de char no seu vetor de char:
	printf("\nQuantidade: %d", strlen(Palavra));
	
	// A função pronta strlen tem como objetivo contar a quantidade de
	// caracteres que foram encontrados dentro de um vetor de char
	// OBS: Caracteres como espaço são contados tambem.
	// OBS2: Strlen contas os caracteres ate achar um '\0' que signfiica
	// o fim de um vetor de char.
	
	
	// -----------------------------------------------------------------// 	

	
}
