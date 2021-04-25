// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
using namespace std;

int prioritet(char chr) {
        if (chr == '(')
                return 0;
        else if (chr == ')')
                return 1;
        else if ((chr == '+') || (chr == '-'))
                return 2;
        else
                return 3;
}

string infx2pstfx(string inf) {
   TStack<char> stack;
        string res;
        for (int i = 0; i < inf.length(); ++i) {
                if (isdigit(inf[i])) {
                        while (isdigit(inf[i])) {
                                res += inf[i];
                                i++;
                        }
                        i--;
                        res += ' ';
                }
                else if ((inf[i] == '(') || (stack.isEmpty()) || (priority(inf[i]) > priority(stack.get()))) {
                        stack.push(inf[i]);
                }
                else if (inf[i] == ')') {
                        char x = stack.get();
                        stack.pop();
                        while (x != '(') {
                                res += x;
                                res += ' ';
                                x = stack.get();
                                stack.pop();
                        }
                }
                else {
                        while (!stack.isEmpty() && (priority(stack.get()) >= priority(inf[i]))) {
                                res += stack.get();
                                res += ' ';
                                stack.pop();
                        }
                        stack.push(inf[i]);
                }
        }
        while (!stack.isEmpty()) {
                res += stack.get();
                res += ' ';
                stack.pop();
        }
        res.pop_back();
        return res;
  return string("");
}

int eval(string pst) {
   TStack<int> stack;
        string ch1;
        for (int i = 0; i < pst.length(); i++) {
                if (isdigit(pst[i])) {
                        while (isdigit(pst[i])) {
                                ch1 += pst[i];
                                i++;
                        }
                        stack.push(stoi(ch1));
                        ch1.clear();
                }
                else if (pst[i] != ' ') {
                        int num2 = stack.get();
                        stack.pop();
                        int num1 = stack.get();
                        stack.pop();
                        if (pst[i] == '*') {
                                stack.push(num1 * num2);
                        }
                        else if (pst[i] == '/') {
                                stack.push(num1 / num2);
                        }
                        else if (pst[i] == '+') {
                                stack.push(num1 + num2);
                        }
                        else if (pst[i] == '-') {
                                stack.push(num1 - num2);
                        }
                }
        }
        return stack.get();
  return 0;
}
