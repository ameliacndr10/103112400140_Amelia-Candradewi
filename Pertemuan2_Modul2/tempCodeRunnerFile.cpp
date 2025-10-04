  //perkalian matriks 2x2
    for (int i = 0; i < 3; i++){
        for( int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                arrE[i][j] = arrA[i][k] * arrB[k][j];
            }
        }
    }