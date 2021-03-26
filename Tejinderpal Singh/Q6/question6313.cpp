
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

string secret_msg;
int max_matches = 0; // the highest number of matches
char BESTMATCH[32];  // to store the best match
int threshold = 1;
int stored_Tries;       //declaring all variables globally so that I can use them in all functions
char savedTries[5][32]; // array thats storing the best matches
bool solved = false;

string encrypt(string message, char *key)
{
    string encrypted_msg;
    for (int i = 0; i < message.length(); i++)
    {
        char x = (message[i] + key[i]) % 26; //encryption algorithm that encrypts the message that is passed through
        x += 'A';                            // (found the encryption algorithm for vigenere cipher on GeeksForGeeks )
        encrypted_msg += x;
    }
    return encrypted_msg;
}
string decrypt(string message, char *key)
{
    string decrypted_msg;

    for (int i = 0; i < message.length(); i++)
    {
        char x = (message[i] - key[i] + 26) % 26; //just a reversal of the encryption to unscramble the message

        x += 'A';

        decrypted_msg += x;
    }
    return decrypted_msg;
}
char *generate_Key(int z)
{ //function that returns a pointer to the new char array that was generated

    char *try_key = new char[32]; //making the new array

    if (z < 5) //if the threshold is less than 5, generate a new array and check it against the key
    {
        for (int i = 0; i < 32; i++)
        {
            try_key[i] = 'A' + rand() % 26; // filling the char array with random letters
        }
        return try_key;
    }

    else
    {
        char *try_key2 = new char[32];

        for (int i = 0; i < 32; i++)
        {
            try_key[i] = 'A' + rand() % 26; // if the threshold is above 5, then create a new char array andperform recombination with the other stored arrays
        }
        for (int i = 0; i < 32; i++)
        {
            savedTries[4][i] = try_key[i];

            try_key2[i] = savedTries[rand() % 5][i]; // % 5 because we are randomly choosing an array from the saved tries to mix with
        }
        return try_key2;
    }
}

int try_key(char *attempt, char *key)
{
    int counter = 0;

    for (int i = 0; i < 32; i++)
    {
        if (attempt[i] == key[i]) // checking if the current char matches the current char in the original key
        {
            counter++;
        }
    }

    if (counter > max_matches)
    {
        for (int i = 0; i < 32; i++)
        {
            BESTMATCH[i] = attempt[i];
        }
        max_matches = counter;
    }

    if (counter == 32) // there was an exact match
    {
        cout << "We have found a match that successfully decyrpts the secret message: " << decrypt(secret_msg, attempt);
        solved = true; // we have cracked the code
        return 0;
    }

    else if (counter > threshold)
    {
        for (int i = 0; i < 32; i++)
        {
            savedTries[stored_Tries % 5][i] = attempt[i]; //if the counter is above the threshold then perform recombination again
        }
        threshold++; //increase the threshold with each match
        stored_Tries++;
        return 1;
    }

    else
        return 2;
}
void printCharArray(char *a)
{
    for (int i = 0; i < 32; i++) // basic print function
    {
        cout << a[i];
    }
}

int main()
{
    srand(time(nullptr));
    int tries = 0;
    char *key_try = new char[32]; // making the new char array to pass through the function - generate_Key
    string message = "ILOVETOGOTOTHEBEACHWITHMYFRIEND";
    char KEY[32] = {'C', 'A', 'R', 'C', 'A', 'R', 'C', 'A', 'R', 'C', 'A', 'R', 'C', 'A', 'R', 'C', 'A', 'R', 'C', 'A', 'R', 'C', 'A', 'R', 'C', 'A', 'R', 'C', 'A', 'R', 'C'};
    secret_msg = encrypt(message, KEY); //secret_msg will hold the encryption

    cout << "The encrypted message is: " << secret_msg << endl;
    int tried;

    while (!solved) // keep going until solved is true
    {
        cout << "\nCurrent number of tries: " << tries << endl;
        tries++;
        if (tries > 100000) // setting the arbirtary limt to 25000
        {
            cout << "\nThe attempt limit has been exceeded, this was the best match: ";

            printCharArray(BESTMATCH);

            cout << "\nIf we try to decode the secret message with the best match, we get: " << decrypt(secret_msg, BESTMATCH) << endl;
            break; // printing the best match if the limit is reached and the code has not been cracked
        }

        key_try = generate_Key(threshold); // generating the key and storing it in key_try
        cout << "The random key that we generated : ";

        printCharArray(key_try);

        cout << endl
             << "Decrypted message using the generated key: " << decrypt(secret_msg, key_try);

        tried = try_key(key_try, KEY); //this will let the program know if the match was good, bad, or an exact match
        if (tried == 0)
        {
            continue; // if try_key returns the value 0, then the while loops begins from the start
        }
        else if (tried == 1)
        {
            cout << "\nThe generated key was a good match and therefore added to the list" << endl; // try_key returns 1 if the match was decent
        }
        else
        {
            cout << "\nThe generated key was not a good match and therefore it was not added to the list" << endl; // 0 for bad match
        }
    }
}