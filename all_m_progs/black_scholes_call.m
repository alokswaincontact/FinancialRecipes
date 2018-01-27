function c = black_scholes_call(S,K,r,sigma,time) 
   time_sqrt = sqrt(time);
   d1 = (log(S/K)+r*time)/(sigma*time_sqrt)+0.5*sigma*time_sqrt; 
   d2 = d1-(sigma*time_sqrt);
   c = S * normcdf(d1) - K * exp(-r*time) * normcdf(d2);
endfunction
