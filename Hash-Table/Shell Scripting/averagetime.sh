
read -p "please enter dictionary file name:" dictfile
read -p "please enter grid file name:" gridfile

RUNNING_TIME=`./a.out ${dictfile} ${gridfile} | tail -1`

RUNNING_TIME_2=`./a.out ${dictfile} ${gridfile} | tail -1`

RUNNING_TIME_3=`./a.out ${dictfile} ${gridfile} | tail -1`

RUNNING_TIME_4=`./a.out ${dictfile} ${gridfile} | tail -1`

RUNNING_TIME_5=`./a.out ${dictfile} ${gridfile} | tail -1`

total=$((RUNNING_TIME + RUNNING_TIME_2 + RUNNING_TIME_3 + RUNNING_TIME_4 + RUNNING_TIME_5))
#echo $RUNNING_TIME + $RUNNING_TIME_2 + $RUNNING_TIME_3 + RUNNING_TIME_4 + RUNNING_TIME_5))"
total=$((total/5))

total=$((total*1000))

echo "The average run time is ${total}"
