#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#pragma warning(disable:4996)

//thousand.bin five-hundred.bin
int main() {
	FILE *fa, *fb;
	uint32_t na = 0, nb = 0, sum = 0;

	fa = fopen("thousand.bin", "r");
	if (fa == NULL) {
		printf("file a error\n");
		return 1;
	}
	fread(&na, sizeof(na), 1, fa);
	fclose(fa);
	uint32_t n_na = ntohl(na);

	fb = fopen("five-hundred.bin", "r");
	if (fb == NULL) {
		printf("file b error\n");
		return 1;
	}
	fread(&nb, sizeof(nb), 1, fb);
	fclose(fb);
	uint32_t n_nb = ntohl(nb);

	sum = n_na + n_nb;
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", n_na, n_na, n_nb, n_nb, sum, sum);

	return 0;
}

