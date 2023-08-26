#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool hasLeftRecursion(const string& nonTerminal, const vector<string>& productions) {
    for (const string& production : productions) {
        if (production.find(nonTerminal) == 0) {
            return true;
        }
    }
    return false;
}

bool hasLeftRecursion(const map<string, vector<string>>& grammar) {
    for (const auto& entry : grammar) {
        if (hasLeftRecursion(entry.first, entry.second)) {
            return true;
        }
    }
    return false;
}

int main() {
    map<string, vector<string>> userGrammar;
    int numNonTerminals;

    cout << "Enter the number of non-terminals: ";
    cin >> numNonTerminals;

    for (int i = 0; i < numNonTerminals; ++i) {
        string nonTerminal;
        int numProductions;

        cout << "Enter non-terminal " << i + 1 << ": ";
        cin >> nonTerminal;

        cout << "Enter the number of productions for " << nonTerminal << ": ";
        cin >> numProductions;

        vector<string> productions;
        for (int j = 0; j < numProductions; ++j) {
            string production;
            cout << "Enter production " << j + 1 << " for " << nonTerminal << ": ";
            cin >> production;
            productions.push_back(production);
        }

        userGrammar[nonTerminal] = productions;
    }

    if (hasLeftRecursion(userGrammar)) {
        cout << "The grammar has left recursion." << endl;
    } else {
        cout << "The grammar does not have left recursion." << endl;
    }

    return 0;
}
