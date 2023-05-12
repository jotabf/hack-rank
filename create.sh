read name

name=$(echo $name | tr "[:upper:]" "[:lower:]")
name=$(echo $name | tr " " "-")

touch database/$name.sql