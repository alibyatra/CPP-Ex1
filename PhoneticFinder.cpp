#include "PhoneticFinder.hpp"
#include <iostream>

using namespace std;
namespace phonetic {
int iSimilar(char x, char y)
{
    x = tolower(x);
    y = tolower(y);
    if (x==y)
    return 1;
    if ((x == 'w' && y == 'v') || (x == 'v' && y == 'w'))
        return 1;
    if ((x == 'b' && y == 'f') || (x == 'f' && y == 'b'))
        return 1;
    if ((x == 'b' && y == 'p') || (x == 'p' && y == 'b'))
        return 1;
    if ((x == 'f' && y == 'p') || (x == 'p' && y == 'f'))
        return 1;
    if ((x == 'g' && y == 'j') || (x == 'j' && y == 'g'))
        return 1;
    if ((x == 'c' && y == 'k') || (x == 'k' && y == 'c'))
        return 1;
    if ((x == 'c' && y == 'q') || (x == 'q' && y == 'c'))
        return 1;
    if ((x == 'q' && y == 'k') || (x == 'k' && y == 'q'))
        return 1;
    if ((x == 's' && y == 'z') || (x == 'z' && y == 's'))
        return 1;
    if ((x == 'd' && y == 't') || (x == 't' && y == 'd'))
        return 1;
    if ((x == 'o' && y == 'u') || (x == 'u' && y == 'o'))
        return 1;
    if ((x == 'i' && y == 'y') || (x == 'y' && y == 'i'))
        return 1;
    return 0;
}
string find(string text, string word)
{
    if (word.length() == 0 || word == " ")
        {
            throw runtime_error("Empty word");
        }

    string str = "";
    int j = 0;
    size_t i = 0;
    for (i = 0; i < text.length(); i++)
    {
    
    while (text[i] == ' ')
    {
        i++;
    }

    while ((text.length() > i) && (word.length() > j) && (iSimilar(text[i], word[j]))
    {
        str += text[i];
        j++;
        i++;
    }

    if (str.length() == word.length())
    {
        if (!(isalpha(text[i])))
        return str;
    }

    str = "";
    j = 0;
}
if ((word.length() != str.length()))
    {        
    throw runtime_error("Sorry, The word " + word + " is not exist in the text.");
    }
return str;
}
}