#include <stdio.h>

int main() {
    int proshmo = 1;
    long long max;
    double S = 0.0;  // Χρησιμοποιούμε double για ακρίβεια

    scanf("%lld", &max);

    for (long long i = 1; i <= max; i++) {
        // 1/i^2 = 1/(i*i) με double για να μην χάσουμε δεκαδικά
        S +=  (1.0 /(i*i*i*i));
        proshmo *= (-1);  // Αλλάζει πρόσημο σε κάθε βήμα
    }

    printf("%.15lf\n", S);  // Εκτυπώνει με 15 δεκαδικά ψηφία
    return 0;
}
