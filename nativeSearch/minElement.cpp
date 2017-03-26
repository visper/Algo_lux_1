int* minElemet(int* begin, int* end)
{
	int* result = begin;
	for(int* it = begin+1; it < end; ++it) {
		if(*it < *result) {
			result = begin;
		}
		++begin;
	}
	return result;
}
