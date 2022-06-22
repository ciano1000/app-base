internal void* win32_memory_reserve(u64 size) {
	//TODO: in debug maybe we should always set the base to be the same?
	return VirtualAlloc(null, size, MEM_RESERVE, null);
}

internal void* win32_memory_commit(void *base, u64 size) {
	return VirtualAlloc(base, size, MEM_COMMIT, PAGE_READWRITE);
}

internal void win32_memory_decommit(void *start, u64 size) {
	VirtualFree(start, size, MEM_DECOMMIT);
}

internal void win32_memory_release(void *base) {
	VirtualFree(base, null, MEM_RELEASE);
}
