

auto it = remove_if(v.begin(), v.end(), [] (int x) { return x < 0; });
v.erase(it, v.end());

ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, 
		UnaryPredicate pred); {
	auto it1 = first;
	auto it2 = last;

	while (first != last) {
		while (pred(*first)) {
			++first;
			--it2;
		}
		*it1 = *first;
		++first;
		++it1;
	}

	return it2;

	0h0ej first=0->1, it1=0, it2=5->4
	hh0ej first=2, it1=1, it2=4
	hh0ej first=2->3, it1=1, it2=4->3
	he0ej first=4, it1=2, it2=3
	hejej first=5, it1=3, it2=3
	first=last, return it2

}

