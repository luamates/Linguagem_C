//SISTEMA DE AVALIAÇÃO DE EVENTO E PROJETOS.
//Os alunos (1000) devem dar uma nota cada no evento, e os jurados (5) devem avaliar os projetos (20).

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int evento[1000];
int projeto[20][5];

void verificarExibir(){
	int i, soma = 0;
	float media;
	
	for(i = 0 ; i < 1000 ; i++)
	{
		soma += evento[i];
	}
	media = soma/1000;
	printf("\n\nMédia das notas: %.2f. \n", media);
	system("pause");
	system("cls");
}

void Projetos(){
	int lin, col, soma = 0;
	float media;
	
	for(lin = 0 ; lin < 20 ; lin++)
	{
		for(col = 0 ; col < 5 ; col++)
		{
			soma += projeto[lin][col];
		}
		media = soma/5;
		printf("\n\nMédia do projeto %i: %.2f", lin+1, media);
		soma = 0;
	}
	printf("\n");
	system("pause");
	system("cls");
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	char opcao[1];
	int teste = 1, i, verificar, lin, col, zero;
	
	inicio:
	do
	{
			teste = 0;
			printf("E – Notas do evento – alunos \nP – Notas dos projetos - juízes \nS - Sair \n\nDigite a opção: ");
			scanf("%s", &opcao[1]);
			
			switch(opcao[1])
			{
				case 69:
					printf("\n\nInsira a avaliação de cada aluno (0 - 10): \n");
					for(i = 0 ; i < 1000 ; i++)
					{
						do
						{
							verificar = 0;
							printf("[ALUNO %i] Nota: ", i+1);
							scanf("%i", &evento[i]);
							if(evento[i] < 0 || evento[i] > 10)
							{
								printf("\nAvaliação inválida. \n");
								verificar = 1;
							}
						} while (verificar == 1);	
					}
					verificarExibir();
				break;
				
				case 80:
					printf("\n\nInsira a avaliação de cada item: \n");
					for(lin = 0 ; lin < 20 ; lin++)
					{
						for(col = 0 ; col < 5 ; col++)
						{
							do
							{
								verificar = 0;
								printf("[PROJETO %i | JUIZ %i]: ", lin+1, col+1);
								scanf("%i", &projeto[lin][col]);
								if(projeto[lin][col] == 0)
								{
									zero += 1;
								}
								if(projeto[lin][col] < 0 || projeto[lin][col] > 10)
								{
									printf("Avaliação inválida. \n");
									verificar = 1;
								}
							} while(verificar == 1);
						}
					}
					printf("\nQuantidade de notas ZERO: %i", zero);
					Projetos();
				break;
				
				case 83:
					return 0;	
				break;
				
				default:
					teste = 1;
					printf("\n\nOpção inválida. Entre novamente.\n");
					sleep(1);
			}
			system("cls");
			printf("\n\nConsulta finalizada. Retornando...\n");
			sleep(2);
			system("cls");
			opcao[1] = '\0';
	} while(1);
}
