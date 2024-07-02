void intersection(int *arr1, int *arr2, int n, int m) 
{
    int i=0;
    int j=0;
    int size=n+m;
    sort(arr1,arr1+n);
    sort(arr2,arr2,+m);
    int output[size];
    int k=0;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            output[k] = arr1[i];
            i++;
            k++;
        } else {
            output[k] == arr2[j];
            j++;
            k++;
        }
    }
        while(i<n){
            output[k] = arr1[i];
            i++;
            k++;

        }
        while(j<m){
            output[k] =arr2[j];
            j++;
            k++;
        }
    for(int s=0;s<size;s++){
        cout << output[s] << " ";
    }
}