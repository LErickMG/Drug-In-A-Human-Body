compile:
	g++ src/usoFarmaceando.cpp -o bin/usoFarmaceando

run:
	./bin/usoFarmaceando

testing:
	g++ test/test.cpp -o test/test && ./test/test
	
