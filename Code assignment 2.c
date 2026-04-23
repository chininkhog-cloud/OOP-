#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the seat map
void print_seat(int **seat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%02d ", seat[i][j]); 
        }
        printf("\n");
    }
}

int main() {
    int row = 10, col = 10;

    //Dynamically allocate 2D array
    int **seat = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++) {
        seat[i] = (int *)malloc(col * sizeof(int));
    }

    //Initialize all to 0
    for(int i = 0; i < row; i++) {
        memset(seat[i], 0, col * sizeof(int));
    }

    // Assign values
    seat[0][0] = 11;
    seat[0][3] = 24;
    seat[1][1] = 35;
    seat[2][5] = 47;
    seat[3][3] = 58;
    seat[4][9] = 69;
    seat[5][0] = 70;
    seat[5][5] = 81;
    seat[5][9] = 92;
    seat[6][4] = 13;
    seat[7][7] = 26;
    seat[8][2] = 39;
    seat[9][9] = 44;

    printf("[Original seat map]\n");
    print_seat(seat, row, col);

    //Create backup array
    int **backup = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++) {
        backup[i] = (int *)malloc(col * sizeof(int));
        memcpy(backup[i], seat[i], col * sizeof(int)); 
    }

    printf("\n[Backup seat map]\n");
    print_seat(backup, row, col);

    //Clear row 5 in original
    memset(seat[5], 0, col * sizeof(int));

    printf("\n[Original after clearing row 5]\n");
    print_seat(seat, row, col);

    printf("\n[Backup after original was modified]\n");
    print_seat(backup, row, col);

    //Find row with most assigned seats (in backup)
    int maxrow = 0, maxcount = 0;

    for (int i = 0; i < row; i++) {
        int count = 0;
        for (int j = 0; j < col; j++) {
            if (backup[i][j] != 0) {
                count++;
            }
        }

        if (count > maxcount) {
            maxcount = count;
            maxrow = i;
        }
    }

    printf("\n[Row with most assigned seats]\n");
    printf("Row: %d\n", maxrow);
    printf("Count: %d\n", maxcount);

    for (int i = 0; i < row; i++) {
        free(seat[i]);
        free(backup[i]);
    }
    free(seat);
    free(backup);

    return 0;
}