#include <stdio.h>

int main(int argc, char *argv[]) {
	char *bruh = "bruh\n";
	while (1)
		printf("%s", bruh); //infinite loop, as is standard for yes
	
	/* gnu yes is fucking crazy, it utilizes caching to minimize io bottlenecking and it can print 5.5gb of yesses in a second. arguably superior than dd if=/dev/zero for wiping drives lol */
	return 0;
}
