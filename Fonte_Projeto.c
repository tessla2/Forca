#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>     
#include <locale.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define P 20  
#define L 16

void animacao(tentativas)
{
	switch (tentativas)
	{
	case 5:
		printf("\n    \n      *\n     ***\n    *****\n   ( @ @ )\n    | L |\n     <W>\n");
		break;
	case 4:
		printf("\n    \n       \n        \n         \n   ( @ @ )\n    | L |\n     <W>\n");
		break;
	case 3:
		printf("\n    \n       \n        \n         \n   ( @ @ )\n         \n     <W>\n");
		break;
	case 2:
		printf("\n    \n       \n        \n         \n   ( @ @ )\n         \n        \n");
		break;
	case 1:
		printf("\n    \n       \n        \n         \n   ( X X )\n         \n        \n");
		break;
	case 0:
		printf("\n    *********\n    *       *\n    * R.I.P *\n    *       *\n   ***********\n");
		break;
	}

}
void carinhaFeliz()
{
	printf("      *     *\n");
	printf("    *        *\n");
	printf("  *            *\n");
	printf(" *   O       O   *\n");
	printf(" *               *\n");
	printf("*     \\_____/     *\n");
	printf("  *              *\n");
	printf("    *          *\n");
	printf("      *      *\n");
}
void menu()
{
	printf("\n=========== Bem vindo! ============\n ");
	printf("\nEscolha uma das opções:\n ");
	printf("\n1-Jogar.");
	printf("\n0-Sair.\n");
	printf("\n===================================\n");
	printf("\n");
}
void menu2()
{
	printf("\n=================================\n");
	printf("\nEscolha uma das seguintes opções:\n");
	printf("\n1- Adivinhar letra.\n");
	printf("2- Adivinhar palavra.\n");
	printf("\n0- Sair.\n");
	printf("\n===================================\n");
}
void menu3()
{
	printf("\n===================================\n");
	printf("\nEscolha uma das opções:\n");
	printf("\n1-Voltar a jogar.");
	printf("\n0-Sair.\n");
	printf("\n===================================\n");
}
int sorteio()
{
	srand((unsigned)time(NULL));
	return rand() % 20;
}
iniciaJogo(char palavraJogada[L])
{
	for (int i = 0; i < strlen(palavraJogada); i++)
		palavraJogada[i] = '_';
}
void batota(char palavraSorteada[L], char palavraJogada[L], int idSorteado)
{
	int cheat;
	printf("\n=========Obrigada por jogar!:-)===========\n");
	printf("\nPrima 1 para sortear uma palavra oculta.\n");
	printf("\n==========================================\n");
	scanf(" %i", &cheat);
	system("cls");
	if (cheat == 2)
	{
		printf("Posição sorteada  :%d\n", idSorteado);
		printf("Palavra sorteada  :%s\n", palavraSorteada);
		printf("Palavra do jogo   :%s\n", palavraJogada);
	}
	if (cheat == 1)
		printf("\nPalavra do jogo   :%s\n", palavraJogada);
}
int main()
{
	setlocale(LC_ALL, "Portuguese");

	char palavrasTodas[P][L] = { "CACHORRO","FELINO","TARTARUGA", "PINGUIM", "GOLFINHO", "BRASIL", "PORTUGAL", "CHINA", "ARGENTINA", "ALEMANHA", "ESPANHA", "COMPUTADOR", "PASTEL", "TECLADO", "BALEIA", "ESPELUNCA", "BORBOLETA", "PAPAGAIO", "PASSARO", "BACALHAU" };
	char palavraSorteada[L];
	char palavraJogada[L];
	char palavraUser[L];
	char letrasUser[] = { "_ _ _ _ _" };
	char letrasUser2[] = { "_ _ _ _ _" };
	int idSorteado;
	int letraEncontrada;
	int tentativas;
	int acertos;
	char letra;
	int op;
	int op2;
	int n;

	menu();
	scanf(" %i", &op);
	system("cls");

	while (op == 1)
	{
		idSorteado = sorteio();
		strcpy(palavraSorteada, palavrasTodas[idSorteado]);
		strcpy(palavraJogada, palavrasTodas[idSorteado]);
		iniciaJogo(palavraJogada);
		batota(palavraSorteada, palavraJogada, idSorteado);
		tentativas = 5;
		acertos = 0;
		n = -2;

		while (tentativas > 0 && acertos < strlen(palavraSorteada))
		{
			menu2();
			scanf(" %i", &op2);
			system("cls");

			if (op2 == 0)
			{
				exit(0);
			}
			letraEncontrada = 0;
			if (op2 == 1)
			{
				printf("\nPalavra do jogo: %s\n", palavraJogada);
				printf("\nLetras incorretas: %s\n", letrasUser);
				printf("\nTentativas: %i\n", tentativas);
				animacao(tentativas);
				printf("\n=================================\n");
				printf("\nDigite uma letra: \n");
				scanf(" %c", &letra);
				system("cls");

				for (int i = 0; i < strlen(palavraSorteada); i++)
				{
					if (palavraSorteada[i] == toupper(letra) && palavraJogada[i] == '_')
					{
						palavraJogada[i] = toupper(letra);
						acertos++;
						letraEncontrada = 1;
					}
				}
				if (letraEncontrada != 1)
				{
					printf("\nLetra não encontrada.  %s\n", palavraJogada);
					tentativas = tentativas - 1;
					n = n + 2;
					letrasUser[n] = toupper(letra);
					printf("\nLetras incorretas: %s\n", letrasUser);
					printf("\nTentativas: %i \n", tentativas);
					animacao(tentativas);
					if (tentativas == 0)
						printf("    Game Over\n");
				}
				if (letraEncontrada == 1)
				{
					printf("\nLetra encontrada! %s \n", palavraJogada);
					printf("\nLetras incorretas: %s\n", letrasUser);
					printf("\nTentativas: %i\n", tentativas);
					animacao(tentativas);
					if (strcmp(palavraSorteada, palavraJogada) == 0)
					{
						system("cls");
						printf("\nParabéns! Palavra desvendada!\n");
						printf("\n      %s \n \n", palavraSorteada);
						carinhaFeliz();
					}
				}
			}
			if (op2 == 2)
			{
				printf("\nPalavra do jogo: %s\n", palavraJogada);
				printf("\nLetras incorretas: %s\n", letrasUser);
				printf("\nTentativas: %i\n", tentativas);
				animacao(tentativas);
				printf("\n=================================\n");
				printf("\nDigite uma palavra: \n");
				scanf(" %s", &palavraUser);
				system("cls");
				for (int i = 0; i < strlen(palavraUser); i++)
				{
					palavraUser[i] = toupper(palavraUser[i]);
				}
				if (strcmp(palavraUser, palavraSorteada) == 0)
				{
					printf("\nParabéns! Palavra desvendada!\n");
					printf("\n      %s \n \n", palavraSorteada);
					carinhaFeliz();
					acertos = strlen(palavraSorteada);
				}
				if (strcmp(palavraUser, palavraSorteada) != 0)
				{
					printf("\nPalavra incorreta.  %s\n", palavraJogada);
					printf("\nLetras incorretas: %s\n", letrasUser);
					tentativas = tentativas - 1;
					printf("\nTentativas: %i\n", tentativas);
					animacao(tentativas);
					if (tentativas == 0)
						printf("    Game Over\n");
				}
			}
		}
		strcpy(letrasUser, letrasUser2);
		menu3();
		scanf(" %i", &op);
		system("cls");
	}
	return 0;
}