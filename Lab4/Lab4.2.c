//find a way to make this code a lot simpler

#include <stdio.h>

#define maxN 30

void rotate(int v[maxN], int storage[maxN], int n, int p, int dir);

int main() {
    int n, m, dir, p;
    int i = 0;
    int v[maxN], storage[maxN];


    printf("Please write the number of elements for the vector\n");
    scanf("%d", &n);

    printf("Please choose the direction(-1 = right, 1= left):\n");
    scanf("%d", &dir);

    printf("Please choose the number of repetitions:\n");
    scanf("%d", &p);

    printf("Values:\n");
    while (i < n) {
        scanf("%d", &m);
        v[i] = m;
        storage[i] = m;
        i++;
    }


    rotate(v, storage, n, p, dir);


    return 0;
}


void rotate(int v[maxN], int storage[maxN], int n, int p, int dir) {

    int temp[n];
    int k = 0;


    switch (dir) {
        case 1:


            for (int i = p; i < n; i++) {
                temp[k] = v[i];
                k++;
            }

            for (int i = 0; i < p; i++) {
                temp[k] = v[i];
                k++;
            }

            for (int i = 0; i < n; i++) {
                v[i] = temp[i];
            }
            break;

        case -1:

            for (int i = 0; i < n; i++) {
                p = p % n;
                temp[(i + n - p * dir) % n] = v[i];
            }

            for (int i = 0; i < n; i++) {
                v[i] = temp[i];
            }
            break;
        default:
            perror("Direction is not specified correctly");
    }

    for (int i = 0; i < n; i++)
        printf("%d", v[i]);


}