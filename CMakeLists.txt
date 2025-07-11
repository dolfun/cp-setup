cmake_minimum_required(VERSION 3.20.0)
project(cp)

set(
  SOURCES
  main.cc
)

foreach(SOURCE ${SOURCES})
  get_filename_component(TARGET ${SOURCE} NAME_WE)

  add_executable(${TARGET} ${SOURCE})
  target_compile_features(${TARGET} PRIVATE cxx_std_23)
  target_compile_options(${TARGET} PRIVATE
    -Wall -Wextra
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>
    $<$<CONFIG:Release>:-march=native>
  )
  target_link_options(${TARGET} PRIVATE 
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>
  )
endforeach()

target_precompile_headers(main PRIVATE <bits/stdc++.h>)

configure_file(input.txt input.txt)