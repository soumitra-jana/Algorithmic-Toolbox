#include <iostream>

int get_change(int amount)
{
    int number_of_coins = 0;

    if (amount >= 10)
    {
        number_of_coins += amount / 10;
        amount %= 10;
    }

    if (amount >= 5)
    {
        number_of_coins += amount / 5;
        amount %= 5;
    }

    number_of_coins += amount;

    return number_of_coins;
}

int main()
{
    int amount;

    std::cin >> amount;
    std::cout << get_change(amount) << '\n';

    return 0;
}
