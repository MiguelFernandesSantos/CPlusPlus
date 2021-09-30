# include <stdio.h>
# include <locale.h>

main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int N1 = 0;
	int N2 = 0;
	int N3 = 0;
	int N4 = 0;
	int N5 = 0;

	int Soma = 0;
	int  Total = 0;
	double Media = 0;
	
	
	int X = 1;
	
	printf("| ----------------- Inicio ----------------- |\n");
	
		while (X != 0 ){
			
			printf("\n Entre com um valor inteiro positivo \n ou digite 0 (zero) para finalizar o programa: ");
			scanf("%d",&X);
			
			Soma = Soma + X;
			
				
			if(X == 0){
				
				printf("\nSaindo...\n");
			
			}else if(X < 0 ){
				
				printf(" O valor digitado é um numero negativo, por favor insira um novo numero.\n\n");
				
			}else if ( X >= 1 && X <= 9){
				
				N1 = N1 + 1;
				Total = Total + 1;
				
			}else if( X >= 10 && X <= 99){
				
				N2 = N2 + 1;
				Total = Total + 1;
				
			}else if ( X >= 100 && X <= 999){
				
				N3 = N3 + 1;
				Total = Total + 1;
				
			}else if ( X >= 1000 && X <= 10000){
				
				N4 = N4 + 1;
				Total = Total + 1;
				
			}else if( X > 10000){
				
				N5 = N5 + 1;
				Total = Total + 1;
				
			}
				
		}	
		
		printf("\n|-------------- Processamento -------------|\n");
		
		if (Total == 0){
			
			printf("\nAtenção !!!! Você não digitou nenhum número.\n");
			
		}else{
		
		Media = Soma / Total;
		
		printf("\n Você digitou %d números, sendo:\n", Total);
		printf("\n Você digitou %d números entre 1 e 9. \n", N1);
		printf("\n Você digitou %d números entre 10 e 99. \n", N2);
		printf("\n Você digitou %d números entre 100 e 999. \n", N3);
		printf("\n Você digitou %d números entre 1000 e 10000. \n", N4);
		printf("\n Você digitou %d números maiores que 10.000 \n", N5);
		
		printf("\n O cálculo da média dos números digitados é => %.2lf \n", Media);
		
		}
		
		printf("\n|------------------- FIM ------------------|\n");
		
}
