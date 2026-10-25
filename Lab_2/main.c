#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char wejscie = 0x15;

	//Wariant C
	{
		//char wejscie = 0x16;
		char wyjscie = 0;

		__asm {
			mov al, wejscie;
			cmp al, 0x16;
			jnz przeskocz_prawda;
			mov wyjscie, 0;
			jz koniec_if;
			przeskocz_prawda:
			mov wyjscie, 1;
			koniec_if:
		}

		printf("Wyjscie wariant C (cmp): %d\n", wyjscie);
	}



	//Wariant B
	{
		//char wejscie = 0x16;
		char wyjscie = 0;

		__asm {
			mov al, wejscie;
			sub al, 0x16;
			jnz isfalse;
			mov wyjscie, 0;
			jz close;
			isfalse:
			mov wyjscie, 1;
			close:
		}

		printf("Wyjscie wariant B (sub): %d\n", wyjscie);
	}


	//Wariant A
	{
		//char wejscie = 0x16;
		char wyjscie = 0;

		__asm {
			mov al, wejscie;
			add al, 0xEA;
			jnz isfalse_;
			mov wyjscie, 0;
			jmp close_;
			isfalse_:
			mov wyjscie, 1;
			close_:
		}

		printf("Wyjscie wariant A (add): %d\n", wyjscie);
	}


	return EXIT_SUCCESS;
}