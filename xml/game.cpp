#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to select a word based on category
string select_word(int category) {
    if (category == 1) return "banana";       // Fruits
    else if (category == 2) return "germany"; // Countries
    else if (category == 3) return "jupiter"; // Planets
    else if (category == 4) return "guitar";  // Instruments
    else if (category == 5) return "swahili"; // Languages
    return "";
}

// Function to display the current status of the guessed word
void display_word(const string& word, const string& guessed_letters) {
    for (int i = 0; i < word.length(); ++i) { // Traditional for loop
        char letter = word[i];
        if (guessed_letters.find(letter) != string::npos) {
            cout << letter;
        } else {
            cout << '_';
        }
    }
    cout << endl;
}

// Function to play the game
void play_game(int category) {
    string word = select_word(category);
    string guessed_letters;
    int chances = 6;
    cout << "Guess the word! You have " << chances << " chances." << endl;
    while (chances > 0) {
        display_word(word, guessed_letters);
        cout << "Enter a letter (or type 'exit' to quit): ";
        string input;
        cin >> input;

        // Check if the user wants to exit
        if (input == "exit") {
            cout << "Thanks for playing!" << endl;
            return;
        }

        // Check for single letter input
        if (input.length() != 1) {
            cout << "Please enter a single letter." << endl;
            continue;
        }

        // Process the guessed letter
        char guess = input[0];
        if (guessed_letters.find(guess) == string::npos) {
            guessed_letters += guess;
            if (word.find(guess) == string::npos) {
                chances--;
                cout << "Wrong guess! You have " << chances << " chances left." << endl;
            } else {
                cout << "Good guess!" << endl;
            }
        } else {
            cout << "You already guessed that letter." << endl;
        }

        // Check if all letters have been guessed
        bool all_guessed = true;
        for (int i = 0; i < word.length(); ++i) { // Traditional for loop
            char letter = word[i];
            if (guessed_letters.find(letter) == string::npos) {
                all_guessed = false;
                break;
            }
        }
        if (all_guessed) {
            cout << "Congratulations! You've guessed the word: " << word << endl;
            return;
        }
    }
    cout << "You've run out of chances! The word was: " << word << endl;
}

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));
    char play_again;
    do {
        cout << "Select a category:\n1. Fruits\n2. Countries\n3. Planets\n4. Instruments\n5. Languages\n";
        int category;
        cin >> category;

        play_game(category);  // Pass the category to play_game

        cout << "Do you want to play again? (y/n): ";
        cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y');
    cout << "Thanks for playing!" << endl;
    return 0;
}

