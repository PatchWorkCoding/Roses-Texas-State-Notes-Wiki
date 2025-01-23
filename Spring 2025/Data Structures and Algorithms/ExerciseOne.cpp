class IntArray {
 private:
   int *dataArray;
 public:
  IntArray(int size) {
   dataArray = new int[size];
  };

  void SetItemAt(int _index, int _value) {
   //Check to see if Index is inside bounds
   dataArray[_index] = _value;
  };

  int GetItemAt(int _index) {
   //Check to see if index is inside bounds
   return dataArray[_index];
  };

  //Add destructor to free up memory!
};
