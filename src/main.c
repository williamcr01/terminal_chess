#include <stdio.h>
#include <string.h>

#include "include/hash_map.h"

#define CHESS_BOARD_SIZE 8
#define SPACES 10

size_t str_hash_func(void *key) {
    char *str = key;
    size_t hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

int str_key_cmp(void *key1, void *key2) { return strcmp(key1, key2); }

void initial_positions(hash_map_t *piece_pos) {
    // white pieces
    hash_map_insert(piece_pos, "A1", "WR");
    hash_map_insert(piece_pos, "B1", "WN");
    hash_map_insert(piece_pos, "C1", "WB");
    hash_map_insert(piece_pos, "D1", "WQ");
    hash_map_insert(piece_pos, "E1", "WK");
    hash_map_insert(piece_pos, "F1", "WB");
    hash_map_insert(piece_pos, "G1", "WN");
    hash_map_insert(piece_pos, "H1", "WR");
    hash_map_insert(piece_pos, "A2", "WP");
    hash_map_insert(piece_pos, "B2", "WP");
    hash_map_insert(piece_pos, "C2", "WP");
    hash_map_insert(piece_pos, "D2", "WP");
    hash_map_insert(piece_pos, "E2", "WP");
    hash_map_insert(piece_pos, "F2", "WP");
    hash_map_insert(piece_pos, "G2", "WP");
    hash_map_insert(piece_pos, "H2", "WP");

    // black pieces
    hash_map_insert(piece_pos, "A8", "BR");
    hash_map_insert(piece_pos, "B8", "BN");
    hash_map_insert(piece_pos, "C8", "BB");
    hash_map_insert(piece_pos, "D8", "BQ");
    hash_map_insert(piece_pos, "E8", "BK");
    hash_map_insert(piece_pos, "F8", "BB");
    hash_map_insert(piece_pos, "G8", "BN");
    hash_map_insert(piece_pos, "H8", "BR");
    hash_map_insert(piece_pos, "A7", "BP");
    hash_map_insert(piece_pos, "B7", "BP");
    hash_map_insert(piece_pos, "C7", "BP");
    hash_map_insert(piece_pos, "D7", "BP");
    hash_map_insert(piece_pos, "E7", "BP");
    hash_map_insert(piece_pos, "F7", "BP");
    hash_map_insert(piece_pos, "G7", "BP");
    hash_map_insert(piece_pos, "H7", "BP");
}

void init_chess_board() {
    int i, j;

    hash_map_t *piece_pos = hash_map_create(32, str_hash_func, str_key_cmp);
    initial_positions(piece_pos);

    for (i = 0; i < CHESS_BOARD_SIZE; i++) {
        for (j = 0; j < CHESS_BOARD_SIZE; j++) {
            if (j == 0) {
                printf("%*s%d ", SPACES, "", i + 1);
            }
            if (j < CHESS_BOARD_SIZE - 1) {
                printf("# ");
            } else {
                printf("#\n");
            }
            if (i == CHESS_BOARD_SIZE - 1 && j == CHESS_BOARD_SIZE - 1) {
                printf("%*s%s\n", SPACES + 2, "", "A B C D E F G H");
            }
        }
    }
}

int main() {
    init_chess_board();
    return 0;
}