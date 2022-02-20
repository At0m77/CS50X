
    /** Buuble

    for(int count = 0 ; count < candidate_count;count++) {


        for(int index = 0; index < candidate_count -1 ;index++) {


            if(candidates[index].votes > candidates[index+1].votes) {



                                candidate temp =  candidates[index];


                                candidates[index] = candidates[index + 1];
                                candidates[index + 1] = temp;

            }
        }

    }  **/

   /** selection sort
    * for(int i = 0; i < candidate_count; i++)
    {
        int smallest = candidates[i].votes;
        int smallest_index;
        for(int n = i ; n < candidate_count; n++)
        {
            if (candidates[n].votes < smallest)
            {
                smallest = candidates[n].votes;
                smallest_index = n;
            }
        }

        candidate temp = candidates[i];
        candidates[i] = candidates[smallest_index];
        candidates[smallest_index] = temp;

    }**/


   sort(0, candidate_count-1);

void merge(int low,int high , int mid){
    candidate sorted[high - low + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (candidates[i].votes < candidates[j].votes){
            sorted[k] = candidates[i];
            k++;
            i++;
        }
        else{
            sorted[k] = candidates[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        sorted[k] = candidates[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        sorted[k] = candidates[j];
        j++;
        k++;
    }
    printf("%s",sorted[high -1].name);
}


void sort(int low, int high)
{
    if (low < high)
    {
       int  mid = (low + high) / 2;
        sort(low, mid);
        sort(mid + 1,high);
        merge(low,high,mid);
    }
    else{
        return;
    }
}







