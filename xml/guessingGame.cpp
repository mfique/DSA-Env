#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

string selectRandomItem(const vector<string>& list) {
    srand(static_cast<unsigned int>(time(0)));
    int index = rand() % list.size();
    return list[index];
}

string revealWord(const string& word, const string& guesses) {
    string displayedWord = "";
    for (size_t i = 0; i < word.length(); ++i) {
        char character = word[i];
        if (guesses.find(character) != string::npos) {
            displayedWord += character;
        } else {
            displayedWord += '_';
        }
    }
    return displayedWord;
}

void startGame() {
    vector<string> petList;
    petList.push_back("cat");
    petList.push_back("dog");
    petList.push_back("bird");
    petList.push_back("lion");
    petList.push_back("tiger");
    petList.push_back("panda");

    vector<string> sportTeams;
    sportTeams.push_back("Real Madrid");
    sportTeams.push_back("Barcelona");
    sportTeams.push_back("Manchester United");
    sportTeams.push_back("Liverpool");
    sportTeams.push_back("Bayern Munich");
    sportTeams.push_back("Manchester City");

    vector<string> regions;
    regions.push_back("Gasabo");
    regions.push_back("Nyabihu");
    regions.push_back("Nyarugenge");
    regions.push_back("Musanze");
    regions.push_back("Burera");
    regions.push_back("Bugesera");

    vector<string> movies;
    movies.push_back("Avengers");
    movies.push_back("Sweet Home");
    movies.push_back("Lucifer");
    movies.push_back("Legacies");
    movies.push_back("Welcome to Waikiki");

    vector<string> novels;
    novels.push_back("Harry Potter");
    novels.push_back("Darkest Temptation");
    novels.push_back("Love of Lycan");
    novels.push_back("Hellbound with You");
    novels.push_back("Error 404");

    cout << "Choose a category:\n";
    cout << "1. Pets\n";
    cout << "2. Sports Teams\n";
    cout << "3. Regions\n";
    cout << "4. Movies\n";
    cout << "5. Novels\n";

    int userChoice;
    cin >> userChoice;

    vector<string> selectedCategory;
    switch (userChoice) {
        case 1:
            selectedCategory = petList;
            break;
        case 2:
            selectedCategory = sportTeams;
            break;
        case 3:
            selectedCategory = regions;
            break;
        case 4:
            selectedCategory = movies;
            break;
        case 5:
            selectedCategory = novels;
            break;
        default:
            cout << "Invalid selection. Exiting game.\n";
            return;
    }

    string secretWord = selectRandomItem(selectedCategory);
    string guessedChars = "";
    int remainingAttempts = 5;

    while (true) {
        cout << "Current word: " << revealWord(secretWord, guessedChars) << "\n";
        cout << "Attempts left: " << remainingAttempts << "\n";
        cout << "Guess a character: ";
        
        char guess;
        cin >> guess;

        if (!isalpha(guess)) {
            cout << "Enter a valid letter.\n";
            continue;
        }

        guess = tolower(guess);
        if (guessedChars.find(guess) != string::npos) {
            cout << "Letter already guessed.\n";
            continue;
        }

        guessedChars += guess;

        if (secretWord.find(guess) != string::npos) {
            if (revealWord(secretWord, guessedChars) == secretWord) {
                cout << "Congrats! You won. The word was: " << secretWord << "\n";
                return;
            }
        } else {
            remainingAttempts--;
            if (remainingAttempts == 0) {
                cout << "Game over. The word was: " << secretWord << ".\n";
                return;
            }
        }
    }
}
	
int main() {
    while (true) {
        startGame();
        cout << "Do you want to play again? (yes OR no): ";
        string replay;
        cin >> replay;
        if (replay != "yes") {
            break;
        }
    }
    return 0;
}

