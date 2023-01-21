class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans = 0;
        
        sort(arr,arr+n,comp);
        for(int i=0;i<n;i++){
            if(W > arr[i].weight){
                ans += arr[i].value;
                W -= arr[i].weight;
            }else{
                double fract = W;
                fract = (fract/arr[i].weight);
                ans += (fract * arr[i].value);
                break;
            }
        }
        return ans;
        
    }
        
};