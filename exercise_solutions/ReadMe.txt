STL containers
==========================================
Following are commonly used containers. 
vector, list, queue, deque, set, map

1. Vector
>Vector is good for random access. 
>Not so good for insertion and deletion of intermediate elements. Because it will have reorder everything. 
>Vector elements can be added using push_back()
>Can be accessed like array elements
for (int i = 0;i < s.size();i++) {
        cout << s[i] << "  " ;
    }
>vector can be sorted simply using following code 
sort(s.begin(), s.end());

2. List
>List is good for sequential access. Insertion and Deletion is faster. 
>Elements can be added using push_back()
>Elements can be accessed in following manner. 
for (auto x : s) {
        cout << x << "  ";
    }

3. Queue
> is good for First in first out access
> Elements can be added using push() method
> Elements can be accessed in following manner
while (!q.empty()) {
        cout << q.front();
        q.pop();
    }

4. Set 
> is good for storing unique elements. 
> By default set doesn't let duplicates to be stored. 
> Elements can be added using insert() function like map
> Elements can be accessed using following code. 
for (auto x : s) {
        cout << x << " ";
    }
> Elements can be searched using following code. 
> if (s.find(10)!=s.end()) {
          // found 
   }


5. Map 
> Map is good for storing mapping of elements. 
> Elements can be stored using following code
map<int, string> m;
    m.insert(make_pair(1, "Girish"));
> Elements can be accessed using following code
for (auto x : m) {
        cout << x.first << ":" << x.second << endl;
    }
> By default it doesn't allow duplicate key records to be entered. 

6. deque
> Is good for replacement of queue. 
> Elements can be entered in both the ends. 
> Elements can be accessed in following manner. This is not possible with single queue. We have to remove elements to access it. 
for (auto x : d){
        cout << x << " ";
    }	

// -------------	
// virtual 
// -------------	
Assuming B derives A. Following code represents object slicing. It will call methods of A even if they are virtual. 
B b1;
A a1 = b1;
a1.print();

Following code will call methods of B because if you use reference/pointer then only virtual will work. 
A& a1=b1;


// -----------
// Templates
You can use following code to prefix a class or function and then you can use T as object type. 
template <class T>



