#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct DATA {
    string прізвище;
    int рікНародження;
    double оцінка;
};

struct NODE {
    DATA data;
    NODE* Left;
    NODE* Right;
};

void Add(DATA d, NODE*& c);
void ShowElement(NODE* c);
void ShowTree(NODE* c);
int CountElements(NODE* c);
double SumGrades(NODE* c);
double AverageGrade(NODE* c);
void DeleteTree(NODE*& c);
void TransferToSecondTree(NODE* source, NODE*& destination);
void AddByYear(DATA d, NODE*& c);

void Add(DATA d, NODE*& c) {
    if (c == NULL) {
        c = new NODE;
        c->data = d;
        c->Left = NULL;
        c->Right = NULL;
        return;
    }
    
    if (d.прізвище < c->data.прізвище)
        Add(d, c->Left);
    else
        Add(d, c->Right);
}

void AddByYear(DATA d, NODE*& c) {
    if (c == NULL) {
        c = new NODE;
        c->data = d;
        c->Left = NULL;
        c->Right = NULL;
        return;
    }
    
    if (d.рікНародження < c->data.рікНародження)
        AddByYear(d, c->Left);
    else
        AddByYear(d, c->Right);
}

void ShowElement(NODE* c) {
    if (!c) return;
    cout << left;
    cout << setw(15) << c->data.прізвище 
         << setw(10) << c->data.рікНародження 
         << setw(8) << fixed << setprecision(2) << c->data.оцінка << endl;
}

void ShowTree(NODE* c) {
    if (!c) return;
    
    if (c->Left) ShowTree(c->Left);
    ShowElement(c);
    if (c->Right) ShowTree(c->Right);
}

int CountElements(NODE* c) {
    if (!c) return 0;
    
    int count = 1;
    if (c->Left) count += CountElements(c->Left);
    if (c->Right) count += CountElements(c->Right);
    
    return count;
}

double SumGrades(NODE* c) {
    if (!c) return 0;
    
    double sum = c->data.оцінка;
    if (c->Left) sum += SumGrades(c->Left);
    if (c->Right) sum += SumGrades(c->Right);
    
    return sum;
}

double AverageGrade(NODE* c) {
    int count = CountElements(c);
    if (count == 0) return 0;
    
    return SumGrades(c) / count;
}

void DeleteTree(NODE*& c) {
    if (!c) return;
    
    if (c->Left) {
        DeleteTree(c->Left);
        c->Left = NULL;
    }
    
    if (c->Right) {
        DeleteTree(c->Right);
        c->Right = NULL;
    }
    
    delete c;
    c = NULL;
}

void TransferToSecondTree(NODE* source, NODE*& destination) {
    if (!source) return;
    
    AddByYear(source->data, destination);
    
    if (source->Left) TransferToSecondTree(source->Left, destination);
    
    if (source->Right) TransferToSecondTree(source->Right, destination);
}
