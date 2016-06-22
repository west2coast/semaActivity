void* thinker (void* parm) {
	p_thread dissector;
	int tries = 0, d;
	string input;
	cout << "Input a valid string." << endl;
	for (tries = 0; tries >= 3; tries++) {
		cin >> input;
		bool p1Check = false, p2Check = false, p3Check = false, extraCheck = false;
		string p1Input, p2Input, p3Input; // input = parm?
		for (int pos = 0; pos < input.length ; pos++) {

			if (input[pos] == '*') {

				if (input.substr(pos + 1, 3) == "** " && !p3Check) {
					string s = input.substr(pos + 4); // up one to remove space??
					int i = 0;
					while (p3Input == "") { // isEmpty
						if (s[i] == '*' || i == s.length) {
							p3Input = s.substr(0, i - 1);
							pos += p3Input.length - 1; // DOUBLE CHECK AGAIN minus 1 because pos++ in for loop
						}
						i++;
					}
					// Check inside p3Input for validity and set p3Check = true
					int c = 0, lastPos;
					if (p3Input[0] == ' ') {
						lastPos = 0;
					} else {
						lastPos = 1;
					}
					for (int j = lastPos; j < p3Input.length; j++) {
						if (p3Input[j] == ' ' || (j == p3Input.length - 1 && p3Input[j] != ' ')) {
							c++;
						}
					}
					if (c >= 6) { // makes sure there are at least 6 strings in the input
						p3Check = true;
					} else {
						extraCheck = true;
						pos = input.length - 1;
					}

				} else if (input.substr(pos + 1, 2) == "* " && !p2Check) {
					string s = input.substr(pos + 3);
					int i = 0;
					while (p2Input == "") { // isEmpty
						if (s[i] == '*' || i == s.length) {
							p2Input = s.substr(0, i - 1);
							pos += p2Input.length - 1;
						}
						i++;
					}
					// Check inside p2Input for validity and set p2Check = true
					int c = 0;
					for (int j = 0; j < p2Input.length; j++) {
						if (((int) p2Input[j] >= 0 && (int) p2Input[j] < 10) || (j == p2Input.length - 1 && p2Input[j] == ' ')) {
							c++;
						} else if (p2Input.substr(j, 2) == ", ") {
							c += 2;
							j++;
						} else {
							j = p2Input.length;
						}
					}
					if (c == p2Input.length) {
						p2Check = true;
					} else {
						extraCheck = true;
						pos = input.length - 1;
					}

						/* USE IN PART 2 THREAD ONLY
						vector<int> list;
						string num;
						for (int j = 0; j < p2Input.length; j++) {
							if ((int) p2Input[j] >= 0 && (int) p2Input[j] < 10) {
								num += p2Input[j];
							} else if (p2Input[j] == ',' || j == p2Input.length - 1) {
								list.push_back(atoi(num.c_str()));
								num = "";
							}
						}
						double average = 0;
						for (int av = 0; av < list.size; av++)
							average += list.at(av);
						average /= list.size;
						vector<double> sdList;
						for (int j = 0; j < list.size; j++)
							sdList.push_back((list.at(j) - average)*(list.at(j) - average));
						double sdAvg = 0;
						for (int av = 0; av < sdList.size; av++)
							sdAvg += sdList.at(av);
						sdAvg /= sdList.size;
						double sd = sqrt(sdAvg);
						*/

				} else if (input.substr(pos + 1, 1) == " " && !p1Check) {
					string s = input.substr(pos + 2);
					int i = 0;
					while (p1Input == "") { // isEmpty
						if (s[i] == '*' || i == s.length) {
							p1Input = s.substr(0, i - 1);
							pos += p1Input.length - 1;
						}
						i++;
					}
					// Check inside p1Input for validity and set p1Check = true
					int fCheck, mCheck, lCheck, bCheck; // count the amount of times each is found; problem if anything but 1
					for (int j = 0; j < p1Input.length; j++) {
						if (p1Input[j] == 'F') {
							for (int k = j + 1; k < p1Input.length; k++) {
								if (p1Input[k] == '*' || p1Input[k] == ' ') {
									j = k - 1; // Double check
									k = p1Input.length;
								}
							}
							fCheck++;
						} else if (p1Input[j] == 'M') {
							j++;
							mCheck++;
						} else if (p1Input[j] == 'L') {
							for (int k = j + 1; k < p1Input.length; k++) {
								if (p1Input[k] == '*' || p1Input[k] == ' ') {
									j = k - 1;
									k = p1Input.length;
								}
							}
							lCheck++;
						} else if (p1Input[j] == 'B') {
							string date;
							int numCount;
							bool numValid = true;
							for (int k = j + 1; k < p1Input.length; k++) {
								if ((int) p1Input[k] - '0' >= 0 && (int) p1Input[k] - '0' < 10) {
									date += p1Input[k];
									numCount++;
								} else if (p1Input[k] == '*' || p1Input[k] == ' ') {
									j = k - 1;
									k = p1Input.length;
								} else {
									numValid = false;
								}
							}
							if (numCount == 6 && numValid) {
								string day = p1Input.substr(j - 6, 2);
								string month = p1Input.substr(j - 4, 2);
								string year = p1Input.substr(j - 2, 2);
								int dayI = atoi(day.c_str());
								int monthI = atoi(month.c_str());
								int yearI = atoi(year.c_str());
								if ((dayI > 0 && dayI <= 30) && (monthI > 0 && monthI <= 12) && (yearI >= 0 && yearI < 100)) {
									bCheck++;
								}
							}
						}
					}
					int checkTotal = fCheck + mCheck + lCheck + bCheck;
					if ((fCheck == 1 || fCheck == 0) && (mCheck == 1 || mCheck == 0) && (lCheck == 1 || lCheck == 0) && (bCheck == 1 || bCheck == 0) && checkTotal > 0) {
						p1Check = true;
					} else {
						extraCheck = true;
						pos = input.length - 1;
					} // Ends part1 validity check

				} else {
					extraCheck = true;
					pos = input.length - 1;
					// here because if extraCheck is true, the line is invalid anyway
				}

				pos++;
			} else if (pos == input.length - 1) {
				pos = input.length - 1;
			} // end input[pos] == "*" || endOfLine

		} // end for

		if (p1Check && p2Check && p3Check && !extraCheck) {
			tries = 3;
		} else {
			cout << "Incorrect input. Try again." << endl;
			input = "";
		}
	}

	// Find way to put it all in one while loop maybe.
	if (tries > 3) { // tries should be 4 
		//continue
		d = pthread_create(&dissector, NULL, dissect, ?);
	} else {
		cout << "You have tried too many attempts. The program will now close.";
	}
} // for tries