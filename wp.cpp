#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{

    srand(time(NULL));

    bool run = true;
    string blank;
    int tries = 0;

    vector<string> words{
        "hello",
        "thing",
        "whale",
        "soare",
        "level",
        "gates",
    };

    string answer;
    int num = rand() % words.size();

    for (std::vector<string>::size_type i = 0; i != words.size(); i++)
    {
        answer = words[num];
    }

    for (int i = 0; i < answer.length(); ++i)
    {
        blank += "_";
    }

    cout << "This is a wordle clone" << endl;

    while (run && tries <= 5)
    {
        // formatting shit
        cout << "\n";
        cout << endl;
        cout << "\n";
        cout << "\n";

        string guess;

        cout << "Tries: " << tries << endl;
        cout << "Enter Word: ";
        cin >> guess;

        if (guess.length() != 5)
        {
            cout << "Has to be 5 letters" << endl;
        }
        else if (tries > 5)
        {
            cout << "Exceeded maximum tries" << endl;
            run = false;
        }
        else if (guess == answer)
        {
            cout << "CORRECT" << endl;
            run = false;
        }
        // clean input
        else
        {
            ++tries;
            cout << "Letters correct: ";
            int correct = 0;
            for (int i = 0; i < answer.length(); ++i)
            {
                if (guess[i] == answer[i])
                {
                    ++correct;
                    cout << answer[i];
                }
                else
                {
                    cout << "_";
                }
            }
            cout << endl;
        }
    }
}
