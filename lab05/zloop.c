//zloop holder no 1- arkles counter

while (i < N_TILES) { //test for if farnarkle, if farnarkle, sequence1 and 2 values set to zero
    	if (sequence1[i] == sequence2[i]) {
    		//sequence1[i] = 0;
    		//sequence2[i] = 0;
    		arrayf[i] = 1;
    	} else {
    		arrayf[i] = 0;
    	}
    	i++;
    }

while (i < N_TILES) {
    	while (j < N_TILES) {
    		if (sequence1[i] == sequence2[j] && arraya[j] != 1) {
    				arraya[j] = 1;
    				arkles = arkles + 1;
    				//sequence1[i] = 0;
    				//sequence2[j] = 0;
    			}
    			j++;
    		}
    	}
    	j = 0;
    	i++;
    }


 int farnarkles;
	i = 0;
	farnarkles = 0;
	while (i < N_TILES) { //see if the array at number i is the same, then add one farnarkle
		if (sequence1[i] == sequence2[i]) {
			farnarkles = farnarkles + 1;
		}
		i++;
	}
	
    arkles = arkles - farnarkles;
