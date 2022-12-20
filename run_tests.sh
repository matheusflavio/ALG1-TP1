####### Run the tests with this script #######

# The binary file is called "tp01"

for i in easy.in hard.in
do
    echo -n "Running test $i ... "

    diff -q <(./tp01 < input/$i) output/${i/.in/.out}
    if [ $? -eq 0 ]
    then
        echo "---> Passed!"
    else
        echo "---> Failed :/"
    fi
done