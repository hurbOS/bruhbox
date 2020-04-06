#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	int options[2] = {0};
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			char *argument = argv[i];
			int j = 0;
			char c = argument[j];
		        char error[] = "Unknown argument: -";
			if (c == '-') {
				j++;
				c = argument[j];
				switch(c) {
					case 'a': options[0] = 1;
					break;

					case 'l': options[1] = 1;
					default:
					    printf("%s%c\n", error, c);
					    return 1;

				}
		}	
		}
	}
	
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			char* name = dir->d_name;
			if (!options[0]) {
				if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
					continue;
			}
			printf("%s\n", dir->d_name);
			printf("%lu\n", dir->d_ino);
		}
	closedir(d);
	}
	return 0;
}

//TODO: FINISH -l OPTION
/*
char *findpermissions(char *name) {
	int returnval;
	char permissions[11] = "----------";
	returnval = access(name, R_OK);
	if (!returnval)
		permissions[0] = 1;

}
*/ 

