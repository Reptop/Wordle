#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;


string Generate_Word(vector<string> *words);
void Game_Logic(string chosenWord);
bool inGreen(vector<char> Green, char letter);
bool alreadyThere(vector<char> Yellow, vector<char> Blue, char letter);


int main() {
  vector<string> *words = new vector<string>();

  words->push_back("thing");

  cout << RED << "Welcome To Wordle!" << endl;
  cout << BOLDMAGENTA << "You should already know the rules" << endl;

  string random_word = Generate_Word(words);

  Game_Logic(random_word);


  return 0; 
}

string Generate_Word(vector<string> *words) {

  string chosenWord;

  for(vector<string>::size_type i = 0; i != words->size(); i++) {
    chosenWord = words->at(0); 
  }

  return chosenWord;
}

bool alreadyThere(vector<char> Yellow, vector<char> Green, char letter) {

  for (auto i : Yellow) {
    if (i == letter) {
      return true;
    }
  }

  return false;
}

bool inGreen(vector<char> Green, char letter) {
  for (auto i : Green) {
    if (i == letter) {
      return true;
    }
  }
  return false;
}

void Game_Logic(string chosenWord) {
  string input;
  bool run = true;

  vector<char> Green;
  vector<char> Yellow;
  vector<char> Black; 

  cout << "Current Word Status..." << endl;  

  for (int i = 0; i < chosenWord.length(); ++i) {
    cout << "__ ";
  }

  cout << endl;
  cout << "\n";

while (run) {
  
  cout << endl;
  cout << GREEN << "Enter Word: ";
  cin >> input;
  cin.clear();
  cin.ignore(100000, '\n');

  if (input.length() > 5 || input.length() < 5) {
    cout << "Your input should be 5 letters long." << endl;
  }
  else {
    for (int i = 0; i < chosenWord.length(); ++i) {
      cout << "__ ";
    }

    for (int i = 0; i <= input.length(); ++i) {
      for (int j = i; j <= chosenWord.length(); ++j) {
        if (input[i] == chosenWord[j] && alreadyThere(Yellow, Green, input[i]) == false) {
          Green.push_back(input[i]);
          }
        else if (input[i] != chosenWord[j] && chosenWord.find(input[i]) != string::npos && alreadyThere(Yellow, Green, input[i]) == false && inGreen(Green, input[i]) == false) {
            Yellow.push_back(input[i]);
          }
        else if (input[i] != chosenWord[j] && chosenWord.find(input[i]) != string::npos && alreadyThere(Yellow, Green, input[i]) == true) {
              continue;
            }
        else if (input[i] != chosenWord[j] && chosenWord.find(input[i]) == string::npos && alreadyThere(Yellow, Green, input[i]) == false) {
          Black.push_back(input[i]);
          //break;
        }
      }
    }
  }
      cout << endl;

      cout << GREEN << "Green Letters: "; 
      for(std::vector<char>::iterator it = Green.begin(); it != Green.end(); ++it) {
        cout << (*it) << " ";
      }

      cout << endl; 
      cout << "\n";

      cout << YELLOW << "Yellow Letters: ";
      for(std::vector<char>::iterator it = Yellow.begin(); it != Yellow.end(); ++it) {
        cout << (*it) << " ";
      }
      cout << endl;
      cout << "\n";
      
      cout << BLACK << "Black Letters: ";
      for(std::vector<char>::iterator it = Black.begin(); it != Black.end(); ++it) {
        cout << (*it) << " ";
      }

      Yellow.clear();
      Green.clear();
      Black.clear();
    }
  }
