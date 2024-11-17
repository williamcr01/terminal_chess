#include <stdio.h>

#define CHESS_BOARD_SIZE 8
#define SPACES 10

void init_chess_board() {
    int i, j;
    for(i = 0; i < CHESS_BOARD_SIZE; i++) {
        for(j = 0; j < CHESS_BOARD_SIZE; j++) {
            if(j == 0) {
                printf("%*s%d ", SPACES, "", i + 1);
            }
            if(j < CHESS_BOARD_SIZE - 1) {
                printf("# ");
            }else {
                printf("#\n");
            }
            if(i == CHESS_BOARD_SIZE - 1 && j == CHESS_BOARD_SIZE - 1) {
                printf("%*s%s\n", SPACES + 2, "", "A B C D E F G H");
            }
        }
    }
}

int main() {
    init_chess_board();
    return 0;
}