// https://codility.com/demo/take-sample-test/frog_river_one/

int solution(int X, int A[], int N) {    
    
    int leafInLocation[X]; // Keeps track of which locations have leaves on them
    for (int i=0;i<=X;i++) { leafInLocation[i] = 0; }
    
    int firstMissingLeaf = 1;
    for (int time = 0; time < N; time++)
    {
        int leafLocation = A[time];
        //printf("time: %i, location %i\n", time, leafLocation);
        
        if (leafInLocation[leafLocation] == 0)
        {
            leafInLocation[leafLocation] = 1;
            //printf("Set Location: %i\n", leafLocation);
            
            // Check if there are any missing leaves
            int missingLeaf = 0;
            for (int location = firstMissingLeaf; location <= X && missingLeaf == 0; location++)
            {
                if (leafInLocation[location] == 0)
                {
                    //printf("Missing Leaf: %i\n", location);
                    missingLeaf = 1;
                }
                else
                {
                    firstMissingLeaf = location;
                }
            }
            
            if (missingLeaf == 0)
            {
                //printf("No Missing Leaf\n");
                return time;
            }
        }
    }
    
    return -1;
}