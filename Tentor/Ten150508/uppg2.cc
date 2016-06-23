#include <iostream>

template<typename InputIterator>
pair<typename iterator_traits<InputIterator>::value_type, size_t> 
max_count(InputIterator first, InputIterator last) {
	using value_t = typename iterator_traits<InputIterator>::value_type;
	if (first == last) {
		return make_pair(value_t(), 0);
	}
	value_t max = *first;
	size_t count = 1;
	++first;
	while (first != last) {
		value_t val = *first;
		if (max < val) {
			max = val;
			count = 1;
		} else if (val < max) {
			//Do nothing
		} else {
			++count;
		}
		++first;
	}
	return make_pair(max, count);
}
	//initialize iterator
	
	//initialize count
	//if first == last -> return 0
	//max = first.elem
	//while följd != end
	//if max < current value -> max = current val
	//else if current value < max -> do nothing
	//else count++
	//return pair
}
