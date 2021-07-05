# Charlie Gerrie 2021

import sys

# parse arguments
try:
	threshold = int(sys.argv[1])
	limit = int(sys.argv[2])
except IndexError:
	print("Insufficient arguments")
	exit
except ValueError:
	print("Arguments must be numbers")
	exit

# variables for cumulative calculations	
remaining_limit = limit
sum = 0
read_lines = 0;

# read from standard-input
for line in sys.stdin:
	# error handle empty lines
	#if len(line.strip())==0:
		#print("Empty")
	#else:
	
	n = float(line) # will error if non-number
	x = max(0, n - threshold) # remove deductible
	x = min(x, remaining_limit) # don't exceed limit
	remaining_limit = max(0, remaining_limit - x) # subtract from limit
	print("{:.1f}".format(x)) # output
	
	sum += x
	
	# only read 100 lines
	read_lines += 1
	if(read_lines>=100):
		break

# output total
print(sum)
