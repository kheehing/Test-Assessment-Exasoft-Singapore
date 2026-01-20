#include <string>
#include <cassert>
#include <sstream>

// Function to check if a character is alphanumeric
bool is_alnum(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

// how i go about solving this assessment is by first spliting the string into words based on spaces
// then for each word i reverse the alphanumeric characters while keeping the non-alphanumeric characters 
// in their original positions, finally i join the words back together with spaces in between.

std::string reverse_words(const std::string &str)
{
    // TODO: Implement this function
    std::stringstream ss(str);
    std::string token;
    std::string result;
    bool first = true;

    // Process each word separated by spaces
    while (std::getline(ss, token, ' '))
    {
        if (!first)
            result += " ";

        std::string buffer;
        // Process each character in the token
        for (char c : token)
        {
            if (is_alnum(c)) // if the character is alphanumeric, it will be reversed
            {
                buffer.push_back(c);
            }
            else
            {
                // flush reversed buffer
                for (auto it = buffer.rbegin(); it != buffer.rend(); ++it)
                    result.push_back(*it);

                buffer.clear();
                result.push_back(c);
            }
        }

        // flush remaining reversed buffer
        for (auto it = buffer.rbegin(); it != buffer.rend(); ++it)
            result.push_back(*it);

        first = false;
    }

    return result;
}

int main(){
    std::string test_str = "String; 2be reversed...";
    assert(reverse_words(test_str) == "gnirtS; eb2 desrever...");
    return 0;
}