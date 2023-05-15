read input_string

input_string=$(echo $input_string | tr '[:upper:]' '[:lower:]')
input_string=$(echo $input_string | sed 's/ /-/g')

touch $input_string.sh