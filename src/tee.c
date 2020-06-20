#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
int main(int argc, char **argv) 
{
    FILE *outFile;
    static char *write = "w";
    static char *append = "a";
    char *mode = write;
    int opt;
    while ((opt = getopt(argc, argv, "a")) != -1) {
        switch (opt) {
            case 'a':
                mode = append; // more options to come
        }
    }
    if (optind >= argc) { // no file specified
        outFile = fopen("/dev/null", "w");
    } else {
        outFile = fopen(argv[optind], mode);
    }
    char c;
    while ((c = getchar()) != EOF) {
        fprintf(outFile, "%c", c);
        printf("%c", c);
    }
    return 0;
} 
