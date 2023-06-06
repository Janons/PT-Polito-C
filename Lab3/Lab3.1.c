#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#define FIN "..//input.txt"
#define FOUT "output.txt"

int punctuation(int flag, char ch1, FILE *fout);


int main() {
    FILE *fin, *fout;
    int count;
    char current_char, previous_char;
    int punctuation_flag, capital_flag;

    //file parsing
    fin = fopen(FIN, "r");
    fout = fopen(FOUT, "w");
    if (fin == NULL) {
    }

    previous_char = fgetc(fin);

    do {
        current_char = fgetc(fin);
        if (isdigit(current_char)) {
            current_char = '*';
            fprintf(fout, "%c", current_char);

        }
        if (ispunct(previous_char)) {
            if (current_char == ' ' || current_char == '\n' || ispunct(current_char)) {
                punctuation_flag = 0;
            } else {
                punctuation_flag = 1;
                count++;
            }
        }
        punctuation(punctuation_flag, previous_char, fout);

        if (previous_char == '.' || previous_char == '!' || previous_char == '?') {
            capital_flag = 1;
            current_char = toupper(current_char);
            fprintf(fout, "%c", current_char);

        }



    } while (current_char != EOF);
    return 0;

}

int punctuation(int flag, char ch1, FILE *fout) {

    if (flag == 1) {
        fprintf(fout, "%c ", ch1);
    } else
        fprintf(fout, "%c", ch1);

}