#define N 4
#define BLOCKSIZE 2

void do_block(int n, int si, int sj, int sk, int *A, int *B, int *C)
{
    for (int i = si; i < si + BLOCKSIZE; i++){
        for (int j = sj; j < sj + BLOCKSIZE; j++){
            int cij = C[i + j * n];     //cij = C[i][j]
            for(int k=sk; k < sk + BLOCKSIZE; k++){
                cij += A[i + k * n] * B[k + j * n];     //A[i][k] * B[k][j]
            }
            C[i + j * n] = cij;
        }
    }
}

void dgemm(int n, int *A, int *B, int *C)
{
    for (int sj = 0; sj < n; sj += BLOCKSIZE)
        for (int si = 0; si < n; si += BLOCKSIZE)
            for (int sk = 0; sk < n; sk += BLOCKSIZE)
                do_block(n, si, sj, sk, A, B, C);
}

int A_array[4*4] = {
10, 10, 8, 9, \
6, 1, 5, 13, \
1, 8, 3, 5, \
9, 10, 4, 6 \
};

int B_array[4*4] = {
33, -13, 358, -319, \
116, 85, -239, -159, \
-779, 188, 29, 737, \
275, -246, -158, -124 \
};

int C_ref_array[4*4] = {
-2267, 10, 0, 0, \
-6, -2251, 0, 0, \
-1, 1, -2257, 0, \
-9, 9, 0, -2257 \
};

int C_array[4*4];

void matrix_mult()
{
    dgemm(N, A_array, B_array, B_array);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(C_array[i][j]!=C_ref_array[i][j]){
                printf("Error C and C_ref not equal");
                break;
            }
        }
    }
    return 0;
}