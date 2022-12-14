# ALG1-TP1
Repository to save my ALG1-TP1 Implementation.
This implementation passes on 100% of the test and additional-test cases given.
Get 100% note, but with 12.5% decrease due to delivery delay.

## Compiling and Running the Program
First of all, clone this repo into a folder of your preference inside your machine by openinng a terminal inside that folder and than enter the project folder by running these commands:
```
git clone https://github.com/matheusflavio/ALG1-TP1.git
cd ALG1-TP1
```
Then, build the tp01 executable. To do that, use the terminal that previously is located inside the project root folder and run the command:
```
make
```
After that, run a test instance by using a command like this:
```
./tp01 < input/input.txt
```
Note that 'input/input.txt' is just a location of a .txt file named 'input.txt' that comes within this repository. It can be used with any location and any .txt file. By running the command that way, the terminal show a line for each case written "yes" if that case is satisfying or "nao" if it's not. That way, line 1 is the answer for test 1, line 2 for the test 2, and so on until the "0 0" input shows on the .txt file.


## Comparing Outputs
To DIRECTLY compare the tests results on the execution, run on terminal:

```
# Case 1 (Tests that refer to the project specification PDF)
diff <(./tp01 < input/input.txt) output/input-out.txt
```
```
# Case 2 (Additional tests given on the course forum)
diff <(./tp01 < input/in.txt) output/in-out.txt
```
Note that 'input-out.txt' and 'in-out.txt' are the correct and expected outputs for each test instance located at './input/' folder.
By using the 'diff' command, the terminal give an output showing the differences between the program execution outputs and the output expectation. Since, at least for these test cases, the program is 100% right, the output of theses comparations are empty since there's no difference.

## Cleaning .o files and the Executable
Just run on the terminal:
```
make clean
```
