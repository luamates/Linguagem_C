/*
Desenvolva uma aplicação que recebe os votos de 3 candidatos a prefeitura de uma cidade.

O total de eleitores deverá ser informado antes da votação, que deverá ser um valor maior
ou igual a 1, obrigatoriamente. ( 1 ponto)

Ao iniciar a votação o eleitor deverá votar em um dos candidatos, branco ou nulo usando um
valor inteiro de sua escolha. Para votar necessáriamente o eleitor deve digitar um valor inteiro.
Caso o voto realizado seja inválido, mostrar uma mensagem de erro e receber o voto novamente. ( 2 pontos)

O candidato vencedor deverá ter pelo menos mais que 50% dos votos válidos, votos brancos e nulos não
são considerados votos válidos. (1 ponto)

Caso tenha um candidato com mais do que 50% dos votos válidos imprimir o número desse canditado, caso
contrário  imprimir a mensagem: “Realizar uma nova eleição”. (2 pontos)

No final da votação mostrar o candidato vencedor (caso tenha) ou a informação "Realizar uma nova eleição" 
e finalizar a aplicação. (2 pontos)

No final da votação mostrar o percentual de votos de cada candidato e o percentual de votos nulos e brancos.
O percentual é em relação a todos os votos realizados. ( 2 pontos)
*/

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int eleitores, i, voto, marcio = 0, antonio = 0, joaquim = 0, branco = 0, nulo = 0;
	float pmarcio, pantonio, pjoaquim, pbranco, pnulo, pmarciogeral, pantoniogeral, pjoaquimgeral; //a letra "p" no início indica "porcentagem".
	
	printf("Bem vindo ao sistema URNA MAX, por Lucas Amates de Oliveira.");
	
	do
	{
		printf("\nInsira a quantidade de eleitores existentes na cidade: ");
		scanf("%i", &eleitores);
		
		if(eleitores < 1)
		{
			printf("\n\n[ERRO] Insira um número maior que zero.");
		}
	} while (eleitores < 1);
	
	for(i = 0 ; i < eleitores ; i++)
	{
		do
		{
			printf("\n\n[ELEITOR %i]", i + 1); //numero do eleitor
			printf("\n\nPor favor, insira seu voto: \n(1) Dr. Márcio Nunes   (2) Antônio da mercearia   (3) Professor Joaquim   (4) Voto branco   (5) Voto nulo \nMeu candidato: ");
			scanf("%i", &voto);
			
			if(voto < 1 || voto > 5)
			{
				printf("\n\n[ERRO] Voto inválido. Insira o voto novamente: \n\n");
			}
			
		} while (voto < 1 || voto > 5);
		
		if(voto == 1)
		{
			marcio += 1;
		}
		else
		{
			if(voto == 2)
			{
				antonio += 1;
			}
			else
			{
				if(voto == 3)
				{
					joaquim += 1;
				}
				else
				{
					if(voto == 4)
					{
						branco += 1;
					}
					else
					{
						nulo += 1;
					}
				}
			}
		}
	}
	
	//Contagem dos votos #porcentagem votos validos
	
	pmarcio = marcio * 100 / (marcio + antonio + joaquim);
	pantonio = antonio * 100 / (marcio + antonio + joaquim);
	pjoaquim = joaquim * 100 / (marcio + antonio + joaquim);
	
	pmarciogeral = marcio * 100 / eleitores;
	pantoniogeral = antonio * 100 / eleitores;
	pjoaquimgeral = joaquim * 100 / eleitores;
	pbranco = branco * 100 / eleitores;
	pnulo = nulo * 100 / eleitores;
	
	printf("\n\n========================================================================== \n[ANÁLISE DOS DADOS]\n\n");
	
	if(pmarcio > 50 || pantonio > 50 || pjoaquim > 50)
	{
		if(pmarcio > pantonio && pmarcio > pjoaquim)
		{
			printf("Candidato vencedor da eleição:  Dr. Márcio Nunes.");
		}
		else
		{
			if(pantonio > pmarcio && pantonio > pjoaquim)
			{
				printf("Candidato vencedor da eleição:  Antônio da Mercearia.");
			}
			else
			{
				printf("Candidato vencedor da eleição:  Professor Joaquim");
			}
		}	
		
	}
	else
	{
		printf("\n[ERRO] Como não houve nenhum candidato com mais de 50%% dos votos válidos, o sistema não pôde finalizar a operação. \nRealize uma nova eleição.");
	}
	
	printf("\n\nCANDIDATO     PERCENTUAL \n------------------------ \nDr. Márcio    %.2f%% \nAntônio       %.2f%% \nJoaquim       %.2f%% \n\nVOTOS INVÁLIDOS \nBranco        %.2f%% \nNulo          %.2f%%", pmarciogeral, pantoniogeral, pjoaquimgeral, pbranco, pnulo);	

	
	return 0;
}
