#include <iostream>
int x, y, a, b;

void exgcd(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    } else {
        // x = y', y = x' - [a / b] * y'
        exgcd(b, a % b);
        int tmp = y;
        y = x - (a / b) * y;
        x = tmp;
    }
}

int main() {
    a = 6, b = 4;
    exgcd(6, 4);
    std::cout << x << " " << y;
    return 0;
}
