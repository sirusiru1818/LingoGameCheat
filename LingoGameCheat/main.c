//
//  main.c
//  LingoGameCheat
//
//  Created by U4cn on 10/2/25.
//

#include <stdio.h>
#include "MatrixReader.h"

int main(void) {
    int rows, cols;
    if(get_matrix_size("matrix.txt", &rows, &cols) != 0) {
        return 1;
    }
    
    printf("%d %d\n",rows,cols);
    
    return 0;
}
