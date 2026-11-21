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
}

int partition(int *array, int left, int right){
    int pivot = array[(left +right)/2];
    int i = left;
    int j = right;
    while (array[i] < pivot){i++;}
    while (array[j] > pivot){j--;}
    if (i >=j){}
    else{
        //swap(a[i++], a[j--])
        int tmpi = array[i++];
        int tmpj = array[j--];
        array[j--] = tmpi;
        array[i++] = tmpj;
    }
    return j;
}

/* void quicksort(a: T[n], int l, int r)
     if l < r
        int q = partition(a, l, r)
        quicksort(a, l, q)
        quicksort(a, q + 1, r)*/
void quick_sort(int *array, int left, int right){
    if (left<right){
        int q = partition(array, left, right);
        quick_sort(array, left, q);
        quick_sort(array, q+1, right);
    }
}