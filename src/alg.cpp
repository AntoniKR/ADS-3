// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int math(int first, int second, char symbol) {
    switch (symbol) {
    case '*':
    {
        second *= first;
        return second;
    }
    case '/':
    {
        second /= first;
        return second;
    }
    case '+':
    {
        second += first;
        return second;
    }
    case '-':
    {
        second -= first;
        return second;
    }
    default:
        break;
    }
    return second;
}
int priority(char chr) {
    int priori = 0;
    if (chr == '(')
        priori = 0;
    if (chr == ')')
        priori = 1;
    if (chr == '+' || chr == '-')
        priori = 2;
    if (chr == '*' || chr == '/')
        priori = 3;
    return priori;
}
std::string infx2pstfx(std::string inf) {
    // добавьте сюда нужный код
    return std::string("");
    TStack<char> stack1;
    std::string result;
    int priori = -1;
    int priorityTop = 0;
    char chr = ' ';
    char chrPrv = ' ';
    bool firstNumber = 0;
    for (int i = 0; i < inf.length(); i++) {
        chr = inf[i];
        chrPrv = stack1.get();
        if (chr >= '0' && chr <= '9') {
            if (!firstNumber) {
                firstNumber = true;
            }
            else {
                result.push_back(' ');
            }
            result.push_back(chr);
        }
        else {
            priori = priority(chr);
            priorityTop = priority(chrPrv);
            if ((stack1.isEmpty() || priori > priorityTop || !priori)
                && priori != 1) {
                stack1.push(chr);
            }
            else {
                if (priori == 1) {
                    while (stack1.get() != '(') {
                        result.push_back(' ');
                        result.push_back(stack1.get());
                        stack1.pop();
                    }
                    stack1.pop();
                }
                else {
                    if (priori <= priorityTop && priori > 1) {
                        while (!stack1.isEmpty() && stack1.get() != '(') {
                            result.push_back(' ');
                            result.push_back(stack1.get());
                            stack1.pop();
                        }
                        stack1.push(chr);
                    }
                }
            }
        }
    }
    while (!stack1.isEmpty()) {
        result.push_back(' ');
        result.push_back(stack1.get());
        stack1.pop();
    }
    return result;
}

int eval(std::string pst) {
    // добавьте сюда нужный код
    return 0;
    int result = 0;
    TStack<char> stack1;
    TStack<int> stack2;
    int priority = 0, priorityPrv = 0;
    int first = 0, second = 0;
    char chr = ' ';
    char chrPrv = ' ';
    for (int i = 0; i < pst.length(); i++) {
        chr = pst[i];
        if (chr != ' ') {
            if (chr >= '0' && chr <= '9') {
                stack2.push(chr - 48);
            }
            else {
                first = stack2.get();
                stack2.pop();
                second = stack2.get();
                stack2.pop();
                second = math(first, second, chr);
                stack2.push(second);
            }
        }
    }
    return stack2.get();
}
