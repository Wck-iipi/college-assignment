#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

// Grammar production structure
struct Production {
    std::string nonTerminal;
    std::vector<std::string> symbols;
};

class GrammarAnalyzer {
public:
    void addProduction(const Production& production) {
        productions.push_back(production);
    }

    void calculateFirstSets() {
        for (const auto& production : productions) {
            calculateFirstSet(production.nonTerminal);
        }
    }

    void calculateFollowSets() {
        followSets[startSymbol].insert("$");
        for (const auto& production : productions) {
            calculateFollowSet(production);
        }
    }

    void printFirstSets() {
        std::cout << "FIRST Sets:" << std::endl;
        for (const auto& entry : firstSets) {
            std::cout << entry.first << ": { ";
            for (const auto& symbol : entry.second) {
                std::cout << symbol << " ";
            }
            std::cout << "}" << std::endl;
        }
    }

    void printFollowSets() {
        std::cout << "FOLLOW Sets:" << std::endl;
        for (const auto& entry : followSets) {
            std::cout << entry.first << ": { ";
            for (const auto& symbol : entry.second) {
                std::cout << symbol << " ";
            }
            std::cout << "}" << std::endl;
        }
    }

private:
    std::vector<Production> productions;
    std::map<std::string, std::set<std::string>> firstSets;
    std::map<std::string, std::set<std::string>> followSets;
    std::string startSymbol = "S";

    void calculateFirstSet(const std::string& nonTerminal) {
        if (firstSets.find(nonTerminal) != firstSets.end()) {
            return;
        }

        std::set<std::string> firstSet;

        for (const auto& production : productions) {
            if (production.nonTerminal == nonTerminal) {
                const std::string& firstSymbol = production.symbols.front();
                if (isTerminal(firstSymbol)) {
                    firstSet.insert(firstSymbol);
                } else {
                    calculateFirstSet(firstSymbol);
                    const auto& symbolsFirstSet = firstSets[firstSymbol];
                    firstSet.insert(symbolsFirstSet.begin(), symbolsFirstSet.end());
                }
            }
        }

        firstSets[nonTerminal] = firstSet;
    }

    void calculateFollowSet(const Production& production) {
        for (size_t i = 0; i < production.symbols.size(); ++i) {
            const std::string& symbol = production.symbols[i];
            if (!isTerminal(symbol)) {
                if (i == production.symbols.size() - 1) {
                    followSets[symbol].insert(followSets[production.nonTerminal].begin(), followSets[production.nonTerminal].end());
                } else {
                    const std::string& nextSymbol = production.symbols[i + 1];
                    if (isTerminal(nextSymbol)) {
                        followSets[symbol].insert(nextSymbol);
                    } else {
                        const auto& nextFirstSet = firstSets[nextSymbol];
                        followSets[symbol].insert(nextFirstSet.begin(), nextFirstSet.end());
                        if (nextFirstSet.find("") != nextFirstSet.end()) {
                            followSets[symbol].insert(followSets[production.nonTerminal].begin(), followSets[production.nonTerminal].end());
                        }
                    }
                }
            }
        }
    }

    bool isTerminal(const std::string& symbol) {
        return islower(symbol[0]);
    }
};

int main() {
    GrammarAnalyzer grammarAnalyzer;

    // Add productions
    grammarAnalyzer.addProduction({"S", {"A", "a"}});
    grammarAnalyzer.addProduction({"S", {"B", "b"}});
    grammarAnalyzer.addProduction({"A", {"c"}});
    grammarAnalyzer.addProduction({"B", {"d"}});

    // Calculate FIRST and FOLLOW sets
    grammarAnalyzer.calculateFirstSets();
    grammarAnalyzer.calculateFollowSets();

    // Print FIRST and FOLLOW sets
    grammarAnalyzer.printFirstSets();
    grammarAnalyzer.printFollowSets();

    return 0;
}
