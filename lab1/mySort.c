void mySort(int d[], unsigned int n)
{

    for (int i = 0; i < n-1; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(d[i] > d[j])
            {
                int stored = d[i];
                d[i] = d[j];
                d[j] = stored;
            }
        }
    }  
}
