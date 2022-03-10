int arkles, i, j, original1[N_TILES], original2[N_TILES]; //arrayf is array for farnarkles, arraya is array for arkles
//saving sequence 1 and 2 
    i = 0;
    while (i < N_TILES) {
    	sequence1[i] = original1[i];
    	sequence2[i] = original2[i];
    	i++;
    }
    i = 0;
    while (i < N_TILES) { //test for if farnarkle, if farnarkle, sequence1 and 2 values set to zero
    	if (sequence1[i] == sequence2[i]) {
    		sequence1[i] = 0;
    		sequence2[i] = 0;
    	}
    	i++;
    }
    
    // test for arkles
    i = 0;
    j = 0;
    arkles = 0;
    while (i < N_TILES) {
    	while (j < N_TILES) {
    			if (sequence1[i] == sequence2[j] && sequence1[i] != 0) {
    				arkles = arkles + 1;
    				sequence1[i] = 0;
    				sequence2[j] = 0;
    			}
    			j++;
    		
    	}
    	j = 0;
    	i++;
    }
    //restoring orginials
    i = 0;
    while (i < N_TILES) {
    	original1[i] = sequence1[i];
    	original2[i] = sequence2[i];
    	i++;
    }
    return arkles; 
}


