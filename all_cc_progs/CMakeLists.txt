# LIBOBJS - list of files to create financial recipes library
set(LIBOBJS cflow_irr.cc cflow_irr_test_unique.cc cflow_pv.cc cflow_pv_discrete.cc cflow_irr_discrete.cc)

set(LIBOBJS ${LIBOBJS} termstru_transforms.cc termstru_yield_interpolated.cc)

set(LIBOBJS ${LIBOBJS} bonds_price_discrete.cc bonds_convexity_discrete.cc 
           bonds_duration_discrete.cc bonds_duration_macaulay_discrete.cc bonds_yield_discrete.cc)

set(LIBOBJS ${LIBOBJS} bonds_convexity.cc bonds_duration.cc bonds_duration_macaulay.cc 
           bonds_duration_termstru.cc bonds_convexity_termstru.cc bonds_price_both.cc bonds_price.cc 
           bonds_price_termstru.cc bonds_yield.cc bonds_duration_modified.cc)

set(LIBOBJS ${LIBOBJS} term_structure_class.cc term_structure_class_flat.cc term_structure_class_interpolated.cc)

set(LIBOBJS ${LIBOBJS} bin_eur_call_ud_one.cc bin_eur_call_ud.cc binomial_tree_ud.cc)

set(LIBOBJS ${LIBOBJS} black_scholes_call.cc black_scholes_call_div.cc black_scholes_delta_call.cc  
           black_scholes_delta_put.cc black_scholes_imp_vol_bisect.cc black_scholes_imp_vol_newt.cc 
           black_scholes_partials_call.cc black_scholes_partials_put.cc black_scholes_price_payout_call.cc 
           black_scholes_price_payout_put.cc black_scholes_put.cc black_scholes_put_div.cc)

set(LIBOBJS ${LIBOBJS} warrant_price_black_scholes.cc warrant_price_black_scholes_dividends.cc)

set(LIBOBJS ${LIBOBJS} bin_am_call.cc bin_am_delta_call.cc bin_am_delta_put.cc bin_am_div_call.cc 
           bin_am_div_put.cc bin_am_partials_call.cc bin_am_partials_put.cc bin_am_prop_div_call.cc 
           bin_am_prop_div_put.cc bin_am_put.cc bin_eur_call.cc  bin_eur_put.cc 
           bin_am_call_payout.cc bin_am_put_payout.cc)

set(LIBOBJS ${LIBOBJS} anal_price_am_call_div.cc)

set(LIBOBJS ${LIBOBJS} approx_am_call.cc approx_am_put.cc approx_am_put_johnson.cc)

set(LIBOBJS ${LIBOBJS} currency_opt_bin_call.cc currency_opt_bin_put.cc currency_opt_euro_call.cc currency_opt_euro_put.cc)

set(LIBOBJS ${LIBOBJS} futures_opt_call_black.cc futures_opt_put_black.cc futures_price.cc)

set(LIBOBJS ${LIBOBJS} futures_opt_call_bin.cc futures_opt_put_bin.cc)

set(LIBOBJS ${LIBOBJS} findiff_exp_am_call.cc findiff_exp_am_put.cc findiff_exp_eur_call.cc findiff_exp_eur_put.cc)

set(LIBOBJS ${LIBOBJS} merton_jump_diff_call.cc)

set(LIBOBJS ${LIBOBJS} exotics_lookback_call.cc exotics_lookback_put.cc)

set(LIBOBJS ${LIBOBJS} bermudan_call_option.cc bermudan_put_option.cc)

set(LIBOBJS ${LIBOBJS} exotics_asian_price_call.cc)

set(LIBOBJS ${LIBOBJS} option_price_american_perpetual_call.cc option_price_american_perpetual_put.cc)

set(LIBOBJS ${LIBOBJS} simulated_call_euro.cc simulated_delta_call.cc simulated_delta_put.cc simulated_put_euro.cc)

set(LIBOBJS ${LIBOBJS} simulate_lognormal_variable.cc 
           simulate_lognormally_distributed_sequence.cc 
           simulate_european_options_generic_routine_antithetic_variate.cc 
           simulate_european_options_generic_routine.cc 
           simulate_european_options_generic_routine_control_variate.cc 
           simulate_european_options_generic_routine_price_sequence.cc 
           simulate_european_options_generic_routine_price_sequence_control_variate.cc)

set(LIBOBJS ${LIBOBJS} payoff_average.cc payoff_binary_options.cc payoff_black_scholes_case.cc payoff_lookback.cc)

set(LIBOBJS ${LIBOBJS} binomial_generic.cc binomial_generic_delta.cc payoff_binary_put_call.cc)

set(LIBOBJS ${LIBOBJS} opt_price_trinom_am_call.cc opt_price_trinom_am_put.cc)

set(LIBOBJS ${LIBOBJS} bondopt_call_bs.cc bondopt_put_bs.cc  
           bondopt_call_coupon_bs.cc bondopt_put_coupon_bs.cc  
           bondopt_call_binom_am.cc bondopt_put_binom_am.cc)

set(LIBOBJS ${LIBOBJS} termstru_yield_nels_sie.cc term_structure_class_nelson_siegel.cc)

set(LIBOBJS ${LIBOBJS} termstru_discfact_cubic_spline.cc term_structure_class_cubic_spline.cc)

set(LIBOBJS ${LIBOBJS} termstru_discfact_cir.cc  term_structure_class_cir.cc)

set(LIBOBJS ${LIBOBJS} termstru_discfact_vasicek.cc term_structure_class_vasicek.cc)

set(LIBOBJS ${LIBOBJS} term_structure_class_svensson.cc termstru_yield_svensson.cc)

set(LIBOBJS ${LIBOBJS} interest_rate_trees_gbm_build.cc 
           interest_rate_trees_gbm_value_of_cashflows.cc 
           interest_rate_trees_gbm_value_of_callable.cc)

set(LIBOBJS ${LIBOBJS} term_structure_class_ho_lee.cc 
            term_structure_class_ho_lee_calc.cc 
            term_structure_class_ho_lee_build_tree.cc 
            term_structure_class_ho_lee_price_bond_option.cc)

set(LIBOBJS ${LIBOBJS} bondopt_call_vasicek.cc  bondopt_put_vasicek.cc)

set(LIBOBJS ${LIBOBJS} bondopt_call_rend_bart.cc)

set(LIBOBJS ${LIBOBJS} normdist.cc cum_normal_bivariate.cc cum_normal.cc random_normal.cc random_uniform.cc)

# Define target to create a static financial recipes library
add_library(financial_recipes STATIC ${LIBOBJS})

# Add the current directory for headers
target_include_directories(financial_recipes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
