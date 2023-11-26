#include <iostream>
#include <string>
using namespace std;
class String_Encryption
{
private:
    string alphabets;
    string Key_Words;
    string encrypted_message;

public:
    String_Encryption()
    {
        alphabets = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        Key_Words = "zyxwvutsrqponmlkjihgfedcba ZYXWVUTSRQPONMLKJIHGFEDCBA";
    }
    void encrypt()
    {
        string secret_message;
        cout << "Enter your secret message  " << endl;
        getline(cin, secret_message);

        cout << "Encrypted_message..." << endl;

        for (int i = 0; i < secret_message.length(); i++)
        {
            char position = alphabets.find(secret_message[i]);

            if (position != string::npos)
            {
                char new_character = Key_Words.at(position);
                encrypted_message += new_character;
            }
            else
            {

                encrypted_message += i;
            }
        }
    }
    string getencryption()
    {
        return encrypted_message;
    }
};

int main()
{
    String_Encryption Encryption;
    Encryption.encrypt();
    cout << "\nEncrypted_message is : " << Encryption.getencryption() << endl;
    return 0;
}