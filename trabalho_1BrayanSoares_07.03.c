#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i, j, num, num_antes, cont;
    
    srand(time(NULL));
    
    int matriz[3][3], matriz_descon[6][6];
	
	/*= {
		{0, 1 ,0},
		{0, 1 ,0},
		{0, 1, 1}
	};*/
    
    for (i = 0; i < 3; i++) {
    	for (j = 0; j < 3; j++) {
          matriz[i][j] = rand() % 256;  
        }
   }

    printf("MATRIZ\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nRLE:\n");

    num_antes = matriz[0][0];  
    cont = 0;  

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) { 
            num = matriz[i][j];
			matriz_descon[i][j] = matriz[i][j];
			
            if (num == num_antes) {
                cont++; 
            } 
			else {
                printf("%d | %d  \n", cont, num_antes);
                num_antes = num; 
                cont = 1; 
            }
        }
    }
    printf("%d | %d\n", cont, num_antes);  
    
    printf("\n");
    printf("MATRIZ DESCOMPACTADA\n");
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz_descon[i][j]);
        }
        printf("\n");
    }
}

