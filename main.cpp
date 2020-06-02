#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;


int main()
{
    int n;

    cout << "Size of the matrix (>2)? " << endl;
    cin >> n;

    MatrixXd m(n,n);
    m << VectorXd::Zero(n), MatrixXd::Identity(n, n).block(0, 0, n, n-1);
    m = m + MatrixXd::Identity(n, n);
    VectorXd v(n);
    for (int ii = 0; ii < n-1; ++ii) {
        v[ii] = 2*ii + 1;
    }
    v[n-1] = n-1;


    VectorXd s = m.partialPivLu().solve(v);

    cout << "Matrix:\n\n";
    cout << m << endl << endl;
    cout << "Vector:\n\n";
    cout << v << endl << endl;
    cout << "Solution (x) of M*x = v:\n\n";
    cout << s << endl << endl;

    return 0;
}