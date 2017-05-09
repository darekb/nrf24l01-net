FILE(REMOVE_RECURSE
  "atmega328p.map"
  "CMakeFiles/upload_eeprom"
  "atmega328p.eep"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/upload_eeprom.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
