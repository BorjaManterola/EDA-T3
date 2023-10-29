#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <sstream>
#include "Claseshpp/abbNode.hpp"
#include "Claseshpp/abb.hpp"
#include "Claseshpp/node.hpp"
#include "Claseshpp/stack.hpp"

using namespace std;
 
int prec(string c)
{
    if (c == "^")
        return 3;
    else if (c == "/" || c == "*")
        return 2;
    else if (c == "+" || c == "-")
        return 1;
    else
        return -1;
}

bool comprobar(string a, vector<string> b) {
    for (unsigned int i = 0; i < b.size(); i++) {
        if (a == b[i]) {
            return true;
        }
    }
    return false;
}
 
vector<string> infixToPostfix(vector<string> s) {
    eda::Stack st;
    vector<string> result;
    vector<string> operaciones = {"+", "-", "*", "/", "^"};

    for (unsigned int i = 0; i < s.size(); i++) {
        string c = s[i];

        if (comprobar(c, operaciones)) {
            while (!st.isEmpty() && prec(s[i]) <= prec(st.top()->getData())) {
                result.push_back(st.top()->getData());
                st.pop();
            }
            st.push(c);
        }

        else if (c == "(")
            st.push("(");
        else if (c == ")") {
            while (st.top()->getData() != "(") {
                result.push_back(st.top()->getData());
                st.pop();
            }
            st.pop();
        }
        else {
            result.push_back(c);
        }
    }
 
    while (!st.isEmpty()) {
        result.push_back(st.top()->getData());
        st.pop();
    }
    return result;
}

float operacionAux(float a, float b, string c) {
    if (c == "+") {
        return a + b;
    }
    else if (c == "-") {
        return a - b;
    }
    else if (c == "*") {
        return a * b;
    }
    else if (c == "/") {
        return a / b;
    }
    else if (c == "^") {
        return pow(a, b);
    }
    return 0;
}

float operacion(vector<string> exp) {
    vector<string> operaciones = {"+", "-", "*", "/", "^"};
    eda::Stack st;
    for (unsigned int i = 0; i < exp.size(); i++) {
        if (comprobar(exp[i], operaciones)) {
            if(st.isEmpty()) {
                std::cout << "Error" << endl;
            } else {
                float a = stof(st.top()->getData());
                st.pop();
                float b = stof(st.top()->getData());
                st.pop();
                float x = operacionAux(b, a, exp[i]);
                ostringstream ss3;
                ss3 << x;
                string c = ss3.str();
                st.push(c);
            }
        }
        else {
            st.push(exp[i]);
        }
    }
    float ans = stof(st.top()->getData());
    st.pop();
    return ans;
}

vector<string> dividirString(string s) {
    vector<string> palabras;
    stringstream ss(s);
    string palabra;

    while (ss >> palabra) {
        palabras.push_back(palabra);
    }
    return palabras;
}

string arreglarExpresion(string exp) {
    string exp_aux;
    for (unsigned int i = 0; i < exp.size(); i++) {
        if (exp[i] == '(') {
            exp_aux += "( ";
        } else if (exp[i] == ')') {
            exp_aux += " )";
        } else {
            exp_aux += exp[i];
        }
    }
    return exp_aux;
}

vector<string> reemplazarVariable(vector<string> nom, map<string, float> var, vector<string> exp) {
    vector<string> exp_aux;
    for (unsigned int i = 0; i < exp.size(); i++) {
        int k = 0;
        for (unsigned int j = 0; j < nom.size(); j++) {
            if (exp[i] == nom[j]) {
                string aux = to_string(var[nom[j]]);
                exp_aux.push_back(aux);
                k = 1;
            }
        }
        if (k == 0) {
            exp_aux.push_back(exp[i]);
        }
    }
    return exp_aux;
}

trees::ABBNode* build_ABB(vector<string> exp) {
    vector<string> operaciones = {"+", "-", "*", "/", "^"};
    eda::Stack st;
    for (unsigned int i = 0; i < exp.size(); i++) {
        trees::ABBNode* nodo = new trees::ABBNode(exp[i]);
        if (comprobar(nodo->getDato(), operaciones)) {
            nodo->setRight(st.top()->getABBNode());
            st.pop();
            nodo->setLeft(st.top()->getABBNode());
            st.pop();
            st.push(nodo);
        } else {
            st.push(nodo);
        }
    }
    return st.top()->getABBNode();
}

int main() {
    float ans = 0;
    vector<string> operaciones = {"+", "-", "*", "/", "^"};
    map<string, float> variables;
    string input = "INICIO";
    vector<string> nombres;
    nombres.push_back("ans");
    vector<string> postfijo;
    vector<string> postfijoVar;
    vector<string> expres;

    std::cout << "####### CALCULADORA INTERACTIVA #######" << endl;

    while(true) {
        getline(cin, input);
        istringstream ss(input);
        string pedazo;
        getline(ss, pedazo, ' ');
        if (pedazo == "FIN") {
            break;
        }
        else if (pedazo == "tree") {
            trees::ABB abb(build_ABB(postfijo));
            abb.traverse();
            continue;
        }
        string aux1 = pedazo;
        getline(ss, pedazo, ' ');
        if (pedazo == "=") {
            getline(ss, pedazo, ' ');
            string aux2 = pedazo;
            variables[aux1] = stof(aux2);
            nombres.push_back(aux1);
            continue;
        }
        else {
            string expresion = arreglarExpresion(input);
            expres = dividirString(expresion);
            postfijo = infixToPostfix(expres);
            postfijoVar = reemplazarVariable(nombres, variables, postfijo);
            ans = operacion(postfijoVar);
            std::cout << "ans = " << ans << endl;
            variables["ans"] = ans;
        }
    }
    return 0;
}