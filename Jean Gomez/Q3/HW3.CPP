#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// void printMatrix(int arr, int rows, int cols);
void printMatrix(int **arr, int rows, int cols) {
    cout<<"This is what your matrix looks like: "<<endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout<<arr[i][j]<<"      ";
        }
        cout<<endl;
    }
}

void bubblesort(int **arr, int rows, int cols) {
//int size = rows * cols; // total # of elements in our matrix
int i,j,x,y;
bool swapped = true;

// While loop checks that if we have swapped then the loop is not done being sorted. Therefore only time we can break out of the while loop is when we
// go throught the entire 2d array and we do not end up swapping once. This would mean our 2d array is completely sorted.
while(swapped == true) {
    swapped = false;
        for(j = 0; j < rows; j++) {
            for(x = 0; x < cols; x++) {
                //if statment used to check we are not at the end of the column 
                //compares the first element in the array to the element next to it and if it is greater than the elements before it then we swap
                    
                    if(arr[j][x] > arr[j][x+1]) {   
                        if((x+1)<cols) {   // less than columns, not at the end of the row                 
                            std::swap(arr[j][x], arr[j][x+1]);
                            swapped = true; 
                        }
                    }
                    //if we are at the end of the column and there is another row under it then
                    //we compare the element at the end of the column to the first element in the row under it
                    //(must satisfy both conditions)
                    if(x == cols - 1 && (j+1) < rows) { 
                        if(arr[j][x] > arr[j + 1][0]) {
							std::swap(arr[j][x], arr[j + 1][0]);
                            swapped = true;
                        }
                    }
                
            }
           
        }
    }
}

void insertionSort(int **arr, int rows, int cols) {
    int key,y;
    bool swapped = true;

    while(swapped == true) {
        swapped = false;
        for(int i = 0; i < rows; i++) {
            for(int j =1; j < cols; j++) { 
                key = arr[i][j]; // [0][1] 
                y = j - 1;  // will go through the columns

                // y variable will serve as the element right before the key and if the while loop keeps going then that means there are
                // more elements to go through and it will stop when we get to the first element in that row.

                while(y >= 0 && arr[i][y] > key) { //shift greater elment to the right
                    //if the element prior to the key is greater than it then we shift its value to the right until the condition isn't met in the while
                    //loop
                    arr[i][y+1] = arr[i][y];
                    y = y - 1;
                }
                // 4 3 2

                // now after shifting the value to the right the final position whos value was shifted to the right will store the keys value after breaking
                //out of while loop.
                arr[i][y+1] = key;

                // if we are at the end of the column and there is another row below it then we check if the first element in that row is less than
                // the last element in the previous row. If so we swap them and set the boolean variable equal to true.
                if(j == cols - 1 && (i+1) < rows) {
                        if(arr[i][j] > arr[i  + 1][0]) {
							int temp = arr[i+1][0];
                            arr[i+1][0] = arr[i][j];
                            arr[i][j] = temp;
                            swapped = true;
                        }
                }

            }
        }

    }    
}

void selectionSort(int **arr, int rows, int cols) {

    

    //Rc & Cc is checking through the positions in the 2d array so we can
    //later use the logic to compare the original index to all the elements in the 2d array. Just give us each position in the 2d array
    //that is the purpose of the first 2d arrays.
    int Row_c, Col_c;

    for(Row_c = 0; Row_c < rows; Row_c++){
        for(Col_c = 0; Col_c < cols; Col_c++) { // makes sure we go through each position in the 2d array
            int currentN = arr[Row_c][Col_c]; //[0,0]
            int minN = currentN;
            int minNRow = Row_c;
            int minNcol = Col_c;
        
            for(int Col2d = Col_c + 1; Col2d < cols; Col2d++){ //Due to backtracking issues this loop was needed
                if(arr[Row_c][Col2d] < minN){ // if any value in that row are less than the the position we are in 
                    minNRow = Row_c;  // record the row position
                    minNcol = Col2d;  // record the col position
                    minN = arr[Row_c][Col2d];  // minN will now be the smallest value we are comparing others to.
                }
            }
          
          //goes to the next row and starts comapring the values to minN until we find a value smaller then it in which case we record its position and column
          //Then we set that value equal to minN. minN will be the smallest value 
            for(int Row2d = Row_c + 1 ; Row2d < rows; Row2d++) {
                for(int Col2d = 0; Col2d < cols; Col2d++) {
                    if(arr[Row2d][Col2d] < minN) {
                        minNRow = Row2d;
                        minNcol = Col2d;
                        minN = arr[Row2d][Col2d];
                    }
                    
                }
            }
            // now we will have recorded the smallest value's position and we will swap with the first position of the 2d array with the smallest values position. Now
            //we can move onto the next position of the 2d array and find the second smallest value until we have finished sorting
            std::swap(arr[Row_c][Col_c], arr[minNRow][minNcol]);
            
            
        }
    }
    
}



int main() {
    int rows,cols;
    int **array;

    cout<<"Enter number of rows: "<<endl;
    cin>>rows;
    cout<<"Enter number of columns: "<<endl;
    cin>>cols;

   array = new int *[rows];     //this will create an array of pointers
   for(int i = 0; i < rows; i++) {
       array[i] = new int[cols]; // each ptr in the previous array will now have memory location of an array
   }

    cout<<"Input the values for your 2d array: "<<endl;
    for(int x = 0; x < rows; x++){
        for(int y = 0; y < cols; y++) {
            cin>>array[x][y];
        }
    }

    printMatrix(array,rows,cols);
    // bubblesort(array,rows,cols);
    insertionSort(array,rows,cols);
    // selectionSort(array,rows,cols);
    printMatrix(array,rows,cols);

}



