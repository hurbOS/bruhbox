#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// int strptr = 0;
	char yee[80] = {'\0'};
	// char *buf = malloc(80 * sizeof(int));

	if (argc > 1) {
		/*
		buf = argv[1];
		strptr = strlen(argv[1]);
		for (int i = 2; i < argc; i++) {
			buf[strptr++] = ' ';
			if ((strptr + strlen(argv[i])) >= 80) {
				printf("Error: 2 long 4 me");
				return 1;
			}
			buf = strcat(buf, argv[i]);
			strptr += strlen(argv[i]);
			}
	*yee = *buf; */ //figure out this pointer nonsense, otherwise just accept one arg for now
	snprintf(yee, strlen(argv[1])+1, argv[1]);
	if (argc > 2) {
		printf("Only one arg for now, sorry :(");
		return 1;
	}
	}
	else yee[0] = 'y';
	while(1) {
		printf("%s\n", yee); //infinite loop, as is standard for yes
	}
	/* gnu yes is fucking crazy, it utilizes caching to minimize io bottlenecking and it can print 5.5gb of yesses in a second. arguably superior than dd if=/dev/zero for wiping drives lol */
	return 0;
}
