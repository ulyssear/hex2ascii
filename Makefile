MAKEFLAGS += --silent --no-print-directory

hex2ascii: clean
	gcc -o hex2ascii hex2ascii.c

test: hex2ascii
	# TODO: Unit tests
	# Test 1
	test="756C797373654061726E6175642E74656368";
	buffer=`./hex2ascii $test`;
	expected="ulysse@arnaud.tech";

	# Test 2
	test="686578326173636969";
	buffer=`./hex2ascii $test`;
	expected="hex2ascii";

	# Test 3
	test="6c6f72656d20697073756d20646f6c6f722073697420616d6574";
	buffer=`./hex2ascii $test`;
	expected="lorem ipsum dolor sit amet";

clean:
	-rm hex2ascii 2>/dev/null;

# makefile function to check tests
