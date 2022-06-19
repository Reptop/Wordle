#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

void title()
{
   cout << R"(
 _       ______  ____  ____  __    ______
| |     / / __ \/ __ \/ __ \/ /   / ____/
| | /| / / / / / /_/ / / / / /   / __/   
| |/ |/ / /_/ / _, _/ /_/ / /___/ /___   
|__/|__/\____/_/ |_/_____/_____/______    
)" << '\n';

}

int main()
{

    srand(time(NULL));

    vector<string> words{
        "hello",
        "thing",
        "whale",
        "soare",
        "level",
        "gates",
        "abaca",
        "aback",
        "abada",
        "abaft",
        "aband",
        "abase",
        "abash",
        /*abate
        abbey
        abbot
        abdal
        abeam
        abear
        abele
        aberr
        abhal
        abhor
        abide
        abies
        abiko
        abime
        abler
        abnet
        abode
        aboma
        aboon
        abord
        abort
        about
        above
        abray
        abrus
        absis
        abuja
        abuna
        abuse
        abuzz
        abyme
        abysm
        abyss
*/
    };

    string answer;
    string blank;
    int tries = 0;
    bool run = true; 
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

    title();

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
                else if ("if ") {

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
