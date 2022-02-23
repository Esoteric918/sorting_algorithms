#include "sort.h"


 void merge_up(int *arr, int n)
 {
          int step=n/2,i,j,k,temp;
          while (step > 0) {
            for (i=0; i < n; i+=step*2) {
              for (j=i,k=0;k < step;j++,k++) {
            if (arr[j] > arr[j+step]) {
              // swap
              temp = arr[j];
              arr[j]=arr[j+step];
              arr[j+step]=temp;
            }
              }
            }
            step /= 2;
          }
        }

        void merge_down(int *arr, int n) {
          int step=n/2,i,j,k,temp;
          while (step > 0) {
            for (i=0; i < n; i+=step*2) {
              for (j=i,k=0;k < step;j++,k++) {
            if (arr[j] < arr[j+step]) {
              // swap
              temp = arr[j];
              arr[j]=arr[j+step];
              arr[j+step]=temp;
            }
              }
            }
            step /= 2;
          }
        }
