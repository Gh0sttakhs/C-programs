#include <stdio.h>

int main() {
    int proshmo = 1;
    long long max;
    double S = 0.0;  // Χρησιμοποιούμε double για ακρίβεια

    scanf("%lld", &max);

    for (long long i = 2; i <= max; i+=2) {
        // 1/i^2 = 1/(i*i) με double για να μην χάσουμε δεκαδικά
        S +=proshmo *  (1.0 /(i*(i+1)*(i+2)));
        proshmo *= (-1);  // Αλλάζει πρόσημο σε κάθε βήμα
    }

    printf("%.15lf\n", S);  // Εκτυπώνει με 15 δεκαδικά ψηφία
    return 0;
}
