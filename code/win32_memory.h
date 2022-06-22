/*
* Depends on....
* windows.h, kernel32.lib
*/ 
//TODO: setup large page support and query this value
#define MEMORY_MIN_COMMIT Kilobyte(4)

struct MemoryArena {
	void* base;
	u64 max;
	u64 commit_pos;
	u64 alloc_pos;
};