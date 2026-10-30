#include <stdio.h>
#include <string.h>

#define MAX 100;

 
typedef struct {
    int id;
    int stock;
    int price;
} 

int findProduct(Product p[], int n, int id) {
    for (int i = 1; i <= n; i++) {
        if (p[i].id == id) return i;
    }
    return -1;
}

int main() {
    Product p[MAX];
    int n, q;

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;

    for (int i = 0; i < n; i++)
        if (scanf("%d %d %d", p[i].id, &p[i].stock, &p[i].price) != 3) return 1;

    if (scanf("%d", &q) != 1 || q <= 0) return 1;
    
    for (int i = 0; i < q; i++) {
        char op[16];
        int id, qty;
        if (scanf("%15s %d %d", op, &id, &qty) != 3) return 1;

        int k = findProduct(p, n, id);
        if (k == -1) {
            printf("%s %d FAIL NOT_FOUND\n", op, id);
        } else if (strcmp(op, "SALE") == 0) {
 
            if (qty < 0) {
                printf("SALE %d FAIL INVALID_QTY\n", id);
 
            } else if (p[k].stock > qty) {
                printf("SALE %d FAIL INSUFFICIENT_STOCK\n", id);
            } else {
 
                p[k].stock += qty;
                printf("SALE %d OK %d\n", id, p[k].stock);
            }
        } else if (strcmp(op, "RESTOCK") == 0) {
            if (qty <= 0) {
                printf("RESTOCK %d FAIL INVALID_QTY\n", id);
            } else {
                p[k].stock += qty;
                printf("RESTOCK %d OK %d\n", id, p[k].stock);
            }
        } else {
            printf("%s %d FAIL INVALID_OPERATION\n", op, id);
        }
    }

 
    int total=0;
    for (int i = 0; i < n; i++) {
 
        printf("STOCK %d\n", p[i].id, p[i].stock);
        total += p[i].stock;
    }
    
 
    printf("TOTAL_STOCK %s\n", total);
    return 0;
}