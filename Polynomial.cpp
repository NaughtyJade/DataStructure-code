#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Polynomial;

class Term{
    friend Polynomial;
private:
    float coef;
    int exp;
};

class Polynomial{
private:
    Term *termArray;
    int capacity;
    int terms;
public:
    Polynomial(){
        capacity = 2;
        termArray = new Term[capacity];
        terms = 0;
    }
    //--------------------------------------------------------------
    void show(){
        int pos = terms;
        for (int i = 0; i < terms; i++) {
            if (termArray[pos].exp == 0) {
                if (termArray[pos].coef >= 0) {
                    cout << " + " << termArray[pos].coef << endl;
                }
                else{
                    cout << " - " << termArray[pos].coef << endl;
                }
            }
            else{
                if (pos == terms) {
                    if (termArray[pos].coef >= 0) {
                        cout << termArray[pos].coef << "X^" << termArray[pos].exp;
                    }
                    else{
                        cout << termArray[pos].coef << "X^" << termArray[pos].exp;
                    }
                }
                else{
                    if (termArray[pos].coef >= 0) {
                        cout << " + " << termArray[pos].coef << "X^" << termArray[pos].exp;
                    }
                    else{
                        cout << " - " << termArray[pos].coef << "X^" << termArray[pos].exp;
                    }
                }
            }
        }
    }
    //--------------------------------------------------------------
    Polynomial Add(Polynomial poly){
        Polynomial c;
        int aPos = 0, bPos = 0;
        while((aPos < terms) && (bPos < poly.terms)){
            if (termArray[aPos].exp == termArray[bPos].exp) {
                float t = termArray[aPos].coef + termArray[bPos].coef;
                if (t) {
                    c.NewTerm(t, termArray[aPos].exp);
                    aPos++;
                    bPos++;
                }
            }
            else if (termArray[aPos].exp < termArray[bPos].exp){
                c.NewTerm(termArray[bPos].coef, termArray[bPos].exp);
                bPos++;
            }
            else{
                c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
                aPos++;
            }
        }
        for (; aPos < terms; aPos++) {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
        }
        for (; bPos < poly.terms; bPos++) {
            c.NewTerm(termArray[bPos].coef, termArray[bPos].exp);
        }
        
        return c;
    }
    //--------------------------------------------------------------
    Polynomial Mult(Polynomial poly){
        Polynomial c;
        for (int i = 0; i < terms; i++) {
            Polynomial temp;
            for (int j = 0; j < poly.terms; j++) {
                temp.NewTerm(termArray[i].coef * poly.termArray[j].coef, termArray[i].exp * poly.termArray[j].exp);
            }
            c.Add(temp);
        }
        return c;
    }
    //--------------------------------------------------------------
    float Eval(float f){
        float ans = 0;
        for (int i = 0; i < terms; i++) {
            ans = termArray[i].coef * pow(f, termArray[i].exp);
        }
        return ans;
    }
    
    //--------------------------------------------------------------
    void NewTerm(const float theCoef, const int theExp){
        if (terms == capacity) {
            capacity *= 2;
            Term *temp = new Term[capacity];
            copy(termArray, termArray + terms, temp);
            delete termArray;
            termArray = temp;
        }
        termArray[terms].coef = theCoef;
        termArray[terms++].exp = theExp;
    }
    //--------------------------------------------------------------
};

int main(){
    float coef;
    int exp, terms;
    Polynomial a;
    Polynomial b;
    cin >> terms;
    cout << "terms in" << endl;
    for(; terms > 0; terms--){
        cin >> coef >> exp;
        cout << "coef exp in" << endl;
        a.NewTerm(coef, exp);
        cout << "term in" << endl;
    }
    cin >> terms;
    for(; terms > 0; terms--){
        cin >> coef >> exp;
        b.NewTerm(coef, exp);
    }
    cout << "f1() + f2() = ";
    a.Add(b);
    cout << "f1() * f2() = ";
    a.Mult(b);
    return 0;
}
