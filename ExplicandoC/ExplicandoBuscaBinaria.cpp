/*	

	Name: ExplicandoBuscaBinaria.cpp
	Author: Miguel fernandes Santos 
	Date: 11/06/22 13:20
	Description: Explicando buscabinaria
	
*/


// ------------------------------------------------------------------------//


// Includes:
# include <stdio.h> // biblioteca basica do C
# include <string.h> // biblioteca para utilizar função para vetor de char
# include <stdlib.h>  // biblioteca de funções gesrais
# include <locale.h> //necessário para usar setlocale


// ------------------------------------------------------------------------//


// Prototipações:
void ordena(int *, int);


// ------------------------------------------------------------------------//


// inicio do main:
int main(){
	
	// Adiciona a acentuação brasileira:
	setlocale(LC_ALL, "Portuguese");
	
	// Declara um vetor que se inicia com alguns valores desorganizados:
	int MeuArray[] = {100,35, 17, 92, 8, -5, 40, 23, 71, 19, 27,92};
	
	// Chama a função ordena que execulta um buble no vetor:
	ordena(MeuArray,  sizeof(MeuArray) / sizeof(int));
	
	// Declara 4 variaveis:
	int inicio, fim, meio, Valor;
	
	// A variavel inicio se inicia com 0:
	inicio = 0;
	
	// A variavel fim se inicia com o ultimo indice do vetor: 
	fim = (sizeof(MeuArray) / sizeof(int)) - 1;
	
	// entrada do valor a procurar:
	printf("Digite o valor que deseja procurar: ");
	scanf("%d", &Valor);
	
	// começa um laço de repetição que continua ate inicio ser maior q fim:
	while(inicio <= fim){
		
		// A variavel meio recebe inicio mais o fim, e o resultado é divido
		// por 2:
		meio = (inicio + fim) / 2;
		
		
		/*
		
			utilizando do indice retornado anteriormente pelo calculo,
			ele faz uma verificação se a posição do vetor que aquele indice
			aponta é igual ao valor procurado
		
		*/
		if(MeuArray[meio] == Valor){ // se encontrou:
			
			// mostra o indice do vetor, junto posição
			printf("\n\nIndice: %d | posição %d\n\n", meio, meio + 1);
			break;
			
		}
		else if(MeuArray[meio] > Valor){
		/*
		
			utilizando do indice retornado anteriormente pelo calculo,
			ele faz uma verificação se a posição do vetor que aquele indice
			aponta é maior que o valor procurado
			essa verificação é feita para saber se o valor procurado se 
			encontra a direita:
		
		*/	
			
			// fim recebe meio - 1, fazendo com que o array seja quebrado
			// em duas partes:
			fim = meio - 1;
			
		}
		else if(MeuArray[meio] <= Valor){
		/*
		
			utilizando do indice retornado anteriormente pelo calculo,
			ele faz uma verificação se a posição do vetor que aquele indice
			aponta é menor ou igual que o valor procurado
			essa verificação é feita para saber se o valor procurado se 
			encontra a esquerda do indice:
		
		*/	
			
			// inicio recebe meio + 1, fazendo com que o array seja quebrado
			// em duas partes:	
			inicio = meio + 1;
			
		}// fim do if
		
	}// fim do while:
	
	// um laço so para exibir o vetor:
	for(int i = 0; i < (sizeof(MeuArray) / sizeof(int)); i++){
		
		// exibe o array por completo:
		printf("%d,", MeuArray[i]);	
		
	}// fim do for:
	
} // fim do main:


// ------------------------------------------------------------------------//


// função para ordenar um vetor de numeros:
void ordena(int *pont, int tam){
	
	// execulta um bublle:
	for(int i = tam - 1; i > 0 ; i--){
		
		for(int x = 0; x <= i; x++){
			
			if(pont[x] > pont[x + 1]){
				
				int aux = pont[x];
				pont[x] = pont[x +1];
				pont[x + 1] = aux;
				
			}
			
		}
		
	} // fim do buble:
	
}// fim da função ordena
