#include <iostream>
#include <string>

using namespace std;

void InserirApagar(string&, string&);
 
int main() {
 
    int n;
    cin >> n;
    
    while (n--) {
        string palavra1, palavra2, mix;
        
        cin >> palavra1 >> palavra2;

        while (not palavra1.empty() and not palavra2.empty())
        {
            InserirApagar(mix, palavra1);
            InserirApagar(mix, palavra2);
        }
        
        while (not palavra1.empty())
        {
            InserirApagar(mix, palavra1);
        }

        while (not palavra2.empty())
        {
            InserirApagar(mix, palavra2);
        }
        
        cout << mix << endl;
    }

    return 0;
}

void InserirApagar(string &mix, string &palavra) {
    mix.insert(mix.length(), 1, palavra[0]);
    palavra.erase(0, 1);
}