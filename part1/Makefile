all:
	make testArray
	make testQueue
	make testMap

testArray:
	g++ test-array.cpp -o test-array
	./test-array

testQueue:
	g++ test-queue.cpp -o test-queue
	./test-queue

testMap:
	g++ test-map.cpp -o test-map
	./test-map

clean:
	rm test-array test-map test-queue

