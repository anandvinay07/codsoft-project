#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // seed the random number generator
    int number = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess = 0;
    int guessAmount = 0;

    cout << "Guess a number between 1 and 100: " << endl;

    while (guess!= number) {
        cin >> guess;
        guessAmount++;

        if (guess < number) {
            cout << "Too low! Try again." << endl;
        } else if (guess > number) {
            cout << "Too high! Try again." << endl;
        }
    }

    cout << "Congratulations! You guessed the correct number in " << guessAmount << " attempts." << endl;

    return 0;
}