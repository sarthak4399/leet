#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solutions
{
public:
    void Alternate(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (i % 2 == 0) 
            {
                s[i] = toupper(s[i]);
            }
            else
            {
                s[i] = tolower(s[i]); 
            }
        }
        cout << s << endl; 
    }
};

int main()
{
    Solutions s;
    s.Alternate("Sarthak");
    return 0;
}
