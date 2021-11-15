echo "the num"
read n
a=$(($n))
echo "the power"
read p
for (( i = p ;i >1 ;i--))
do 
n=$(($n*$a))
done
echo $n
