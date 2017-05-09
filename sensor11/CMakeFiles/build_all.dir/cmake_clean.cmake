FILE(REMOVE_RECURSE
  "atmega328p.map"
  "CMakeFiles/build_all"
  "atmega328p.hex"
  "atmega328p.eep"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/build_all.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
