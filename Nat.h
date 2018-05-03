//
// Benedikt Lüken-Winkels, 1138844
//

#ifndef RECHNERARITHMETIK_NAT_H
#define RECHNERARITHMETIK_NAT_H
using namespace std;
class Nat{
public:
    static Nat shift (Nat x, int n);
    static Nat add (Nat x, Nat y);
    string toString(void);
    void toBaseX (int n);
    Nat(int n);
    Nat();
    int getBase(void);

private:
    int base;
    vector<int> valueBaseX;
};
#endif //RECHNERARITHMETIK_NAT_H
