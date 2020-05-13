# test_generator.py
# This generates a list of large numbers

import random
import argparse

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument("input", help = "acceptable range")
	parser.add_argument("size", help = "how many numbers")
	args = parser.parse_args()

	f = open("input.txt", "w+")
	for i in range(int(args.size)):
		f.write(str(random.randrange(int(args.input))) + '\n')
	f.close()

if __name__=="__main__":
	main()
