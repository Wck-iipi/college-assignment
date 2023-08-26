#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Node class for the parse tree
class TreeNode {
public:
    std::string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const std::string& val) : value(val), left(nullptr), right(nullptr) {}
};

class ParseTreeGenerator {
public:
    TreeNode* generateParseTree(const std::string& expression) {
        std::istringstream iss(expression);
        std::string token;
        std::vector<std::string> tokens;

        // Tokenize the expression
        while (iss >> token) {
            tokens.push_back(token);
        }

        return parseExpression(tokens, 0, tokens.size() - 1);
    }

private:
    TreeNode* parseExpression(const std::vector<std::string>& tokens, int start, int end) {
        if (start == end) {
            return new TreeNode(tokens[start]);
        }

        int opIndex = findOperatorIndex(tokens, start, end);

        if (opIndex != -1) {
            TreeNode* node = new TreeNode(tokens[opIndex]);
            node->left = parseExpression(tokens, start, opIndex - 1);
            node->right = parseExpression(tokens, opIndex + 1, end);
            return node;
        }

        return parseExpression(tokens, start + 1, end - 1);
    }

    int findOperatorIndex(const std::vector<std::string>& tokens, int start, int end) {
        int opIndex = -1;
        int parenCounter = 0;

        for (int i = end; i >= start; --i) {
            if (tokens[i] == ")") {
                ++parenCounter;
            } else if (tokens[i] == "(") {
                --parenCounter;
            } else if ((tokens[i] == "+" || tokens[i] == "-") && parenCounter == 0) {
                opIndex = i;
                break;
            }
        }

        if (opIndex == -1) {
            for (int i = end; i >= start; --i) {
                if ((tokens[i] == "*" || tokens[i] == "/") && parenCounter == 0) {
                    opIndex = i;
                    break;
                } else if (tokens[i] == ")") {
                    ++parenCounter;
                } else if (tokens[i] == "(") {
                    --parenCounter;
                }
            }
        }

        return opIndex;
    }
};

void printParseTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr || root->right != nullptr) {
        std::cout << "(";
    }

    printParseTree(root->left);
    std::cout << root->value;
    printParseTree(root->right);

    if (root->left != nullptr || root->right != nullptr) {
        std::cout << ")";
    }
}


int main() {
    ParseTreeGenerator generator;
    std::string expression = "5 + 3 * 4";
    TreeNode* root = generator.generateParseTree(expression);

    // Print the parse tree (in-order traversal)
    std::cout << "Parse Tree: ";
    printParseTree(root);
    std::cout << std::endl;

    return 0;
}
