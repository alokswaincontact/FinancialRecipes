# Files needed to build date library
set(DATEOBJS    date.cc 
                dated_obs.cc 
                dated_obs_periodic.cc
                date_compare.cc
                dated_obs_calc.cc 
                dated_obs_subsets.cc
                date_iterate.cc
                dated_obs_io.cc)

# Define the library target
add_library(date_library STATIC ${DATEOBJS})

# Add include directories for the library if needed
target_include_directories(date_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
