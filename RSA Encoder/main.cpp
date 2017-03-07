#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    string msg, plaintxt, block;
    stringstream trans, coded;
    int p1, p2, prod, relp;

    cout << "Enter message:  ";
    getline(cin, msg);

    cout << "Pick 2 primes:  ";
    cin >> p1 >> p2;    //primes
    prod = p1*p2;

    cout << "Pick a number relatively prime to the phi(" << prod << "):  ";
    cin >> relp;        //relatively prime

    enum letter {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};
    for (unsigned i(0); i < msg.length(); ++i){
        switch (tolower(msg.at(i))){
            case 'a':
                trans << "01";
                break;
            case 'b':
                trans << "02";
                break;
            case 'c':
                trans << "03";
                break;
            case 'd':
                trans << "04";
                break;
            case 'e':
                trans << "05";
                break;
            case 'f':
                trans << "06";
                break;
            case 'g':
                trans << "07";
                break;
            case 'h':
                trans << "08";
                break;
            case 'i':
                trans << "09";
                break;
            case 'j':
                trans << "10";
                break;
            case 'k':
                trans << "11";
                break;
            case 'l':
                trans << "12";
                break;
            case 'm':
                trans << "13";
                break;
            case 'n':
                trans << "14";
                break;
            case 'o':
                trans << "15";
                break;
            case 'p':
                trans << "16";
                break;
            case 'q':
                trans << "17";
                break;
            case 'r':
                trans << "18";
                break;
            case 's':
                trans << "19";
                break;
            case 't':
                trans << "20";
                break;
            case 'u':
                trans << "21";
                break;
            case 'v':
                trans << "22";
                break;
            case 'w':
                trans << "23";
                break;
            case 'x':
                trans << "24";
                break;
            case 'y':
                trans << "25";
                break;
            case 'z':
                trans << "26";
                break;
            case ' ':
                trans << "27";
                break;
        }
    }
    trans >> plaintxt;

    for (int pos(0); pos < plaintxt.size(); pos += 4) {
        block = plaintxt.substr(pos, 4);

        int exp(1);
        int rem = atoi(block.c_str());
        //raise to binomial power
        for (int i(1); i < relp; i = pow(2, exp+1), exp++) {
            rem = rem*rem % prod;
        }
        //raise to additional power
        for (int i = pow(2, exp-1); i < relp; i++){
            rem = rem*atoi(block.c_str()) % prod;
        }

        coded << setfill('0') << setw(4) << rem;
    }
    coded >> msg;

    cout << "Endcoded msg is " << msg << endl;
    return 0;
}
