#include <stdio.h>

#define ARRAYMAX 62

int main(void) {
	char ch[100];
	int charray[ARRAYMAX];
	int countar[ARRAYMAX];
	int n = '0';
	int c = 'A';
	int l = 'a';
	int wc = 0;

	for (int i = 0; i < ARRAYMAX; i++) {
		countar[i] = 0;
		if (i < 10) {
			charray[i] = n++;
		} else if (i < 36) {
			charray[i] = c++;
		} else {
			charray[i] = l++;
		}
	}
	printf("Insert string:");
	fflush(stdout);
	fgets(ch, 100, stdin);

	while(ch[wc] != '\0') {
		for (int i = 0; i < ARRAYMAX; i++) {
			if ((int)ch[wc] == charray[i]) {
				countar[i]++;
				break;
			}
		}
		wc++;
	}

	for (int i = 0; i < ARRAYMAX; i++) {
		printf("%c | ", charray[i]);
		for(int j = 0; j < countar[i]; j++) {
			printf("+");
		}
		printf("\n");
	}

	int max = 0;
	for (int i = 0; i < ARRAYMAX; i++) {
		if(countar[i] > max) {
			max = countar[i];
		}
	}

	while(max) {
		printf("%d | ", max);
		for (int i = 0; i < ARRAYMAX; i++) {
			if(countar[i] >= max) {
				printf("  +");
			} else {
				printf("   ");
			}
		}
		printf("\n");
		max--;
	}
	printf("  ----");
	for(int i = 0; i < ARRAYMAX; i++) {
		printf("---");
	}
	printf("\n");
	printf("    ");
	for(int i = 0; i < ARRAYMAX; i++) {
		printf(" %2c", charray[i]);
	}

	return 0;
}
