# Files needed to build date library
set(SECURITYOBJS    
        security_price_history.cc               
        security_price_history_search.cc
        security_price_history_erase.cc         
        security_price_history_sizes.cc
        security_price_history_prices.cc        
        security_price_history_utils.cc

        stock_price_history.cc
        stock_price_history_adjustments.cc
        stock_price_history_dividends.cc)

# Define the library target
add_library(security_library STATIC ${SECURITYOBJS})

# Add include directories for the library if needed
target_include_directories(security_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(security_library PRIVATE date_library)
