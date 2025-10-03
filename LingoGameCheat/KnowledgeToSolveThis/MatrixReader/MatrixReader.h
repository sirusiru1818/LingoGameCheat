//
//  MatrixReader.h
//  LingoGameCheat
//
//  Created by U4cn on 10/3/25.
//

#ifndef MATRIX_READER_H
#define MATRIX_READER_H

#include <stdio.h>

// 행과 열 개수를 세고 결과를 반환하는 함수
// 성공: 0, 열 불일치/파일 에러: 1
int get_matrix_size(const char *filename, int *rows, int *cols);

#endif
