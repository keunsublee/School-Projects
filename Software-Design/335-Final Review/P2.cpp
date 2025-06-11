void vectorMedian (const std::vector<int> * instructions){
    std::vector <int> vec; 
    std::vector <int> med;
    for (int num : * instructions){
        if (num !=-1){
           //use upper bound to get iterator to insert position
           auto it = std::upper_bound(vec.begin(), vec.end(), num);
            
            vec.insert(it, num);
        }
 
        else {
            if (!vec.empty())
            med.push_back(vec[((vec.size()-1) /2)]);
            vec.erase(std::next(vec.begin(), (vec.size() - 1) / 2));
    }
}}

void listmedian (const std::vector<int> * instructions){
    std::list<int> list;
    std::vector<int> med;

    for (int num : *instructions) {
        if (num != -1) {
            
            auto it = std::upper_bound(list.begin(), list.end(), num); 
            list.insert(it, num);

        } 
        else if (!list.empty() && num ==-1) {
            auto it = list.begin();
            std::advance(it, ((list.size()-1) / 2));
            med.push_back(*it); 
            list.erase(it);
        }
        }}


void heapMedian (const std::vector<int> * instructions){
std::priority_queue<int> max;  //smaller half 
    std::priority_queue<int, std::vector<int>, std::greater<int>> min; // min heap for larger half
    std::vector<int> med;
    int maxs = 0, mins = 0;    
    for (int num : *instructions) {
        if (num != -1) {
            //check empty or check if num is smaller 
            if (max.empty() || num <= max.top()) {
                max.push(num); maxs++;
            } else if (!max.empty() && num >= max.top()) {  //check 2nd heap is smaller 
                min.push(num); mins++;
            }
            
        //adjusting sizes to keep 
        if (maxs > mins + 1) {
            min.push(max.top());  mins++;
            max.pop(); maxs--;
        } else if (mins > maxs + 1) {
            max.push(min.top());  maxs++;
            min.pop();  mins--;    }
        }
       
        else if (num ==-1){
            if (maxs >= mins) {   //odd, so median is in max
                med.push_back(max.top());
                max.pop(); maxs--;
            } else if (maxs < mins) {
                med.push_back(min.top());
                min.pop(); mins--;
 
            }
        }
    }
}

 void treeMedian (const std::vector<int> * instructions){
    AvlTree <int> max; 
    AvlTree <int> min;
    std::vector<int> med;
    int maxs =0; //max    //class data member
    int mins =0; //min      

    const auto t1_start = std::chrono::steady_clock::now();


    for (int num : *instructions) {
        if (num != -1) {
   
            if (max.isEmpty() || num <= max.findMax()) {    //base empty, compare to max in mtree
                max.insert(num);    
                maxs++;   } 
            else {
                min.insert(num); 
                mins++;   }

            // check size and move elements between trees
            if (maxs > mins + 1) {
                min.insert(max.findMax());      mins++;
                max.remove(max.findMax());      maxs--;
            } 
            
            else if (mins > maxs + 1) {
                max.insert(min.findMin());maxs++;
                min.remove(min.findMin());mins--;
            }
        }
 
 
        else if (num ==-1 && ((maxs+mins )>0) ){  //pop median
            if (maxs >= mins ) {   //odd, so median is in maxsmall
                med.push_back(max.findMax());
                max.remove(max.findMax()); maxs--;
            } else if (maxs < mins ) {
                med.push_back(min.findMin());
                min.remove(min.findMin()); mins --; 
            }
        }
    }
 
 