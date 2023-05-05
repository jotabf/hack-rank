read input

input=$(echo $input | tr '[:upper:]' '[:lower:]')

if [ "$input" = "y" ] 
then
  echo "YES"
elif [ "$input" = "n" ]  
then
  echo "NO"
fi