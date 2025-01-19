#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*
    .1-74 Numbers to be in card
    .24 Numbers to match excluding fck middle
    .48 Numbers to be drawn
*/

// Random matrix
void randomBingoCard(int matrix[5][5]){
    int usedNumbers[75] = {0}; // Numbers to 1 - 74
    int randomNumber;

    // Rows
    for(int i = 0; i < 5; i++){
        // Columns
        for(int j = 0; j < 5; j++){
            if(i == 2 & j == 2){ // middle of matrix
                matrix[i][j] = 0;
                continue;
            }
            // Unique numbers 1 to 74
            do {
                randomNumber = rand() % 74 + 1;
            }while (usedNumbers[randomNumber]);

            matrix[i][j] = randomNumber;
            usedNumbers[randomNumber] = 1; // mark number as used
        }

    }


}

// Testing matrix :)
void displayMatrix(int matrix[5][5]){
    printf("Sua cartela de Bingo: \n");

    printf("===================\n");
    // Rows
    for(int i = 0; i < 5; i++){
        printf("||"); // Left border
        // Columns
        for(int j = 0; j < 5; j++){
            printf("%-2d ", matrix[i][j]);
        }
        printf("||\n"); // Right border
    }
    printf("===================\n\n");
}

// Drawing random number 1 to 74
int drawNumber(int drawnNumbers[75]){
    int randomNumber;
    do{
        randomNumber = rand() % 74 + 1;
    }while (drawnNumbers[randomNumber]);

    drawnNumbers[randomNumber] = 1;
    return randomNumber;
}

int main()
{
    srand(time(0)); // Allowing 'Randomness' by setting seed to time
    int cartelaDeBingo[5][5];
    int drawnNumbers[75] = {0};
    int numbersToDraw = 48; // Qnt of numbers to be drawn
    int matches = 0;

    randomBingoCard(cartelaDeBingo);
    displayMatrix(cartelaDeBingo);

    // Drawing each x secondsb
    for(int i = 0; i < numbersToDraw; i++){

        int drawn = drawNumber(drawnNumbers);

        // Check for matches
        for(int row = 0; row < 5; row++){
            for(int column = 0; column < 5; column++){
                if(cartelaDeBingo[row][column] == drawn){
                    matches++;
                    printf("%d. Numero sorteado: %d | Parabens, voce tem %d/24\n", i+1, drawn, matches);

                    goto next_draw;
                }
            }
        }

        // If dont match
        printf("%d. Numero sorteado: %d\n", i+1, drawn);
        next_draw:;
        usleep(300000); //300,000 microseconds
    }

    if(matches == 24){
        printf("\nParabens voce ganhou NO BINGO SENA DA VIRADA DO UTIDOLAS MEU/MINHA GOSTOSO(A)!!!");
    }else{
        printf("\nVC TEVE %d/24 PERDEU PERDEU KKKKKKKKKKK UUUUH PRA ELE GENTEE UUUUUH", matches);
    }

    return 0;
}
