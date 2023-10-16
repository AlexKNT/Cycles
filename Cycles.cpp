#include <cstdio>

// Function to check if all digits in A are in B
bool isDigitsInNotation(int A, int B) {
    while (A != 0) {
        int digitA = A % 10;
        int tempB = B;
        bool digitFound = false;

        while (tempB != 0) {
            int digitB = tempB % 10;
            if (digitA == digitB) {
                digitFound = true;
                break;
            }
            tempB /= 10;
        }

        if (!digitFound) {
            return false;
        }

        A /= 10;
    }

    return true;
}

int main() {
    const int MAX_DIGITS = 10;  // Maximum number of digits in an integer
    int A, B;

    printf("Enter two integers A and B: ");
    scanf_s("%d %d", &A, &B);

    if (isDigitsInNotation(A, B) && isDigitsInNotation(B, A)) {
        printf("Each digit of A is in the notation of B and each digit of B is in the notation of A.\n");
    }
    else {
        printf("Not all digits of A are in the notation of B, or not all digits of B are in the notation of A.\n");
    }

    return 0;
}
