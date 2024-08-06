#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Polynomial;

class Term {
    friend Polynomial;
private:
    float coef;
    int exp;
public:
    Term() : coef(0), exp(0) {}
};

class Polynomial {
private:
    Term *termArray;
    int capacity;
    int terms;
public:
    Polynomial() {
        capacity = 2;
        termArray = new Term[capacity];
        terms = 0;
    }

    // 拷貝構造函數
    Polynomial(const Polynomial& poly) {
        capacity = poly.capacity;
        terms = poly.terms;
        termArray = new Term[capacity];
        copy(poly.termArray, poly.termArray + terms, termArray);
    }

    // 賦值運算符
    Polynomial& operator=(const Polynomial& poly) {
        if (this == &poly) return *this; // 自我賦值檢查
        delete[] termArray;
        capacity = poly.capacity;
        terms = poly.terms;
        termArray = new Term[capacity];
        copy(poly.termArray, poly.termArray + terms, termArray);
        return *this;
    }

    // 析構函數
    ~Polynomial() {
        delete[] termArray;
    }

    //--------------------------------------------------------------
    void show(){
        int pos = terms;
        for (int i = 0; i < terms; i++) {
            if (i == terms - 1) {
                if (termArray[pos].coef >= 0) {
                    cout << " + " << termArray[i].coef << endl;
                }
                else{
                    cout << " - " << termArray[i].coef << endl;
                }
            }
            else{
                if (i + terms == terms) {
                    if (termArray[i].coef >= 0) {
                        cout << termArray[i].coef << "X^" << termArray[i].exp;
                    }
                    else{
                        cout << termArray[i].coef << "X^" << termArray[i].exp;
                    }
                }
                else{
                    if (termArray[i].coef >= 0) {
                        cout << " + " << termArray[i].coef << "X^" << termArray[i].exp;
                    }
                    else{
                        cout << " - " << termArray[i].coef << "X^" << termArray[i].exp;
                    }
                }
            }
        }
    }
    //--------------------------------------------------------------
    Polynomial Add(Polynomial poly) {
        Polynomial c;
        int aPos = 0, bPos = 0;
        while ((aPos < terms) && (bPos < poly.terms)) {
            if (termArray[aPos].exp == poly.termArray[bPos].exp) {
                float t = termArray[aPos].coef + poly.termArray[bPos].coef;
                if (t) {
                    c.NewTerm(t, termArray[aPos].exp);
                }
                aPos++;
                bPos++;
            } else if (termArray[aPos].exp < poly.termArray[bPos].exp) {
                c.NewTerm(poly.termArray[bPos].coef, poly.termArray[bPos].exp);
                bPos++;
            } else {
                c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
                aPos++;
            }
        }
        for (; aPos < terms; aPos++) {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
        }
        for (; bPos < poly.terms; bPos++) {
            c.NewTerm(poly.termArray[bPos].coef, poly.termArray[bPos].exp);
        }
        
        return c;
    }
    //--------------------------------------------------------------
    Polynomial Mult(Polynomial poly) {
        Polynomial c;
        for (int i = 0; i < terms; i++) {
            Polynomial temp;
            for (int j = 0; j < poly.terms; j++) {
                float newCoef = termArray[i].coef * poly.termArray[j].coef;
                int newExp = termArray[i].exp + poly.termArray[j].exp;
                temp.NewTerm(newCoef, newExp);
            }
            c = c.Add(temp);  // 累加結果
        }
        return c;
    }
    //--------------------------------------------------------------
    float Eval(float f) {
        float ans = 0;
        for (int i = 0; i < terms; i++) {
            ans += termArray[i].coef * pow(f, termArray[i].exp);
        }
        return ans;
    }
    //--------------------------------------------------------------
    void NewTerm(const float theCoef, const int theExp) {
        if (terms == capacity) {
            capacity *= 2;
            Term *temp = new Term[capacity];
            copy(termArray, termArray + terms, temp);
            delete[] termArray;
            termArray = temp;
        }
        termArray[terms].coef = theCoef;
        termArray[terms++].exp = theExp;
    }
    //--------------------------------------------------------------
};

int main() {
    float coef;
    int exp, terms;
    Polynomial a;
    Polynomial b;
    cin >> terms;
    for(; terms > 0; terms--){
        cin >> coef >> exp;
        a.NewTerm(coef, exp);
    }
    a.show();
    cin >> terms;
    for(; terms > 0; terms--){
        cin >> coef >> exp;
        b.NewTerm(coef, exp);
    }
    b.show();
    cout << "f1() + f2() = ";
    (a.Add(b)).show();
    cout << "f1() * f2() = ";
    (a.Mult(b)).show();
    return 0;
}
