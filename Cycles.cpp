#include <cstdio>
#include <cstring>
#include <unordered_set>


void showDividers(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0) printf("%i\n", i);
    }
}

bool isPrime(int n)
{
    int count = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) count++;
    }
    return count == 0;
}

void showDigits(int n)
{
    while (n != 0)
    {
        printf("%i, ", n % 10);
        n /= 10;
    }
    printf("\n");
}

bool isDivided(int n)
{
    int d = n;
    while (d != 0)
    {
        int c = d % 10;
        if (c == 0 || n % c != 0) return false;
        d /= 10;
    }
    return true;
}

// Var. 14
// Function to check if two numbers have the same digits

bool haveSameDigits(const int A, const int B) {
    // Convert A and B to C-strings
    char strA[20];  // Assuming 20 is enough for A and B
    char strB[20];
    sprintf_s(strA, "%d", A);
    sprintf_s(strB, "%d", B);

    // Create sets to store unique digits for A and B
    std::unordered_set<char> setA, setB;

    // Populate setA with digits from A
    for (size_t i = 0; i < strlen(strA); ++i) {
        setA.insert(strA[i]);
    }

    // Populate setB with digits from B
    for (size_t i = 0; i < strlen(strB); ++i) {
        setB.insert(strB[i]);
    }

    // Check if the sets are equal
    return setA == setB;
}



void main()
{
    int N;
    printf("N = "); scanf_s("%i", &N);

    printf("\nDividers:\n");
    showDividers(N);

    printf("\nIs N prime?\n");
    if (isPrime(N)) printf("The number %i is prime number\n", N);
    else printf("The number %i is not prime number\n", N);

    // Uzd. 3
    printf("\nAll primes from 2 to %i\n", N);
    for (int i = 2; i <= N; i++)
    {
        if (isPrime(i))
        {
            printf("%i is a prime number\n", i);
        }
    }

    printf("\nDigits of %i:\n", N);
    showDigits(N);

    printf("\n");
    if (isDivided(N)) printf("The number %i is divided by all its digits\n", N);
    else printf("The number %i is not divided by all its digits\n", N);

    // Uzd. 4

    int A, B;
    printf("\nA = "); scanf_s("%i", &A);
    printf("B = "); scanf_s("%i", &B);

    printf("\nNumbers in the range %i to %i that are divided by each of their digits:\n", A, B);
    for (int i = A; i <= B; ++i)
    {
        if (isDivided(i))
        {
            printf("%i\n", i);
        }
    }

    // Majas darba, var. 14
    if (haveSameDigits(A, B)) {
        printf("\n%i and %d have the same digits.\n", A, B);
    }
    else {
        printf("\n%i and %d do not have the same digits.\n", A, B);
    }
}