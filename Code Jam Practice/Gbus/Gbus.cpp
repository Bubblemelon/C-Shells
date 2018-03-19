#include <iostream>

int main()
{
  // stores the number of cases
  int case_num;

  // stores the 2d array row size
  int row;

  // ">>" will skip whitespace by default
  //
  // puts value into case_num
  std::cin >> case_num;

  // going through each case:
  for(int i = 1; case_num >= i; ++i)
  {
    std::cout << "Case #" << i << ": ";

    std::cin >> row;

    // 2D array to store the line after (N) look at readme
    // column is set to 2 because values are in pairs
    int two_d[row][2];

    // storing values into the 2d array:
    for(int r = 0; row > r; ++r)
    {
      // column size is set to 2
      for(int c = 0; 2 > c; ++c)
      {
        std::cin >> two_d[r][c];
      } // for c

    } // for r

    // stores the number of outputs
    int output_num;

    std::cin >> output_num;

    // to store each bus to count:
    int array[output_num];

    // storing values into the array:
    for(int v = 0; output_num > v; ++v)
    {
      std::cin >> array[v];
    } // for v

    //comparision (finding the output)
    for(int compare = 0; output_num > compare; ++compare)
    {
      int count = 0;

      //comparing each cell in the two_d array
      for(int r = 0; row > r; ++r)
      {
        for(int c = 0; 1 > c; ++c)
        {
          if( two_d[r][c] <= array[compare] && two_d[r][c + 1] >= array[compare] )
          {
            count++;
          }

        } // for c
      } // for r


      std::cout << count << " ";


    } // for compare

    std::cout << std::endl;

  } // for i



  return 0;
}
