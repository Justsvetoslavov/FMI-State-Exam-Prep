const char* the_big_boss(const char* leaders[][2], size_t n) {
	if (n == 0) {
		return "";
	}
	const char* iter = leaders[0][0];
	bool hasChanged = false;
	while (true) {
		hasChanged = false;
		for (size_t i = 0; i < n; i++) {
			if (strcmp(leaders[i][0], iter) == 0) {
				iter = leaders[i][1];
				hasChanged = true;
				break;
			}
		}

		if (!hasChanged) {
			break;
		}
	}

	return iter;
}

bool is_subordinate(const char* employee,
	const char* manager,
	const char* leaders[][2], // employee - manager
	size_t n
) {
	for (size_t i = 0; i < n; i++) {
		if (strcmp(leaders[i][0], employee) == 0) {
			return strcmp(manager, leaders[i][1]) == 0
				|| is_subordinate(leaders[i][1], manager, leaders, n);
		}
	}

	return false;
}
