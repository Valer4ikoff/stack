/* 1, Дано рядок s, який містить лише символи , визначити,
чи введений рядок дійсний.
Рядок введення дійсний, якщо:
- Відкриті дужки повинні бути закриті однотипними дужками.
- Відкриті дужки повинні бути закриті в правильному порядку.
- Кожна закрита дужка має відповідну відкриту дужку такого ж типу.*/






/*


#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string s) {
    std::stack<char> st;
    std::unordered_map<char, char> brackets = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char ch : s) {
        if (brackets.find(ch) != brackets.end()) {
            // Якщо це закрита дужка
            if (st.empty() || st.top() != brackets[ch]) {
                return false;  // Неправильний порядок дужок
            }
            st.pop();
        } else {
            // Якщо це відкрита дужка, додаємо її в стек
            st.push(ch);
        }
    }

    return st.empty();  // Дужки повністю збалансовані, якщо стек порожній в кінці
}

int main() {
    // Приклади тестування
    std::cout << std::boolalpha;  // Для виводу "true" або "false" замість 1 або 0

    std::string s1 = "()";
    std::string s2 = "()[]{}";
    std::string s3 = "(]";

    std::cout << "Example 1: " << isValid(s1) << std::endl;  // Очікується true
    std::cout << "Example 2: " << isValid(s2) << std::endl;  // Очікується true
    std::cout << "Example 3: " << isValid(s3) << std::endl;  // Очікується false

    return 0;
}



*/

/* 2, Враховуючи root бінарного дерева, поверніть упорядкований обхід (Inorder Traversal) значень його вузлів.*/




/*

#include <iostream>
#include <vector>
#include <stack>

// Визначення вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stack;

    TreeNode* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();
        result.push_back(current->val);
        current = current->right;
    }

    return result;
}

int main() {
    // Створення тестового бінарного дерева
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Отримання упорядкованого обходу (Inorder Traversal)
    std::vector<int> result = inorderTraversal(root);

    // Виведення результату
    std::cout << "[ ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;

    // Звільнення пам'яті
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}


*/





/*3, Створіть стек, який підтримує надсилання, висунення, 
початок і отримання мінімального елемента в постійному часі.*/




/*


#include <stack>
#include <iostream>

class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> minStack;

public:
    MinStack() {}

    void push(int val) {
        stack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (stack.top() == minStack.top()) {
            minStack.pop();
        }
        stack.pop();
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    std::cout << "getMin: " << minStack.getMin() << std::endl;

    minStack.pop();
    std::cout << "top: " << minStack.top() << std::endl;

    std::cout << "getMin: " << minStack.getMin() << std::endl;

    return 0;
}


*/






/*4, Реалізуйте чергу FIFO, використовуючи лише два стеки. 
Реалізована черга повинна підтримувати всі функції звичайної черги (push, peek, pop і empty).*/




/*

#include <iostream>
#include <stack>

class MyQueue {
public:
  
MyQueue() {
}

void push(int x) {
    mainStack.push(x);
}

int pop() {
    if (helperStack.empty()) {
        while (!mainStack.empty()) {
            helperStack.push(mainStack.top());
            mainStack.pop();
        }
    }

    int front = helperStack.top();
    helperStack.pop();
    return front;
}


int peek() {
    if (helperStack.empty()) {
        while (!mainStack.empty()) {
            helperStack.push(mainStack.top());
            mainStack.pop();
        }
    }

    return helperStack.top();
}


bool empty() {
    return mainStack.empty() && helperStack.empty();
}

private:
    std::stack<int> mainStack;
    std::stack<int> helperStack;
};

int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);

    int peekResult = myQueue.peek();
    int popResult = myQueue.pop();
    bool isEmpty = myQueue.empty();

    // Виведення результатів
    std::cout << "Peek result: " << peekResult << std::endl;
    std::cout << "Pop result: " << popResult << std::endl;
    std::cout << "Is empty: " << (isEmpty ? "true" : "false") << std::endl;

    return 0;
}


*/




/*5, Дано закодований рядок, повернути його декодований рядок.*/




/*

#include <iostream>
#include <stack>
#include <cctype>

std::string decodeString(const std::string& s) {
    std::stack<int> countStack;
    std::stack<std::string> resultStack;

    int count = 0;
    std::string currentResult = "";

    for (char ch : s) {
        if (std::isdigit(ch)) {
            count = count * 10 + (ch - '0');
        } else if (ch == '[') {
            countStack.push(count);
            resultStack.push(currentResult);
            count = 0;
            currentResult = "";
        } else if (ch == ']') {
            int repeatCount = countStack.top();
            countStack.pop();

            std::string lastResult = resultStack.top();
            resultStack.pop();

            for (int i = 0; i < repeatCount; ++i) {
                lastResult += currentResult;
            }

            currentResult = lastResult;
        } else {
            currentResult += ch;
        }
    }

    return currentResult;
}

int main() {
    // Приклади використання
    std::string example1 = "3[a]2[bc]";
    std::string example2 = "3[a2[c]]";
    std::string example3 = "2[abc]3[cd]ef";

    std::cout << "Example 1: " << decodeString(example1) << std::endl;
    std::cout << "Example 2: " << decodeString(example2) << std::endl;
    std::cout << "Example 3: " << decodeString(example3) << std::endl;

    return 0;
}



*/





