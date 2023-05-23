#include <stdio.h>

void subSequences(int v[], int n);

int main() {
    int n, m;
    int i = 0;

    printf("Please write the number of elements for the vector\n");
    scanf("%d", &n);
    int v[n];

    printf("Values:\n");
    while (i < n) {
        scanf("%d", &m);
        v[i] = m;
        i++;
    }

    subSequences(v, n);


    return 0;
}


void subSequences(int v[], int n) {
    int counter = 0;


    for (int i = 0; i < n; i++) {
        if (v[i] != 0)
            counter++;

        if (v[i] == 0) {
            if (counter >= i) {
                for (int s = 0; s < i; s++) {
                    printf("%d", v[s]);

                }
                counter = 0;
                printf("\n");
            }

            if (counter < i) {
                for (int s = i - counter; s < i; s++) {
                    printf("%d", v[s]);
                }
                counter = 0;
                printf("\n");
            }

        }
    }
}