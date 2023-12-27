#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern int errno;


void rot13(char str[]) {
    int case_type, idx, len;
    len = strlen(str);

    for (idx = 0; idx < len; idx++) {
        // Only consider alphabetic characters
        if (str[idx] < 'A' || (str[idx] > 'Z' && str[idx] < 'a') || str[idx] > 'z') {
            continue;
        }
        // Determine if the char is upper or lower
        if (str[idx] >= 'a') {
            case_type = 'a';
        } else {
            case_type = 'A';
        }
        str[idx] = (str[idx] + 13) % (case_type + 26);
        if (str[idx] < 26) {
            str[idx] += case_type;
        }
    }
}


int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Please specify an input file\n");
        return 0;
    }

    FILE *fp;
    int errnum;

    fp = fopen(argv[1], "r+");

    if (fp == NULL) {
        errnum = errno;
        fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
        exit(EXIT_FAILURE);
    }

    if (fseek(fp, 0, SEEK_END) != 0) {
        fprintf(stderr, "Error using fseek\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    int file_size = ftell(fp);

    if (file_size == -1) {
        fprintf(stderr, "Error using fseek\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    if (fseek(fp, 0, SEEK_SET) != 0) {
        fprintf(stderr, "Error using fseek\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    char buffer[file_size];
    fread(buffer, file_size, 1, fp);

    rot13(buffer);

    fp = freopen(NULL, "w", fp);
    if (fp == NULL) {
        errnum = errno;
        fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, file_size, 1, fp);

    fclose(fp);

    return 1;
}