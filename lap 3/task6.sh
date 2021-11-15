sum=0
i=1
while [ true ]
do 
echo "Enter a positive integer :"
read n
if [ $n -eq 0 ]
then
echo "Average = $sum "
break
elif [ $n -gt 0 ]
then
sum=$((($sum+$n)/i))
i=$(($i+1))
elif [ $n -lt 0 ]
then
echo "Error"
fi
done
