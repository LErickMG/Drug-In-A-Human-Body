compile:
	g++ src/usoFarmaceando.cpp -I/usr/include/python2.7 -lpython2.7 -o bin/usoFarmaceando -std=c++11
run:
	./bin/usoFarmaceando

testing:
	g++ test/test.cpp -o test/test && ./test/test
	
