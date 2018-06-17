#include <stdio.h>
#include <string.h>

int main()
{
	char words[25];
	char words2[25];
	char array[5][25];
	char array2[5][25];
	int i;
	int j;

	i = 0; j = 0;

	printf("Plain text:PLEASANT INNOVATIONS!\n");
	printf("Encrypted text:");
	words[0] = 'P'; words[1] = 'L'; words[2] = 'E'; words[3] = 'A'; words[4] = 'S'; words[5] = 'A'; words[6] = 'N'; words[7] = 'T'; words[8] = ' '; words[9] = 'I';
	words[10] = 'N'; words[11] = 'N'; words[12] = 'O'; words[13] = 'V'; words[14] = 'A'; words[15] = 'T'; words[16] = 'I'; words[17] = 'O'; words[18] = 'N'; words[19] = 'S'; words[20] = '!';

	while (i <= 20)
	{

		array[j][i] = words[i];
		i = i + 1;
		j = j + 1;

		if (j > 4) {
			while (j != 0) {
				if (j == 5) {
					j = j - 2;
				}
				array[j][i] = words[i];
				i = i + 1;
				j = j - 1;
			}
		}
	}

	printf("%c", array[0][0]); printf("%c", array[0][8]); printf("%c", array[0][16]);
	printf("%c", array[1][1]); printf("%c", array[1][7]); printf("%c", array[1][9]); printf("%c", array[1][15]); printf("%c", array[1][17]);
	printf("%c", array[2][2]); printf("%c", array[2][6]); printf("%c", array[2][10]); printf("%c", array[2][14]); printf("%c", array[2][18]);
	printf("%c", array[3][3]); printf("%c", array[3][5]); printf("%c", array[3][11]); printf("%c", array[3][13]); printf("%c", array[3][19]);
	printf("%c", array[4][4]); printf("%c", array[4][12]); printf("%c", array[4][20]);

	i = 0; j = 0;

	printf("\n\nEncrypted text:S ETYTVNAAOAIW ERH\n");
	printf("Plain text:");

	words2[0] = 'S'; words2[1] = ' '; words2[2] = 'E'; words2[3] = 'T'; words2[4] = 'Y'; words2[5] = 'T'; words2[6] = 'V'; words2[7] = 'N'; words2[8] = 'A'; words2[9] = 'A';
	words2[10] = 'O'; words2[11] = 'A'; words2[12] = 'I'; words2[13] = 'W'; words2[14] = ' '; words2[15] = 'E'; words2[16] = 'R'; words2[17] = 'H';

	array2[0][0] = words2[0]; array2[0][8] = words2[1]; array2[0][16] = words2[2];
	array2[1][1] = words2[3]; array2[1][7] = words2[4]; array2[1][9] = words2[5]; array2[1][15] = words2[6]; array2[1][17] = words2[7];
	array2[2][2] = words2[8]; array2[2][6] = words2[9]; array2[2][10] = words2[10]; array2[2][14] = words2[11];
	array2[3][3] = words2[12]; array2[3][5] = words2[13]; array2[3][11] = words2[14]; array2[3][13] = words2[15];
	array2[4][4] = words2[16]; array2[4][12] = words2[17];

	i = 0; j = 0;

	while (i <= 17)
	{

		printf("%c", array2[j][i]);
		i = i + 1;
		j = j + 1;

		if (j > 4) {
			while (j != 0) {
				if (j == 5) {
					j = j - 2;
				}
				printf("%c", array2[j][i]);
				i = i + 1;
				j = j - 1;
			}
		}
	}


	return 0;

}