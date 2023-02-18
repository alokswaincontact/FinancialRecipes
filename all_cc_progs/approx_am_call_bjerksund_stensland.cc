#include "fin_recipes.h"
#include <cmath>
#include "normdist.h"

inline double phi(double S, double T, double gamma, double H, double X, double r, double b, double sigma){
    double sigma_sqr=pow(sigma,2);
    double kappa = 2.0*b/sigma_sqr + 2.0*gamma - 1.0;
    double lambda = (-r + gamma * b + 0.5*gamma*(gamma-1.0)*sigma_sqr)*T; // check this, says lambda in text
    double d1= - (log(S/H)+(b+(gamma-0.5)*sigma_sqr)*T)/(sigma*sqrt(T));
    double d2= - (log((X*X)/(S*H))+(b+(gamma-0.5)*sigma_sqr)*T)/(sigma*sqrt(T));
    double phi = exp(lambda) * pow(S,gamma) * (N(d1) - pow((X/S),kappa) * N(d2));
    return phi;
};

double option_price_american_call_approximated_bjerksund_stensland( const double& S,
								    const double& K,
								    const double& r,
								    const double& b,
								    const double& sigma,
								    const double& T ){
    double sigma_sqr=pow(sigma,2);
    double B0=max(K,(r/(r-b)*K));
    double beta = (0.5 - b/sigma_sqr) + sqrt( pow((b/sigma_sqr-0.5),2) + 2.0 * r/sigma_sqr);
    double Binf = beta/(beta-1.0)*K;
    double hT= - (b*T + 2.0*sigma*sqrt(T))*((K*K)/(Binf-B0));
    double XT = B0+(Binf-B0)*(1.0-exp(hT));
    double alpha = (XT-K)*pow(XT,-beta);
    double C=alpha*pow(S,beta);
    C -= alpha*phi(S,T,beta,XT,XT,r,b,sigma);
    C += phi(S,T,1,XT,XT,r,b,sigma);
    C -= phi(S,T,1,K,XT,r,b,sigma) ;
    C -= K*phi(S,T,0,XT,XT,r,b,sigma);
    C += K*phi(S,T,0,K,XT,r,b,sigma);
    double c=option_price_european_call_payout(S,K,r,b,sigma,T);  // for safety use the Black Scholes as lower bound
    return max(c,C);
};
