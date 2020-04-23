#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char buf[256] = {'\0'};
	int strptr = 0;
	for (int i = 1; i < argc; i++) {
		sprintf(buf, argv[i]);
		strptr +=  strlen(argv[i]);
		buf[strptr] = '\0';
		puts(buf);
	}
	return 0;
}
