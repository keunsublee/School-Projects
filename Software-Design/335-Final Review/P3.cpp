
void stdSort (const std::string & header, std::vector<int> data){
    int size = data.size();

    std::sort(data.begin(), data.end());


void quickSelect2 (const std::string & header, std::vector<int> data){
std::vector<int> k = {0, size/4 -1, size/2-1, size*3/4 -1, size-1};
    quickSelect(data, 0, size-1, k);

    quickSelect(data, 0, size/2-1, k);

    quickSelect(data, size/2-1, size-1, k);

template <typename Comparable>
void quickSelect( std::vector<Comparable> &a, int left, int right, std::vector<int> k )
{    if(left+20 <= right )
    {    const Comparable & pivot = median3(a,left,right );

        int i=left, j=right-1;
        for( ; ; )
        {   while(a[++i] < pivot ) { }
            while(pivot < a[--j] ) { }
            if(i<j)
                std::swap(a[i], a[j] );
            else
                break;
        }

        std::swap(a[i], a[right-1 ] );   

        bool recleft=false, recright=false;
        for (int key : k) {
            if (key < i)
                recleft = true;
            else if (key > i)
                recright = true;
        }

        if (recleft)
            quickSelect(a, left, i-1, k);
        if (recright)
            quickSelect(a, i+1, right, k);
    }
    else  
        insertionSort(a, left, right );
}
 
quickselect1 recursion
        std::swap(a[i], a[right- 1] );   
        if(k <= i )
            quickSelect(a, left, i-1, k );
        else if(k > i+1 )
            quickSelect(a, i+1, right, k ); 

       int min = data[0]; 
    for (int i=1; i < size/4 -1; i++) {
        if (data[i] < min) 
        {   min = data[i];  }
    }
    

void countingSort(const std::string &header, std::vector<int> data) {
    int size = data.size();
    
/* 
 Then, sort that vector using std::sort (in an input with many duplicates, a vector of unique values will be much smaller than a vector of all the values). 
 Finally, iterate through that vector finding P25, P50, and P75. 
 You'll have to count how many data points you've seen along the way, since each element of the vector represents multiple data point, not just one.  */
  
    // hash map that adds keys and increments when added
    std::unordered_map<int, int> keymap;
    for (int key : data) {
        keymap[key]++;   }

    std::vector<std::pair<int, int>> pairvec(keymap.begin(), keymap.end());

    //  iterate through the hash map, pushing the key-value pairs in the hash map to a vector
    std::sort(pairvec.begin(), pairvec.end());

    int index=0, p25=-1, p50=-1, p75=-1;
    for (auto &pair : pairvec) {
        index+=pair.second;
        if (p25==-1 && index >= size/4) {
            p25=pair.first;            }
        if (p50==-1 && index >= size/2) {
            p50=pair.first;        }
        if (p75==-1 && index >= size*3/4) {
            p75=pair.first;
            break;          }
    }    

    auto minmax = std::minmax_element(data.begin(), data.end());
    int min = *minmax.first;
    int max = *minmax.second;
    int count2= pairvec.size();


    int p25 = data[size/4 -1];
    int p50 = (size%2==0) ? (data[size/2 -1]+data[size/2]) /2 : data[size/2];
    int p75 = data[size *3/4 -1];

    int max = data[size-1];
    for (int i=size*3/4 -1; i < size-1; i++) {
        if (data[i] > max) 
        {   max = data[i];  }
    }

