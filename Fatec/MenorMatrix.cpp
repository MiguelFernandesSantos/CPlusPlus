# include <stdio.h>
# include <locale.h>
# include <stdlib.h>  

int saida (int *linha, int *coluna, int matrix[][2]);

main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int valores[2][2];
	int TamanhoColuna = 1;
	int Tamanholinha = 1;
	int retornado;
	int * p1 = &TamanhoColuna;
	int * p2 = &Tamanholinha;	
	
	for(int Coluna = 0; Coluna <= TamanhoColuna; Coluna++){
		
		for(int linha = 0; linha <= Tamanholinha; linha ++){
			
			printf("Digite o valor da linha %d da coluna %d :", linha + 1, Coluna + 1);
			scanf("%d",&valores[Coluna][linha]);
			printf("\n\n");
			
		}
	
	}
	
	saida(p2 , p1,	valores);
	
	printf("O menor numero é o: %d", valores[TamanhoColuna][Tamanholinha]);
	
}


int saida (int *linha, int *coluna, int matrix[][2]){
	
	// 0 = coluna | 1 = Linha
	int retorno[2];
	int menorvalor = 0;
	
	for(int ColunaInicio = 0; ColunaInicio <= *coluna; ColunaInicio++){
		
		for(int LinhaInicio = 0; LinhaInicio <= *linha; LinhaInicio++){
		
			if(menorvalor == 0){
				
				menorvalor = matrix[ColunaInicio][LinhaInicio];
				retorno[0] = ColunaInicio;
				retorno[1] = LinhaInicio;

			}else if(menorvalor > matrix[ColunaInicio][LinhaInicio]){
				
				menorvalor = matrix[ColunaInicio][LinhaInicio];
				retorno[0] = ColunaInicio;
				retorno[1] = LinhaInicio;
				
			}
			
		}
		
	}
	
	*coluna = retorno[0];
	*linha = retorno[1];
	
}
