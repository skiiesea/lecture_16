#include <iostream>

char* dec_to_fib(int num) {
    static char result[64] = {0};
    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    int fib[64] = {0};
    fib[0] = 1;
    fib[1] = 2;

    int index_max_fib;

    for (int i = 2; fib[i - 1] <= num && i < 64; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        index_max_fib = i;
    }

    int i = 0;
    for(int j = index_max_fib; j >= 0; --j) {
        if (num >= fib[j]) {
            num -= fib[j];
            result[i++] = '1';
        } else {
            result[i++] = '0';
        }
    }
    result[i] = '\0';

    return result;
}
int main() {
    std::cout << "Enter a number: ";
    int n;
    std::cin >> n;
    char* res = dec_to_fib(n);
    std::cout << "base Fibonacci: " << res << std::endl;
    return 0;
}