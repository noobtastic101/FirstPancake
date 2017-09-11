cmake_minimum_required(VERSION 3.8)
project(1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp PairingHeap/TripleLinkedList/TripleLinkedList.cpp PairingHeap/TripleLinkedList/TripleLinkedList.h PairingHeap/TripleLinkedList/TripleLinkedListNode.cpp PairingHeap/TripleLinkedList/TripleLinkedListNode.h PairingHeap/PairingHeap.cpp PairingHeap/PairingHeap.h ProcessControlBlock.cpp ProcessControlBlock.h Processes.cpp Processes.h Utils/Pair.cpp Utils/Pair.h)
add_executable(1 ${SOURCE_FILES})