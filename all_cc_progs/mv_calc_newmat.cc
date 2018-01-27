#include <cmath>
using namespace std;

#include "newmat.h"
using namespace NEWMAT;

double mv_calculate_mean(const Matrix& e, const Matrix& w){ 
    Matrix tmp = e.t()*w;
    return tmp(1,1);
};

double mv_calculate_variance(const Matrix& V, const Matrix& w){ 
    Matrix tmp = w.t()*V*w;
    return tmp(1,1);
};

double mv_calculate_st_dev(const Matrix& V, const Matrix& w){ 
    double var = mv_calculate_variance(V,w);
    return sqrt(var);
};
