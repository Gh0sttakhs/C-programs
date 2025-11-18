/* File: squarefree.c */

/* Counts square-free numbers in a range */

#include <stdio.h>
#include <math.h>

// Συνάρτηση που ελέγχει αν ένας αριθμός είναι square-free
int is_square_free(int n) {
    if (n <= 0) return 0;
    
    int temp = n;
    int factor = 2;
    
    while (factor * factor <= temp) {
        int count = 0;
        
        // Μετράμε πόσες φορές διαιρείται ο αριθμός με τον τρέχοντα παράγοντα
        while (temp % factor == 0) {
            count++;
            temp /= factor;
            // Αν διαιρεθεί περισσότερες από 1 φορά, δεν είναι square-free
            if (count > 1) {
                return 0;
            }
        }
        
        // Βελτιστοποιημένη αλλαγή παραγόντων (όπως στο αρχικό πρόγραμμα)
        if (factor == 2) {
            factor = 3;
        }
        else if (factor % 6 == 1) {
            factor += 4;
        }
        else {
            factor += 2;
        }
    }
    
    return 1;  // Square-free
}

int main() {
    int minnum, maxnum, num;
    int count = 0;
    
    printf("Please, give minimum number: ");
    scanf("%d", &minnum);
    printf("Please, give maximum number: ");
    scanf("%d", &maxnum);
    
    printf("Square-free numbers between %d and %d:\n", minnum, maxnum);
    
    for (num = minnum; num <= maxnum; num++) {
        if (is_square_free(num)) {
           // printf("%d ", num);
            count++;
            
            // Νέα γραμμή κάθε 10 αριθμούς για καλύτερη εμφάνιση
            if (count % 10 == 0) {
               // printf("\n");
            }
        }
    }
    
    printf("\n\nTotal square-free numbers: %d\n", count);
    
    return 0;
}
