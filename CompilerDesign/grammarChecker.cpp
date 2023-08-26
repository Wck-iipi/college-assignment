#include <iostream>
#include <cctype>
#include <string>

class ParseTree {
private:
    std::string label;
    ParseTree* left;
    ParseTree* right;
public:
    ParseTree(const std::string& label) : label(label), left(nullptr), right(nullptr) {}
    ParseTree(const std::string& label, ParseTree* left, ParseTree* right)
        : label(label), left(left), right(right) {}

    void print(int indent = 0) {
        for (int i = 0; i < indent; ++i) {
            std::cout << " ";
        }
        std::cout << label << std::endl;

        if (left) {
            left->print(indent + 2);
        }
        if (right) {
            right->print(indent + 2);
        }
    }
};

class Parser {
public:
    Parser(const std::string& input) : input(input), pos(0) {}

    bool parse() {
        return parseE();
    }

    ParseTree* getParseTree() {
        return parseTree;
    }

private:
    bool match(char c) {
        if (pos < input.size() && input[pos] == c) {
            ++pos;
            return true;
        }
        return false;
    }

    bool parseE() {
        ParseTree* t1 = parseT();
        if (t1) {
            if (match('+')) {
                ParseTree* t2 = parseE();
                if (t2) {
                    parseTree = new ParseTree("+", t1, t2);
                    return true;
                }
                delete t2;
            }
            parseTree = t1;
            return true;
        }
        return false;
    }

    bool parseT() {
        ParseTree* t1 = parseF();
        if (t1) {
            if (match('*')) {
                ParseTree* t2 = parseT();
                if (t2) {
                    parseTree = new ParseTree("*", t1, t2);
                    return true;
                }
                delete t2;
            }
            parseTree = t1;
            return true;
        }
        return false;
    }

    bool parseF() {
        if (match('(')) {
            if (parseE() && match(')')) {
                parseTree = new ParseTree("F", new ParseTree("("), getParseTree());
                match(')');
                return true;
            }
            return false;
        } else if (std::isdigit(input[pos])) {
            std::string num;
            while (pos < input.size() && std::isdigit(input[pos])) {
                num += input[pos++];
            }
            parseTree = new ParseTree("F", new ParseTree(num), nullptr);
            return true;
        }
        return false;
    }

    std::string input;
    int pos;
    ParseTree* parseTree;
};

int main() {
    std::string input;
    std::cout << "Enter an arithmetic expression: ";
    std::cin >> input;

    Parser parser(input);
    if (parser.parse()) {
        std::cout << "Input belongs to the grammar." << std::endl;
        ParseTree* parseTree = parser.getParseTree();
        std::cout << "Parse Tree:" << std::endl;
        parseTree->print();
        delete parseTree;
    } else {
        std::cout << "Input does not belong to the grammar." << std::endl;
    }

    return 0;
}

