all:
	make testArray
	make testQueue
	make testMap

testArray:
	g++ test-array.cpp -o test-array
	./test-array
	@echo "tests for array: All passed"

testQueue:
	g++ test-queue.cpp -o test-queue
	./test-queue
	@echo "tests for queue: All passed"

testMap:
	g++ test-map.cpp -o test-map
	./test-map
	@echo "tests for map: All passed"

clean:
	rm test-array test-map test-queue

