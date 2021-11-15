echo "the salary"
read s
if [ $s -gt 2000 ]
then
r=$(($s*85/100))
echo "your new salary is $r"
elif [ $s -ge 1000 ] && [ $s -le 2000 ]
then
r=$(($s*90/100))
echo "your new salary is $r"
else
echo "your new salary is $s"
fi
