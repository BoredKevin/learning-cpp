#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <string>

int get_valid_input(const std::string& prompt, int min_value, int max_value, const std::string& unit);

#endif // INPUT_VALIDATOR_H
