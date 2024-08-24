#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int coef;
    int exp;
    Node* link;

    Node(int c = 0, int e = 0, Node* l = nullptr) : coef(c), exp(e), link(l) {}
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = new Node(); 
        head->link = head; 
    }

    Polynomial(const Polynomial& a) {
        head = new Node();
        head->link = head;
        Node* current = a.head->link;
        Node* last = head;
        while (current != a.head) {
            last->link = new Node(current->coef, current->exp);
            last = last->link;
            current = current->link;
        }
        last->link = head; 
    }

    ~Polynomial() {
        Node* current = head->link;
        while (current != head) {
            Node* temp = current;
            current = current->link;
            delete temp;
        }
        delete head;
    }

    const Polynomial& operator=(const Polynomial& a) {
        if (this != &a) {
            this->~Polynomial(); 
            head = new Node();
            head->link = head;
            Node* current = a.head->link;
            Node* last = head;
            while (current != a.head) {
                last->link = new Node(current->coef, current->exp);
                last = last->link;
                current = current->link;
            }
            last->link = head;
        }
        return *this;
    }

    friend istream& operator>>(istream& is, Polynomial& x) {
        int n, c, e;
        is >> n;
        for (int i = 0; i < n; ++i) {
            is >> c >> e;
            Node* newNode = new Node(c, e);
            Node* current = x.head;
            while (current->link != x.head && current->link->exp > e) {
                current = current->link;
            }
            newNode->link = current->link;
            current->link = newNode;
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Polynomial& x) {
        Node* current = x.head->link;
        while (current != x.head) {
            os << current->coef << "x^" << current->exp;
            current = current->link;
            if (current != x.head) os << " + ";
        }
        return os;
    }

    Polynomial operator+(const Polynomial& b) const {
        Polynomial result;
        Node* aPtr = head->link;
        Node* bPtr = b.head->link;
        Node* rPtr = result.head;

        while (aPtr != head || bPtr != b.head) {
            if (aPtr == head || (bPtr != b.head && bPtr->exp > aPtr->exp)) {
                rPtr->link = new Node(bPtr->coef, bPtr->exp);
                bPtr = bPtr->link;
            } else if (bPtr == b.head || (aPtr != head && aPtr->exp > bPtr->exp)) {
                rPtr->link = new Node(aPtr->coef, aPtr->exp);
                aPtr = aPtr->link;
            } else {
                int sumCoef = aPtr->coef + bPtr->coef;
                if (sumCoef != 0) {
                    rPtr->link = new Node(sumCoef, aPtr->exp);
                }
                aPtr = aPtr->link;
                bPtr = bPtr->link;
            }
            rPtr = rPtr->link;
        }
        rPtr->link = result.head;
        return result;
    }

    Polynomial operator-(const Polynomial& b) const {
        Polynomial result;
        Node* aPtr = head->link;
        Node* bPtr = b.head->link;
        Node* rPtr = result.head;

        while (aPtr != head || bPtr != b.head) {
            if (aPtr == head || (bPtr != b.head && bPtr->exp > aPtr->exp)) {
                rPtr->link = new Node(-bPtr->coef, bPtr->exp);
                bPtr = bPtr->link;
            } else if (bPtr == b.head || (aPtr != head && aPtr->exp > bPtr->exp)) {
                rPtr->link = new Node(aPtr->coef, aPtr->exp);
                aPtr = aPtr->link;
            } else {
                int diffCoef = aPtr->coef - bPtr->coef;
                if (diffCoef != 0) {
                    rPtr->link = new Node(diffCoef, aPtr->exp);
                }
                aPtr = aPtr->link;
                bPtr = bPtr->link;
            }
            rPtr = rPtr->link;
        }
        rPtr->link = result.head;
        return result;
    }

    Polynomial operator*(const Polynomial& b) const {
        Polynomial result;
        Node* aPtr = head->link;

        while (aPtr != head) {
            Polynomial temp;
            Node* bPtr = b.head->link;
            Node* tPtr = temp.head;

            while (bPtr != b.head) {
                int c = aPtr->coef * bPtr->coef;
                int e = aPtr->exp + bPtr->exp;
                tPtr->link = new Node(c, e);
                tPtr = tPtr->link;
                bPtr = bPtr->link;
            }
            tPtr->link = temp.head;
            result = result + temp;
            aPtr = aPtr->link;
        }
        return result;
    }

    float Evaluate(float x) const {
        float result = 0.0;
        Node* current = head->link;
        while (current != head) {
            result += current->coef * pow(x, current->exp);
            current = current->link;
        }
        return result;
    }
};

int main() {
    Polynomial p1, p2;
    cout << "First Polynomial(n c1 e1 c2 e2 ... cn en):";
    cin >> p1;
    cout << "Second Polynomial(n c1 e1 c2 e2 ... cn en):";
    cin >> p2;

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial mult = p1 * p2;

    cout << "First Polynomial: " << p1 << endl;
    cout << "Second Polynomial: " << p2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Diff: " << diff << endl;
    cout << "Mult: " << mult << endl;

    float x;
    cout << "x value";
    cin >> x;
    cout << "First Polynomial when x = " << x << " value: " << p1.Evaluate(x) << endl;

    return 0;
}
