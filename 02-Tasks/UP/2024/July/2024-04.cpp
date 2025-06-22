unsigned x = 8, y = 3;
while (x > 0) {
    if (x % y == 0) break;
    else x -= 1;
}
std::cout << x;