//
//  Square.c
//  LingoGameCheat
//
//  Created by U4cn on 10/3/25.
//
#include "MatrixReader.h"

int get_matrix_size(const char *filename, int *rows, int *cols) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    int tempCols = 0;
    int ch;
    int run = 0;
    *rows = 0;
    *cols = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch >= '0' && ch <= '9') {
            if (!run) {
                run = 1;
                tempCols++;
            }
        } else if (ch == ' ' || ch == '\t') {
            run = 0;
        } else if (ch == '\n') {
            run = 0;

            if (*cols == 0) {
                *cols = tempCols;
            } else if (tempCols != *cols) {
                fprintf(stderr, "열 개수가 맞지 않습니다: %d vs %d\n", *cols, tempCols);
                fclose(fp);
                return 1;
            }

            (*rows)++;
            tempCols = 0;
        }
    }

    if (tempCols > 0) {
        if (*cols == 0) {
            *cols = tempCols;
        } else if (tempCols != *cols) {
            fprintf(stderr, "열 개수가 맞지 않습니다: %d vs %d\n", *cols, tempCols);
            fclose(fp);
            return 1;
        }
        (*rows)++;
    }

    fclose(fp);
    return 0;
}
