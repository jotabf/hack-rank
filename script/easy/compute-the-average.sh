read n

sum=0
for((i=0;i<$n;i++));
do
  read value
  sum=$((sum + value))
done

printf "%.3f" $(bc -l <<< "$sum/$n")