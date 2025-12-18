#include <iostream>
using namespace std;

typedef char KieuDuLieu;

struct Nut {
    KieuDuLieu giaTri;
    Nut* conTrai;
    Nut* conPhai;
};

typedef Nut* CayNhiPhan;


void khoiTao(CayNhiPhan &C) {
    C = NULL;
}

int laCayRong(CayNhiPhan C) {
    return C == NULL;
}


Nut* taoNut(KieuDuLieu x) {
    Nut* p = new Nut;
    p->giaTri = x;
    p->conTrai = p->conPhai = NULL;
    return p;
}


void themConTrai(Nut* p, KieuDuLieu x) {
    if (p != NULL && p->conTrai == NULL)
        p->conTrai = taoNut(x);
}


void themConPhai(Nut* p, KieuDuLieu x) {
    if (p != NULL && p->conPhai == NULL)
        p->conPhai = taoNut(x);
}


void duyetTruoc(CayNhiPhan C) {
    if (C == NULL) return;
    cout << C->giaTri << " ";
    duyetTruoc(C->conTrai);
    duyetTruoc(C->conPhai);
}


void duyetGiua(CayNhiPhan C) {
    if (C == NULL) return;
    duyetGiua(C->conTrai);
    cout << C->giaTri << " ";
    duyetGiua(C->conPhai);
}

void duyetSau(CayNhiPhan C) {
    if (C == NULL) return;
    duyetSau(C->conTrai);
    duyetSau(C->conPhai);
    cout << C->giaTri << " ";
}

int main() {
    CayNhiPhan T;
    khoiTao(T);

    T = taoNut('A');
    themConTrai(T, 'B');
    themConPhai(T, 'C');
    themConTrai(T->conTrai, 'D');
    themConPhai(T->conTrai, 'E');
    themConTrai(T->conPhai, 'F');
    themConPhai(T->conPhai, 'G');

    duyetTruoc(T); cout << endl;
    duyetGiua(T);  cout << endl;
    duyetSau(T);   cout << endl;

    return 0;
}
