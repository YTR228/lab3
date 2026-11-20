void selection_sort(int *array, int len){
    for (int i =0; i  <= len-2; i++){
        int min_index = i;
        for (int j = i+1; j <= len-1; j++){
            if (array[j] < array[min_index]){
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp; 
        }
        return array;

    }